#ifndef SYMBOLTABLE__H
#define SYMBOLTABLE__H

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include "node.h"

class Literal;

class SymbolTable {
public:
  SymbolTable(const SymbolTable * p) : table(), functions(), parent(p) {}
  SymbolTable(const SymbolTable& old) : table(old.table), functions(old.functions), parent(old.parent) {}
  void  setValue(const std::string& name, const Literal* val);
  const Literal* getValue(const std::string& name) const;
  void  setFunction(const std::string& name, const Node* val);
  const Node* getFunction(const std::string& name) const;
private:
  std::map<std::string, const Literal*> table;
  std::map<std::string, const Node*> functions;
  const SymbolTable * parent;
  SymbolTable& operator=(const SymbolTable&) = delete;
};

#endif
