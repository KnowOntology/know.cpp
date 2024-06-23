/* This is free and unencumbered software released into the public domain. */

#pragma once

#include <cstdint> // for std::uint64_t
#include <ctime>   // for std::time_t
#include <memory>  // for std::shared_ptr
#include <string>  // for std::string
#include <vector>  // for std::vector

#include "place.hpp"
#include "thing.hpp"

namespace know {
  class event;
  class place;
  class thing;
}

class know::event {
  using string = ::std::string;
  template<typename T> using shared_ptr = ::std::shared_ptr<T>;
  template<typename T> using vector = ::std::vector<T>;

public:
  std::time_t end;
  shared_ptr<know::place> place;
  std::time_t start;

  inline virtual ~event() = default;

  inline virtual shared_ptr<event> clone() const {
    auto clone = std::make_shared<event>();
    clone->end = this->end;
    clone->place = this->place;
    clone->start = this->start;
    return clone;
  }
};
