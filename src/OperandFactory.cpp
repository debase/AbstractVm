/*
** OperandFactory.cpp for operandFactory in /home/debas_e_elementary/Project/abstract_VM
**
** Made by DEBAS
** Login   <debas_e_elementary@epitech.net>
**
** Started on  Sat Feb 15 20:15:56 2014 DEBAS
// Last update Wed Feb 26 11:49:45 2014 Etienne
*/

#include <sys/types.h>
#include "Operand.hpp"

OperandFactory::OperandFactory() {
  _create_ptr[Int8] = &OperandFactory::createInt8;
  _create_ptr[Int16] = &OperandFactory::createInt16;
  _create_ptr[Int32] = &OperandFactory::createInt32;
  _create_ptr[Float] = &OperandFactory::createFloat;
  _create_ptr[Double] = &OperandFactory::createDouble;
}

IOperand		*OperandFactory::createOperand(eOperandType type,
						       const std::string & value) {
  PF			ptr = _create_ptr[type];
  IOperand *tmp = (this->*ptr)(value);

  return tmp;
}

IOperand		*OperandFactory::createInt8(const std::string &value) const {
  int16_t		nbr;
  std::stringstream	ss;

  nbr = Operand<int8_t>::stringToValue(value);
  return (new Operand<int8_t>(Int8, nbr));
}

IOperand		*OperandFactory::createInt16(const std::string &value) const {
  int16_t		nbr;
  std::stringstream	ss;

  nbr = Operand<int16_t>::stringToValue(value);
  return (new Operand<int16_t>(Int16, nbr));
}

IOperand		*OperandFactory::createInt32(const std::string &value) const {
  int32_t		nbr;
  std::stringstream	ss;

  nbr = Operand<int32_t>::stringToValue(value);
  return (new Operand<int32_t>(Int32, nbr));
}

IOperand		*OperandFactory::createFloat(const std::string &value) const {
  float			nbr;
  std::stringstream	ss;

  nbr = Operand<float>::stringToValue(value);
  return (new Operand<float>(Float, nbr));
}

IOperand		*OperandFactory::createDouble(const std::string &value) const {
  double		nbr;
  std::stringstream	ss;

  nbr = Operand<double>::stringToValue(value);
  return (new Operand<double>(Double, nbr));
}
