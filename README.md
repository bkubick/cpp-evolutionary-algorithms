# Evolutionary Algorithms
Introduction to evolutionary algorithms using C++.


### Poblems to Solve
This repo is designated to run evolutionary algorithms on various projects, such as:
1. Traveling Salesman
2. More to come! (Next up I plan to build a physics simulator and build an algorithm to evolve an organism that walks)


### Traveling Salesman
#### Problem
The traveling salesman problem is a classical np-hard graph problem. The problem asks a salesman to travel to a handful of locations, and needs to identify the optimal route such that the total distance traveled is the lowest possible value.

#### To-Do
1. Need to add unit tests
2. Need to add similar test with randomly generated permutations for each generation instead of a GA.
3. Need to add similar test with the hill climber method.
4. Need to experiment with different types of crossover functions, mutation methods, etc.

#### Genetic Algorithm
The findings below consisted of testing 100 locations consisting of (x, y) coordinates. A simple genetic algorithm was ran using roulette selection and double point crossover, consisting of the following steps:
1. Create starting population of size n with randomized permutations of genes (order of locations to travel).
2. Run roulette selection on population to identify two parents for crossover.
3. Crossover two parents as selected from step-2, and create two offspring.
4. Repeat step 2 and 3 until the total population has been doubled (n children and n parents).
5. Attempt to mutate the genes of each child chromosome based off the mutation probability.
6. Grab the top 50% of chromosomes (n chromosomes) with the best fitness (lowest total distance) from the combined population (n children and n parents), and assign those chromosomes to be the starting population for the next generation.
7. Repeat steps 2-6 for the total number of generations, g.

<img alt="Traveling Salesman Findings" src="https://github.com/bkubick/cpp-evolutionary-algorithms/blob/main/results/traveling_salesman/max_fitnesses.png"/>
<p align="middle">
  Figure-1: Max fitness values (total travel distance) for each generation in the Genetic Algorithm.
</p>
