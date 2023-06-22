#pragma once

#include <vector>


class Fitness
{
    private:
        std::vector< std::vector<double> > fitness_matrix;
        std::vector< std::vector<double> > createFitnessMatrix(std::vector< std::vector<double> > const& coordinates);

    public:
        Fitness(std::vector< std::vector<double> > coordinates);
        double calculateFitness(std::vector<int> const& order);
        int size();
};
