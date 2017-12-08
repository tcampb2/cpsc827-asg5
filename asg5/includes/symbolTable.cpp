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

void SymbolTable::endScope() {
  for (std::map<std::string, const Literal*>::const_iterator it = table.begin(); it != table.end(); it++) {
    if(it->second != nullptr){
      //delete it->second;
      table[it->first] = nullptr;
    }
  }
}

