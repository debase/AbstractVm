//
// parser.hpp for header in /home/collin_b/project/abstract_vm/abstract_VM/src
// 
// Made by jonathan.collinet
// Login   <collin_b@epitech.net>
// 
// Started on  Wed Feb 12 16:14:47 2014 jonathan.collinet
// Last update Tue Feb 18 14:51:31 2014 jonathan.collinet
//

#ifndef PARSER_HPP_
# define PARSER_HPP_

# include <fstream>
# include <iostream>
# include <string>
# include <algorithm>
# include <list>
# include <map>
# include "Exception.hpp"

class				Parser
{

public:
  typedef enum			Lexer
    {
      ERROR = 0,
      INSTR,
      INSTR_ARG,
      TYPE,
      VALUE,
      EXIT_PROG
    }				ELexer;

  typedef enum			type
    {
      ERR = 0,
      INT8,
      INT16,
      INT32,
      FLOAT,
      DOUBLE
    }				EType;

private:
  std::map<std::string, ELexer>	_lexer;
  std::map<std::string, EType>	_lexer_type;
  std::map<ELexer, std::string>	_values;
  int				_cur_line;

public:
  Parser();
  ~Parser() {}

  std::string	getInstr();
  std::string	getType();
  std::string	getValue();
  void				checkOUNderflow(const std::string &val, bool neg, const EType &t);
  void				isValidNumber(const std::string &val, const EType &t);
  void				setValues(const std::string &instr, const std::string &type, const std::string &value);
  std::string			checkType(const std::string &val, EType &type);
  std::string			checkValue(const std::string &val, const EType &);
  std::list<std::string>	explodeString(const std::string &str, const char c);
  bool				isNumber(const char &);
  void				isValidNumber(const std::string &, const short &);
  bool				checkLine(std::string &);
  void				parseOnFlow(/* Memory m, */ const char *);
  void				parseFile(const char *);
  void				parseIn();
  bool				parseLine(std::string &);
  void				parseInstrWithArg(std::string &, size_t,
						  const std::string &);
  void				getInnerBrackets(size_t, std::string &,
						 const std::string &,
						 const std::string &,
						 const short &);
  int				getLastFirstPos_of(std::string &, const char) const;

};

#endif
