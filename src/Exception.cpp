//
// Exception.cpp for cpp in /home/collin_b/project/abstract_vm/abstract_VM/src
// 
// Made by jonathan.collinet
// Login   <collin_b@epitech.net>
// 
// Started on  Thu Feb 13 13:25:09 2014 jonathan.collinet
// Last update Thu Feb 20 13:01:34 2014 jonathan.collinet
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

FileNotOpened::FileNotOpened(const std::string &message, const int &nbline) throw()
  : Exception(message, nbline)
{
  _message = "cannot open the file : \"" + message + "\"";
  _line = nbline;
}

FileNotOpened::~FileNotOpened() throw()
{
}

const char*	FileNotOpened::what() const throw()
{
  return (_message.c_str());
}

int		FileNotOpened::where() const throw()
{
  return (_line);
}

LeftClosedParth::LeftClosedParth(const std::string &message, const int &nbline) throw()
  : Exception(message, nbline)
{
  _message = "missing closed parenthesis in line : \"" + message + "\"";
  _line = nbline;
}

LeftClosedParth::~LeftClosedParth() throw()
{
}

const char*	LeftClosedParth::what() const throw()
{
  return (_message.c_str());
}

int		LeftClosedParth::where() const throw()
{
  return (_line);
}

BadInstr::BadInstr(const std::string &message, const int &nbline) throw()
  : Exception(message, nbline)
{
  _message = "bad instruction syntax : \"" + message + "\"";
  _line = nbline;
}

BadInstr::~BadInstr() throw()
{
}

const char*	BadInstr::what() const throw()
{
  return (_message.c_str());
}

int		BadInstr::where() const throw()
{
  return (_line);
}

BadNumber::BadNumber(const std::string &message, const int &nbline) throw()
  : Exception(message, nbline)
{
  _message = "bad syntax on not floating number : \"" + message + "\"";
  _line = nbline;
}

BadNumber::~BadNumber() throw()
{
}

const char*	BadNumber::what() const throw()
{
  return (_message.c_str());
}

int		BadNumber::where() const throw()
{
  return (_line);
}

BadFloatNumber::BadFloatNumber(const std::string &message, const int &nbline) throw()
  : Exception(message, nbline)
{
  _message = "bad syntax on floating number : \"" + message + "\"";
  _line = nbline;
}

BadFloatNumber::~BadFloatNumber() throw()
{
}

const char*	BadFloatNumber::what() const throw()
{
  return (_message.c_str());
}

int		BadFloatNumber::where() const throw()
{
  return (_line);
}

BadOperand::BadOperand(const std::string &message, const int &nbline) throw()
  : Exception(message, nbline)
{
  _message = "bad operand syntax : \"" + message + "\"";
  _line = nbline;
}

BadOperand::~BadOperand() throw()
{
}

const char*	BadOperand::what() const throw()
{
  return (_message.c_str());
}

int		BadOperand::where() const throw()
{
  return (_line);
}

NullValue::NullValue(const std::string &message, const int &nbline) throw()
  : Exception(message, nbline)
{
  _message = "null value : \"" + message + "\"";
  _line = nbline;
}

NullValue::~NullValue() throw()
{
}

const char*	NullValue::what() const throw()
{
  return (_message.c_str());
}

int		NullValue::where() const throw()
{
  return (_line);
}

FileEmpty::FileEmpty(const std::string &message, const int &nbline) throw()
  : Exception(message, nbline)
{
  _message = "file is empty : \"" + message + "\"";
  _line = nbline;
}

FileEmpty::~FileEmpty() throw()
{
}

const char*	FileEmpty::what() const throw()
{
  return (_message.c_str());
}

int		FileEmpty::where() const throw()
{
  return (_line);
}

Overflow::Overflow(const std::string &message, const int &nbline) throw()
  : Exception(message, nbline)
{
  _message = "overflow value : \"" + message + "\"";
  _line = nbline;
}

Overflow::~Overflow() throw()
{
}

const char*	Overflow::what() const throw()
{
  return (_message.c_str());
}

int		Overflow::where() const throw()
{
  return (_line);
}

Underflow::Underflow(const std::string &message, const int &nbline) throw()
  : Exception(message, nbline)
{
  _message = "underflow value : \"" + message + "\"";
  _line = nbline;
}

Underflow::~Underflow() throw()
{
}

const char*	Underflow::what() const throw()
{
  return (_message.c_str());
}

int		Underflow::where() const throw()
{
  return (_line);
}

