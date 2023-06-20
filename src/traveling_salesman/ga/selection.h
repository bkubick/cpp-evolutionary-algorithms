#pragma once

#include <vector>

#include "chromosome.h"


/**
 * Roulette selection which creates a population of offspring with the same size as the original
 * population. The offspring are selected using the normalized cumulative some of all the fitnesses
 * in the population, to make it more likely a chromosome with a higher fitness (lower value) is more
 * likely to be selected.
 * 
 * TODO: Need to update to take the crossover function as a parameter.
 * 
 * @param population    the population to generate the next generation from.
 * @return The newly created population.
*/
vector<Chromosome> roulette(vector<Chromosome>& population);
