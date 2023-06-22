#include <vector>

#include "hill_climber_algorithm.h"
#include "../chromosome.h"
#include "../fitness.h"
#include "../utils/array.h"


HillClimberAlgorithm::HillClimberAlgorithm(Fitness fitness): fitness(fitness){}


/**
 * Runs the traveling salesman hill climber algorithm with the corresponding constants declared.
 * 
 * @param population_size       the size of each population for each generation.
 * @param num_generations       the number of generations to run.
 * @return the maximum fitness value for each generation ran.
*/
std::vector<double> HillClimberAlgorithm::run(int const& population_size, int const& num_generations)
{
    // Initializing population_1
    std::vector<Chromosome> population_1 = chromosome_factory::createRandomPopulation(population_size, this->fitness);

    // Storing Best Population
    std::vector<double> max_per_generation = utils::zerosVector(num_generations);

    // Running through genetic algorithm
    for (int generation = 0; generation < num_generations; generation++) {
        // Cloning population 2 from population 1
        std::vector<Chromosome> population_2 = population_1;

        // Switching order of random genes in population 2
        for (auto& chromosome : population_2) {
            chromosome.reverseSubsetOfGenes();
        }

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
