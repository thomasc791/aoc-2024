#include "scanner.h"
#include <string>

Scanner::Scanner(std::vector<std::string> input) : m_Input(input) {}

void Scanner::lines() {
  m_Sum = 0;
  for (std::string line : m_Input) {
    m_Line = line;
    m_c = m_Line.begin();
    setLine(m_Line);
    readLine();
  }
}

void Scanner::setLine(std::string line) { m_Line = line; }

int Scanner::getSum() { return m_Sum; };

void Scanner::readLine() {
  for (; m_c != m_Line.end(); m_c++) {
    readFunction();
  }
}
void Scanner::readFunction() {
  std::string multFun = "mul";
  std::string doFun = "do";
  std::string dontFun = "don't";
  std::stringstream func;
  for (; isalpha(*m_c) || std::string(1, *m_c) == "'"; m_c++) {
    func << *m_c;
  }
  if (func.str().find(multFun) != std::string::npos) {
    readToken(multFun);
  }
  if (func.str().find(dontFun) != std::string::npos && m_Part_2) {
    readDoToken(dontFun);
  } else if (func.str().find(doFun) != std::string::npos && m_Part_2) {
    readDoToken(doFun);
  }
}

bool Scanner::readToken(std::string func) {
  std::string prevToken = "";
  std::stringstream function;
  if (std::string(1, *m_c) == "(") {
    function << func;
    prevToken = "(";
    m_c++;
  } else {
    return false;
  }
  std::vector<std::string> numbers = {"", ""};
  bool tokenFinal = false;
  for (; !tokenFinal; m_c++) {
    const char c = *m_c;
    switch (c) {
    case ')':
      if (prevToken == "," && m_Add == true) {
        prevToken = ")";
        function << numbers[1] << c << std::endl;
        m_Sum += atoi(numbers[0].c_str()) * atoi(numbers[1].c_str());
        return true;
      } else
        return false;
    case ',':
      if (prevToken == "(") {
        prevToken = ",";
        function << numbers[0] << c;
        continue;
      } else
        return false;
    default:
      if (isdigit(c) && prevToken == "(") {
        numbers[0].push_back(c);
      } else if (isdigit(c) && prevToken == ",") {
        numbers[1].push_back(c);
      } else {
        return false;
      }
      continue;
    }
  }
  return false;
}

bool Scanner::readDoToken(std::string func) {
  std::stringstream function;
  std::string prevToken = "";
  bool doBool;
  bool tokenFinal = false;

  if (std::string(1, *m_c) == "(") {
    doBool = true;
    prevToken = "(";
    function << func;
    function << prevToken;
    m_c++;
  } else
    return false;

  for (; !tokenFinal; m_c++) {
    const char c = *m_c;
    switch (c) {
    case ')':
      if (prevToken == "(") {
        prevToken = ")";
        function << prevToken;
        m_Add = (func != "don't");
        return true;
      } else
        return false;
      break;
    default:
      return false;
    }
  }
  return false;
}
