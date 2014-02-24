//
// Exception.cpp for cpp in /home/collin_b/project/abstract_vm/abstract_VM/src
//
// Made by jonathan.collinet
// Login   <collin_b@epitech.net>
//
// Started on  Thu Feb 13 13:25:09 2014 jonathan.collinet
// Last update Mon Feb 24 18:35:37 2014 Etienne
//

#include "Exception.hpp"

Exception::Exception(const std::string &message, const int nbline) throw()
{
  _message = message;
  _line = nbline;
}

Exception::~Exception() throw()
{
}

const char	*Exception::what() const throw() {
  return (_message.c_str());
}

int		Exception::where() const throw() {
  return _line;
}

FileNotOpened::FileNotOpened(const std::string &message, const int nbline) throw()
  : Exception("cannot open the file : \"" + message + "\"", nbline)
{
}

FileNotOpened::~FileNotOpened() throw()
{
}

ParenthesisError::ParenthesisError(const std::string &message, const int nbline) throw()
  : Exception("Parenthesis error in line : \"" + message + "\"", nbline)
{
}

ParenthesisError::~ParenthesisError() throw()
{
}

BadInstr::BadInstr(const std::string &message, const int nbline) throw()
  : Exception("bad instruction syntax : \"" + message + "\"", nbline)
{
}

BadInstr::~BadInstr() throw()
{
}

BadNumber::BadNumber(const std::string &message, const int nbline) throw()
  : Exception("Syntax number error: \"" + message + "\"", nbline)
{
}

BadNumber::~BadNumber() throw()
{
}

BadFloatNumber::BadFloatNumber(const std::string &message, const int nbline) throw()
  : Exception("bad syntax on floating number : \"" + message + "\"", nbline)
{
}

BadFloatNumber::~BadFloatNumber() throw()
{
}

BadOperand::BadOperand(const std::string &message, const int nbline) throw()
  : Exception("bad operand syntax : \"" + message + "\"", nbline)
{
}

BadOperand::~BadOperand() throw()
{
}

NullValue::NullValue(const std::string &message, const int nbline) throw()
  : Exception("null value : \"" + message + "\"", nbline)
{
}

NullValue::~NullValue() throw()
{
}

Overflow::Overflow(const std::string &message, const int nbline) throw()
  : Exception("overflow value : \"" + message + "\"", nbline)
{
}

Overflow::~Overflow() throw()
{
}

Underflow::Underflow(const std::string &message, const int nbline) throw()
  : Exception("underflow value : \"" + message + "\"", nbline)
{
}

Underflow::~Underflow() throw()
{
}

SyntaxError::SyntaxError(const std::string &message, const int nbline) throw()
  : Exception("Syntax error : \"" + message + "\"", nbline)
{
}

SyntaxError::~SyntaxError() throw()
{
}

EmptyStack::EmptyStack(const std::string &op, const int nbline) throw()
  : Exception(op + " on empty stack", nbline)
{
}

EmptyStack::~EmptyStack() throw () {

}

ArithmetiqueException::ArithmetiqueException(const std::string &message, const int nbline) throw()
  : Exception("Error during arithmetique execution : \"" + message + "\"", nbline)
{
}

ArithmetiqueException::~ArithmetiqueException() throw () {

}

DivZeroException::DivZeroException() throw()
  : Exception("Division by zero", 0)
{
}

DivZeroException::~DivZeroException() throw () {

}

ModZeroException::ModZeroException() throw()
  : Exception("Modulo by zero", 0)
{
}

ModZeroException::~ModZeroException() throw () {

}

PrintTypeException::PrintTypeException() throw()
  : Exception("print error : value on the the top of the stack isn't 8 bit", 0)
{
}

PrintTypeException::~PrintTypeException() throw () {

}

AssertException::AssertException() throw()
  : Exception("assert error : value on the the top isn't the same", 0)
{
}

AssertException::~AssertException() throw () {

}

ExitNotFoundException:: ExitNotFoundException() throw()
  : Exception("exit error : exit instruction not found", 0)
{
}

ExitNotFoundException::~ ExitNotFoundException() throw () {

}
