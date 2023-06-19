#include <set>
#include <vector>
#include <iostream>

#include "chromosome.h"
#include "../utils/random.h"


std::set<int> selectKUniqueIndices(int k, int max_index)
{
    std::set<int> indices;

    while (indices.size() < k) {
        indices.insert(generateRandomNumber(max_index));
    }

    return indices;
}


Chromosome::Chromosome(Fitness fitness, std::vector<int> genes): fitness(fitness), genes(genes)
{
    setFitnessValue();
}


void Chromosome::setFitnessValue()
{
    fitness_value = fitness.calculateFitness(genes);
}


double Chromosome::getFitnessValue()
{
    return fitness_value;
}


Fitness Chromosome::getFitness()
{
    return fitness;
}


std::vector<int> Chromosome::getGenes()
{
    return genes;
}


void Chromosome::reverseSubsetGeneMutate()
{
    std::set<int> indices = selectKUniqueIndices(2, genes.size() - 1);
    std::vector<int> updated_genes;

    // Insert the genes up to the first index to flip
    for (int i = 0; i < *indices.begin(); i++) {
        updated_genes.push_back(genes[i]);
    }

    // Insert flipped genes
    for (int i = *indices.rbegin(); i > *indices.begin() - 1; i--) {
        updated_genes.push_back(genes[i]);
    }

    // Insert the remaining genes
    for (int i = *indices.rbegin() + 1; i < genes.size(); i++) {
        updated_genes.push_back(genes[i]);
    }

    genes = updated_genes;
    setFitnessValue();
}
