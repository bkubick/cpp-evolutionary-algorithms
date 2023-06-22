#include <vector>

#include "../chromosome.h"
#include "../fitness.h"


class HillClimberAlgorithm {
    private:
        Fitness fitness;

    public:
        HillClimberAlgorithm(Fitness fitness);
        std::vector<double> run(int const& population_size, int const& num_generations);
};
