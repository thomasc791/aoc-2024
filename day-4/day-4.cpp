#include "day-4.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>

int main() {
  auto input = readinput("input");

  int sum_1 = part_1(input);
  int sum_2 = part_2(input);
  std::cout << "Part 1: " << sum_1 << std::endl;
  std::cout << "Part 2: " << sum_2 << std::endl;
}

template <typename T> int part_1(T input) {
  diagonalStrings(input);
  std::string xmas = "XMAS";
  std::string samx = "SAMX";
  size_t sum = 0;
  for (std::string line : input) {
    for (size_t i = 0; (i = line.find(xmas, i)) != std::string::npos;
         i += xmas.size()) {
      sum++;
    }
    for (size_t i = 0; (i = line.find(samx, i)) != std::string::npos;
         i += samx.size()) {
      sum++;
    }
    std::cout << line << std::endl;
  }
  return sum;
}

template <typename T> void diagonalStrings(T &input) {
  size_t vertSize = input.size();
  size_t horiSize = input[0].size();
  input.resize(vertSize + horiSize);
  for (size_t i = 0; i < vertSize; i++) {
    for (size_t j = vertSize - 1; j < input.size(); j++) {
      input[j].push_back(input[i][j - vertSize]);
    }
  }
  size_t vertHoriSize = input.size();
  input.resize(vertHoriSize * 3 - 13);
  size_t i;
  for (i = 3; i < horiSize; i++) {
    size_t vert_j = 0;
    for (size_t j = horiSize - i - 1; j < horiSize; j++) {
      input[vertHoriSize + i - 3].push_back(input[vert_j][j]);
      vert_j++;
    }
  }
  if (vertSize - horiSize != 0) {
    for (i = 0; i < vertSize - horiSize; i++) {
      size_t vert_j = 1;
      for (size_t j = 0; j < horiSize; j++) {
        input[vertHoriSize + horiSize + i - 3].push_back(input[vert_j][j]);
        vert_j++;
      }
    }
  }
  for (i = vertSize - horiSize + 1; i < horiSize - 3; i++) {
    size_t vert_j = 0;
    for (size_t j = 0; j < horiSize - i; j++) {
      input[vertHoriSize + horiSize + i - 4].push_back(input[i + vert_j][j]);
      vert_j++;
    }
  }
  for (i = 3; i < horiSize; i++) {
    size_t vert_j = 0;
    for (size_t j = i + 1; j > 0; j--) {
      input[vertHoriSize + vertSize + horiSize + i - 10].push_back(
          input[vert_j][j - 1]);
      vert_j++;
    }
  }
  if (vertSize - horiSize != 0) {
    for (i = 0; i < vertSize - horiSize; i++) {
      size_t vert_j = 1;
      for (size_t j = horiSize; j > 0; j--) {
        input[2 * vertHoriSize + i + horiSize - 3].push_back(
            input[vert_j][j - 1]);
        vert_j++;
      }
    }
  }
  for (i = vertSize - horiSize + 1; i < horiSize - 3; i++) {
    size_t vert_j = 0;
    for (size_t j = horiSize; j > i; j--) {
      input[2 * vertHoriSize + i + horiSize - 11].push_back(
          input[i + vert_j][j - 1]);
      vert_j++;
    }
  }
}

template <typename T> int part_2(T input) {
  std::string xmas;
  return 0;
}

std::vector<std::string> readinput(std::string file) {
  std::vector<std::string> input;
  std::ifstream f;
  f.open(file);

  std::string a, b;
  std::string val;

  for (std::string line; std::getline(f, line);) {
    input.push_back(line);
  }

  f.close();

  return input;
}
