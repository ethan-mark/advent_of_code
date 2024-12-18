#include "main.hpp"
#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <string>




int main() {

	std::pair<std::vector<int>, std::vector<int>> results = get_input_vectors();
	int result_sum = { day_one(results.first,results.second) };
	std::cout << result_sum;
	return 0;
}