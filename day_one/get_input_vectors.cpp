#include "main.hpp"
#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <string>
#include <sstream>

std::pair<std::vector<int>, std::vector<int>> get_input_vectors() {
	std::ifstream file("day_one_inputs.txt");
	std::string str;
	std::vector<int> vecOne = {};
	std::vector<int> vecTwo = {};
	while (std::getline(file, str)) {
		std::istringstream iss(str);
		int x, y = {};
		iss >> x >> y; 
		std::cout << x << " " << y << "\n";
		vecOne.push_back(x);
		vecTwo.push_back(y);
	}
	return std::make_pair(vecOne, vecTwo);
}