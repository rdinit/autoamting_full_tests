#include <complex/complex.hpp>
#include <iostream>

void printHeader() {
  std::cout
      << "|STATUS|               ANSWER == CORRECT              | COMMENT\n";
}
bool printTestLog(std::string answer, std::string correct,
                  std::string comment) {
  bool status = answer == correct;
  if (status) {
    std::cout << "|  \033[92mOK\033[0m  | ";
  } else {
    std::cout << "| \033[91mFAIL\033[0m | ";
  }
  std::cout.width(20);
  std::cout << std::right;
  std::cout << answer;
  if (status) {
    std::cout << " == ";
  } else {
    std::cout << " != ";
  }
  std::cout.width(20);
  std::cout << std::left;
  std::cout << correct << " | " << comment << std::endl;

  return status;
}

std::pair<bool, Complex> testInput(std::string input_string) {
  std::istringstream input(input_string);
  Complex complex_number;
  input >> complex_number;
  return std::pair<bool, Complex>{input.good(), complex_number};
}

void testMethods() {
  printHeader();
  std::string x;
  std::ostringstream ostr("");
  int correct_counter = 0;
  int total_tests_counter = 0;

  ostr.str("");
  ostr << Complex(3, 4);
  correct_counter += printTestLog(ostr.str(), "{3, 4}", "create {3, 4}");
  total_tests_counter += 1;

  ostr.str("");
  ostr << Complex(4);
  correct_counter += printTestLog(ostr.str(), "{4, 0}", "complex <- 4");
  total_tests_counter += 1;

  ostr.str("");
  ostr << Complex(3, 4) + Complex(3, -1);
  correct_counter += printTestLog(ostr.str(), "{6, 3}", "{3, 4} + {3, -1}");
  total_tests_counter += 1;

  ostr.str("");
  ostr << Complex(3, 4) - Complex(3, -1);
  correct_counter += printTestLog(ostr.str(), "{0, 5}", "{3, 4} - {3, -1}");
  total_tests_counter += 1;

  ostr.str("");
  ostr << abs(Complex(3, 4));
  correct_counter += printTestLog(ostr.str(), "5", " abs({3, 4})");
  total_tests_counter += 1;

  ostr.str("");
  ostr << Complex(3, 4) * 2;
  correct_counter += printTestLog(ostr.str(), "{6, 8}", " {3, 4} * 2");
  total_tests_counter += 1;

  ostr.str("");
  ostr << 2 * Complex(3, 4);
  correct_counter += printTestLog(ostr.str(), "{6, 8}", " 2 * {3, 4}");
  total_tests_counter += 1;

  ostr.str("");
  ostr << Complex(6, 4) / 2;
  correct_counter += printTestLog(ostr.str(), "{3, 2}", " {6, 4} / 2");
  total_tests_counter += 1;

  ostr.str("");
  try {
    Complex(6, 4) / 0;
  } catch (const std::invalid_argument& e) {
    ostr << e.what();
  }
  correct_counter +=
      printTestLog(ostr.str(), "Division by zero", " {6, 4} / 0");
  total_tests_counter += 1;

  ostr.str("");
  ostr << Complex(12, 8) / Complex(6, 4);
  correct_counter += printTestLog(ostr.str(), "{2, 0}", "{12, 8} / {6, 4}");
  total_tests_counter += 1;

  ostr.str("");
  ostr << (Complex(12, 8) == Complex(12, 8));
  correct_counter += printTestLog(ostr.str(), "1", "{12, 8} == {12, 8}");
  total_tests_counter += 1;

  double z = 100;
  z /= 9995577897775;
  double power = 6575763;
  double y = pow(z, 0.5 / power);
  y = pow(y, 2);
  y = pow(y, power);

  ostr.str("");
  ostr << (y == z);
  correct_counter +=
      printTestLog(ostr.str(), "0",
                   "z = 100/(9995577897775) y = (z**0.5/x) ** 2 ** x; y == z");
  total_tests_counter += 1;

  ostr.str("");
  ostr << (Complex(y, 8) == Complex(z, 8));
  correct_counter += printTestLog(ostr.str(), "1", "{z, 8} == {y, 8}");
  total_tests_counter += 1;

  ostr.str("");
  ostr << (Complex(12, 8) == Complex(12, 7));
  correct_counter += printTestLog(ostr.str(), "0", "{12, 8} != {12, 7}");
  total_tests_counter += 1;

  ostr.str("");
  ostr << (Complex(12, 8) == Complex(11, 8));
  correct_counter += printTestLog(ostr.str(), "0", "{12, 8} != {11, 8}");
  total_tests_counter += 1;

  ostr.str("");
  std::pair<bool, Complex> test_results = testInput("{1, 2}");
  ostr << test_results.first << " " << test_results.second;
  correct_counter += printTestLog(ostr.str(), "1 {1, 2}", "Input: {1, 2}");
  total_tests_counter += 1;

  ostr.str("");
  test_results = testInput("{1,2}");
  ostr << test_results.first << " " << test_results.second;
  correct_counter += printTestLog(ostr.str(), "1 {1, 2}", "Input: {1,2}");
  total_tests_counter += 1;

  ostr.str("");
  test_results = testInput("{1, 2");
  ostr << test_results.first << " " << test_results.second;
  correct_counter += printTestLog(ostr.str(), "0 {0, 0}", "Input: {1, 2");
  total_tests_counter += 1;

  ostr.str("");
  test_results = testInput("1, 2");
  ostr << test_results.first << " " << test_results.second;
  correct_counter += printTestLog(ostr.str(), "0 {0, 0}", "Input: (1, 2}");
  total_tests_counter += 1;

  // finally tests counting
  ostr.str("");
  ostr << correct_counter;
  std::string correct_counter_str = ostr.str();
  ostr.str("");
  ostr << total_tests_counter;
  printTestLog(correct_counter_str, ostr.str(), "correct tests / total tests");
}

int main() {
  std::cout << "Running tests:\n";
  testMethods();
  return 0;
}