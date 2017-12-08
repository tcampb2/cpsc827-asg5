#include "node.h"
#include "poolOfNodes.h"
#include <cmath>

class Literal : public Node {
public:
  virtual ~Literal() {}

  virtual bool getBool() const =0;

  virtual bool operator>(const Literal&) const =0;
  virtual bool opGt(float) const =0;
  virtual bool opGt(int) const =0;

  virtual bool operator<(const Literal&) const =0;
  virtual bool opLt(float) const =0;
  virtual bool opLt(int) const =0;

  virtual bool operator>=(const Literal&) const =0;
  virtual bool opGtEq(float) const =0;
  virtual bool opGtEq(int) const =0;

  virtual bool operator<=(const Literal&) const =0;
  virtual bool opLtEq(float) const =0;
  virtual bool opLtEq(int) const =0;

  virtual bool operator==(const Literal&) const =0;
  virtual bool opEqEq(float) const =0;
  virtual bool opEqEq(int) const =0;

  virtual bool operator!=(const Literal&) const =0;
  virtual bool opNEq(float) const =0;
  virtual bool opNEq(int) const =0;

  virtual const Literal* operator+(const Literal&) const =0;
  virtual const Literal* opPlus(float) const =0;
  virtual const Literal* opPlus(int) const =0;

  virtual const Literal* operator*(const Literal&) const =0;
  virtual const Literal* opMult(float) const =0;
  virtual const Literal* opMult(int) const =0;

  virtual const Literal* operator-(const Literal&) const =0;
  virtual const Literal* opSubt(float) const =0;
  virtual const Literal* opSubt(int) const =0;

  virtual const Literal* operator/(const Literal&) const =0;
  virtual const Literal* opDiv(float) const =0;
  virtual const Literal* opDiv(int) const =0;
  
  virtual const Literal* powFunc(const Literal&) const =0;
  virtual const Literal* opPow(float) const =0;
  virtual const Literal* opPow(int) const =0;

  virtual const Literal* divFloorFunc(const Literal&) const =0;
  virtual const Literal* opFloorDiv(float) const =0;
  virtual const Literal* opFloorDiv(int) const =0;

  virtual const Literal* operator%(const Literal&) const =0;
  virtual const Literal* opMod(float) const =0;
  virtual const Literal* opMod(int) const =0;

  virtual const Literal* negate() const =0;

  virtual const Literal* eval() const = 0;
  virtual void print() const { 
    std::cout << "No Way" << std::endl; 
  }
};

class FloatLiteral: public Literal {
public:
  FloatLiteral(float _val): val(_val) {}

  virtual bool getBool() const { 
    if(val == 0){
	return false;
    }
    else{
	return true;
    }
  }

  virtual bool operator>(const Literal& rhs) const{
    return rhs.opGt(val);
  }
  virtual bool opGt(float lhs) const  {
    return lhs > val;
  }
  virtual bool opGt(int lhs) const  {
    return lhs > val;
  }

  virtual bool operator<(const Literal& rhs) const{
    return rhs.opLt(val);
  }
  virtual bool opLt(float lhs) const  {
    return lhs < val;
  }
  virtual bool opLt(int lhs) const  {
    return lhs < val;
  }

  virtual bool operator>=(const Literal& rhs) const{
    return rhs.opGtEq(val);
  }
  virtual bool opGtEq(float lhs) const  {
    return lhs >= val;
  }
  virtual bool opGtEq(int lhs) const  {
    return lhs >= val;
  }

  virtual bool operator<=(const Literal& rhs) const{
    return rhs.opLtEq(val);
  }
  virtual bool opLtEq(float lhs) const  {
    return lhs <= val;
  }
  virtual bool opLtEq(int lhs) const  {
    return lhs <= val;
  }

  virtual bool operator==(const Literal& rhs) const{
    return rhs.opEqEq(val);
  }
  virtual bool opEqEq(float lhs) const  {
    return lhs == val;
  }
  virtual bool opEqEq(int lhs) const  {
    return lhs == val;
  }

  virtual bool operator!=(const Literal& rhs) const{
    return rhs.opNEq(val);
  }
  virtual bool opNEq(float lhs) const  {
    return lhs != val;
  }
  virtual bool opNEq(int lhs) const  {
    return lhs != val;
  }

  virtual const Literal* operator+(const Literal& rhs) const  {
    return rhs.opPlus(val);
  }
  virtual const Literal* opPlus(float lhs) const  {
    const Literal* node = new FloatLiteral(lhs + val);
    PoolOfNodes::getInstance().add(node);
    return node; 
  }
  virtual const Literal* opPlus(int lhs) const  {
    const Literal* node = new FloatLiteral(lhs + val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator-(const Literal& rhs) const  {
    return rhs.opSubt(val);
  }
  virtual const Literal* opSubt(float lhs) const  {
    const Literal* node = new FloatLiteral(lhs - val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opSubt(int lhs) const  {
    const Literal* node = new FloatLiteral(lhs - val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator*(const Literal& rhs) const  {
    return rhs.opMult(val);
  }
  virtual const Literal* opMult(float lhs) const  {
    const Literal* node = new FloatLiteral(lhs * val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opMult(int lhs) const  {
    const Literal* node = new FloatLiteral(static_cast<float>(lhs) * val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator/(const Literal& rhs) const  {
    return rhs.opDiv(val);
  }
  virtual const Literal* opDiv(float lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new FloatLiteral(lhs / val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opDiv(int lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new FloatLiteral(lhs / val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  
  virtual const Literal* powFunc(const Literal& rhs) const  {
    return rhs.opPow(val);
  }
  virtual const Literal* opPow(float lhs) const  {
    const Literal* node = new FloatLiteral(std::pow(lhs, val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opPow(int lhs) const  {
    const Literal* node = new FloatLiteral(std::pow(static_cast<float>(lhs), val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  
  virtual const Literal* divFloorFunc(const Literal& rhs) const  {
    return rhs.opFloorDiv(val);
  }
  virtual const Literal* opFloorDiv(float lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new FloatLiteral(std::floor(lhs / val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opFloorDiv(int lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new FloatLiteral(std::floor(lhs / val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  
  virtual const Literal* operator%(const Literal& rhs) const  {
    return rhs.opMod(val);
  }
  virtual const Literal* opMod(float lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node;
    if(val < 0){
	if(lhs < 0){
		node = new FloatLiteral(std::fmod(lhs, val));
	}
	else{
		node = new FloatLiteral(std::fmod(lhs, val) + val);
	}
    }
    else{
	if(lhs < 0){
		node = new FloatLiteral(std::fmod(lhs, val) + val);
	}
	else{
		node = new FloatLiteral(std::fmod(lhs, val));
	}
    }
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opMod(int lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node;
    if(val < 0){
	if(lhs < 0){
		node = new FloatLiteral(std::fmod(static_cast<float>(lhs), val));
	}
	else{
		node = new FloatLiteral(std::fmod(static_cast<float>(lhs), val) + val);
	}
    }
    else{
	if(lhs < 0){
		node = new FloatLiteral(std::fmod(static_cast<float>(lhs), val) + val);
	}
	else{
		node = new FloatLiteral(std::fmod(static_cast<float>(lhs), val));
	}
    }
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  
  virtual const Literal* negate() const {
  	const Literal* node = new FloatLiteral(-val);
  	PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* eval() const { return this; }
  virtual void print() const {
    std::cout << "FLOAT: " << val << std::endl;
  }
private:
  float val;
};

class IntLiteral: public Literal {
public:
  IntLiteral(int _val): val(_val) {}

  virtual bool getBool() const { 
    if(val == 0){
	return false;
    }
    else{
	return true;
    }
  }

  virtual bool operator>(const Literal& rhs) const{
    return rhs.opGt(val);
  }
  virtual bool opGt(float lhs) const  {
    return lhs > val;
  }
  virtual bool opGt(int lhs) const  {
    return lhs > val;
  }

  virtual bool operator<(const Literal& rhs) const{
    return rhs.opLt(val);
  }
  virtual bool opLt(float lhs) const  {
    return lhs < val;
  }
  virtual bool opLt(int lhs) const  {
    return lhs < val;
  }

  virtual bool operator>=(const Literal& rhs) const{
    return rhs.opGtEq(val);
  }
  virtual bool opGtEq(float lhs) const  {
    return lhs >= val;
  }
  virtual bool opGtEq(int lhs) const  {
    return lhs >= val;
  }

  virtual bool operator<=(const Literal& rhs) const{
    return rhs.opLtEq(val);
  }
  virtual bool opLtEq(float lhs) const  {
    return lhs <= val;
  }
  virtual bool opLtEq(int lhs) const  {
    return lhs <= val;
  }

  virtual bool operator==(const Literal& rhs) const{
    return rhs.opEqEq(val);
  }
  virtual bool opEqEq(float lhs) const  {
    return lhs == val;
  }
  virtual bool opEqEq(int lhs) const  {
    return lhs == val;
  }

  virtual bool operator!=(const Literal& rhs) const{
    return rhs.opNEq(val);
  }
  virtual bool opNEq(float lhs) const  {
    return lhs != val;
  }
  virtual bool opNEq(int lhs) const  {
    return lhs != val;
  }

  virtual const Literal* operator+(const Literal& rhs) const  {
    return rhs.opPlus(val);
  }
  virtual const Literal* opPlus(float lhs) const  {
    const Literal* node = new FloatLiteral(static_cast<float>(val) + lhs);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opPlus(int lhs) const  {
    const Literal* node = new IntLiteral(lhs + val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator-(const Literal& rhs) const  {
    return rhs.opSubt(val);
  }
  virtual const Literal* opSubt(float lhs) const  {
    const Literal* node = new FloatLiteral(lhs - val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opSubt(int lhs) const  {
    const Literal* node = new IntLiteral(lhs - val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator*(const Literal& rhs) const  {
    return rhs.opMult(val);
  }
  virtual const Literal* opMult(float lhs) const  {
    const Literal* node = new FloatLiteral(lhs * val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opMult(int lhs) const  {
    const Literal* node = new IntLiteral(lhs * val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator/(const Literal& rhs) const  {
    return rhs.opDiv(val);
  }
  virtual const Literal* opDiv(float lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new FloatLiteral(lhs / val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opDiv(int lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node;
    if(((lhs % val) == 0) || (((lhs > 0) && (val > 0)) || ((lhs < 0) && (val < 0)))) {
      node = new IntLiteral(lhs / val);
    }
    else {
      node = new IntLiteral((lhs / val) - 1);
    }
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  
  virtual const Literal* powFunc(const Literal& rhs) const  {
    return rhs.opPow(val);
  }
  virtual const Literal* opPow(float lhs) const  {
    const Literal* node = new FloatLiteral(std::pow(lhs, static_cast<float>(val)));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opPow(int lhs) const  {
    const Literal* node = new IntLiteral(std::pow(lhs, val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  
  virtual const Literal* divFloorFunc(const Literal& rhs) const  {
    return rhs.opFloorDiv(val);
  }
  virtual const Literal* opFloorDiv(float lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new FloatLiteral(std::floor(lhs / val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opFloorDiv(int lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node;
    if(((lhs % val) == 0) || (((lhs > 0) && (val > 0)) || ((lhs < 0) && (val < 0)))) {
      node = new IntLiteral(lhs / val);
    }
    else {
      node = new IntLiteral((lhs / val) - 1);
    }
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator%(const Literal& rhs) const  {
    return rhs.opMod(val);
  }
  virtual const Literal* opMod(float lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node;
    if(val < 0){
	if(lhs < 0){
		node = new FloatLiteral(std::fmod(lhs, static_cast<float>(val)));
	}
	else{
		node = new FloatLiteral(std::fmod(lhs, static_cast<float>(val)) + val);
	}
    }
    else{
	if(lhs < 0){
		node = new FloatLiteral(std::fmod(lhs, static_cast<float>(val)) + val);
	}
	else{
		node = new FloatLiteral(std::fmod(lhs, static_cast<float>(val)));
	}
    }
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opMod(int lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node;
    if(val < 0){
	if(lhs < 0){
		node = new IntLiteral((lhs % val));
	}
	else{
		node = new IntLiteral((lhs % val) + val);
	}
    }
    else{
	if(lhs < 0){
		node = new IntLiteral((lhs % val) + val);
	}
	else{
		node = new IntLiteral(lhs % val);
	}
    }
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  
  virtual const Literal* negate() const {
    const Literal* node = new IntLiteral(-val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* eval() const { return this; }
  virtual void print() const { 
    std::cout << "INT: " << val << std::endl;
  }
protected:
  int val;
};

class BoolLiteral: public IntLiteral {
public:
  BoolLiteral(int _val): IntLiteral(_val) {}

  virtual bool getBool() const { 
    if(val == 0){
	return false;
    }
    else{
	return true;
    }
  }

  virtual const Literal* eval() const {
    return this; 
  }
  virtual void print() const {
    if(val == 0){
	std::cout << "False" << std::endl;
    }
    else{
	std::cout << "True" << std::endl;
    }
  }
};

class NoneLiteral: public Literal{
public:
  NoneLiteral() {}

  virtual bool getBool() const { return false; }

  virtual bool operator>(const Literal&) const{ return false; }
  virtual bool opGt(float) const  { return false; }
  virtual bool opGt(int) const  { return false; }

  virtual bool operator<(const Literal&) const{ return false; }
  virtual bool opLt(float) const  { return false; }
  virtual bool opLt(int) const  { return false; }

  virtual bool operator>=(const Literal& rhs) const{
	const NoneLiteral * none = dynamic_cast<const NoneLiteral *>(&rhs); 
	return !(!(none)); 
  }
  virtual bool opGtEq(float) const  { return false; }
  virtual bool opGtEq(int) const  { return false; }

  virtual bool operator<=(const Literal& rhs) const{
	const NoneLiteral * none = dynamic_cast<const NoneLiteral *>(&rhs); 
	return !(!(none)); 
  }
  virtual bool opLtEq(float) const  { return false; }
  virtual bool opLtEq(int) const  { return false; }

  virtual bool operator==(const Literal& rhs) const{
	const NoneLiteral * none = dynamic_cast<const NoneLiteral *>(&rhs); 
	return !(!(none)); 
  }
  virtual bool opEqEq(float) const  { return false; }
  virtual bool opEqEq(int) const  { return false; }

  virtual bool operator!=(const Literal& rhs) const{
	const NoneLiteral * none = dynamic_cast<const NoneLiteral *>(&rhs); 
	return !(none); 
  }
  virtual bool opNEq(float) const  { return true; }
  virtual bool opNEq(int) const  { return true; }

  virtual const Literal* operator+(const Literal&) const {return this;}
  virtual const Literal* opPlus(float) const {return this;}
  virtual const Literal* opPlus(int) const {return this;}

  virtual const Literal* operator*(const Literal&) const {return this;}
  virtual const Literal* opMult(float) const {return this;}
  virtual const Literal* opMult(int) const {return this;}

  virtual const Literal* operator-(const Literal&) const {return this;}
  virtual const Literal* opSubt(float) const {return this;}
  virtual const Literal* opSubt(int) const {return this;}

  virtual const Literal* operator/(const Literal&) const {return this;}
  virtual const Literal* opDiv(float) const {return this;}
  virtual const Literal* opDiv(int) const {return this;}
  
  virtual const Literal* powFunc(const Literal&) const {return this;}
  virtual const Literal* opPow(float) const {return this;}
  virtual const Literal* opPow(int) const {return this;}

  virtual const Literal* divFloorFunc(const Literal&) const {return this;}
  virtual const Literal* opFloorDiv(float) const {return this;}
  virtual const Literal* opFloorDiv(int) const {return this;}

  virtual const Literal* operator%(const Literal&) const {return this;}
  virtual const Literal* opMod(float) const {return this;}
  virtual const Literal* opMod(int) const {return this;}
  
  virtual const Literal* negate() const {return this;}

  virtual const Literal* eval() const { return this; }
  virtual void print() const { 
    std::cout << "None" << std::endl;
  }
};

