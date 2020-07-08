//#include"Div_n_Conc.hpp"
#include "point.hpp"
#include <vector>     //std::vector<>
#include <set>        //std::set<>
#include <cstdlib>    //rand()
#include <iostream>   //std::cin std::cout
#include <cmath> 

int main(int argc, char* argv[]) {
  int seed, size, rangeh, rangev;
  std::cout << "please enter a seed for the number generation\n";
  std::cin >> seed;
  std::cout << "please now set the desired size of the set\n";
  std::cin >> size;
  std::cout << "lastly please enter the horizontal and vertical range\n";
  std::cin >> rangeh;
  std::cin >> rangev;
  std::vector<point> pts(size);
  for (auto &i : pts) {
    std::srand(seed);
    i.x = rand() % (rangeh + 1);
    i.y = rand() % (rangev + 1);
    seed++;
  }
  for (auto i : pts) {
    std::cout << i.x << " " << i.y << "\n";
  }
  return 0;
}