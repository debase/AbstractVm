/*
** Memory.cpp for memory in /home/debas_e_elementary/Project/abstract_VM/src
**
** Made by DEBAS
** Login   <debas_e_elementary@epitech.net>
**
** Started on  Thu Feb 13 20:38:17 2014 DEBAS
// Last update Sun Feb 23 19:42:06 2014 Etienne
*/

#ifndef MEMORY_H_
#define MEMORY_H_

#include <list>
#include "Instruction.hpp"
#include "OperandFactory.hpp"

class Memory
{

public:
  Memory();
  ~Memory() {}

  void		push(IOperand *toPush);
  IOperand	*getFirst();
  void		pop();
  void		dump();
  size_t	stackSize();
private:
  std::list<IOperand *>		_stack;
};

#endif //MEMORY_H_
