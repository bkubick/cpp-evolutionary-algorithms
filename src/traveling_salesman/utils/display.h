#include <string>


namespace utils {
    /**
     * Helper to round double to set number of decimal places within a string.
     * 
     * @param value         the double to be rounded.
     * @param precisiion    how many decimal places to round the double to.
     * @return the string of the round double.
    */
    std::string roundDouble(double value, int precision = 3);
}
