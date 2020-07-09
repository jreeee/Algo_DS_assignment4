#include "Div_n_Conc.hpp" //the file includes the algorithms the struct point and std:vector

#include <cstdlib>    //rand()
#include <iostream>   //std::cin std::cout

int main(int argc, char* argv[]) {

  int seed, size, range; 

  //setting all the values based on user input
  std::cout << "-Please enter a seed for the number generation\n>";
  std::cin >> seed;
  std::cout << "-Please now specify the number of points\n>";
  std::cin >> size;
  std::cout << "-Lastly please enter the horizontal and vertical range\n>";
  std::cin >> range;

  //checking for bad inputs
  if (size <= 2) {
    std::cout << "!Error: size must be greater than two\n";
    return 1;
  }
  if (range < 1) {
    std::cout << "!Error: range too small or negative\n";
    return 1;
  }

  //generating the set based on the requirements
  std::cout << "\n-Thank you, generating the set\n\n";
  std::vector<point> pts(abs(size));
  int setid = 0;
  for (auto &i : pts) {
    std::srand(seed);
    i.x = rand() % (range + 1);
    seed++;
    i.y = rand() % (range + 1);
    seed++;
    i.id = setid;
    setid++;
  }

  //printing out all the points that are in the set
  std::cout << "-Generating complete: the following points are in the set:\n\n";
  for (auto i : pts) {
    std::cout << "-> (" << i.x << "|" << i.y << ")\n";
  }

  //bruteforcing the closest points by using the naive algorithm
  std::cout << "\n\n-using the naive Algorithm:\n\n";
  auto res = naive_alg(pts);
  auto dst = dist(res.first, res.second);
  std::cout << "=>the closest points are (" << res.first.x << "|" << res.first.y << "), (" << res.second.x << "|" << res.second.y << ") with a distance of " << dst << "\n\n";

  //using divide and conquer to get the closest points
  std::cout << "-using divide and conquer:\n\n";
  res = div_n_conc(pts);
  dst = dist(res.first, res.second);
  std::cout << "=>the closest points are (" << res.first.x << "|" << res.first.y << "), (" << res.second.x << "|" << res.second.y << ") with a distance of " << dst << "\n\n";

  return 0;
}