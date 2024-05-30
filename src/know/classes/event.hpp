/* This is free and unencumbered software released into the public domain. */

#pragma once

namespace know { class event; }

class know::event {
public:
  virtual ~event() = default;
};
