#include "main.hpp"
#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <string>


int main() {
	
	std::pair<std::vector<int>,std::vector<int>> results = get_input_vectors();
	std::cout << day_two(results.first, results.second) << std::endl;
	return 0;
}