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
  Operand(eOperandType enum_type, Type value);
  int			getPrecision() const;
  std::string const	&toString() const;
  eOperandType		getType() const ;
  static std::string	valueToString(const Type value);
  static Type		stringToValue(const std::string &value);
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

#endif //OPERAND_H_
