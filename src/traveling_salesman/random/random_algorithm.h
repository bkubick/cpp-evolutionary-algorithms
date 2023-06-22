#include <vector>

#include "../chromosome.h"
#include "../fitness.h"


class RandomAlgorithm {
    private:
        Fitness fitness;

    public:
        RandomAlgorithm(Fitness fitness);
        std::vector<double> run(int const& population_size, int const& num_generations);
};
