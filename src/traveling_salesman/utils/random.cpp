#include <random>

#include "random.h"


/**
 * Generates a random number between 0 (inclusive) and the designated max number.
 * @param max_number    the max value the number can be.
 * @return the randomly generated number
*/
int generateRandomNumber(int max_number) {
    std::random_device rd;
    std::uniform_int_distribution<int> dist(0, max_number);
    return dist(rd);
}


/**
 * Generates a random decimal between 0 (inclusive) 1.
 * @return the randomly generated decimal.
*/
double generateRandomDecimal() {
    std::random_device rd;
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    return dist(rd);
}
