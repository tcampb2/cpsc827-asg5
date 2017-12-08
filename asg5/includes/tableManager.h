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
  void     setFunction(const std::string& name, const Node* val);
  const    Node* getFunction(const std::string& name) const;
  void     newScope();
  void     newScope(SymbolTable* oldTable);
  SymbolTable * getScope();
  void	   endScope();
  void	   endScopeImpl();
private:
  std::stack<SymbolTable *> tableStack;
  std::vector<SymbolTable *> tablePool;
  SymbolTable * global;
  TableManager() : tableStack(), tablePool(), 
	global(new SymbolTable(nullptr)) 
	{ tableStack.push(global); tablePool.push_back(global); }
  TableManager(const TableManager&) = delete;
  TableManager& operator=(const TableManager&) = delete;
};

#endif
