//
// Cpu.hpp for cpu in /home/debas_e/Project/abstract_VM
//
// Made by Etienne
// Login   <debas_e@epitech.net>
//
// Started on  Sun Feb 23 18:05:48 2014 Etienne
// Last update Sun Feb 23 19:22:39 2014 Etienne
//

#ifndef CPU_HH
#define CPU_HH

#include <map>
#include <iostream>
#include "Memory.hpp"
#include "Instruction.hpp"

class		Cpu
{
public:
  typedef void		(Cpu::*ptrf)(void);

  Cpu(Memory *);
  ~Cpu() {}
  void		execute(std::list<Instruction *> instruction);
  void		mul();
  void		add();
  void		div();
  void		sub();
  void		mod();
  void		pop();
  void		push();
  void		dump();
  void		assert();
  void		exit();
private:
  Memory	*_memmory;
Instruction	*_instruction;
  std::map<std::string, ptrf>	_exec_instr;
};
#endif
