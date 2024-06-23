/* This is free and unencumbered software released into the public domain. */

#pragma once

#include <cstdint> // for std::uint64_t
#include <ctime>   // for std::time_t
#include <memory>  // for std::shared_ptr
#include <string>  // for std::string
#include <vector>  // for std::vector

#include "person.hpp"
#include "thing.hpp"

namespace know {
  class group;
  class person;
  class thing;
}

class know::group {
  using string = ::std::string;
  template<typename T> using shared_ptr = ::std::shared_ptr<T>;
  template<typename T> using vector = ::std::vector<T>;

public:
  vector<string> logos;
  vector<shared_ptr<know::person>> members;

  inline virtual ~group() = default;

  inline virtual shared_ptr<group> clone() const {
    auto clone = std::make_shared<group>();
    clone->logos = this->logos;
    clone->members = this->members;
    return clone;
  }
};
