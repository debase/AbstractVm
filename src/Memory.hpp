/*
** Memory.cpp for memory in /home/debas_e_elementary/Project/abstract_VM/src
**
** Made by DEBAS
** Login   <debas_e_elementary@epitech.net>
**
** Started on  Thu Feb 13 20:38:17 2014 DEBAS
** Last update Sat Feb 15 22:14:37 2014 DEBAS
*/

#ifndef MEMORY_H_
#define MEMORY_H_

#include <map>
#include <vector>
#include <queue>
#include <stack>
#include "Instruction.hpp"
#include "OperandFactory.hpp"

class Memory
{

public:
  Memory();
  ~Memory() {}

  void		push(IOperand *toPush);
  void		pop();
  void		dump();
  void		addInstruction(const std::string &instruction,
			       const std::string &operande = "",
			       const std::string &value = "");
  std::queue<Instruction *> getInstruction();
private:
  std::queue<Instruction *>		_instruction;
  std::stack<IOperand *>		_stack;
  std::map<std::string, eOperandType>	_type;
  OperandFactory	*factory;
};

#endif //MEMORY_H_
