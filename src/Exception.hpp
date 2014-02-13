//
// Exception.hpp for header in /home/collin_b/project/abstract_vm/abstract_VM/src
// 
// Made by jonathan.collinet
// Login   <collin_b@epitech.net>
// 
// Started on  Thu Feb 13 13:24:19 2014 jonathan.collinet
// Last update Thu Feb 13 13:31:41 2014 jonathan.collinet
//

#ifndef EXCEPTION_HPP_
# define EXCEPTION_HPP_

# include <iostream>
# include <string>
# include <exception>

class				Exception : public std::exception
{
public:
  Exception(std::string message) throw();
  virtual ~Exception() throw();
  virtual const char*		what() const throw();
private:
  std::string			_message;
};

#endif
