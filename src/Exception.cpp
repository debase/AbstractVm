//
// Exception.cpp for cpp in /home/collin_b/project/abstract_vm/abstract_VM/src
// 
// Made by jonathan.collinet
// Login   <collin_b@epitech.net>
// 
// Started on  Thu Feb 13 13:25:09 2014 jonathan.collinet
// Last update Thu Feb 13 13:25:52 2014 jonathan.collinet
//

#include "Exception.hpp"

Exception::Exception(std::string message) throw()
{
  _message = message;
}

Exception::~Exception() throw()
{
}

const char*	Exception::what() const throw()
{
  return (_message.c_str());
}
