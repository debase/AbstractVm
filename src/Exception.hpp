//
// Exception.hpp for header in /home/collin_b/project/abstract_vm/abstract_VM/src
//
// Made by jonathan.collinet
// Login   <collin_b@epitech.net>
//
// Started on  Thu Feb 13 13:24:19 2014 jonathan.collinet
// Last update Mon Feb 24 18:42:25 2014 Etienne
//

#ifndef EXCEPTION_HPP_
# define EXCEPTION_HPP_

# include <iostream>
# include <string>
# include <exception>

class				Exception : public std::exception
{
public:
  Exception(const std::string &, const int ) throw();
  virtual ~Exception() throw();
  virtual const char*		what() const throw();
  virtual int			where() const throw();

private:
  std::string			_message;
  int				_line;
};

class				FileNotOpened : public Exception
{
public:
  FileNotOpened(const std::string &, const int ) throw();
  virtual ~FileNotOpened() throw();
};

class				ParenthesisError : public Exception
{
public:
  ParenthesisError(const std::string &, const int ) throw();
  virtual ~ParenthesisError() throw();
};

class				BadInstr : public Exception
{
public:
  BadInstr(const std::string &, const int ) throw();
  virtual ~BadInstr() throw();
};

class				BadNumber : public Exception
{
public:
  BadNumber(const std::string &, const int ) throw();
  virtual ~BadNumber() throw();
};

class				BadFloatNumber : public Exception
{
public:
  BadFloatNumber(const std::string &, const int ) throw();
  virtual ~BadFloatNumber() throw();
};

class				BadOperand : public Exception
{
public:
  BadOperand(const std::string &, const int ) throw();
  virtual ~BadOperand() throw();
};

class				NullValue : public Exception
{
public:
  NullValue(const std::string &, const int ) throw();
  virtual ~NullValue() throw();
};

class				Overflow : public Exception
{
public:
  Overflow(const std::string &, const int ) throw();
  virtual ~Overflow() throw();
};

class				Underflow : public Exception
{
public:
  Underflow(const std::string &, const int ) throw();
  virtual ~Underflow() throw();
};

class				SyntaxError : public Exception
{
public:
  SyntaxError(const std::string &, const int ) throw();
  virtual ~SyntaxError() throw();
};

class				EmptyStack : public Exception
{
public:
  EmptyStack(const std::string &, const int) throw();
  virtual ~EmptyStack() throw();
};

class				ArithmetiqueException : public Exception
{
public:
  ArithmetiqueException(const std::string &, const int) throw();
  virtual ~ArithmetiqueException() throw();
};

class				DivZeroException : public Exception
{
public:
  DivZeroException() throw();
  virtual ~DivZeroException() throw();
};

class				ModZeroException : public Exception
{
public:
  ModZeroException() throw();
  virtual ~ModZeroException() throw();
};

class				PrintTypeException : public Exception
{
public:
  PrintTypeException() throw();
  virtual ~PrintTypeException() throw();
};

class				AssertException : public Exception
{
public:
  AssertException() throw();
  virtual ~AssertException() throw();
};

class				 ExitNotFoundException : public Exception
{
public:
  ExitNotFoundException() throw();
  virtual ~ ExitNotFoundException() throw();
};

#endif
