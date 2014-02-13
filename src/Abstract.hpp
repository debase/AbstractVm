//
// abstract.hpp for header in /home/collin_b/project/abstract_vm/abstract_VM/src
// 
// Made by jonathan.collinet
// Login   <collin_b@epitech.net>
// 
// Started on  Wed Feb 12 16:07:17 2014 jonathan.collinet
// Last update Thu Feb 13 15:33:59 2014 jonathan.collinet
//

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
