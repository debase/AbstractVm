/*
** Memory.cpp for memory in /home/debas_e_elementary/Project/abstract_VM/src
**
** Made by DEBAS
** Login   <debas_e_elementary@epitech.net>
**
** Started on  Thu Feb 13 21:05:36 2014 DEBAS
// Last update Wed Feb 26 11:37:14 2014 Etienne
*/

#include <iostream>
#include <iomanip>
#include "Memory.hpp"

Memory::Memory() {
}

void			Memory::push(IOperand *op) {
  _stack.push_front(op);
}

IOperand		*Memory::getFirst() const {
  return _stack.front();
}

void			Memory::pop() {
  _stack.pop_front();
}

void			Memory::dump() {
  if (_stack.empty() == false) {
    std::list<IOperand *>::iterator it;
    for (it = _stack.begin() ; it != _stack.end(); it++) {
      std::cout << (*it)->toString() << std::endl;
    }
  }
}

size_t			Memory::stackSize() const {
  return _stack.size();
}
