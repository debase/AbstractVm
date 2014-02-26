/*
** Instruction.cpp for instruction in /home/debas_e_elementary/Project/abstract_VM/src
**
** Made by DEBAS
** Login   <debas_e_elementary@epitech.net>
**
** Started on  Thu Feb 13 23:41:46 2014 DEBAS
// Last update Wed Feb 26 11:35:01 2014 Etienne
*/

#include "Instruction.hpp"

Instruction::Instruction(IOperand *op, std::string instruction, int line) {
  _op = op;
  _instruction = instruction;
  _line = line;
}

std::string	Instruction::getInstruction() const {
  return _instruction;
}

IOperand		*Instruction::getOperand() const {
  return _op;
}

int		Instruction::getLine() const {
  return _line;
}
