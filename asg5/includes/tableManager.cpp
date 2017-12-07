#include <map>
#include <algorithm>
#include "tableManager.h"
#include "literal.h"

TableManager::~TableManager() {
  free(global);
}

TableManager& TableManager::getInstance() {
  static TableManager instance;
  return instance;
}

const Literal* TableManager::getValue(const std::string& name) const {
  int n = tables.size() - 1;
  while(n > 0){
	if(tables[n]->hasValue(name)){
		const Literal* answer = tables[n]->getValue(name);
		if(answer == nullptr) throw name+std::string(" not found");
		return answer;
  	}
  }
  const Literal* answer = global->getValue(name);
  if(answer == nullptr) throw name+std::string(" not found");
  return answer;
}

void TableManager::setValue(const std::string& name, const Literal* val) { 
  tables.back()->setValue(name, val);
}

void TableManager::startScope(){
  tables.emplace_back(new SymbolTable());
}

void TableManager::endScope(){
  free(tables.back());
  tables.pop_back();
}

