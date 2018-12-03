#pragma once
#include "Person.h"

class PersonAddressBuilder;
class PersonJobBuilder;

class PersonBuilderBase
{
protected:
  Person& person;
  explicit PersonBuilderBase(Person& person)
    : person{ person }
  {
  }
public:
  operator Person() const
  {
    return std::move(person);
  }

  // builder facets

  PersonAddressBuilder lives() const;
  PersonJobBuilder works() const;
};

class PersonBuilder : public PersonBuilderBase
{
  Person p;
  // If we only have Person p, with no PersonBuilderBase, we would replication over and over 
  // again the class Person. We cannot innerit from Person either. We can use a base class which
  // has a reference to it
public:
  PersonBuilder(): PersonBuilderBase{p}
  {
  }

};