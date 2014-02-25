//
// Operand.cpp for operand in /home/debas_e/Project/abstract_VM
//
// Made by Etienne
// Login   <debas_e@epitech.net>
//
// Started on  Sat Feb 22 16:48:07 2014 Etienne
// Last update Tue Feb 25 23:06:29 2014 Etienne
//

#include <sys/types.h>
#include <limits>
#include <cmath>
#include <limits.h>
#include "Operand.hpp"
#include "Exception.hpp"

template<typename Type>
Operand<Type>::Operand(eOperandType enum_type, Type value) {
  std::stringstream	ss;

  _enum_type = enum_type;
  _value = value;
  ss << value;
  ss >> _str;
  factory = new OperandFactory();
}

template<>
Operand<int8_t>::Operand(eOperandType enum_type, int8_t value) {
  std::stringstream	ss;

  _enum_type = enum_type;
  _value = value;
  ss << static_cast<int16_t>(_value);
  ss >> _str;
  factory = new OperandFactory();
}

template<typename Type>
int		Operand<Type>::getPrecision() const {
  return static_cast<int>(_enum_type);
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
  Type          rhs_value = Operand<Type>::stringToValue(rhs.toString());
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
  Type          rhs_value = Operand<Type>::stringToValue(rhs.toString());
  Type          res = this->_value * rhs_value;
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
  Type          rhs_value = Operand<Type>::stringToValue(rhs.toString());
  if (rhs_value == 0.0) {
    throw DivZeroException();
  }
  Type          res = this->_value / rhs_value;
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
std::string		Operand<Type>::valueToString(Type value) {
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
Type		Operand<Type>::stringToValue(std::string value) {
  std::stringstream	ss;
  Type			ret;

  ss << value;
  ss >> ret;
  return (ret);
}

template<>
int8_t		Operand<int8_t>::stringToValue(std::string value) {
  std::stringstream	ss;
  int16_t		ret;

  ss << value;
  ss >> ret;
  return (static_cast<int8_t>(ret));
}

template class Operand<int8_t>;
template class Operand<int16_t>;
template class Operand<int32_t>;
template class Operand<float>;
template class Operand<double>;
