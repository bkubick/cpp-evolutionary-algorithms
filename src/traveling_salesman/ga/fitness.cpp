#include <cmath>
#include <vector>

#include "fitness.h"

#include "../utils/debug.h"

using std::vector;


Fitness::Fitness(vector< vector<double> > coordinates): fitness_matrix(createFitnessMatrix(coordinates)){}


vector< vector<double> > Fitness::createFitnessMatrix(vector< vector<double> > const& coordinates) {
    /* Creates the fitness matrix
    */
    vector< vector<double> > matrix;

    for (int i = 0; i < coordinates.size(); i++) {
        vector<double> row;
        for (int j=0; j < coordinates.size(); j++) {
            double x_diff = coordinates[j][0] - coordinates[i][0];
            double y_diff = coordinates[j][1] - coordinates[i][1];
            double distanceBetweenPoints = sqrt(pow(x_diff, 2) + pow(y_diff, 2));
            row.push_back(distanceBetweenPoints);
        }
        matrix.push_back(row);
    }
    return matrix;
}


double Fitness::calculateFitness(vector<int> const& order) {
    double fitness = 0.0;

    for (int i = 0; i < order.size() - 1; i++) {
        int m = order[i];
        int n = order[i + 1];
        fitness += fitness_matrix[m][n];
    }

    int m = order[order.size()-1];
    int n = order[0];

    fitness += this->fitness_matrix[m][n];

    return fitness;
}


int Fitness::size() {
    return this->fitness_matrix.size();
}
