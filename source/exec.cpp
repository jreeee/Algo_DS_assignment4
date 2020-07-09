#include "Div_n_Conc.hpp"
#include "M_sort.hpp"
#include "point.hpp"
#include "naive.hpp"
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

  std::cout << "\n\n-using the naive Algorithm:\n\n";
  auto res = naive_alg(pts);
  auto dst = dist(res.first, res.second);
  std::cout << "=>the closest points are " << res.first.x << " | " << res.first.y << ", " << res.second.x << " | " << res.second.y << " with a distance of " << dst << "\n\n";

  std::cout << "-using divide and conquer:\n\n";
  res = div_n_conc(pts);
  dst = dist(res.first, res.second);
  std::cout << "=>the closest points are " << res.first.x << " | " << res.first.y << ", " << res.second.x << " | " << res.second.y << " with a distance of " << dst << "\n\n";
  return 0;
}