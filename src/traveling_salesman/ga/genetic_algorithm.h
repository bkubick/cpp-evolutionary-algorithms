#pragma once
#include <vector>

#include "chromosome.h"
#include "fitness.h"


class GeneticAlgorithm {
    private:
        Fitness fitness;

    public:
        GeneticAlgorithm(Fitness fitness);
        std::vector<double> run(int const& population_size, int const& num_generations, double const& mutation_probability);
};
