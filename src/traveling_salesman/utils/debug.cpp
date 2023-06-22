#include <functional>
#include <iostream>
#include <tuple>
#include <vector>

#include "debug.h"


template <typename T, typename Func>
/**
 * Utility function to print out the entities in a vector.
 * 
 * @param list the list to be printed.
*/
void printListHelper(std::vector<T> list, Func printItem)
{
    std::cout << '[';
    for (int i = 0; i < list.size(); i++) {
        printItem(list[i]);

        if (i != list.size() - 1) {
            std::cout << ',';
        }
    }
    std::cout << ']' << std::endl;
}


/**
 * Utility function to print out the int entities in a vector.
 * 
 * @param list the list to be printed.
*/
void debug::printList(std::vector<int> list)
{
   printListHelper(list, [](int item) {std::cout << item;});
}


/**
 * Utility function to print out the double vector entities in a vector.
 * 
 * @param list the list to be printed.
*/
void debug::printList(std::vector< std::vector<double> > list)
{
    auto lambda = [](std::vector<double> item) {
        std::cout << '[';
        for (auto i : item) {
            std::cout << i;
            if (i != item[item.size() - 1]) {
                std::cout << ',';
            }
        }
        std::cout << ']';
    };
    printListHelper(list, lambda);
}


/**
 * Utility function to print out the double entities in a vector.
 * 
 * @param list the list to be printed.
*/
void debug::printList(std::vector<double> list)
{
   printListHelper(list, [](double item) {std::cout << item;});
}


/**
 * Utility function to print out tuple entities within a vector.
 * 
 * @param list the list to be printed.
*/
void debug::printList(std::vector< std::tuple<double, int> > list)
{
    auto lambda = [](std::tuple<double, int> item) {
        std::cout << "(" << std::get<0>(item) << ", " << std::get<1>(item) << ")";
    };
    printListHelper(list, lambda);
}
