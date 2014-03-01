//
// Operand.cpp for operand in /home/debas_e/Project/abstract_VM
//
// Made by Etienne
// Login   <debas_e@epitech.net>
//
// Started on  Sat Feb 22 16:48:07 2014 Etienne
// Last update Sat Mar  1 01:05:51 2014 Etienne
//

#include <sys/types.h>
#include <limits>
#include <cmath>
#include <limits.h>
#include "Operand.hpp"
#include "Exception.hpp"

std::string	eraseUselessNumber(const std::string &s)
{
  size_t	pos = 0;
  int		inc = 0;
  std::string	ret = s;

  if ((pos = s.find(".")) != std::string::npos)
    {
      inc = ret.size();
      while (ret[--inc])
	if (ret[inc] != '0')
	  break;
      if (ret[inc] == '.')
	ret = ret.erase(inc, ret.size());
      else
	ret = ret.erase(inc + 1, ret.size());
      return (ret);
    }
  return (ret);
}

template<typename Type>
Operand<Type>::Operand(eOperandType enum_type, Type value) {
  std::stringstream	ss;

  _enum_type = enum_type;
  _value = value;
  _str = Operand<Type>::valueToString(value);
  factory = new OperandFactory();
}

template<typename Type>
int		Operand<Type>::getPrecision() const {
  return _enum_type;
}

template<typename Type>
eOperandType	Operand<Type>::getType() const
{
  return _enum_type;
}

template<typename Type>
IOperand	*Operand<Type>::operator+(const IOperand &rhs) const {
  if (getPrecision() < rhs.getPrecision()) {
    eOperandType	t = std::max(rhs.getType(), getType());
    IOperand		*tmp;
    IOperand		*res;

    tmp = factory->createOperand(t, toString());
    res = *tmp + rhs;
    delete tmp;
    return res;
  }
  Type		maxVal = std::numeric_limits<Type>::max();
  Type		minVal = std::numeric_limits<Type>::min();
  Type          rhs_value = Operand<Type>::stringToValue(rhs.toString());

  if ((rhs_value > 0) && (this->_value > maxVal - rhs_value)) {
    throw Overflow(_str + " + " + Operand<Type>::valueToString(rhs_value), 0);
  }
  if ((rhs_value < 0) && (this->_value < minVal - rhs_value)) {
    throw Underflow(_str + " + " + Operand<Type>::valueToString(rhs_value), 0);
  }
  Type          res = this->_value + rhs_value;
  return (factory->createOperand(getType(), Operand<Type>::valueToString(res)));
}

template<typename Type>
IOperand	*Operand<Type>::operator-(const IOperand &rhs) const {
  if (getPrecision() < rhs.getPrecision()) {
    eOperandType	t = std::max(rhs.getType(), getType());
    IOperand		*tmp;
    IOperand		*res;

    tmp = factory->createOperand(t, toString());
    res = *tmp - rhs;
    delete tmp;
    return res;
  }
  Type		maxVal = std::numeric_limits<Type>::max();
  Type		minVal = std::numeric_limits<Type>::min();
  Type          rhs_value = Operand<Type>::stringToValue(rhs.toString());

  if ((rhs_value < 0) && (this->_value > maxVal + rhs_value)) {
    throw Overflow(_str + " - " + Operand<Type>::valueToString(rhs_value), 0);
  }
  if ((rhs_value > 0) && (this->_value < minVal + rhs_value)) {
    throw Underflow(_str + " - " + Operand<Type>::valueToString(rhs_value), 0);
  }
  Type          res = this->_value - rhs_value;
  return (factory->createOperand(getType(), Operand<Type>::valueToString(res)));
}

template<typename Type>
IOperand	*Operand<Type>::operator*(const IOperand &rhs) const {
  if (getPrecision() < rhs.getPrecision()) {
    eOperandType	t = std::max(rhs.getType(), getType());
    IOperand		*tmp;
    IOperand		*res;

    tmp = factory->createOperand(t, toString());
    res = *tmp * rhs;
    delete tmp;
    return res;
  }
  bool		isNeg;
  Type          rhs_value = Operand<Type>::stringToValue(rhs.toString());
  if ((this->_value > 0 && rhs_value < 0) || (rhs_value > 0 && this->_value < 0))
    isNeg = true;
  else
    isNeg = false;
  Type          res = this->_value * rhs_value;
  if ((res / rhs_value) != this->_value)
    {
      if (isNeg == false)
	throw Overflow(_str + " * " + Operand<Type>::valueToString(rhs_value), 0);
      else
	throw Underflow(_str + " * " + Operand<Type>::valueToString(rhs_value), 0);
    }
  return (factory->createOperand(getType(), Operand<Type>::valueToString(res)));
}

template<typename Type>
IOperand	*Operand<Type>::operator/(const IOperand &rhs) const {
  if (getPrecision() < rhs.getPrecision()) {
    eOperandType	t = std::max(rhs.getType(), getType());
    IOperand		*tmp;
    IOperand		*res;

    tmp = factory->createOperand(t, toString());
    res = *tmp / rhs;
    delete tmp;
    return res;
  }
  bool		isNeg;
  Type          rhs_value = Operand<Type>::stringToValue(rhs.toString());
  if ((this->_value > 0 && rhs_value < 0) || (rhs_value > 0 && this->_value < 0))
    isNeg = true;
  else
    isNeg = false;
  Type		res = this->_value / rhs_value;
  IOperand	*reste = *this % rhs;
  if (((res * rhs_value) + Operand<Type>::stringToValue(reste->toString())) != this->_value)
    {
      if (isNeg == false)
	throw Overflow(_str + " / " + Operand<Type>::valueToString(rhs_value), 0);
      else
	throw Underflow(_str + " / " + Operand<Type>::valueToString(rhs_value), 0);
    }
  return (factory->createOperand(getType(), Operand<Type>::valueToString(res)));
}

template<typename Type>
IOperand	*Operand<Type>::operator%(const IOperand &rhs) const {
  if (getPrecision() < rhs.getPrecision()) {
    eOperandType	t = std::max(rhs.getType(), getType());
    IOperand		*tmp;
    IOperand		*res;

    tmp = factory->createOperand(t, toString());
    res = *tmp % rhs;
    delete tmp;
    return res;
  }
  Type          rhs_value = Operand<Type>::stringToValue(rhs.toString());
  if (rhs_value == 0.0) {
    throw ModZeroException();
  }
  std::string	res = Operand<Type>::valueToString(fmod(_value, rhs_value));
  return (factory->createOperand(getType(), res));
}

template<typename Type>
std::string const	&Operand<Type>::toString() const {
  return this->_str;
}

template<typename Type>
std::string		Operand<Type>::valueToString(const Type value) {
  std::stringstream	ss;
  std::string		ret;

  ss << value;
  ss >> ret;
  return (ret);
}

template<>
std::string		Operand<int8_t>::valueToString(int8_t value) {
  std::stringstream	ss;
  std::string		ret;

  ss << static_cast<int16_t>(value);
  ss >> ret;
  return (ret);
}

template<typename Type>
Type		Operand<Type>::stringToValue(const std::string &value) {
  std::stringstream	ss;
  Type			ret;
  std::string		str;
  std::string		cmp;

  ss << value;
  ss >> ret;
  cmp = eraseUselessNumber(value);
  str = Operand<Type>::valueToString(ret);
  str = eraseUselessNumber(str);
  // std::cout << str + " -- " + cmp << std::endl;
  if (str != cmp) {
    if (value[0] == '-')
      throw Underflow(value, 0);
    else
      throw Overflow(value, 0);
  }
  return (ret);
}

template<>
int8_t		Operand<int8_t>::stringToValue(const std::string &value) {
  std::stringstream	ss;
  int16_t		ret;
  std::string		str;

  ss << value;
  ss >> ret;
  str = Operand<int8_t>::valueToString(ret);
  if (str != value) {
    if (value[0] == '-')
      throw Underflow(value, 0);
    else
      throw Overflow(value, 0);
  }
  return (static_cast<int8_t>(ret));
}

template class Operand<int8_t>;
template class Operand<int16_t>;
template class Operand<int32_t>;
template class Operand<float>;
template class Operand<double>;
