#include <vector>

#ifndef VECTOR_UTILS_
#define VECTOR_UTILS_

/**
 * Checks if a vector contains the value.
 * 
 * @param array the vector to check if the corresponding value is within.
 * @param value the value to check if is within the corresponding vector.
 * @return      whether or not the value is within the vector.
*/
bool containsValue(std::vector<int> const& list, int const& value);


/**
 * Gets the value and index in a sub-vector from the corresponding vector.
 * 
 * @param array the vector to get the indexes from.
 * @return      the vector of sub-vectors containing the value and corresponding index.
*/
std::vector< std::tuple<double, int> > getValueIndexArray(std::vector<double> const& array);


/**
 * Shuffles a vector in place.
 * 
 * @param array the vector to be shuffled.
*/
void shuffleVector(std::vector<int>& array);


/**
 * Creates a vector of all ones, with the corresponding size.
 * 
 * @param size  the size of the vector to be created.
 * @return      the newly created ones vector with the corresponding size.
*/
std::vector<double> onesVector(int const& size);


/**
 * Creates a vector of all zeros, with the corresponding size.
 * 
 * @param size  the size of the vector to be created.
 * @return      the newly created zeros vector with the corresponding size.
*/
std::vector<double> zerosVector(int const& size);


/**
 * Creates a vector beginning at 0, indexing by 1 until vector is the corresponding size.
 * 
 * @param size  the size of the vector to be created.
 * @return      the newly created ones vector with the corresponding size.
*/
std::vector<int> rangeVector(int const& size);


/**
 * Sums up all the elements in the vector and returns the result.
 * 
 * @param array the vector to sum the elements for.
 * @return      the value of all summed up elements.
*/
double sumElements(std::vector<double>& array);


/**
 * Subtracts two vectors and returns the resulting vector.
 * 
 * @param array_1   the vector to subtract from.
 * @param array_2   the vector to subtract.
 * @return          the resulting vector difference.
*/
std::vector<double> subtractVectors(std::vector<double> const& array_1, std::vector<double> const& array_2);


/**
 * Divides each element in a vector by a scalar, then returns the resulting vector.
 * 
 * @param array the vector to divide each element by.
 * @return      the resulting vector after dividing each element by a scalar.
*/
std::vector<double> divideByScalar(std::vector<double> const& array, double const& scalar);


/**
 * Creates the cumulative sum of all elements in the vector, and returns the resulting vector.
 * 
 * @param array the vector to create the cumulative sum vector from.
 * @return      the resulting vector of the cumulative sum.
*/
std::vector<double> cumulativeSum(std::vector<double> const& array);

#endif
