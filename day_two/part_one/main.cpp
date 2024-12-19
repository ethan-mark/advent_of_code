#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <string>
#include <sstream>
#include <map>

std::vector<std::vector<int>> get_input_vectors() {
	std::ifstream file("inputs_day_two.txt");
	std::string str;
	std::vector<int> row_vector = {};
    std::vector<std::vector<int>> input_vector = {};
	while (std::getline(file, str)) {
        std::istringstream iss(str);
        int number = {}; 
        for (int i=0; i < iss.str().size(); i++){
            iss >> number;
            row_vector.push_back(number);
        }
        input_vector.push_back(row_vector);
	}; 
    return input_vector; 
}

void determine_level_safety(std::vector<std::vector<int>> vec){
    std::map<std::string,int> safety_tracker = {}; 
    int index = {0};
    while (index < vec.size()){
        bool isSubtract = false;
        bool isAdd = false;
        if (vec[index][0] < vec[index][1]){
            isAdd = true;
        }
        else if (vec[index][0]> vec[index][1]){
            isSubtract = true;
        }
        else if (vec[index][0] == vec[index][1]){
            continue;
        }
        int previous_number = vec[index][1];
        for (int i=2; i < vec[index].size()-1 ;i ++){
            int current_number = vec[index][i]
            if (isAdd && abs(previous_number - current_number )){
                
            }
           
        }
        index++;
    }
}


int main(){
    determine_level_safety(get_input_vectors());
    return 0;
}
