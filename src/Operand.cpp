//
// Operand.cpp for operand in /home/debas_e/Project/abstract_VM
//
// Made by Etienne
// Login   <debas_e@epitech.net>
//
// Started on  Sat Feb 22 16:48:07 2014 Etienne
// Last update Sat Feb 22 19:19:21 2014 Etienne
//

#include <sys/types.h>
#include <cmath>
#include "Operand.hpp"

template<typename Type>
Operand<Type>::Operand(eOperandType enum_type, Type value) {
  std::stringstream    ss;

  _enum_type = enum_type;
  _value = value;
  ss << value;
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
  Type          rhs_value = Operand::stringToValue(rhs.toString());
  Type          res = this->_value + rhs_value;
  return (factory->createOperand(getType(), Operand::valueToString(res)));
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
  Type          rhs_value = Operand::stringToValue(rhs.toString());
  Type          res = this->_value - rhs_value;
  return (factory->createOperand(getType(), Operand::valueToString(res)));
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
  Type          rhs_value = Operand::stringToValue(rhs.toString());
  Type          res = this->_value * rhs_value;
  return (factory->createOperand(getType(), Operand::valueToString(res)));
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
  Type          rhs_value = Operand::stringToValue(rhs.toString());
  Type          res = this->_value / rhs_value;
  return (factory->createOperand(getType(), Operand::valueToString(res)));
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
  Type          rhs_value = Operand::stringToValue(rhs.toString());
  std::string	res = Operand::valueToString(fmod(_value, rhs_value));
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

template<typename Type>
Type		Operand<Type>::stringToValue(std::string value) {
  std::stringstream	ss;
  Type			ret;

  ss << value;
  ss >> ret;
  return (ret);
}

template class Operand<int8_t>;
template class Operand<int16_t>;
template class Operand<int32_t>;
template class Operand<float>;
template class Operand<double>;
