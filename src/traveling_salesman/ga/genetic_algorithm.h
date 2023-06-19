#pragma once
#include <vector>

#include "chromosome.h"
#include "fitness.h"


class GeneticAlgorithm {
    private:
        int population_size;
        int num_generations;
        double mutation_probability;
        Fitness fitness;

    public:
        GeneticAlgorithm(int population_size, int num_generations, double mutation_probability, Fitness fitness);
        std::vector<double> run();
};
