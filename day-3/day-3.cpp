#include "day-3.h"
#include "scanner.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

int main() {
  auto input = readinput("input");

  int sum = part_1_and_2(input);
  std::cout << "Part 2: " << sum << std::endl;
}

int part_1_and_2(std::vector<std::string> input) {
  Scanner scanner(input);
  scanner.lines();
  return scanner.getSum();
}

std::vector<std::string> readinput(std::string file) {
  std::vector<std::string> input;
  std::ifstream f;
  f.open(file);

  auto count = std::count(std::istreambuf_iterator<char>{f}, {}, '\n');
  f.seekg(0);

  input.resize(count);
  std::string a, b;
  std::string val;
  size_t i = 0;

  for (std::string line; std::getline(f, line);) {
    input.push_back(line);
    i++;
  }

  f.close();

  return input;
}
