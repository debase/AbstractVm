//
// Exception.hpp for header in /home/collin_b/project/abstract_vm/abstract_VM/src
// 
// Made by jonathan.collinet
// Login   <collin_b@epitech.net>
// 
// Started on  Thu Feb 13 13:24:19 2014 jonathan.collinet
// Last update Sun Feb 16 14:22:42 2014 jonathan.collinet
//

#ifndef EXCEPTION_HPP_
# define EXCEPTION_HPP_

# include <iostream>
# include <string>
# include <exception>

class				Exception : public std::exception
{
public:
  Exception(const std::string &, const int &) throw();
  virtual ~Exception() throw();
  virtual const char*		what() const throw();
  virtual int			where() const throw();

private:
  std::string			_message;
  int				_line;
};

#endif
