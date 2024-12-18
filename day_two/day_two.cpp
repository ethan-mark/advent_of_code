#include "main.hpp"
#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <string>
#include <sstream>

int day_two(std::vector<int> vecOne, std::vector<int> vecTwo) {
	std::vector<int> results = {};
	for (auto num : vecOne) {
		std::cout << num << "\n";
		num += 1; 
	}

	return 0;
}