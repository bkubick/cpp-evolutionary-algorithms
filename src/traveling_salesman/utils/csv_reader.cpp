#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "csv_reader.h"


/**
 * Helper used to read in the vector of (x, y) coordinates from a file.
 * 
 * @param filepath  the file path of the coordinate file.
 * @return the vector of (x, y) coordinates read in from the file.
*/
std::vector< std::vector<double> > utils::readCoordinateCsvFile(const std::string& filepath)
{
    std::ifstream myFile;
    myFile.open(filepath, std::ios::in);
    
    if (myFile.fail()) {
        std::string errorString = "File: " + filepath + " failed to open";
        throw std::runtime_error(errorString);
    }
    
    std::vector< std::vector<double> > contents;
    std::string line;
    
    while (!myFile.eof()) {
        std::getline(myFile, line);
        std::stringstream s_stream(line);

        if (line.length() == 0) {
            break;
        }

        std::vector<double> result;
        while(s_stream.good()) {
            std::string substr;
            std::getline(s_stream, substr, ',');
            result.push_back(std::stod(substr));
        }

        contents.push_back(result);
    }

    myFile.close();
    
    return contents;
}
