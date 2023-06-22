#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <string>
#include <tuple>
#include <vector>

#include "matplotlibcpp.h"

#include "genetic_algorithm.h"
#include "../chromosome.h"
#include "../fitness.h"
#include "../utils/csv_reader.h"
#include "../utils/display.h"

namespace plt = matplotlibcpp;


int main(int argc, char* argv[])
{
    if (argc == 1) {
        throw std::runtime_error("Filename argument for plot file not passed in");
    }

    std::cout << "Starting Main" << std::endl;
    std::string test_file = "./data/traveling_salesman/TSP1.csv";

    // Test coordinates. This will eventually be replaced by an input file.
    std::cout << "Reading File" << std::endl;
    std::vector< std::vector<double> > coordinates = utils::readCoordinateCsvFile(test_file);

    // fitness
    std::cout << "Creating Fitness" << std::endl;
    Fitness fitness = Fitness(coordinates);
    GeneticAlgorithm ga = GeneticAlgorithm(fitness);

    // Running algorithm (population_size, number_of_generations, mutation_probability)
    // Note that the limit is based off total individuals of 100,000
    std::vector< std::tuple<int, int, double> > algorithm_constants = {
        {10, 100000, 0.001},
        {20, 50000, 0.001},
        {50, 20000, 0.001},
        {10, 100000, 0.01},
        {20, 50000, 0.01},
        {50, 20000, 0.01},
        {10, 100000, 0.05},
        {20, 50000, 0.05},
        {50, 20000, 0.05},
    };

    // Output variables
    const std::string figure_file = argv[1];

    for (auto algorithm_constant : algorithm_constants) {
        const double mutation_probability = std::get<2>(algorithm_constant);
        const int number_of_generations = std::get<1>(algorithm_constant);
        const int population_size = std::get<0>(algorithm_constant);

        std::string output_title = "Running Genetic Algorithm";
        std::string population_text = "Population: " + std::to_string(population_size);
        std::string generation_text = "Generations: " + std::to_string(number_of_generations);
        std::string mutation_text = "Mutation Prob: " + utils::roundDouble(mutation_probability);

        std::cout << output_title << " - " << population_text << " " << generation_text << " " << mutation_text << std::endl;

        std::vector<double> fitnesses = ga.run(population_size, number_of_generations, mutation_probability);

        std::string label = population_text + " " + generation_text + " " + mutation_text;

        plt::plot(fitnesses, {{"label", label}});
        plt::title("Total Distance Traveled");
        plt::xlabel("Generations");
        plt::ylabel("Total Distance");
        plt::legend();
        plt::tight_layout();
    }

    plt::savefig(figure_file);

    return 0;
}
