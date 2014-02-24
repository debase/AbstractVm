/*
** Instruction.hpp for instruction in /home/debas_e_elementary/Project/abstract_VM/src
**
** Made by DEBAS
** Login   <debas_e_elementary@epitech.net>
**
** Started on  Thu Feb 13 23:06:50 2014 DEBAS
// Last update Mon Feb 24 00:17:57 2014 Etienne
*/

#ifndef INSTRUCTION_H_
#define INSTRUCTION_H_

#include <string>
#include "IOperand.hpp"

class Instruction{
public:
  Instruction(IOperand *op, std::string instruction, int line);
  IOperand	*getOperand();
  std::string	&getInstruction();
  int		getLine();
private:
  IOperand	*_op;
  std::string	_instruction;
  int		_line;
};

#endif //INSTRUCTION_H_
