#include <vector>

#include "random_algorithm.h"
#include "../chromosome.h"
#include "../fitness.h"
#include "../utils/array.h"


RandomAlgorithm::RandomAlgorithm(Fitness fitness): fitness(fitness){}


/**
 * Helper to create a randomly generated population of chromosomes.
 * 
 * @param size  the size of the population of chromosomes.
 * @return      the randomly created population.
*/
std::vector<Chromosome> RandomAlgorithm::createRandomPopulation(int const& size)
{
    std::vector<Chromosome> population;
    population.reserve(size);

    for (int i = 0; i < (size); i++) {
        std::vector<int> range_vector = utils::rangeVector(fitness.size());
        utils::shuffleVector(range_vector);
        population.push_back(Chromosome(fitness, range_vector));
    }

    return population;
}


/**
 * Runs the traveling salesman random algorithm with the corresponding constants declared.
 * 
 * @param population_size       the size of each population for each generation.
 * @param num_generations       the number of generations to run.
 * @return the maximum fitness value for each generation ran.
*/
std::vector<double> RandomAlgorithm::run(int const& population_size, int const& num_generations)
{
    // Initializing population_1
    std::vector<Chromosome> population_1 = this->createRandomPopulation(population_size);

    // Storing Best Population
    std::vector<double> max_per_generation = utils::zerosVector(num_generations);

    // Running through genetic algorithm
    for (int generation = 0; generation < num_generations; generation++) {
        // Creating population 2
        std::vector<Chromosome> population_2 = this->createRandomPopulation(population_size);

        // Sort and Grab top 50%
        std::vector<Chromosome> combined_population;
        combined_population.reserve(population_1.size() + population_2.size());
        combined_population.insert(combined_population.end(), population_1.begin(), population_1.end());
        combined_population.insert(combined_population.end(), population_2.begin(), population_2.end());

        std::sort(combined_population.begin(), combined_population.end(), [](Chromosome chromosome_1, Chromosome chromosome_2){
            return chromosome_1.getFitnessValue() < chromosome_2.getFitnessValue();
        });
        for (int i = 0; i < population_size; i++) {
            population_1[i] = combined_population[i];
        }

        // Pushing best value to array
        Chromosome best_chromosome = population_1[population_size - 1];
        max_per_generation[generation] = best_chromosome.getFitnessValue();
    }

    return max_per_generation;
}
