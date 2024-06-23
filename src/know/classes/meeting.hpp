/* This is free and unencumbered software released into the public domain. */

#pragma once

#include <cstdint> // for std::uint64_t
#include <ctime>   // for std::time_t
#include <memory>  // for std::shared_ptr
#include <string>  // for std::string
#include <vector>  // for std::vector

#include "event.hpp"

namespace know {
  class meeting;
  class event;
}

class know::meeting {
  using string = ::std::string;
  template<typename T> using shared_ptr = ::std::shared_ptr<T>;
  template<typename T> using vector = ::std::vector<T>;

public:
  inline virtual ~meeting() = default;

  inline virtual shared_ptr<meeting> clone() const {
    auto clone = std::make_shared<meeting>();
    return clone;
  }
};
