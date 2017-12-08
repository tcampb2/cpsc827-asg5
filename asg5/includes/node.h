#pragma once
#include <iostream>
#include <typeinfo>

class Literal;

class Node {
public:
  Node() {}
  virtual ~Node() {}
  std::string name() const { return typeid(*this).name(); }
  virtual const Literal* eval() const = 0;
  virtual void print() const { 
    std::cout << "NODE" << std::endl; 
  }
};

