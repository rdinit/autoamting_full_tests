#include <dynarray/dynarray.hpp>
#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("check") {
  DynArray da(4);
  //sstd::cout << da.size() << std::endl;
  CHECK(da.size() == 4);

};