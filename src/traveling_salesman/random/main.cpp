#include <stdexcept>
#include <string>
#include <tuple>
#include <vector>

#include "matplotlibcpp.h"

#include "random_algorithm.h"
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
    RandomAlgorithm ra = RandomAlgorithm(fitness);

    // Running algorithm (population_size, number_of_generations)
    // Note that the limit is based off total individuals of 1,000,000
    std::vector< std::tuple<int, int> > algorithm_constants = {
        {10, 100000},
        {20, 50000},
        {50, 20000},
    };

    // Output variables
    const std::string figure_file = argv[1];

    for (auto algorithm_constant : algorithm_constants) {
        const int number_of_generations = std::get<1>(algorithm_constant);
        const int population_size = std::get<0>(algorithm_constant);

        std::string output_title = "Running Random Algorithm";
        std::string population_text = "Population: " + std::to_string(population_size);
        std::string generation_text = "Generations: " + std::to_string(number_of_generations);

        std::cout << output_title << " - " << population_text << " " << generation_text << std::endl;

        std::vector<double> fitnesses = ra.run(population_size, number_of_generations);

        std::string label = population_text + " " + generation_text;

        plt::plot(fitnesses, {{"label", label}});
        plt::title("Random Algorithm - Total Distance Traveled");
        plt::xlabel("Generations");
        plt::ylabel("Total Distance");
        plt::legend();
        plt::tight_layout();
    }

    plt::savefig(figure_file);

    return 0;
}
