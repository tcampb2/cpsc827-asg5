#pragma once

//  Declarations for a calculator that builds an AST
//  and a graphical representation of the AST.
//  by Brian Malloy

#include <iostream>
#include <string>
#include <map>
#include <deque>
#include "literal.h"
#include "symbolTable.h"
#include "tableManager.h"

extern void yyerror(const char*);
extern void yyerror(const char*, const char);

class IdentNode : public Node {
public:
  IdentNode(const std::string id) : Node(), ident(id) { } 
  virtual ~IdentNode() {}
  const std::string getIdent() const { return ident; }
  virtual const Literal* eval() const;
private:
  std::string ident;
};

class UnaryNode : public Node {
public:
  UnaryNode(Node* n) : Node(), node(n) {}
  virtual const Literal* eval() const = 0;
  UnaryNode(const UnaryNode&) = delete;
  UnaryNode& operator=(const UnaryNode&) = delete;
protected:
  Node *node;
};

class BinaryNode : public Node {
public:
  BinaryNode(Node* l, Node* r) : Node(), left(l), right(r) {}
  virtual const Literal* eval() const = 0;
  BinaryNode(const BinaryNode&) = delete;
  BinaryNode& operator=(const BinaryNode&) = delete;
protected:
  Node *left;
  Node *right;
};

class AsgBinaryNode : public BinaryNode {
public:
  AsgBinaryNode(Node* left, Node* right);
  virtual const Literal* eval() const;
};

class AddBinaryNode : public BinaryNode {
public:
  AddBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

class SubBinaryNode : public BinaryNode {
public:
  SubBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

class MulBinaryNode : public BinaryNode {
public:
  MulBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

class DivBinaryNode : public BinaryNode {
public:
  DivBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

class PowBinaryNode : public BinaryNode {
public:
  PowBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

class FDivBinaryNode : public BinaryNode {
public:
  FDivBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

class ModBinaryNode : public BinaryNode {
public:
  ModBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

class GtBinaryNode : public BinaryNode {
public:
  GtBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

class LtBinaryNode : public BinaryNode {
public:
  LtBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

class GtEqBinaryNode : public BinaryNode {
public:
  GtEqBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

class LtEqBinaryNode : public BinaryNode {
public:
  LtEqBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

class EqEqBinaryNode : public BinaryNode {
public:
  EqEqBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

class NEqBinaryNode : public BinaryNode {
public:
  NEqBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

class MinUnaryNode : public UnaryNode {
public:
  MinUnaryNode(Node* node) : UnaryNode(node) { }
  virtual const Literal* eval() const;
};

class PrintUnaryNode : public UnaryNode {
public:
  PrintUnaryNode(Node* node) : UnaryNode(node) { }
  virtual const Literal* eval() const;
};

class ReturnUnaryNode : public UnaryNode {
public:
  ReturnUnaryNode(Node* node) : UnaryNode(node) { }
  virtual const Literal* eval() const;
};

class BoolCheckUnaryNode : public UnaryNode {
public:
  BoolCheckUnaryNode(Node* node) : UnaryNode(node) { }
  virtual const Literal* eval() const;
};

class SuiteNode : public Node {
public:
  SuiteNode() : Node(), nodes() {}
  void add(Node* n) { nodes.push_back(n); }
  virtual const Literal* eval() const;
  SuiteNode(const SuiteNode&) = delete;
  SuiteNode& operator=(const SuiteNode&) = delete;
protected:
  std::vector<Node *> nodes;
};

class FunctionNode : public Node {
public:
  FunctionNode(const std::string id, Node * suiteNode, SymbolTable* t) : 
	Node(), name(id), 
	suite(suiteNode), table(t) 
	{ }
  virtual const Literal* eval() const;
  FunctionNode(const FunctionNode&) = delete;
  FunctionNode& operator=(const FunctionNode&) = delete;
protected:
  std::string name;
  Node * suite;
  SymbolTable* table;
};

class CallNode : public Node {
public:
  CallNode(const std::string id) : Node(), ident(id) { } 
  virtual ~CallNode() {}
  const std::string getIdent() const { return ident; }
  virtual const Literal* eval() const;
private:
  std::string ident;
};

class IfNode : public Node {
public:
  IfNode() : Node(), testNodes(), suiteNodes(), elseNode() { } 
  void addTest(Node* n) { testNodes.push_back(n); }
  void firstTest(Node* n) { testNodes.push_front(n); }
  void addSuite(Node* n) { suiteNodes.push_back(n); }
  void firstSuite(Node* n) { suiteNodes.push_front(n); }
  void addElse(Node* n) { elseNode = n; }
  virtual const Literal* eval() const;
  IfNode(const IfNode&) = delete;
  IfNode& operator=(const IfNode&) = delete;
private:
  std::deque<Node *> testNodes;
  std::deque<Node *> suiteNodes;
  Node* elseNode;
};
