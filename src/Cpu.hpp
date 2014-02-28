//
// Cpu.hpp for cpu in /home/debas_e/Project/abstract_VM
//
// Made by Etienne
// Login   <debas_e@epitech.net>
//
// Started on  Sun Feb 23 18:05:48 2014 Etienne
// Last update Fri Feb 28 15:52:25 2014 jonathan.collinet
//

#ifndef CPU_HH
#define CPU_HH

#include <map>
#include <sstream>
#include <iostream>
#include "Memory.hpp"
#include "Instruction.hpp"

class		Cpu
{
public:
  typedef void		(Cpu::*ptrf)(void) const ;

  Cpu(Memory *);
  ~Cpu() {}
  void		execute(std::list<Instruction *>, bool);
  void		mul() const ;
  void		add() const ;
  void		div() const ;
  void		sub() const ;
  void		mod() const ;
  void		pop() const ;
  void		push() const ;
  void		dump() const ;
  void		assert() const ;
  void		print() const ;
private:
  Memory	*_memmory;
  Instruction	*_instruction;
  std::map<std::string, ptrf>	_exec_instr;
};
#endif
