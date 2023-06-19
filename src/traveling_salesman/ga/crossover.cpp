#include <cstdlib>
#include <tuple>
#include <vector>

#include "crossover.h"
#include "../utils/array.h"
#include "../utils/random.h"


std::tuple<Chromosome, Chromosome> doublePointCrossover(Chromosome parent_1, Chromosome parent_2) {
    std::vector<int> genes_1 = parent_1.getGenes();
    std::vector<int> genes_2 = parent_2.getGenes();
    int number_of_genes = genes_1.size();

    // Initializing new vectors of genes
    std::vector<int> new_genes_1(number_of_genes, -1);
    std::vector<int> new_genes_2(number_of_genes, -1);

    // Determining split points
    int split_1_index = 0, split_2_index = 0;
    while (split_1_index == split_2_index) {
        split_1_index = generateRandomNumber(number_of_genes - 1);
        split_2_index = generateRandomNumber(number_of_genes - 1);
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
            if (!containsValue(new_genes_1, genes_1[j])) {
                new_genes_1[i] = genes_1[j];
                break;
            }
        }

        for (int j = 0; j < number_of_genes; j++) {
            if (!containsValue(new_genes_2, genes_2[j])) {
                new_genes_2[i] = genes_2[j];
                break;
            }
        }
    }

    // Inserting Back
    for (int i = split_2_index + 1; i < number_of_genes; i++) {
        for (int j = 0; j < number_of_genes; j++) {
            if (!containsValue(new_genes_1, genes_1[j])) {
                new_genes_1[i] = genes_1[j];
                break;
            }
        }

        for (int j = 0; j < number_of_genes; j++) {
            if (!containsValue(new_genes_2, genes_2[j])) {
                new_genes_2[i] = genes_2[j];
                break;
            }
        }
    }

    Chromosome child_1 = Chromosome(parent_1.getFitness(), new_genes_1);
    Chromosome child_2 = Chromosome(parent_2.getFitness(), new_genes_2);

    return std::make_tuple(child_1, child_2);
}
