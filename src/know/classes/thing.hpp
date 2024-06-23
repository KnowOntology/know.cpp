/* This is free and unencumbered software released into the public domain. */

#pragma once

#include <cstdint> // for std::uint64_t
#include <ctime>   // for std::time_t
#include <memory>  // for std::shared_ptr
#include <string>  // for std::string
#include <vector>  // for std::vector

#include "link.hpp"

namespace know {
  class thing;
  class link;
}

class know::thing {
  using string = ::std::string;
  template<typename T> using shared_ptr = ::std::shared_ptr<T>;
  template<typename T> using vector = ::std::vector<T>;

public:
  string glyph;
  vector<string> ids;
  vector<shared_ptr<know::link>> links;
  vector<string> names;
  vector<string> notes;
  vector<string> photos;

  inline virtual ~thing() = default;

  inline virtual shared_ptr<thing> clone() const {
    auto clone = std::make_shared<thing>();
    clone->glyph = this->glyph;
    clone->ids = this->ids;
    clone->links = this->links;
    clone->names = this->names;
    clone->notes = this->notes;
    clone->photos = this->photos;
    return clone;
  }
};
