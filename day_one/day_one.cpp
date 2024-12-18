#include "main.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

int day_one(std::vector<int> arrOne, std::vector<int> arrTwo) {
	std::sort(arrOne.begin(), arrOne.end());
	std::sort(arrTwo.begin(), arrTwo.end());
	std::vector<int> results = {};
	for (int i = 0; i < arrOne.size(); i++) {
		results.push_back(abs(arrOne[i] - arrTwo[i]));
		std::cout << "ArrayOne: " << arrOne[i] << "; ArrayTwo: " << arrTwo[i] << " = "<< abs(arrOne[i] - arrTwo[i]) << "\n";
	}
	int sum = std::accumulate(results.begin(), results.end(), 0);
	return sum; 
}