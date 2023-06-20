#pragma once

#include <vector>
using std::vector;

class Fitness {
    private:
        vector< vector<double> > fitness_matrix;
        vector< vector<double> > createFitnessMatrix(const vector< vector<double> >& coordinates);

    public:
        Fitness(vector< vector<double> > coordinates);
        double calculateFitness(const vector<int>& order);
        int size();
};
