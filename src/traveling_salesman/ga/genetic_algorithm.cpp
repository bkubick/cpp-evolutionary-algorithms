#include <algorithm>
#include <vector>

#include "genetic_algorithm.h"
#include "crossover.h"
#include "selection.h"
#include "../utils/array.h"
#include "../utils/random.h"


GeneticAlgorithm::GeneticAlgorithm(Fitness fitness): fitness(fitness){};


/**
 * Runs the traveling salesman genetic algorithm with the corresponding constants declared.
 * 
 * @param population_size       the size of each population for each generation.
 * @param num_generations       the number of generations to run.
 * @param mutation_probability  the likelihood of a chromosome to mutate genes.
 * @return the maximum fitness value for each generation ran.
*/
std::vector<double> GeneticAlgorithm::run(int const& population_size, int const& num_generations, double const& mutation_probability)
{
    // Creating original population
    std::vector<Chromosome> population_1;
    for (int i = 0; i < population_size; i++) {
        std::vector<int> range_vector = utils::rangeVector(fitness.size());
        utils::shuffleVector(range_vector);
        population_1.push_back(Chromosome(fitness, range_vector));
    }

    // Storing Best Population
    std::vector<double> max_per_generation = utils::zerosVector(num_generations);

    // Running through genetic algorithm
    for (int generation = 0; generation < num_generations; generation++) {
        std::vector<Chromosome> population_2 = selection::roulette(population_1);

        // Mutation
        for (int i = 0; i < population_2.size(); i++) {
            if (utils::generateRandomDecimal() <= mutation_probability) {
                population_2[i].reverseSubsetOfGenes();
            }
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
