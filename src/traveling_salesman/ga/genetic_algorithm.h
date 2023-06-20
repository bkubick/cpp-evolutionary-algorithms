#pragma once
#include <vector>

#include "chromosome.h"
#include "fitness.h"


class GeneticAlgorithm {
    private:
        Fitness fitness;

    public:
        GeneticAlgorithm(Fitness fitness);
        std::vector<double> run(const int& population_size, const int& num_generations, const double& mutation_probability);
};
