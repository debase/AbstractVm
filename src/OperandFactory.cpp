/*
** OperandFactory.cpp for operandFactory in /home/debas_e_elementary/Project/abstract_VM
**
** Made by DEBAS
** Login   <debas_e_elementary@epitech.net>
**
** Started on  Sat Feb 15 20:15:56 2014 DEBAS
** Last update Sat Feb 15 22:25:38 2014 DEBAS
*/

#include <sys/types.h>
#include "OperandFactory.hpp"
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
  return (new Operand<int8_t>(Int8, value));
}

IOperand		*OperandFactory::createInt16(const std::string &value) const {
  return (new Operand<int16_t>(Int16, value));
}

IOperand		*OperandFactory::createInt32(const std::string &value) const {
  return (new Operand<int32_t>(Int32, value));
}

IOperand		*OperandFactory::createFloat(const std::string &value) const {
  return (new Operand<float>(Float, value));
}

IOperand		*OperandFactory::createDouble(const std::string &value) const {
  return (new Operand<double>(Double, value));
}
