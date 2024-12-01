#include "day-1.h"
#include "sort.h"
#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <vector>

int main() {
  auto input = readinput("input");
  int sum = part_1(input);
  std::cout << sum << std::endl;

  int sum_2 = part_2(input);
  std::cout << sum_2<< std::endl;
}

int part_1(std::array<std::vector<int>, 2> &input) {
  int low = 0;
  int high = input[0].size() - 1;

  int sum = 0;

  quicksort(input[0], low, high);
  quicksort(input[1], low, high);
  for (size_t i = 0; i <= high; i++) {
    sum += abs(input[0][i] - input[1][i]);
  }
  return sum;
}

int part_2(std::array<std::vector<int>, 2> &input) {
  int sum = 0;
  for (size_t i = 0; i < input[0].size(); i++) {
    int valCurr = input[0][i];
    int count = 0;
    size_t start = 0;
    for (size_t j = start; j < input[1].size(); j++) {
      (input[0][i] == input[1][j]) && count++;
      (input[0][i] > input[1][j]) && [](size_t &start, size_t j) { start = j; };
    }
    sum += count * valCurr;
  }

  return sum;
}

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
