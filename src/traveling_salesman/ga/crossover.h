#pragma once

#include <tuple>
#include <vector>

#include "../chromosome.h"

namespace crossover {

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
std::tuple<Chromosome, Chromosome> doublePoint(Chromosome& parent_1, Chromosome& parent_2);

}
