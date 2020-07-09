#include "Div_n_Conc.hpp" //the file includes the algorithms, the struct point and std:vector

#include <cstdlib>    //rand()
#include <iostream>   //std::cin std::cout

int main(int argc, char* argv[]) {

  int seed, size, rangev, rangeh, setid; 

  //setting all the values based on user input
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
  std::cout << "\n-Thank you, generating the set\n\n";
  setid = 0;
  std::srand(seed);
  std::vector<point> pts(abs(size));
  for (auto &i : pts) {
    i.x = rand() % (rangeh + 1);
    seed++;
    i.y = rand() % (rangev + 1);
    seed++;
    i.id = setid;
    setid++;
  }

  //printing out all the points that are in the set
  std::cout << "-Done; the following points are in the set:\n\n";
  for (auto const& i : pts) {
    std::cout << "-> (" << i.x << "|" << i.y << ")\n";
  }

  //bruteforcing the closest points by using the naive algorithm
  std::cout << "\n\n-using the naive Algorithm:\n\n";
  auto res = naive_alg(pts);
  auto dst = dist(res.first, res.second);
  std::cout << "=>the closest points are (" << res.first.x << "|" << res.first.y << "), (" 
            << res.second.x << "|" << res.second.y << ") with a distance of " << dst << "\n\n";

  //using divide and conquer to get the closest points
  std::cout << "-using divide and conquer:\n\n";
  res = div_n_conc(pts);
  dst = dist(res.first, res.second);
  std::cout << "=>the closest points are (" << res.first.x << "|" << res.first.y << "), (" 
            << res.second.x << "|" << res.second.y << ") with a distance of " << dst << "\n\n";

  //printing out the axis?
  char input;
  std::cout << "-Do you want to look at the x and y axis sorted with merge sort? (y/n)\n";
  std::cin >> input;
  if ((input == 'y') || (input == 'Y')) {

    //since they are calculated in a different function 
    //we have to make new ones and sort them to display everything properly
    std::vector<point> x_ax{pts};
    std::vector<point> y_ax{pts};
    merge_sort(x_ax, 0, x_ax.size()-1, true);
    partial_sort(x_ax, true);
    merge_sort(y_ax, 0, y_ax.size()-1, false);
    partial_sort(y_ax, false);

    //printing the x and y axis
    std::cout << "\n-the x axis looks like this:\n\n";
    for (auto const& i : x_ax) {
      std::cout << "-> (" << i.x << "|" << i.y << ")\n";
    }

    std::cout << "\n\n-the y axis looks like this:\n\n";
    for (auto const& i : y_ax) {
      std::cout << "-> (" << i.x << "|" << i.y << ")\n";
    }
  }

  std::cout << "\n-that's all, bye\n";
  return 0;
}