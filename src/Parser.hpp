//
// parser.hpp for header in /home/collin_b/project/abstract_vm/abstract_VM/src
// 
// Made by jonathan.collinet
// Login   <collin_b@epitech.net>
// 
// Started on  Wed Feb 12 16:14:47 2014 jonathan.collinet
// Last update Sun Feb 16 14:25:38 2014 jonathan.collinet
//

#ifndef PARSER_HPP_
# define PARSER_HPP_

# include <fstream>
# include <iostream>
# include <string>
# include <map>
# include "Exception.hpp"

class				Parser
{

public:
  Parser();
  ~Parser() {}

  std::map<std::string,
	   std::string>		getMap() const;

  bool				isNumber(const char &c);
  void				isValidNumber(const std::string &str, const short &type, int);
  bool				checkLine(std::string &line, int);
  void				parseAndPush(/* Memory m, */ const char *);
  void				parseFile(const char *file);
  void				parseIn();
  bool				isKey(std::string &, int);
  void				parseInstrWithArg(std::string &str, size_t pos,
						  const std::string &key_arg_instr,
						  int);
  void				getInnerBrackets(size_t pos, std::string &str,
						 const std::string &key_arg_instr,
						 const std::string &key_arg_value,
						 const short &type, int);
  int				getLastFirstPos_of(std::string &, const char) const;

};

#endif
