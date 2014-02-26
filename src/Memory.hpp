/*
** Memory.cpp for memory in /home/debas_e_elementary/Project/abstract_VM/src
**
** Made by DEBAS
** Login   <debas_e_elementary@epitech.net>
**
** Started on  Thu Feb 13 20:38:17 2014 DEBAS
// Last update Wed Feb 26 11:37:00 2014 Etienne
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
  IOperand	*getFirst() const ;
  void		pop();
  void		dump();
  size_t	stackSize() const ;
private:
  std::list<IOperand *>		_stack;
};

#endif //MEMORY_H_
