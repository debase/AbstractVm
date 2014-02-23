//
// Cpu.cpp for cpu in /home/debas_e/Project/abstract_VM
//
// Made by Etienne
// Login   <debas_e@epitech.net>
//
// Started on  Sun Feb 23 18:19:23 2014 Etienne
// Last update Sun Feb 23 19:49:13 2014 Etienne
//

#include "Cpu.hpp"

Cpu::Cpu(Memory *memory) {
  this->_memmory = memory;

  _exec_instr["mul"] = &Cpu::mul;
  _exec_instr["add"] = &Cpu::add;
  _exec_instr["div"] = &Cpu::div;
  _exec_instr["sub"] = &Cpu::sub;
  _exec_instr["mod"] = &Cpu::mod;
  _exec_instr["pop"] = &Cpu::pop;
  _exec_instr["push"] = &Cpu::push;
  _exec_instr["dump"] = &Cpu::dump;
  _exec_instr["assert"] = &Cpu::assert;
  _exec_instr["exit"] = &Cpu::exit;
}

void		Cpu::mul() {
  IOperand	*nb1;
  IOperand	*nb2;

  if (_memmory->stackSize() >= 2) {
    nb1 = _memmory->getFirst();
    _memmory->pop();
    nb2 = _memmory->getFirst();
    _memmory->pop();
    _memmory->push(*nb1 * *nb2);
  }
  else {

  }
}

void		Cpu::add() {
  IOperand	*nb1;
  IOperand	*nb2;

  if (_memmory->stackSize() >= 2) {
    nb1 = _memmory->getFirst();
    _memmory->pop();
    nb2 = _memmory->getFirst();
    _memmory->pop();
    _memmory->push(*nb1 + *nb2);
  }
  else {

  }
}

void		Cpu::div() {
  std::cout << "div" << std::endl;
  IOperand	*nb1;
  IOperand	*nb2;

  if (_memmory->stackSize() >= 2) {
    nb1 = _memmory->getFirst();
    _memmory->pop();
    nb2 = _memmory->getFirst();
    _memmory->pop();
    _memmory->push(*nb1 / *nb2);
  }
  else {

  }
}

void		Cpu::sub() {
  IOperand	*nb1;
  IOperand	*nb2;

  if (_memmory->stackSize() >= 2) {
    nb1 = _memmory->getFirst();
    _memmory->pop();
    nb2 = _memmory->getFirst();
    _memmory->pop();
    _memmory->push(*nb1 - *nb2);
  }
  else {

  }
}

void		Cpu::mod() {
  IOperand	*nb1;
  IOperand	*nb2;

  if (_memmory->stackSize() >= 2) {
    nb1 = _memmory->getFirst();
    _memmory->pop();
    nb2 = _memmory->getFirst();
    _memmory->pop();
    _memmory->push(*nb1 % *nb2);
  }
  else {

  }
}

void		Cpu::pop() {
  if (_memmory->stackSize() > 0)
    _memmory->pop();
  else {

  }
}

void		Cpu::push() {
  IOperand	*topush = _instruction->getOperand();

  _memmory->push(topush);
}

void		Cpu::dump() {
  _memmory->dump();
}

void		Cpu::assert() {
  std::cout << "assert" << std::endl;
}

void		Cpu::exit() {
  std::cout << "exit" << std::endl;
}

void		Cpu::execute(std::list<Instruction *> instruction) {
  std::list<Instruction *>::iterator	it;
  ptrf					ptr;

  for (it = instruction.begin() ; it != instruction.end() ; it++) {
    this->_instruction = *it;
    ptr = _exec_instr[this->_instruction->getInstruction()];
    (this->*ptr)();
  }
}
