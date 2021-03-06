/*
** Abstract.hpp for abstract in /home/debas_e_elementary/Project/abstract_VM/src
**
** Made by DEBAS
** Login   <debas_e_elementary@epitech.net>
**
** Started on  Sat Feb 15 22:09:47 2014 DEBAS
// Last update Wed Feb 26 11:16:58 2014 Etienne
*/

#ifndef ABSTRACT_HPP_
# define ABSTRACT_HPP_

#include "Parser.hpp"
#include "Memory.hpp"
#include "Cpu.hpp"

class		Abstract
{
public:
  Abstract();
  ~Abstract();

  void		execute(const char *) const;
private:
  Parser	*parser;
  Memory	*memory;
  Cpu		*cpu;
};

#endif
