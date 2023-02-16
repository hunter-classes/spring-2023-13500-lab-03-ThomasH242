//Thomas Huang, ThomasH242
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include "reservoir.h"
#include "reverseorder.h"
int main(){
  //Task A - East Basin Storage

  std::cout << "Task A" << "\n\n";
  std::cout << "Enter Date 09/10/2018:\n" << "East Basin Storage: "<< get_east_storage("09/10/2018") << "\n\n";
  std::cout << "Enter Date 01/01/2018:\n" << "East Basin Storage: "<< get_east_storage("01/01/2018") << "\n\n";
  std::cout << "Enter Date 11/24/2018:\n" << "East Basin Storage: "<< get_east_storage("11/24/2018") << "\n\n";

  //Task B - Min/Max of East Basin Storage

  std::cout << "Task B" << "\n\n";
  std::cout << "Minimum in East Basin Storage: " << get_min_east() << "\n\n";
  std::cout << "Maximum in East Basin Storage: " << get_max_east() << "\n\n";

  //Task C - Basin elevation comparison 
  std::cout << "Task C" << "\n\n";
  std::cout << "Enter Date: 12/10/2018\n" << "The basin with the higher elevation is: " << compare_basins("12/10/2018") << "\n\n";
  std::cout << "Enter Date: 01/12/2018\n" << "The basin with the higher elevation is: " << compare_basins("01/12/2018") << "\n\n";
  std::cout << "Enter Date: 04/05/2018\n" << "The basin with the higher elevation is: " << compare_basins("04/05/2018") << "\n\n";
  
  //Task D - 
  std::cout << "Task D" << "\n";
  std::cout << "\nThe reverse order of 09/10/2018 to 10/04/2018 of their West Basin Elevation: " << "\n\n";

  reverse_order("09/10/2018","10/04/2018");
  std::cout << "\nThe reverse order of 01/2/2018 to 02/15/2018 of their West Basin Elevation: " << "\n\n";

  reverse_order("01/2/2018","02/15/2018");
  std::cout << "\nThe reverse order of 10/23/2018 to 11/01/2018 of their West Basin Elevation: " << "\n\n";

  reverse_order("10/23/2018","11/01/2018");
  } 