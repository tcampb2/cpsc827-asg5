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

SymbolTable * TableManager::newScope(SymbolTable * table){
	if(table == nullptr){
		SymbolTable * newTable = new SymbolTable(global);
		tablePool.push_back(newTable);
		return newTable;
	}
	else{
		SymbolTable * newTable = new SymbolTable(table);
		tablePool.push_back(newTable);
		return newTable;
	}
}

void TableManager::startScope(SymbolTable* table){
  tableStack.push(table);
}

void TableManager::endScope(){
  tableStack.top()->endScope();
  tableStack.pop();
}

