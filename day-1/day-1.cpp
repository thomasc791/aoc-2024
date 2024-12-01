#include "sort.h"
#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <vector>

std::array<std::vector<int>, 2> readinput(std::string file) {
  std::vector<int> A, B;
  std::ifstream f;
  f.open(file);

  auto count = std::count(std::istreambuf_iterator<char>{f}, {}, '\n');
  f.seekg(0);

  A.resize(count);
  B.resize(count);
  std::string a, b;
  for (size_t i; f >> a >> b; i++) {
    A[i] = std::atoi(a.c_str());
    B[i] = std::atoi(b.c_str());
  }

  f.close();
  std::array<std::vector<int>, 2> input = {A, B};

  return input;
}

int main() {
  auto input = readinput("input");

  int low = 0;
  int high = input[0].size() - 1;

  int sum = 0;

  quicksort(input[0], low, high);
  quicksort(input[1], low, high);
  for (size_t i = 0; i <= high; i++) {
    sum += abs(input[0][i] - input[1][i]);
  }
  std::cout << sum << std::endl;
}
