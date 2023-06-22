#pragma once

#include <vector>

#include "fitness.h"


class Chromosome {
    private:
        Fitness fitness;
        double fitness_value;
        std::vector<int> genes;
        void setFitnessValue();

    public:
        Chromosome(Fitness fitness, std::vector<int> genes);
        double getFitnessValue();
        Fitness getFitness();
        std::vector<int> getGenes();
        void reverseSubsetOfGenes();
};


namespace chromosome_factory {
    std::vector<Chromosome> createRandomPopulation(int const& population_size, Fitness& fitness);
}
