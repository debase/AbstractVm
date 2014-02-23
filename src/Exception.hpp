//
// Exception.hpp for header in /home/collin_b/project/abstract_vm/abstract_VM/src
//
// Made by jonathan.collinet
// Login   <collin_b@epitech.net>
//
// Started on  Thu Feb 13 13:24:19 2014 jonathan.collinet
// Last update Sun Feb 23 15:23:47 2014 Etienne
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
  virtual const char*		what() const throw();
  virtual int			where() const throw();

private:
  std::string			_message;
  int				_line;
};

class				ParenthesisError : public Exception
{
public:
  ParenthesisError(const std::string &, const int ) throw();
  virtual ~ParenthesisError() throw();
  virtual const char*		what() const throw();
  virtual int			where() const throw();

private:
  std::string			_message;
  int				_line;
};

class				BadInstr : public Exception
{
public:
  BadInstr(const std::string &, const int ) throw();
  virtual ~BadInstr() throw();
  virtual const char*		what() const throw();
  virtual int			where() const throw();

private:
  std::string			_message;
  int				_line;
};

class				BadNumber : public Exception
{
public:
  BadNumber(const std::string &, const int ) throw();
  virtual ~BadNumber() throw();
  virtual const char*		what() const throw();
  virtual int			where() const throw();

private:
  std::string			_message;
  int				_line;
};

class				BadFloatNumber : public Exception
{
public:
  BadFloatNumber(const std::string &, const int ) throw();
  virtual ~BadFloatNumber() throw();
  virtual const char*		what() const throw();
  virtual int			where() const throw();

private:
  std::string			_message;
  int				_line;
};

class				BadOperand : public Exception
{
public:
  BadOperand(const std::string &, const int ) throw();
  virtual ~BadOperand() throw();
  virtual const char*		what() const throw();
  virtual int			where() const throw();

private:
  std::string			_message;
  int				_line;
};

class				NullValue : public Exception
{
public:
  NullValue(const std::string &, const int ) throw();
  virtual ~NullValue() throw();
  virtual const char*		what() const throw();
  virtual int			where() const throw();

private:
  std::string			_message;
  int				_line;
};

class				FileEmpty : public Exception
{
public:
  FileEmpty(const std::string &, const int ) throw();
  virtual ~FileEmpty() throw();
  virtual const char*		what() const throw();
  virtual int			where() const throw();

private:
  std::string			_message;
  int				_line;
};

class				Overflow : public Exception
{
public:
  Overflow(const std::string &, const int ) throw();
  virtual ~Overflow() throw();
  virtual const char*		what() const throw();
  virtual int			where() const throw();

private:
  std::string			_message;
  int				_line;
};

class				Underflow : public Exception
{
public:
  Underflow(const std::string &, const int ) throw();
  virtual ~Underflow() throw();
  virtual const char*		what() const throw();
  virtual int			where() const throw();

private:
  std::string			_message;
  int				_line;
};

class				SyntaxError : public Exception
{
public:
  SyntaxError(const std::string &, const int ) throw();
  virtual ~SyntaxError() throw();
  virtual const char*		what() const throw();
  virtual int			where() const throw();

private:
  std::string			_message;
  int				_line;
};

#endif
