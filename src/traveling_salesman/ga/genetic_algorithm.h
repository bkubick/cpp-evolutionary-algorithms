#pragma once
#include <vector>

#include "chromosome.h"
#include "fitness.h"


class GeneticAlgorithm {
    private:
        Fitness fitness;

    public:
        GeneticAlgorithm(Fitness fitness);
        std::vector<double> run(int population_size, int num_generations, double mutation_probability);
};
