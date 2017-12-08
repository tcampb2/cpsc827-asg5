#include <map>
#include <algorithm>
#include "tableManager.h"
#include "literal.h"

TableManager::~TableManager() {
  for (std::vector<SymbolTable*>::const_iterator it = tablePool.begin(); it != tablePool.end(); it++) {
    { std::cout << "delete symbol table" << std::endl; }
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

void TableManager::newScope(){
	SymbolTable * newTable = new SymbolTable(tableStack.top());
	tablePool.push_back(newTable);
	tableStack.push(newTable);
}

SymbolTable * TableManager::getScope(){
	return tableStack.top();
}

void TableManager::startScope(SymbolTable* table){
  tableStack.push(table);
}

void TableManager::endScope(){
  tableStack.top()->endScope();
  tableStack.pop();
}

