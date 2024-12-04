#include "day-3.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

int main() {
  auto input = readinput("input");
  Scanner scanner(input);

  int sum_1 = part_1(scanner);
  int sum_2 = part_2(scanner);
  std::cout << "Part 1: " << sum_1 << std::endl;
  std::cout << "Part 2: " << sum_2 << std::endl;
}

int part_1(Scanner &scanner) {
  scanner.lines();
  return scanner.getSum();
}

int part_2(Scanner &scanner) {
  scanner.m_Part_2 = true;
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
