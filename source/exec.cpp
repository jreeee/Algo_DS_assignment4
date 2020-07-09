#include "Div_n_Conc.hpp"
#include "M_sort.hpp"
#include "point.hpp"
#include <vector>     //std::vector<>
#include <set>        //std::set<>
#include <cstdlib>    //rand()
#include <iostream>   //std::cin std::cout
#include <cmath> 

int main(int argc, char* argv[]) {

  int seed, size, rangeh, rangev; 

  //setting all the values absed on user input
  std::cout << "-Please enter a seed for the number generation\n>";
  std::cin >> seed;
  std::cout << "-Please now specify the number of points\n>";
  std::cin >> size;
  std::cout << "-Lastly please enter the horizontal and vertical range\n>";
  std::cin >> rangeh;
  std::cout << ">";
  std::cin >> rangev;

  //checking for bad inputs
  if (size <= 2) {
    std::cout << "!Error: size must be greater than two\n";
    return 1;
  }
  if ((rangeh < 1) || (rangev < 1)) {
    std::cout << "!Error: range too small or negative\n";
    return 1;
  }

  //generating the set based on the requirements
  std::cout << "\n-Thank you\n-Generating the set\n\n";
  std::vector<point> pts(abs(size));
  for (auto &i : pts) {
    std::srand(seed);
    i.x = rand() % (rangeh + 1);
    i.y = rand() % (rangev + 1);
    seed++;
  }
  std::cout << "-Generating complete: the following points are in the set:\n\n";
  for (auto i : pts) {
    std::cout << "->" << i.x << " " << i.y << "\n";
  }
  std::vector<point> x_ax{pts};
  std::vector<point> y_ax{pts};
  merge_sort(x_ax, 0, x_ax.size()-1, true);
  merge_sort(y_ax, 0, y_ax.size()-1, false);
  std::cout << "\n\n";
  for (auto i : x_ax) {
    std::cout << "-> " << i.x << " " << i.y << "\n";
  }
  std::cout << "\n\n";
  for (auto i : y_ax) {
    std::cout << "-> " << i.x << " " << i.y << "\n";
  }
  return 0;
}