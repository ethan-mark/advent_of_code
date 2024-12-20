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
    std::vector<std::vector<int>> input_vector = {};
    int j = {0};
	while (std::getline(file, str)) {
        std::istringstream iss(str);
        std::vector<int> row_vector = {};
        int number = {}; 
        //std::cout <<"Index: "<< j<<") ";
        while (iss>> number){
            row_vector.push_back(number);
        }
        // for (int x : row_vector){
        //     std::cout << x << " ";
        // }
        input_vector.push_back(row_vector);
        j+=1;
        //std::cout <<"\n";
	}; 
    return input_vector; 
}

int determine_level_safety(std::vector<std::vector<int>> vec){
    std::map<int,int> safety_tracker = {}; 
    int index = {0};
    while (index < vec.size()){
        std::cout << "Index: "<< index<< ") ";
        std::vector<int> &row = vec[index];
        bool isSubtract = false;
        // if (row[0]> row[1]){
        //     isSubtract = true;
        // }
        // if (row[0] == row[1]){
        //     std::cout<< "equal numbers found: " << row[0] << " "<< row[1];
        //     std::cout <<"\n";
        //     index++;
        //     continue;
        // }
        bool safe = true;
        //int previous_number = {row[1]};
        // for (int i =2; i < row.size(); i++){
        //     int current_number = row[i];
        //     std::cout << " " << row[i] << " ";
            // if (previous_number == current_number){
            //     std::cout<< "equal numbers found: " << previous_number << " "<< current_number;
            //     safe = false;
            //     break;
            // }
            // if (isSubtract){
            //     if ( ((previous_number - current_number) < 1) || ((previous_number - current_number) > 3) ){
            //         std::cout<< "subraction failed numbers found: " << previous_number << " "<< current_number;
            //         safe = false;
            //         break;
            //     }
            // }
            // if (!isSubtract){
            //     if ((( current_number - previous_number) < 1) || ((current_number - previous_number) > 3 )){
            //         std::cout<< "addition failed numbers found: " << previous_number << " "<< current_number;
            //         safe = false;
            //         break;
            //     }
            // }
        for (int i =0; i < row.size()-1; i++){
            int current_number = row[i];
            int next_number = row[i+1];
            if (i ==0 && current_number> next_number){
                isSubtract = true;
            }
            int difference = abs(current_number - next_number);
            if (difference < 1 || difference > 3){
                safe = false;
                break;
            }
            std::cout << " " << row[i] << " ";
            if (isSubtract && current_number < next_number){
                safe = false;
                break;
            }
            if (!isSubtract && current_number > next_number){
                safe = false;
                break;
            }
        }
        if (safe){
            safety_tracker[index]=1; 
        }
        std::cout<< " "<< "safe: "<< safe;
        std::cout <<"\n";
        index++;
    }
    int result = {0};
    for (auto &x : safety_tracker){ // &x - reference to each element 
        result += x.second;
    }
    std::cout << result << std::endl; 
    return result;
}


int main(){
    //get_input_vectors();
    determine_level_safety(get_input_vectors());
    return 0;
}
