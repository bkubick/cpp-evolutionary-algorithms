#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <iostream>

#include "chromosome.h"
#include "fitness.h"
#include "genetic_algorithm.h"


std::vector< std::vector<double> > readCoordinateCsvFile(std::string filepath) {
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

        // If last line is blank, break from the loop.
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


int main() {
    std::cout << "Starting Main" << std::endl;
    std::string test_file = "./data/traveling_salesman/TSP1.csv";

    // Test coordinates. This will eventually be replaced by an input file.
    std::cout << "Reading File" << std::endl;
    std::vector< std::vector<double> > coordinates = readCoordinateCsvFile(test_file);

    // fitness
    std::cout << "Creating Fitness" << std::endl;
    Fitness fitness = Fitness(coordinates);
    GeneticAlgorithm ga = GeneticAlgorithm(30, 1000, 0.01, fitness);

    // Running algorithm
    ga.run();
}
