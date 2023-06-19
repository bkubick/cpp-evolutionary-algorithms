OUTPUT = TravelingSalesmanGa

STD = -std=c++11
TAGS = -Wall -Wextra -Wpedantic -Werror

DEBUG_TAGS = -Wunused-result

TRAVELING_SALESMAN_DIR = src/traveling_salesman

GA_DIR = $(TRAVELING_SALESMAN_DIR)/ga
GA_FILES = $(GA_DIR)/fitness.cpp $(GA_DIR)/chromosome.cpp $(GA_DIR)/crossover.cpp  $(GA_DIR)/selection.cpp $(GA_DIR)/genetic_algorithm.cpp  $(GA_DIR)/main.cpp

UTILS_DIR = $(TRAVELING_SALESMAN_DIR)/utils
UTILS_FILES = $(UTILS_DIR)/array.cpp $(UTILS_DIR)/debug.cpp $(UTILS_DIR)/random.cpp

all:
	clang++ $(STD) $(DEBUG_TAGS) $(UTILS_FILES) $(GA_FILES) -o $(OUTPUT)
