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
    // counts ----------------------------------------------------------
    int c = 0;
    int co = 0;
    //West Basin Elevation ---------------------------------------------
    double arr[999]; 
    double newarr[999];
    //dates-------------------------------------------------------------
    std::string datearr[999];
    std::string newdatearr[999];
    std::string datetsv;
    //WORK ------------------------------------------------------------
    while(fin >> datetsv >> eastSt >> eastEl >> westSt >> westEl) { 
        if(datetsv >= date1 && datetsv <= date2){// if date is within start date and end date
            arr[c] = westEl;        //arr[index] = elevation
            datearr[c] = datetsv;   //datesarray[index] = date
            c++;
        }
        fin.ignore(INT_MAX, '\n');
    }
    //This reverses the old arrays and put them in new arrays----------
     for(int i = c-1; i >= 0; i--){//i equals count
        newarr[i] = arr[co];
        newdatearr[i] = datearr[co];
        std::cout << newdatearr[i]<< " " << arr[i] << std::endl;
        co++;
    }
    fin.close();
}