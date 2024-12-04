#include "scanner.h"
#include <string>

Scanner::Scanner(std::vector<std::string> input) : m_Input(input) {}

void Scanner::lines() {
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
    const char *func = readFunction();
  }
}
const char *Scanner::readFunction() {
  std::string multFun = "mul";
  std::string doFun = "do";
  std::string dontFun = "don";
  std::stringstream func;
  for (; isalpha(*m_c); m_c++) {
    func << *m_c;
  }
  if (func.str().find(multFun) != std::string::npos) {
    readToken(multFun);
  }
  if (func.str().find(doFun) != std::string::npos) {
    readDoToken(dontFun);
  }
  return "";
}

bool Scanner::readToken(std::string func) {
  std::stringstream function;
  if (std::string(1, *m_c) == "(") {
    function << func;
  }
  std::vector<std::string> numbers = {"", ""};
  bool tokenFinal = false;
  std::string prevToken = "";
  for (; !tokenFinal; m_c++) {
    const char c = *m_c;
    switch (c) {
    case '(':
      if (prevToken == "") {
        prevToken = "(";
        function << c;
        continue;
      } else
        return false;
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

  bool doBool;
  if (std::string(1, *m_c) == "(") {
    doBool = true;
    function << func;
  } else if (func == "don") {
    doBool = false;
    function << func;
  } else
    return false;
  bool tokenFinal = false;
  std::string prevToken = "";
  for (; !tokenFinal; m_c++) {
    const char c = *m_c;
    switch (c) {
    case '(':
      if (prevToken == "") {
        prevToken = "(";
        function << c;
        continue;
      } else if (prevToken == "`") {
        prevToken = "(";
        function << c;
        continue;
      } else
        return false;
      break;
    case ')':
      if (prevToken == "(") {
        prevToken = ")";
        function << c;
        m_Add = doBool;
        return true;
      } else
        return false;
      break;
    case '`':
      if (!doBool) {
        prevToken = "`";
        function << c;
      }
      break;
    case 't':
      function << c;
      break;
    default:
      continue;
    }
  }
  return false;
}

bool Scanner::readDontToken(std::string func) {
  std::stringstream function;
  if (std::string(1, *m_c) != "(") {
  } else {
    function << func;
  }

  bool tokenFinal = false;
  std::string prevToken = "";
  for (; !tokenFinal; m_c++) {
    const char c = *m_c;
    switch (c) {
    case '(':
      if (prevToken == "") {
        prevToken = "(";
        function << c;
        continue;
      } else
        return false;
    case ')':
      if (prevToken == "(") {
        prevToken = ")";
        m_Add = true;
        return true;
      } else
        return false;
      return false;
    default:
      continue;
    }
  }
  return false;
}
