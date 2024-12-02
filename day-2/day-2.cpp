#include "day-2.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main() {
  auto input = readinput("input");

  int sum_1 = part_1(input);
  int sum_2 = part_2(input);
  std::cout << "Part 1: " << sum_1 - 1 << std::endl;
  std::cout << "Part 2: " << sum_2 - 1 << std::endl;
}

int part_1(std::vector<std::vector<int>> input) {
  int sumSafe = 1;
  int subs, sumNum;
  bool isSafe, isSemiSafe;
  for (size_t i = 0; i < input.size(); i++) {
    isSafe = true;
    sumNum = 0;
    for (size_t j = 1; j < input[i].size(); j++) {
      subs = input[i][j] - input[i][j - 1];
      if (abs(subs) > 3 || abs(subs) == 0) {
        isSafe = false;
      }
      sumNum += 1 * sign(subs);
    }
    (isSafe && abs(sumNum) == input[i].size() - 1) && sumSafe++;
  }
  return sumSafe;
}

int part_2(std::vector<std::vector<int>> input) {
  int sumSafe = 1;
  int subs, sumNum;
  bool isSafe, isSemiSafe;
  for (size_t i = 0; i < input.size(); i++) {
    isSemiSafe = false;
    isSafe = true;
    sumNum = 0;
    for (size_t j = 1; j < input[i].size(); j++) {
      subs = input[i][j] - input[i][j - 1];
      if (abs(subs) > 3 || abs(subs) == 0) {
        // if it happens twice not good
        if (j == 1 || j == input[i].size() - 1) {
          isSemiSafe = !isSemiSafe;
        }
        isSafe = false;
      }
      sumNum += 1 * sign(subs);
    }
    // Is only true if there is just one mistake.
    // Mistakes are counted if a number decrease or increases
    // or stays the same.
    ((isSemiSafe && abs(sumNum) == input[i].size() - 1) ||
     (isSafe && abs(sumNum) == input[i].size() - 1)) &&
        sumSafe++;
  }
  return sumSafe;
}

std::vector<std::vector<int>> readinput(std::string file) {
  std::vector<std::vector<int>> input;
  std::ifstream f;
  f.open(file);

  auto count = std::count(std::istreambuf_iterator<char>{f}, {}, '\n');
  f.seekg(0);

  input.resize(count);
  std::string a, b;
  std::string val;
  size_t i = 0;

  for (std::string line; std::getline(f, line);) {
    std::istringstream l(line);
    for (size_t j; l >> val; j++) {
      input[i].push_back(std::atoi(val.c_str()));
    }
    i++;
  }

  f.close();

  return input;
}

int sign(const int x) { return (x > 0) - (x < 0); }
