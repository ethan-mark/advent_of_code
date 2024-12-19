#include "main.hpp"
#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <string>
#include <sstream>
#include <map> 

int day_two(std::vector<int> vecOne, std::vector<int> vecTwo) {
	std::map<int,int> results = {};
	for (auto num_one : vecOne) {
		results[num_one] = 0;
		for (auto num_two: vecTwo){
			if (num_one == num_two){
				results[num_one]+=1; 
			}
		}
	}
	int similarity_score = {};
	for (auto result : results){
		similarity_score += (result.first * result.second);
	}

	return similarity_score;
}