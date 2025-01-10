#include "algos1.h"

int main() {
  std::string x = "21685454520057057454344565656454";
  std::string x2 = "816854545200570574354534343";
  std::cout << addteste(x, x2) << "\n";
  std::cout << addint(x, x2) << "\n";
  for (int i = 0; i < 100000; ++i) {
    addteste(x, x2);
  };
  return 0;
};


