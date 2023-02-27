// add your code
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include "reservoir.h"
double get_east_storage(std::string date){
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1);
    }
    std::string junk;
    getline(fin, junk); 

    double eastSt, eastEl, westSt, westEl; 
    std::string datetsv;
    while(fin >> datetsv >> eastSt >> eastEl >> westSt >> westEl) { 
        fin.ignore(INT_MAX, '\n');
        if(date == datetsv){
            return eastSt;
        }
    }
    fin.close();
    return 0;
}
double get_min_east(){
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()){
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1);
    }
    std::string junk;
    getline(fin, junk); 
    double eastSt, eastEl, westSt, westEl; 
    double min = INT_MAX;
    std::string datetsv;
    while(fin >> datetsv >> eastSt >> eastEl >> westSt >> westEl) { 
        fin.ignore(INT_MAX, '\n');
        if(eastSt< min){
            min = eastSt;
        }
    }
    fin.close();
    return min;
}
double get_max_east(){
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1);
    }
    std::string junk;
    getline(fin, junk); 
    double eastSt, eastEl, westSt, westEl; 
    double max = 0;
    std::string datetsv;
    while(fin >> datetsv >> eastSt >> eastEl >> westSt >> westEl) { 
        fin.ignore(INT_MAX, '\n');
        if(eastSt > max){
            max = eastSt;
        }
    }
    fin.close();
    return max;
}
std::string compare_basins(std::string date){
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1);
    }
    std::string junk;
    getline(fin, junk); 
    double eastSt, eastEl, westSt, westEl; std::string datetsv;
    while(fin >> datetsv >> eastSt >> eastEl >> westSt >> westEl) { 
        fin.ignore(INT_MAX, '\n');
        if(date == datetsv){
            if(eastEl > westEl){
                return ("East");
            }
            else if(westSt < eastEl){
                return ("West");
            }
            else{
                return ("Equal");
            }
        }
    }
    fin.close();
    return 0;
}