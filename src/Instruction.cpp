/*
** Instruction.cpp for instruction in /home/debas_e_elementary/Project/abstract_VM/src
**
** Made by DEBAS
** Login   <debas_e_elementary@epitech.net>
**
** Started on  Thu Feb 13 23:41:46 2014 DEBAS
// Last update Mon Feb 24 00:18:03 2014 Etienne
*/

#include "Instruction.hpp"

Instruction::Instruction(IOperand *op, std::string instruction, int line) {
  _op = op;
  _instruction = instruction;
  _line = line;
}

std::string		&Instruction::getInstruction() {
  return _instruction;
}

IOperand		*Instruction::getOperand() {
  return _op;
}

int			Instruction::getLine() {
  return _line;
}
