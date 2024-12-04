#include <ctype.h>
#include <iostream>
#include <sstream>
#include <vector>

class Scanner {
public:
  std::vector<std::string> m_Input;

  Scanner(std::vector<std::string> input);

  void lines();
  void setLine(std::string line);
  int getSum();

private:
  std::string m_Line;
  int m_Sum = 0;
  bool m_Add = true;
  std::string::iterator m_c;
  void readLine();
  const char *readFunction();
  bool readToken(std::string func);
  bool readDoToken(std::string func);
  bool readDontToken(std::string func);
};
