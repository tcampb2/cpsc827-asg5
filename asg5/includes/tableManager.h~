#ifndef TABLEMANAGER__H
#define TABLEMANAGER__H

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <stack>
#include "symbolTable.h"

class Literal;

class TableManager {
public:
  ~TableManager();
  static   TableManager& getInstance();
  void     setValue(const std::string& name, const Literal* val);
  const    Literal* getValue(const std::string& name) const;
  void     startScope();
  void	   endScope();
private:
  std::map<std::string, const Literal*> table;
  SymbolTable * global;
  std::vector<SymbolTable *> tables;
  TableManager() : table(), global(new SymbolTable()), tables() {}
  TableManager(const TableManager&) = delete;
  TableManager& operator=(const TableManager&) = delete;
};

#endif
