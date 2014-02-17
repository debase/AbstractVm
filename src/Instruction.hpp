/*
** Instruction.hpp for instruction in /home/debas_e_elementary/Project/abstract_VM/src
**
** Made by DEBAS
** Login   <debas_e_elementary@epitech.net>
**
** Started on  Thu Feb 13 23:06:50 2014 DEBAS
** Last update Fri Feb 14 13:16:07 2014 DEBAS
*/

#ifndef INSTRUCTION_H_
#define INSTRUCTION_H_

#include <string>
#include "IOperand.hpp"

class Instruction{
public:
  Instruction(IOperand *op, std::string instruction = "");
  IOperand	*getOperand();
  std::string	&getInstruction();
private:
  IOperand	*_op;
  std::string	_instruction;
};

#endif //INSTRUCTION_H_
