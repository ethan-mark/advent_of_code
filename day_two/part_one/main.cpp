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
        while (iss>> number){
            row_vector.push_back(number);
        }
        input_vector.push_back(row_vector);
	}; 
    return input_vector; 
}

int determine_level_safety(std::vector<std::vector<int>> vec){
    std::map<int,int> safety_tracker = {}; 
    int index = {0};
    while (index < vec.size()){
        std::vector<int> &row = vec[index];
        bool isSubtract = false;
        if (row[0]> row[1]){
            isSubtract = true;
        }
        else if (row[0] == row[1]){
            continue;
        }
        bool safe = true;
        int previous_number = {row[1]};
        for (int i =2; i < row.size(); i++){
            int current_number = row[i];
            if (previous_number == current_number){
                safe = false;
                break;
            }
            if (isSubtract){
                if ( (abs(previous_number - current_number) < 1) || (abs(previous_number - current_number) > 3) ){
                    safe = false;
                    break;
                }
            }
            if (!isSubtract){
                if ( (abs(previous_number - current_number) < 1) || (abs(previous_number - current_number) > 3) ){
                    safe = false;
                    break;
                }
            }
            
            previous_number = current_number;
            
        }
        if (safe){
            safety_tracker[index]=1; 
        }
        std::cout << index << "\n"; 
        index++;
    }

    int result = {0};
    for (auto &x : safety_tracker){ // &x - reference to each element 
        result += x.second;
        std::cout << x.first << " " << x.second << " "<<result<< "\n";
    }
    std::cout << result << std::endl; 
    return result;
}


int main(){
    determine_level_safety(get_input_vectors());
    return 0;
}
