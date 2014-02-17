#ifndef OPERAND_H_
#define OPERAND_H_

#include <iomanip>
#include <sstream>
#include <iostream>
#include "IOperand.hpp"
#include "OperandFactory.hpp"

template <typename Type>
class Operand : public IOperand
{
public:
Operand(eOperandType enum_type, std::string const &value);
  int			getPrecision() const;
  std::string const	&toString() const;
  eOperandType		getType() const ;
  static std::string	valueToString(Type value);
  static Type		stringToValue(std::string value);
  IOperand		*operator+(const IOperand &rhs) const;
  IOperand		*operator-(const IOperand &rhs) const;
  IOperand		*operator*(const IOperand &rhs) const;
  IOperand		*operator/(const IOperand &rhs) const;
  IOperand		*operator%(const IOperand &rhs) const;
private:
  std::string		_str;
  eOperandType		_enum_type;
  Type			_value;
  OperandFactory	*factory;
};

template<typename Type>
Operand<Type>::Operand(eOperandType enum_type, std::string const &value) : _str(value) {
  std::stringstream    ss;

  _enum_type = enum_type;
  ss.str(value);
  ss >> _value;
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
  if (rhs.getType() > this->getType()) {
    return rhs + *this;
  }
  Type		rhs_value = Operand::stringToValue(rhs.toString());
  Type		res = this->_value + rhs_value;
  if ((res - rhs_value) != this->_value)
    std::cout << "Overflow !" << std::endl;
  return (factory->createOperand(this->getType(), Operand::valueToString(res)));
}

template<typename Type>
IOperand	*Operand<Type>::operator-(const IOperand &rhs) const {
  eOperandType t;
  std::stringstream ss1(this->toString()), ss2(rhs.toString()), ss;
  double res, val1, val2;

  ss1 >> val1;
  ss2 >> val2;
  res = val1 - val2;
  if ((res + val2) != val1)
    std::cout << "Overflow !" << std::endl;
  ss << res;
  t = std::max(this->getType(), rhs.getType());
  return (factory->createOperand(t, ss.str()));
}

template<typename Type>
IOperand	*Operand<Type>::operator*(const IOperand &rhs) const {
  eOperandType t;
  std::stringstream ss1(this->toString()), ss2(rhs.toString()), ss;
  double res, val1, val2;

  ss1 >> val1;
  ss2 >> val2;
  res = val1 * val2;
  if ((res / val2) != val1)
    std::cout << "Overflow !" << std::endl;
  ss << res;
  t = std::max(this->getType(), rhs.getType());
  return (factory->createOperand(t, ss.str()));
}

template<typename Type>
IOperand	*Operand<Type>::operator/(const IOperand &rhs) const {
  eOperandType t;
  std::stringstream ss1(this->toString()), ss2(rhs.toString()), ss;
  double res, val1, val2;

  ss1 >> val1;
  ss2 >> val2;
  res = val1 / val2;
  if ((res * val2) != val1)
    std::cout << "Overflow !" << std::endl;
  ss << res;
  t = std::max(this->getType(), rhs.getType());
  return (factory->createOperand(t, ss.str()));
}

template<typename Type>
IOperand	*Operand<Type>::operator%(const IOperand &rhs) const {
  eOperandType t;
  std::stringstream ss1(this->toString()), ss2(rhs.toString()), ss;
  int res, val1, val2;

  if (rhs.getType() >= Float || this->getType() >= Float)
    std::cout << "Modulo must be between integer" << std::endl;
  ss1 >> val1;
  ss2 >> val2;
  res = val1 % val2;
  ss << res;
  t = std::max(this->getType(), rhs.getType());
  return (factory->createOperand(t, ss.str()));
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

#endif //OPERAND_H_
