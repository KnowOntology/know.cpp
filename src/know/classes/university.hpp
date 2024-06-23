/* This is free and unencumbered software released into the public domain. */

#pragma once

#include <cstdint> // for std::uint64_t
#include <ctime>   // for std::time_t
#include <memory>  // for std::shared_ptr
#include <string>  // for std::string
#include <vector>  // for std::vector

#include "organization.hpp"

namespace know {
  class university;
  class organization;
}

class know::university {
  using string = ::std::string;
  template<typename T> using shared_ptr = ::std::shared_ptr<T>;
  template<typename T> using vector = ::std::vector<T>;

public:
  inline virtual ~university() = default;

  inline virtual shared_ptr<university> clone() const {
    auto clone = std::make_shared<university>();
    return clone;
  }
};
