#ifndef SYMBOLTABLE__H
#define SYMBOLTABLE__H

#include <iostream>
#include <string>
#include <map>
#include <algorithm>

class Literal;

class SymbolTable {
public:
  SymbolTable() : table() {}
  ~SymbolTable();
  void  setValue(const std::string& name, const Literal* val);
  const Literal* getValue(const std::string& name) const;
  bool hasValue(const std::string& name) const;
  void add(const Node* node) { nodes.push_back(node); }
private:
  std::map<std::string, const Literal*> table;
};

#endif
