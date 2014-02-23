//
// parser.hpp for header in /home/collin_b/project/abstract_vm/abstract_VM/src
// 
// Made by jonathan.collinet
// Login   <collin_b@epitech.net>
// 
// Started on  Wed Feb 12 16:14:47 2014 jonathan.collinet
// Last update Thu Feb 20 13:40:51 2014 jonathan.collinet
//

#ifndef PARSER_HPP_
# define PARSER_HPP_

# include <sstream>
# include <fstream>
# include <iostream>
# include <iomanip>
# include <string>
# include <limits>
# include <algorithm>
# include <list>
# include <map>
# include <deque>
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
      P_LEFT,
      P_RIGHT,
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
  std::map<EType, unsigned int>	_get_sum_nf;
  std::map<EType, double>	_get_sum_f;
  std::map<ELexer, std::string>	_values;
  int				_cur_line;
  bool				_p_left;
  bool				_p_right;
  bool				_min_one;

public:
  Parser();
  ~Parser() {}

  void				checkNonFloatantOverflow(const std::string &val, const bool &neg, const EType &t);
  void				checkFloatantOverflow(const std::string &val, const bool &neg, const EType &t);
  void				reinitValues();
  std::map<ELexer, std::string> getValues();  
  void				parseInstrWithArg(std::list<std::string>::iterator it);
  std::string			checkValidValue(std::string &val, const EType &t, size_t &);
  void				checkSpecialCase(const std::string &str, 
						 std::list<std::string>::iterator &it);
  std::string			parseType(const std::string &val, EType &type);
  void				checkOverflow(const std::string &val, const bool &neg, const EType &t);
  void				isValidNumber(const std::string &val, const EType &t);
  void				setValues(const std::string &instr, const std::string &type, 
					  const std::string &value);
  std::string			checkType(std::string &val, EType &type, 
					  std::list<std::string>::iterator &it);
  std::string			checkValue(std::string &val, const EType &);
  std::list<std::string>	explodeString(const std::string &str, const char c);
  bool				isNumber(const char &);
  void				isValidNumber(const std::string &, const short &);
  bool				checkLine(std::string &);
  void				parseOnFlow(/* Memory m, */ const char *);
  void				parseFile(const char *);
  void				parseIn();
  bool				parseLine(std::string &);
  int				getLastFirstPos_of(std::string &, const char) const;

};

#endif
