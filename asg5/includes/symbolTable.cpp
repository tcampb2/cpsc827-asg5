#include <map>
#include <algorithm>
#include "symbolTable.h"
#include "literal.h"

const Literal* SymbolTable::getValue(const std::string& name) const {
  std::map<std::string, const Literal*>::const_iterator it = 
    table.find(name);
  if ( it == table.end() ){
	if(parent != nullptr){
		return parent->getValue(name);
	}
	else{
		return nullptr;
	}
  }
  return it->second;
}

void SymbolTable::setValue(const std::string& name, const Literal* val) { 
  table[name] = val;
}

const Node* SymbolTable::getFunction(const std::string& name) const {
  std::map<std::string, const Node*>::const_iterator it = 
    functions.find(name);
  if ( it == functions.end() ){
	if(parent != nullptr){
		return parent->getFunction(name);
	}
	else{
		return nullptr;
	}
  }
  return it->second;
}

void SymbolTable::setFunction(const std::string& name, const Node* val) {
  functions[name] = val;
}
