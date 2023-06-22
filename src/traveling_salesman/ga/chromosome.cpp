#include <set>
#include <vector>

#include "chromosome.h"
#include "../utils/random.h"


/**
 * Helper function to select K number of unique indices between 0 and max_index.
 * 
 * @param k         the number of unique indices to select.
 * @param max_index the maximum index that can be selected.
 * @return the unique set of selected indices.
*/
std::set<int> selectKUniqueIndices(int k, int max_index)
{
    std::set<int> indices;

    while (indices.size() < k) {
        indices.insert(utils::generateRandomNumber(max_index));
    }

    return indices;
}


Chromosome::Chromosome(Fitness fitness, std::vector<int> genes): fitness(fitness), genes(genes)
{
    setFitnessValue();
}


/**
 * Setter that sets the fitness value for the corresponding chromosome.
*/
void Chromosome::setFitnessValue()
{
    fitness_value = fitness.calculateFitness(genes);
}


/**
 * Getter that grabs the fitness value for the corresponding chromosome.
 * 
 * @return the fitness value of the chromosome.
*/
double Chromosome::getFitnessValue()
{
    return fitness_value;
}


/**
 * Getter that grabs the fitness object for the corresponding chromosome.
 * 
 * TODO: Might consider combining the fitness object with the chromosome class.
 * 
 * @return the fitness object of the chromosome.
*/
Fitness Chromosome::getFitness()
{
    return fitness;
}


/**
 * Getter that grabs the corresponding chromosome's genes.
 * 
 * @return  the vector of the genes (order of locations from the original coordinates
 *          associated with the chromosome's fitness).
*/
std::vector<int> Chromosome::getGenes()
{
    return genes;
}


/**
 * Mutation that selects two random indices of the genes, then reverses them and sets
 * the fitness_value based off the new order.
 * 
 * i.e.
 *  {1, 2, 3, 4, 5} -> {1, 5, 4, 3, 2} if indices 1 and 4 selected.
*/
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
