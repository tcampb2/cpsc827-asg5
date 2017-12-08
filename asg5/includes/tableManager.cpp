#include <map>
#include <algorithm>
#include "tableManager.h"
#include "literal.h"

TableManager::~TableManager() {
  for (std::vector<SymbolTable*>::const_iterator it = tablePool.begin(); it != tablePool.end(); it++) {
    delete *it;
  }
}

TableManager& TableManager::getInstance() {
  static TableManager instance;
  return instance;
}

const Literal* TableManager::getValue(const std::string& name) const {
  return tableStack.top()->getValue(name);
}

void TableManager::setValue(const std::string& name, const Literal* val) { 
  tableStack.top()->setValue(name, val);
}

const Node* TableManager::getFunction(const std::string& name) const {
  return tableStack.top()->getFunction(name);
}

void TableManager::setFunction(const std::string& name, const Node* val) { 
  tableStack.top()->setFunction(name, val);
}

void TableManager::newScope(){
  SymbolTable * newTable = new SymbolTable(tableStack.top());
  tablePool.push_back(newTable);
  tableStack.push(newTable);
}

void TableManager::newScope(SymbolTable * oldTable){
  SymbolTable * newTable = new SymbolTable(*oldTable);
  tableStack.push(newTable);
}

SymbolTable * TableManager::getScope(){
  return tableStack.top();
}

void TableManager::endScope(){
  tableStack.pop();
}

void TableManager::endScopeImpl(){
  SymbolTable * temp = tableStack.top();
  tableStack.pop();
  delete temp;
}

