//
// Cpu.cpp for cpu in /home/debas_e/Project/abstract_VM
//
// Made by Etienne
// Login   <debas_e@epitech.net>
//
// Started on  Sun Feb 23 18:19:23 2014 Etienne
// Last update Mon Feb 24 18:36:05 2014 Etienne
//

#include "Cpu.hpp"
#include "Exception.hpp"

Cpu::Cpu(Memory *memory) {
  this->_memmory = memory;

  _exec_instr["mul"] = &Cpu::mul;
  _exec_instr["add"] = &Cpu::add;
  _exec_instr["div"] = &Cpu::div;
  _exec_instr["sub"] = &Cpu::sub;
  _exec_instr["mod"] = &Cpu::mod;
  _exec_instr["pop"] = &Cpu::pop;
  _exec_instr["push"] = &Cpu::push;
  _exec_instr["print"] = &Cpu::print;
  _exec_instr["dump"] = &Cpu::dump;
  _exec_instr["assert"] = &Cpu::assert;
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
    throw ArithmetiqueException("not enought value on the stack",
				_instruction->getLine());
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
    throw ArithmetiqueException("not enought value on the stack",
				_instruction->getLine());
  }
}

void		Cpu::div() {
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
    throw ArithmetiqueException("not enought value on the stack",
				_instruction->getLine());
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
    throw ArithmetiqueException("not enought value on the stack",
				_instruction->getLine());
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
    throw ArithmetiqueException("not enought value on the stack",
				_instruction->getLine());
  }
}

void		Cpu::pop() {
  if (_memmory->stackSize() > 0)
    _memmory->pop();
  else {
    throw EmptyStack("pop", this->_instruction->getLine());
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
  IOperand	*value;
  IOperand	*onTop;

  if (_memmory->stackSize() == 0) {
    throw EmptyStack("assert", _instruction->getLine());
  }
  onTop = _memmory->getFirst();
  value = _instruction->getOperand();
  if ((onTop->getType() != value->getType())
      || (onTop->toString() != value->toString()))
    {
      throw AssertException();
    }
}

void		Cpu::print() {
  IOperand	*value;

  if (_memmory->stackSize() == 0) {
    throw EmptyStack("print", _instruction->getLine());
  }
  value = _memmory->getFirst();
  if (value->getType() == Int8) {
    char		c;
    std::stringstream	ss;

    ss << value->toString();
    ss >> c;
    std::cout << c << std::endl;
  }
  else {
    throw PrintTypeException();
  }
}

void		Cpu::execute(std::list<Instruction *> instruction) {
  std::list<Instruction *>::iterator	it;
  ptrf					ptr;

  for (it = instruction.begin() ; it != instruction.end() ; it++) {
    _instruction = *it;
    if (_instruction->getInstruction() == "exit")
      return ;
    ptr = _exec_instr[_instruction->getInstruction()];
    try {
      (this->*ptr)();
    }
    catch (Exception &e) {
      std::cerr << "Error : line " << _instruction->getLine() << " : " << e.what() << std::endl;
      return ;
    }
  }
  throw ExitNotFoundException();
}
