//
// Exception.cpp for cpp in /home/collin_b/project/abstract_vm/abstract_VM/src
// 
// Made by jonathan.collinet
// Login   <collin_b@epitech.net>
// 
// Started on  Thu Feb 13 13:25:09 2014 jonathan.collinet
// Last update Sun Feb 16 14:22:39 2014 jonathan.collinet
//

#include "Exception.hpp"

Exception::Exception(const std::string &message, const int &nbline) throw()
{
  _message = message;
  _line = nbline;
}

Exception::~Exception() throw()
{
}

const char*	Exception::what() const throw()
{
  return (_message.c_str());
}

int		Exception::where() const throw()
{
  return (_line);
}
