#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
void reverse_order(std::string date1, std::string date2){
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1);
    }
    std::string junk;
    getline(fin, junk); 
    double eastSt, eastEl, westSt, westEl; 
    int c = 0;
    int co = 0;
    //West Basin Elevation
    double arr[999]; 
    double newarr[999];
    //dates
    std::string datearr[999];
    std::string ndatearr[999];
    std::string datetsv;
    //PREP ^^^ ---------------------------------------------------------
    while(fin >> datetsv >> eastSt >> eastEl >> westSt >> westEl) { 
        if(datetsv >= date1 && datetsv <= date2){
            arr[c] = westEl;
            datearr[c] = datetsv;
            c++;
        }
        fin.ignore(INT_MAX, '\n');
    }
     for(int i = c-1; i >= 0; i--){
        newarr[i] = arr[co];
        ndatearr[i] = datearr[co];
        std::cout << ndatearr[i]<< " " << arr[i] << std::endl;
        co++;
    }
    fin.close();
}