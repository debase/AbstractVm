//
// parser.hpp for header in /home/collin_b/project/abstract_vm/abstract_VM/src
// 
// Made by jonathan.collinet
// Login   <collin_b@epitech.net>
// 
// Started on  Wed Feb 12 16:14:47 2014 jonathan.collinet
// Last update Thu Feb 13 15:22:58 2014 jonathan.collinet
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

  void				setMap(const std::map<std::string, std::string> &);
  void				parse_and_push(const char *);
  bool				isKey(std::string &, std::string &);
  int				getFirstPos_of(std::string &, const char) const;

private:
  std::map<std::string, std::string>		_map;

};

#endif
