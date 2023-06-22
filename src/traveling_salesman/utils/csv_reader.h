#include <string>
#include <vector>


namespace utils {
    /**
     * Helper used to read in the vector of (x, y) coordinates from a file.
     * 
     * @param filepath  the file path of the coordinate file.
     * @return the vector of (x, y) coordinates read in from the file.
    */
    std::vector< std::vector<double> > readCoordinateCsvFile(const std::string& filepath);
}
