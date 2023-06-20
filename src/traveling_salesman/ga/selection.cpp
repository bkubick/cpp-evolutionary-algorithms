#include <algorithm>
#include <functional>
#include <tuple>
#include <vector>

#include "crossover.h"
#include "selection.h"
#include "../utils/array.h"
#include "../utils/random.h"

using std::vector;


/**
 * Returns the index of the bin the value falls within (right comparison).
 * 
 * Assumes all values are positive, and the first bin is >= 0.
 * Does a right comparison, meaning if value falls between
 * two bins, it returns the index of the right bin.
 * 
 * NOTE: Bins passed in defaults to the last bin, if the value does not fall within
 * any other bins. Meaning, if value=2.0, and the last bin is 1.0, the index
 * returned is the index of the last bin, even though the value is greater than
 * the value of the last bin.
 * 
 * @param value the value to identify the corresponding bin.
 * @param bins  the bins to compare the value against.
 * @return The corresponding index of the bin the value falls within.
*/
int binIndexFromProbabilityBin(double value, vector<double>& bins)
{
    // Create vector of tuple with value and index
    vector< std::tuple<double, int> > binsAndIndices = getValueIndexArray(bins);

    // Sort the bins from least to greatest.
    std::sort(binsAndIndices.begin(), binsAndIndices.end(), [](const std::tuple<double, int>& a, const std::tuple<double, int>& b) {
      return std::get<0>(a) < std::get<0>(b);
    });

    // Check left value against 0.0
    if ((value >= 0.0 && value < std::get<0>(binsAndIndices[0]))) {
        return std::get<1>(binsAndIndices[0]);
    }

    // Find the index (TODO: This can be more efficient).
    for (int i = 0; i < binsAndIndices.size() - 1; i++) {
        double binMinValue = std::get<0>(binsAndIndices[i]);
        double binMaxValue = std::get<0>(binsAndIndices[i + 1]);
        double originalIndex = std::get<1>(binsAndIndices[i + 1]);

        // Verifing that value is between bin i and bin i+1
        if (value >= binMinValue && value < binMaxValue) {
            return originalIndex;
        }
    }

    // Only bin it can fall within is the last bin
    return std::get<1>(binsAndIndices[binsAndIndices.size() - 1]);
}


/**
 * Roulette selection which creates a population of offspring with the same size as the original
 * population. The offspring are selected using the normalized cumulative some of all the fitnesses
 * in the population, to make it more likely a chromosome with a higher fitness (lower value) is more
 * likely to be selected.
 * 
 * TODO: Need to update to take the crossover function as a parameter.
 * 
 * @param population            the population to generate the next generation from.
 * @return The newly created population.
*/
vector<Chromosome> roulette(vector<Chromosome>& population)
{
    if (population.size() % 2 != 0) {
        throw std::runtime_error("Population size must be an even number");
    }

    // Storing each individual fitness, and calculate total fitness
    vector<double> population_fitnesses;
    double total_fitness = 0.0;
    for (int i = 0; i < population.size(); i++) {
        double fitness_value = population[i].getFitnessValue();
        total_fitness += fitness_value;
        population_fitnesses.push_back(fitness_value);
    }

    // Getting probabilities (lower fitnesses have higher probability, so subtracting normalized value from 1)
    vector<double> normalized_population_fitnesses = divideByScalar(population_fitnesses, total_fitness);

    vector<double> ones = onesVector(population_fitnesses.size());
    vector<double> probabilities = subtractVectors(ones, normalized_population_fitnesses);

    // Getting Cumulative Sum
    vector<double> cumulative_sum = cumulativeSum(probabilities);

    // Normalizing the cumulative sum so all values are between 0.0 - 1.0, with the largest value being 1.0
    double last_index = cumulative_sum.size() - 1;
    vector<double> normalized_cumulative_sum = divideByScalar(cumulative_sum, cumulative_sum[last_index]);

    vector<Chromosome> offspring;

    for (int i = 0; i < (population.size() / 2); i++) {
        // Grabbing indices of parents based on random_num falling inbetween bins
        int parent_1_index = 0, parent_2_index = 0;
        while (parent_1_index == parent_2_index) {
            double random_decimal_1 = generateRandomDecimal();
            double random_decimal_2 = generateRandomDecimal();
            parent_1_index = binIndexFromProbabilityBin(random_decimal_1, normalized_cumulative_sum);
            parent_2_index = binIndexFromProbabilityBin(random_decimal_2, normalized_cumulative_sum);
        }

        Chromosome parent_1 = population[parent_1_index];
        Chromosome parent_2 = population[parent_2_index];

        // Grabbing New genes
        // TODO: Need to make crossover function a function parameter
        std::tuple<Chromosome, Chromosome> children = doublePointCrossover(parent_1, parent_2);
        offspring.push_back(std::get<0>(children));
        offspring.push_back(std::get<1>(children));
    }

    return offspring;
}
