#pragma once

#include <vector>
using std::vector;

class Fitness {
    private:
        vector< vector<double> > fitness_matrix;
        vector< vector<double> > createFitnessMatrix(vector< vector<double> > coordinates);

    public:
        Fitness(vector< vector<double> > coordinates);
        double calculateFitness(vector<int> order);
        int size();
};
