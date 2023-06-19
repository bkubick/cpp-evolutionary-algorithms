#include <vector>

#ifndef DEBUG_UTILS_
#define DEBUG_UTILS_

// TODO: Need to come back and add docstrings
void printList(std::vector<int> list);
void printList(std::vector<double> list);
void printList(std::vector< std::vector<double> > list);
void printList(std::vector< std::tuple<double, int> > list);

#endif
