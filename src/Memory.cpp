/*
** Memory.cpp for memory in /home/debas_e_elementary/Project/abstract_VM/src
**
** Made by DEBAS
** Login   <debas_e_elementary@epitech.net>
**
** Started on  Thu Feb 13 21:05:36 2014 DEBAS
** Last update Sat Feb 15 22:17:33 2014 DEBAS
*/

#include <iostream>
#include <sys/types.h>
#include "Memory.hpp"

Memory::Memory() {
  _type["int8"] = Int8;
  _type["int16"] = Int16;
  _type["int31"] = Int32;
  _type["float"] = Float;
  _type["double"] = Double;
  factory = new OperandFactory();
}


void			Memory::addInstruction(const std::string &instruction,
					       const std::string &operande,
					       const std::string &value)
{
  IOperand		*new_ioperand;
  Instruction		*new_instru;
  eOperandType		type;

  type = _type[operande];
  new_ioperand = factory->createOperand(type, value);
  new_instru = new Instruction(new_ioperand, instruction);
  _instruction.push(new_instru);
}

void			Memory::push(IOperand *op) {
  // throw exception si stack empty
  _stack.push(op);
}

void		Memory::pop() {
  // throw exception si stack empty
  _stack.pop();
}

void			Memory::dump() {
  if (_stack.empty() == false) {
    IOperand		*tmp;
    tmp = _stack.top();
    std::cout << tmp->toString() << std::endl;
    _stack.pop();
    dump();
    push(tmp);
  }
}

std::queue<Instruction*>	Memory::getInstruction() {
  return _instruction;
}
