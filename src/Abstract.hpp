/*
** Abstract.hpp for abstract in /home/debas_e_elementary/Project/abstract_VM/src
**
** Made by DEBAS
** Login   <debas_e_elementary@epitech.net>
**
** Started on  Sat Feb 15 22:09:47 2014 DEBAS
** Last update Sat Feb 15 22:09:48 2014 DEBAS
*/

#ifndef ABSTRACT_HPP_
# define ABSTRACT_HPP_

# include "Parser.hpp"

class		Abstract
{
public:
  Abstract() {}
  ~Abstract() {}

  Parser	getParser() const;
private:
  Parser	_p;
};

#endif
