#include <algorithm>
#include <iostream>
#include <vector>

#include "genetic_algorithm.h"
#include "crossover.h"
#include "selection.h"
#include "../utils/array.h"
#include "../utils/debug.h"
#include "../utils/random.h"

GeneticAlgorithm::GeneticAlgorithm(Fitness fitness): fitness(fitness){};


std::vector<double> GeneticAlgorithm::run(int population_size, int num_generations, double mutation_probability)
{
    std::cout << "Starting Genetic algorithm" << std::endl;

    // Creating original population
    std::vector<Chromosome> population_1;
    for (int i = 0; i < population_size; i++) {
        std::vector<int> range_vector = rangeVector(fitness.size());
        shuffleVector(range_vector);
        population_1.push_back(Chromosome(fitness, range_vector));
    }

    // Storing Best Population
    std::vector<double> max_per_generation = zerosVector(num_generations);

    // Running through genetic algorithm
    for (int generation = 0; generation < num_generations; generation++) {
        std::vector<Chromosome> population_2 = roulette(population_1);

        // Mutation
        for (int i = 0; i < population_2.size(); i++) {
            if (generateRandomDecimal() <= mutation_probability) {
                population_2[i].reverseSubsetGeneMutate();
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
        std::cout << "Generation " << generation + 1 << " Best Fitness: " << best_chromosome.getFitnessValue() << std::endl;
        max_per_generation.push_back(best_chromosome.getFitnessValue());
    }

    return max_per_generation;
}
