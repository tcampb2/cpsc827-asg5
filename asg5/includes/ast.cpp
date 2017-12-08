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

const Literal* GtBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  BoolLiteral* answer = new BoolLiteral((*x)>(*y));
  PoolOfNodes::getInstance().add(answer);
  return answer;
}

const Literal* LtBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  BoolLiteral* answer = new BoolLiteral((*x)<(*y));
  PoolOfNodes::getInstance().add(answer);
  return answer;
}

const Literal* GtEqBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  BoolLiteral* answer = new BoolLiteral((*x)>=(*y));
  PoolOfNodes::getInstance().add(answer);
  return answer;
}

const Literal* LtEqBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  BoolLiteral* answer = new BoolLiteral((*x)<=(*y));
  PoolOfNodes::getInstance().add(answer);
  return answer;
}

const Literal* EqEqBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  BoolLiteral* answer = new BoolLiteral((*x)==(*y));
  PoolOfNodes::getInstance().add(answer);
  return answer;
}

const Literal* NEqBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  BoolLiteral* answer = new BoolLiteral((*x)!=(*y));
  PoolOfNodes::getInstance().add(answer);
  return answer;
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

const Literal* ReturnUnaryNode::eval() const { 
  if (!node) {
    throw "error";
  }
  return node->eval();
}

const Literal* BoolCheckUnaryNode::eval() const { 
  if (!node) {
    throw "error";
  }
  return node->eval();
}

const Literal* SuiteNode::eval() const {
  for (std::vector<Node*>::const_iterator it = nodes.begin(); it != nodes.end(); it++) {
    FunctionNode * func = dynamic_cast<FunctionNode *>(*it);
    if(!func){
	ReturnUnaryNode * ret = dynamic_cast<ReturnUnaryNode *>(*it);
	if(!ret){
    		(*it)->eval();
	}
	else{
		return ret->eval();
	}
    }
  }
  const Literal* none = new NoneLiteral();
  PoolOfNodes::getInstance().add(none);
  return none;
}

const Literal* FunctionNode::eval() const {
  TableManager::getInstance().newScope(table);
  const Literal* returnValue = suite->eval();
  TableManager::getInstance().endScopeImpl();
  return returnValue;
}

const Literal* CallNode::eval() const {
  const Node* func = TableManager::getInstance().getFunction(ident);
  if(func == nullptr){
 	throw "function not found";
  }
  return func->eval();
}

const Literal* IfNode::eval() const {
  int i = 0;
  for (std::deque<Node*>::const_iterator it = testNodes.begin(); it != testNodes.end(); it++) {
  	if((*it)->eval()->getBool()){
		return suiteNodes[i]->eval();
	}
	i++;
  }
  if(elseNode != nullptr){
	return elseNode->eval();
  }
  const Literal* none = new NoneLiteral();
  PoolOfNodes::getInstance().add(none);
  return none;
}
