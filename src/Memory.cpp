/*
** Memory.cpp for memory in /home/debas_e_elementary/Project/abstract_VM/src
**
** Made by DEBAS
** Login   <debas_e_elementary@epitech.net>
**
** Started on  Thu Feb 13 21:05:36 2014 DEBAS
// Last update Tue Feb 25 21:15:07 2014 jonathan.collinet
*/

#include <iostream>
#include <iomanip>
#include "Memory.hpp"

Memory::Memory() {
}

void			Memory::push(IOperand *op) {
  _stack.push_front(op);
}

IOperand		*Memory::getFirst() {
  return _stack.front();
}

void			Memory::pop() {
  _stack.pop_front();
}

void			Memory::dump() {
  if (_stack.empty() == false) {
    std::list<IOperand *>::iterator it;
    for (it = _stack.begin() ; it != _stack.end(); it++) {
      std::cout << std::setprecision(20) << (*it)->toString() << std::endl;
    }
  }
}

size_t			Memory::stackSize() {
  return _stack.size();
}
