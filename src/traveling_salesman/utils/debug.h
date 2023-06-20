#include <vector>

#ifndef DEBUG_UTILS_
#define DEBUG_UTILS_


/**
 * Utility function to print out the int entities in a vector.
 * 
 * @param list the list to be printed.
*/
void printList(std::vector<int> list);


/**
 * Utility function to print out the double entities in a vector.
 * 
 * @param list the list to be printed.
*/
void printList(std::vector<double> list);


/**
 * Utility function to print out the vector double entities within a vector.
 * 
 * @param list the list to be printed.
*/
void printList(std::vector< std::vector<double> > list);


/**
 * Utility function to print out tuple entities within a vector.
 * 
 * @param list the list to be printed.
*/
void printList(std::vector< std::tuple<double, int> > list);

#endif
