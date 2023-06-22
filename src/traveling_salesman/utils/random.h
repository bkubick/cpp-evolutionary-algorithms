#ifndef RANDOM_UTILS_
#define RANDOM_UTILS_

namespace utils {

/**
 * Generates a random number between 0 (inclusive) and the designated max number.
 * 
 * @param max_number    the max value the number can be.
 * @return the randomly generated number
*/
int generateRandomNumber(int const& maxNumber);


/**
 * Generates a random decimal between 0 (inclusive) 1.
 * 
 * @return the randomly generated decimal.
*/
double generateRandomDecimal();

}
#endif
