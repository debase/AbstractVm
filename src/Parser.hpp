//
// parser.hpp for header in /home/collin_b/project/abstract_vm/abstract_VM/src
// 
// Made by jonathan.collinet
// Login   <collin_b@epitech.net>
// 
// Started on  Wed Feb 12 16:14:47 2014 jonathan.collinet
// Last update Thu Feb 13 22:19:12 2014 jonathan.collinet
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

  void				parse_and_push(/* Memory m, */ const char *);
  void				isKey(std::string &);
  void				parseInstrWithArg(std::string &str, size_t pos,
						  const std::string &key_arg_instr);
  void				getInnerBrackets(size_t pos, std::string &str,
						 const std::string &key_arg_instr,
						 const std::string &key_arg_value);
  int				getFirstPos_of(std::string &, const char) const;

};

#endif
