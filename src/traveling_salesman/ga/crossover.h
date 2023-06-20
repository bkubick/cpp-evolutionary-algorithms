#pragma once

#include <tuple>
#include <vector>

#include "chromosome.h"

std::tuple<Chromosome, Chromosome> doublePointCrossover(Chromosome& parent_1, Chromosome& parent_2);
