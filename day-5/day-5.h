#include <map>
#include <string>
#include <vector>

std::tuple<std::map<int, std::vector<int>>, std::vector<std::vector<int>>>
readinput(std::string file);

template <typename T, typename S>
std::pair<size_t, size_t> part_1_and_2(T rules, S &updates);

template <typename T, typename S>
int checkUpdateIndex(size_t index, T rules, S &u);

template <typename T>
int correctOrder(T rule, T &update, T subupdate, size_t i);
int main();
