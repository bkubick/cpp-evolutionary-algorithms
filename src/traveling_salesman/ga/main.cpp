#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "matplotlibcpp.h"

#include "chromosome.h"
#include "fitness.h"
#include "genetic_algorithm.h"

namespace plt = matplotlibcpp;


/**
 * Helper used to read in the vector of (x, y) coordinates from a file.
 * 
 * @param filepath  the file path of the coordinate file.
 * @return the vector of (x, y) coordinates read in from the file.
*/
std::vector< std::vector<double> > readCoordinateCsvFile(const std::string& filepath)
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


/**
 * Helper used to output a plot of the lowest total distance (best fitness) for each generation
 * to the corresponding pdf file name.
 * 
 * @param pdf_file_name         the name of the output pdf file with the plot.
 * @param fitnesses             the list of lowest fitnesses for each generation.
 * @param mutation_probability  the probability of the mutation used for the algorithm.
*/
void saveFitnessPlot(std::string pdf_file_name, std::vector<double>& fitnesses, double const& mutation_probability)
{
    std::vector<int> generations(fitnesses.size());

    plt::plot(fitnesses);

    plt::title("Total Distance Traveled");
    plt::xlabel("Generations \n (Mutation Probability - ) " + std::to_string(mutation_probability));
    plt::ylabel("Total Distance");
    plt::tight_layout();

    plt::savefig(pdf_file_name);
}


int main()
{
    std::cout << "Starting Main" << std::endl;
    std::string test_file = "./data/traveling_salesman/TSP1.csv";

    // Test coordinates. This will eventually be replaced by an input file.
    std::cout << "Reading File" << std::endl;
    std::vector< std::vector<double> > coordinates = readCoordinateCsvFile(test_file);

    // fitness
    std::cout << "Creating Fitness" << std::endl;
    Fitness fitness = Fitness(coordinates);
    GeneticAlgorithm ga = GeneticAlgorithm(fitness);

    // Running algorithm
    const std::string figure_file = "test.pdf";
    const double mutation_probability = 0.01;
    const int number_of_generations = 50;
    const int population_size = 30;

    std::cout << "Starting Genetic algorithm" << std::endl;
    std::vector<double> fitnesses = ga.run(population_size, number_of_generations, mutation_probability);

    saveFitnessPlot(figure_file, fitnesses, mutation_probability);

    return 0;
}
