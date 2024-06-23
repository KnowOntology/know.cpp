/* This is free and unencumbered software released into the public domain. */

#pragma once

#include <cstdint> // for std::uint64_t
#include <ctime>   // for std::time_t
#include <memory>  // for std::shared_ptr
#include <string>  // for std::string
#include <vector>  // for std::vector

#include "birth.hpp"
#include "death.hpp"
#include "group.hpp"
#include "thing.hpp"

namespace know {
  class person;
  class birth;
  class death;
  class group;
  class thing;
}

class know::person {
  using string = ::std::string;
  template<typename T> using shared_ptr = ::std::shared_ptr<T>;
  template<typename T> using vector = ::std::vector<T>;

public:
  vector<string> accounts;
  std::uint64_t age;
  vector<string> aliases;
  vector<shared_ptr<know::person>> ancestors;
  vector<shared_ptr<know::person>> aunts;
  shared_ptr<know::birth> birth;
  vector<shared_ptr<know::person>> brothers;
  vector<shared_ptr<know::person>> children;
  vector<shared_ptr<know::person>> colleagues;
  vector<shared_ptr<know::person>> cousins;
  vector<shared_ptr<know::person>> daughters;
  shared_ptr<know::death> death;
  vector<shared_ptr<know::person>> descendants;
  vector<string> emails;
  shared_ptr<know::person> father;
  vector<shared_ptr<know::person>> grandchildren;
  vector<shared_ptr<know::person>> granddaughters;
  vector<shared_ptr<know::person>> grandfathers;
  vector<shared_ptr<know::person>> grandmothers;
  vector<shared_ptr<know::person>> grandparents;
  vector<shared_ptr<know::person>> grandsons;
  vector<string> honorifics;
  vector<shared_ptr<know::person>> husbands;
  vector<shared_ptr<know::person>> knows;
  vector<shared_ptr<know::group>> member_ofs;
  shared_ptr<know::person> mother;
  vector<string> nationalities;
  vector<shared_ptr<know::person>> nephews;
  vector<shared_ptr<know::person>> niblings;
  vector<shared_ptr<know::person>> nieces;
  vector<shared_ptr<know::person>> parents;
  vector<shared_ptr<know::person>> partners;
  vector<string> phones;
  vector<shared_ptr<know::person>> piblings;
  vector<shared_ptr<know::person>> relatives;
  string sex;
  vector<shared_ptr<know::person>> siblings;
  vector<shared_ptr<know::person>> sisters;
  vector<shared_ptr<know::person>> sons;
  vector<string> speaks;
  vector<shared_ptr<know::person>> spouses;
  vector<shared_ptr<know::person>> stepchildren;
  vector<shared_ptr<know::person>> stepdaughters;
  vector<shared_ptr<know::person>> stepfathers;
  vector<shared_ptr<know::person>> stepmothers;
  vector<shared_ptr<know::person>> stepparents;
  vector<shared_ptr<know::person>> stepsons;
  vector<shared_ptr<know::person>> uncles;
  vector<shared_ptr<know::person>> wives;

  inline virtual ~person() = default;

  inline virtual shared_ptr<person> clone() const {
    auto clone = std::make_shared<person>();
    clone->accounts = this->accounts;
    clone->age = this->age;
    clone->aliases = this->aliases;
    clone->ancestors = this->ancestors;
    clone->aunts = this->aunts;
    clone->birth = this->birth;
    clone->brothers = this->brothers;
    clone->children = this->children;
    clone->colleagues = this->colleagues;
    clone->cousins = this->cousins;
    clone->daughters = this->daughters;
    clone->death = this->death;
    clone->descendants = this->descendants;
    clone->emails = this->emails;
    clone->father = this->father;
    clone->grandchildren = this->grandchildren;
    clone->granddaughters = this->granddaughters;
    clone->grandfathers = this->grandfathers;
    clone->grandmothers = this->grandmothers;
    clone->grandparents = this->grandparents;
    clone->grandsons = this->grandsons;
    clone->honorifics = this->honorifics;
    clone->husbands = this->husbands;
    clone->knows = this->knows;
    clone->member_ofs = this->member_ofs;
    clone->mother = this->mother;
    clone->nationalities = this->nationalities;
    clone->nephews = this->nephews;
    clone->niblings = this->niblings;
    clone->nieces = this->nieces;
    clone->parents = this->parents;
    clone->partners = this->partners;
    clone->phones = this->phones;
    clone->piblings = this->piblings;
    clone->relatives = this->relatives;
    clone->sex = this->sex;
    clone->siblings = this->siblings;
    clone->sisters = this->sisters;
    clone->sons = this->sons;
    clone->speaks = this->speaks;
    clone->spouses = this->spouses;
    clone->stepchildren = this->stepchildren;
    clone->stepdaughters = this->stepdaughters;
    clone->stepfathers = this->stepfathers;
    clone->stepmothers = this->stepmothers;
    clone->stepparents = this->stepparents;
    clone->stepsons = this->stepsons;
    clone->uncles = this->uncles;
    clone->wives = this->wives;
    return clone;
  }
};
