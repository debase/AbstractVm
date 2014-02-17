/*
** Instruction.cpp for instruction in /home/debas_e_elementary/Project/abstract_VM/src
**
** Made by DEBAS
** Login   <debas_e_elementary@epitech.net>
**
** Started on  Thu Feb 13 23:41:46 2014 DEBAS
** Last update Thu Feb 13 23:44:08 2014 DEBAS
*/

#include "Instruction.hpp"

Instruction::Instruction(IOperand *op, std::string instruction) {
  _op = op;
  _instruction = instruction;
}
