#include <numeric>
#include <random>
#include <stdexcept>
#include <vector>

#include "array.h"

using std::vector;


/**
 * Checks if a vector contains the value.
 * 
 * @param array the vector to check if the corresponding value is within.
 * @param value the value to check if is within the corresponding vector.
 * @return      whether or not the value is within the vector.
*/
bool utils::containsValue(vector<int> const& array, int const& value)
{
    bool found = std::find(array.begin(), array.end(), value) != array.end();
    return found;
}


/**
 * Gets the value and index in a sub-vector from the corresponding vector.
 * 
 * @param array the vector to get the indexes from.
 * @return      the vector of sub-vectors containing the value and corresponding index.
*/
vector< std::tuple<double, int> > utils::getValueIndexArray(vector<double> const& array)
{
    vector< std::tuple<double, int> > arrayAndIndices;
    for (int i = 0; i < array.size(); i++) {
        arrayAndIndices.push_back({ array[i], i });
    }

    return arrayAndIndices;
}


/**
 * Shuffles a vector in place.
 * 
 * @param array the vector to be shuffled.
*/
void utils::shuffleVector(vector<int>& array)
{
    std::random_device rd;
    std::shuffle(array.begin(), array.end(), rd);
}


/**
 * Creates a vector of all ones, with the corresponding size.
 * 
 * @param size  the size of the vector to be created.
 * @return      the newly created ones vector with the corresponding size.
*/
vector<double> utils::onesVector(int const& size)
{
    vector<double> ones_array(size, 1.0);
    return ones_array;
}


/**
 * Creates a vector of all zeros, with the corresponding size.
 * 
 * @param size  the size of the vector to be created.
 * @return      the newly created zeros vector with the corresponding size.
*/
vector<double> utils::zerosVector(int const& size)
{
    vector<double> ones_array(size, 0.0);
    return ones_array;
}


/**
 * Creates a vector beginning at 0, indexing by 1 until vector is the corresponding size.
 * 
 * @param size  the size of the vector to be created.
 * @return      the newly created ones vector with the corresponding size.
*/
vector<int> utils::rangeVector(int const& size)
{
    vector<int> range_vector(size);
    std::iota(range_vector.begin(), range_vector.end(), 0);
    return range_vector;
}


/**
 * Sums up all the elements in the vector and returns the result.
 * 
 * @param array the vector to sum the elements for.
 * @return      the value of all summed up elements.
*/
double utils::sumElements(vector<double>& array)
{
    double total = 0.0;
    for(vector<double>::iterator it = array.begin(); it != array.end(); ++it) {
        total += *it;
    }

    return total;
}


/**
 * Subtracts two vectors and returns the resulting vector.
 * 
 * @param array_1   the vector to subtract from.
 * @param array_2   the vector to subtract.
 * @return          the resulting vector difference.
*/
vector<double> utils::subtractVectors(vector<double> const& array_1, vector<double> const& array_2)
{
    if (array_1.size() != array_2.size()) {
        throw std::runtime_error("Vectors are not same size");
    }

    vector<double> subtracted_array;
    for (int i = 0; i < array_1.size(); i++) {
        subtracted_array.push_back(array_1[i] - array_2[i]);
    }

    return subtracted_array;
}


/**
 * Divides each element in a vector by a scalar, then returns the resulting vector.
 * 
 * @param array the vector to divide each element by.
 * @return      the resulting vector after dividing each element by a scalar.
*/
vector<double> utils::divideByScalar(vector<double> const& array, double const& scalar)
{
    vector<double> divided_list;
    for (int i = 0; i < array.size(); i++) {
        divided_list.push_back(array[i] / scalar);
    }

    return divided_list;
}


/**
 * Creates the cumulative sum of all elements in the vector, and returns the resulting vector.
 * 
 * @param array the vector to create the cumulative sum vector from.
 * @return      the resulting vector of the cumulative sum.
*/
vector<double> utils::cumulativeSum(vector<double> const& array)
{
    double total;
    vector<double> cumulative_sum;
    for (int i = 0; i < array.size(); i++) {
        total += array[i];
        cumulative_sum.push_back(total);
    }

    return cumulative_sum;
}
