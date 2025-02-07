#include <iostream>
// #include <eigen3/Eigen/Dense>
// #include "input.hpp"
#include "test/input_test.hpp"


int main() {
  std::string system_file = "/home/kopfhanger/cpp_code/mbss/system.toml";
  mbss::test_input(system_file);

  return 0;
}