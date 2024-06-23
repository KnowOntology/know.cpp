/* This is free and unencumbered software released into the public domain. */

#pragma once

#include <cstdint> // for std::uint64_t
#include <ctime>   // for std::time_t
#include <memory>  // for std::shared_ptr
#include <string>  // for std::string
#include <vector>  // for std::vector

#include "thing.hpp"

namespace know {
  class link;
  class thing;
}

class know::link {
  using string = ::std::string;
  template<typename T> using shared_ptr = ::std::shared_ptr<T>;
  template<typename T> using vector = ::std::vector<T>;

public:
  string url;

  inline virtual ~link() = default;

  inline virtual shared_ptr<link> clone() const {
    auto clone = std::make_shared<link>();
    clone->url = this->url;
    return clone;
  }
};
