#include <cstdlib>
#include <tuple>
#include <vector>

#include "crossover.h"
#include "../utils/array.h"
#include "../utils/random.h"


/**
 * Crosses over the two chromosomes genes using a double point crossover.
 * Two random indices are selected as the crossover points for parent_1 and
 * parent_2, then those points are used to create two child chromosomes, then
 * the remaining points of the genes are selected in order of the original parent.
 * 
 * i.e.
 *  parent_1_genes = {1, 2, 3, 4, 5} and parent_2_genes = {3, 1, 5, 2, 4}
 *  
 *  create two children that has crossover indices as 2 & 3
 * 
 *  Insert middle to children:
 *  child_1_genes = {0, 0, 5, 2, 0} and child_2_genes = {0, 0, 3, 4, 0}
 * 
 *  Insert beginning to children (first non-selected genes in order  of other parent):
 *  child_1_genes = {1, 3, 5, 2, 0} and child_2_genes = {1, 5, 3, 4, 0}
 * 
 *  Insert end to children (remaining non-selected genes in order of other parent):
 *  child_1_genes = {1, 3, 5, 2, 4} and child_2_genes = {1, 5, 3, 4, 2}
 * 
 * @param parent_1  the first parent to crossover genes to children.
 * @param parent_2  the second parent to crossover genes to children.
 * @return the two newly created children.
*/
std::tuple<Chromosome, Chromosome> crossover::doublePoint(Chromosome& parent_1, Chromosome& parent_2)
{
    std::vector<int> genes_1 = parent_1.getGenes();
    std::vector<int> genes_2 = parent_2.getGenes();
    int number_of_genes = genes_1.size();

    // Initializing new vectors of genes
    std::vector<int> new_genes_1(number_of_genes, -1);
    std::vector<int> new_genes_2(number_of_genes, -1);

    // Determining split points
    int split_1_index = 0, split_2_index = 0;
    while (split_1_index == split_2_index) {
        split_1_index = utils::generateRandomNumber(number_of_genes - 1);
        split_2_index = utils::generateRandomNumber(number_of_genes - 1);
    }

    // Inserting elements
    if (split_2_index < split_1_index) {
        int temp = split_2_index;
        split_2_index = split_1_index;
        split_1_index = temp;
    }

    // Inserting Middle
    for (int i = split_1_index; i < split_2_index + 1; i++) {
        new_genes_1[i] = genes_2[i];
        new_genes_2[i] = genes_1[i];
    }

    // Inserting Front
    for (int i = 0; i < split_1_index; i++) {
        for (int j = 0; j < number_of_genes; j++) {
            if (!utils::containsValue(new_genes_1, genes_1[j])) {
                new_genes_1[i] = genes_1[j];
                break;
            }
        }

        for (int j = 0; j < number_of_genes; j++) {
            if (!utils::containsValue(new_genes_2, genes_2[j])) {
                new_genes_2[i] = genes_2[j];
                break;
            }
        }
    }

    // Inserting Back
    for (int i = split_2_index + 1; i < number_of_genes; i++) {
        for (int j = 0; j < number_of_genes; j++) {
            if (!utils::containsValue(new_genes_1, genes_1[j])) {
                new_genes_1[i] = genes_1[j];
                break;
            }
        }

        for (int j = 0; j < number_of_genes; j++) {
            if (!utils::containsValue(new_genes_2, genes_2[j])) {
                new_genes_2[i] = genes_2[j];
                break;
            }
        }
    }

    Chromosome child_1 = Chromosome(parent_1.getFitness(), new_genes_1);
    Chromosome child_2 = Chromosome(parent_2.getFitness(), new_genes_2);

    return std::make_tuple(child_1, child_2);
}
