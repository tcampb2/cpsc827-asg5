#include <iostream>
#include <typeinfo>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include "ast.h"
#include "symbolTable.h"
#include "tableManager.h"

const Literal* IdentNode::eval() const { 
  const Literal* val = TableManager::getInstance().getValue(ident);
  if(val == nullptr){
 	throw "value not found";
  }
  else{
	/*std::cout << "Val 1" << std::endl;
	val->print();
	std::cout << "Val 2" << std::endl;*/
  }
  return val;
}

AsgBinaryNode::AsgBinaryNode(Node* left, Node* right) : 
  BinaryNode(left, right) { 
}

const Literal* AsgBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* res = right->eval();

  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  TableManager::getInstance().setValue(n, res);
  
  return res;
}

const Literal* AddBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return (*x).operator+(*y);
}

const Literal* SubBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x)-(*y));
}

const Literal* MulBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x)*(*y));
}

const Literal* DivBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x)/(*y));
}

const Literal* PowBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x).powFunc((*y)));
}

const Literal* FDivBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x).divFloorFunc((*y)));
}

const Literal* ModBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x)%(*y));
}

const Literal* MinUnaryNode::eval() const { 
  if (!node) {
    throw "error";
  }
  const Literal* x = node->eval();
  return ((*x).negate());
}

const Literal* PrintUnaryNode::eval() const { 
  if (!node) {
    throw "error";
  }
  const Literal* x = node->eval();
  x->print();
  return x;
}

const Literal* SuiteNode::eval() const {
  for (std::vector<Node*>::const_iterator it = nodes.begin(); it != nodes.end(); it++) {
    FunctionNode * func = dynamic_cast<FunctionNode *>(*it);
    if(!func){
    	(*it)->eval();
    }
  }
  return nullptr;
}

const Literal* FunctionNode::eval() const {
  TableManager::getInstance().newScope(table);
  suite->eval();
  TableManager::getInstance().endScopeImpl();
  return nullptr;
}

const Literal* CallNode::eval() const {
  const Node* func = TableManager::getInstance().getFunction(ident);
  if(func == nullptr){
 	throw "function not found";
  }
  return func->eval();
}
