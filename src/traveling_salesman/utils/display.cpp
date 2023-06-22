#include <fstream>
#include <sstream>
#include <string>

#include "display.h"


/**
 * Helper to round double to set number of decimal places within a string.
 * 
 * @param value         the double to be rounded.
 * @param precisiion    how many decimal places to round the double to.
 * @return the string of the round double.
*/
std::string utils::roundDouble(double value, int precision) {
    std::ostringstream ss;
    ss << std::fixed << std::setprecision(precision) << value;
    return ss.str();
}
