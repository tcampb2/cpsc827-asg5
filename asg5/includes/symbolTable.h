#ifndef SYMBOLTABLE__H
#define SYMBOLTABLE__H

#include <iostream>
#include <string>
#include <map>
#include <algorithm>

class Literal;

class SymbolTable {
public:
  SymbolTable(const SymbolTable * p) : table(), parent(p) {}
  //~SymbolTable();
  void  setValue(const std::string& name, const Literal* val);
  const Literal* getValue(const std::string& name) const;
  //bool hasValue(const std::string& name) const;
  void endScope();
private:
  std::map<std::string, const Literal*> table;
  const SymbolTable * parent;
  SymbolTable(const SymbolTable&) = delete;
  SymbolTable& operator=(const SymbolTable&) = delete;
};

#endif
