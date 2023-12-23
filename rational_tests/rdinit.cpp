#include <rational/rational.hpp>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include <sstream>

#include "doctest.h"

void testing() {
  Rational r(int64_t(3));
  std::cout << Rational(4) << std::endl;

  std::cout << Rational(4, 3) << std::endl;
  try {
    std::cout << Rational(4, 0) << std::endl;
  } catch (const std::invalid_argument& e) {
    std::cout << e.what() << std::endl;
  }
  try {
    std::cout << Rational(4, -1) << std::endl;
  } catch (const std::invalid_argument& e) {
    std::cout << e.what() << std::endl;
  }
}

TEST_CASE("rational ctor") {
  Rational r_def;
  CHECK(0 == r_def.num());
  CHECK(1 == r_def.den());

  Rational r_int(3);
  CHECK(3 == r_int.num());
  CHECK(1 == r_int.den());

  Rational r_minus_int(-3);
  CHECK(-3 == r_minus_int.num());
  CHECK(1 == r_minus_int.den());

  CHECK_THROWS(Rational(1, 0));
}

TEST_CASE("rational gcd") {
  Rational r(15, 6);
  CHECK(5 == r.num());
  CHECK(2 == r.den());

  Rational r_minus(-15, 6);
  CHECK(-5 == r_minus.num());
  CHECK(2 == r_minus.den());

  Rational r_minus2(15, 6);
  r_minus2 /= -1;
  CHECK(-5 == r_minus2.num());
  CHECK(2 == r_minus2.den());

  r_minus2 *= -1;
  CHECK(5 == r_minus2.num());
  CHECK(2 == r_minus2.den());
}

TEST_CASE("arithmetics") {
  Rational r23(2, 3);
  Rational r12(1, 2);
  Rational r76(7, 6);
  Rational r16(1, 6);
  CHECK(r76 == r23 + r12);
  CHECK(r16 == r76 - 1);
  CHECK(r76 == r16 * 7);
  CHECK(r76 == 7 * r16);
  CHECK(r16 == r76 / 7);
};

TEST_CASE("IO") {
  std::istringstream istream("2/3");
  Rational reading;
  Rational r23(2, 3);

  istream >> reading;
  CHECK_FALSE(istream.fail());
  CHECK(reading.num() == 2);
  CHECK(reading.den() == 3);

  std::istringstream istream2("4/5");
  istream2 >> reading;
  CHECK(reading.num() == 4);
  CHECK(reading.den() == 5);

  std::istringstream istream3("7/8");
  istream3 >> reading;
  CHECK(reading.num() == 7);
  CHECK(reading.den() == 8);

  std::istringstream istream4("-712/38");
  istream4 >> reading;
  CHECK(reading.num() == -712);
  CHECK(reading.den() == 38);

  std::istringstream istream5("-123 / 48");
  istream5 >> reading;
  CHECK(reading.num() == -123);
  CHECK(reading.den() == 48);

  std::istringstream istream6("7/ -8");
  CHECK_THROWS(istream6 >> reading);

  std::istringstream istream7("4|54");
  istream7 >> reading;
  std::ostringstream ostream;
  CHECK(istream7.fail());
  ostream << Rational(2, 3);
  CHECK(ostream.str() == "2/3");
};