#include "day-5.h"
#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <tuple>

int main() {
  std::map<int, std::vector<int>> rules;
  std::vector<std::vector<int>> updates;
  std::tie(rules, updates) = readinput("input");
  int sum_1, sum_2;
  std::tie(sum_1, sum_2) = part_1_and_2(rules, updates);
  std::cout << "Part 1: " << sum_1 << std::endl;
  std::cout << "Part 2: " << sum_2 << std::endl;
}

template <typename T, typename S>
std::pair<size_t, size_t> part_1_and_2(T rules, S &updates) {
  size_t countCorrect = 0;
  size_t countIncorrect = 0;
  for (auto u : updates) {
    size_t correct = 0;
    for (size_t i = u.size() - 1; i > 0; i--) {
      correct += checkUpdateIndex(i, rules, u);
    }
    if (correct != 0) {
      countIncorrect += u[u.size() / 2];
    } else {
      countCorrect += u[u.size() / 2];
    }
  }
  return std::pair(countCorrect, countIncorrect);
}

template <typename T, typename S>
int checkUpdateIndex(size_t index, T rules, S &u) {
  size_t count = 0;
  std::vector<int> subupdate(u.begin(), u.begin() + index);
  auto rule = rules[u[index]];
  if (correctOrder(rule, u, subupdate, index)) {
    count += checkUpdateIndex(index, rules, u);
  } else {
    return 0;
  }
  return 1;
}

template <typename T>
int correctOrder(T rule, T &update, T subupdate, size_t i) {
  size_t j = 0;
  for (auto val : subupdate) {
    for (auto r : rule) {
      if (val == r) {
        update.insert(update.begin() + j, update[i]);
        update.erase(update.begin() + i + 1);
        return 1;
      }
    }
    j++;
  }
  return 0;
}

std::tuple<std::map<int, std::vector<int>>, std::vector<std::vector<int>>>
readinput(std::string file) {
  std::map<int, std::vector<int>> rules;
  std::vector<std::vector<int>> updates;
  std::ifstream f;
  f.open(file);

  std::string key, value;
  std::string line;
  std::array<int, 2> keypair;
  std::string delimiter = "|";

  for (; std::getline(f, line) && line != "";) {
    std::stringstream input_line(line);
    for (size_t i = 0; std::getline(input_line, value, '|'); i++) {
      keypair[i] = atoi(value.c_str());
    }
    if (rules.contains(keypair[0])) {
      rules[keypair[0]].push_back(keypair[1]);
    } else {
      rules.insert(std::pair{keypair[0], std::vector<int>{keypair[1]}});
    }
  }

  size_t position = f.tellg();
  auto count = std::count(std::istreambuf_iterator<char>{f}, {}, '\n');
  updates.resize(count);
  f.seekg(position);

  for (size_t i = 0; std::getline(f, line); i++) {
    std::stringstream input_line(line);
    for (; std::getline(input_line, value, ',');) {
      updates[i].push_back(atoi(value.c_str()));
    }
  }

  f.close();

  return std::make_tuple(rules, updates);
}
