/* This is free and unencumbered software released into the public domain. */

#include <know.hpp> // for know::*

#include <cstdlib>  // for EXIT_SUCCESS
#include <iostream> // for std::cout

int main(void) {
  know::thing jhacker;
  jhacker.names = {"J. Random Hacker"};

  std::cout << "Hello, " << jhacker.names[0] << "!\n";

  return EXIT_SUCCESS;
}
