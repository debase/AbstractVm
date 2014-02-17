/*
** OperandFactory.hpp for operandFactory in /home/debas_e_elementary/Project/abstract_VM
**
** Made by DEBAS
** Login   <debas_e_elementary@epitech.net>
**
** Started on  Sat Feb 15 20:09:25 2014 DEBAS
** Last update Sun Feb 16 22:10:47 2014 DEBAS
*/

#ifndef OPERANDFACTORY_H_
#define OPERANDFACTORY_H_

#include <map>
#include "IOperand.hpp"

class OperandFactory
{
public:
  typedef IOperand* (OperandFactory::*PF)(const std::string &) const;

  OperandFactory();
  IOperand	*createOperand(eOperandType type, const std::string & value);
  IOperand	*createInt8(const std::string &value) const;
  IOperand	*createInt16(const std::string &value) const;
  IOperand	*createInt32(const std::string &value) const;
  IOperand	*createFloat(const std::string &value) const;
  IOperand	*createDouble(const std::string &value) const;
private:
  std::map<eOperandType, PF>		_create_ptr;
};

#endif //OPERANDFACTORY_H_
