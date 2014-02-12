//
// parser.hpp for header in /home/collin_b/project/abstract_vm/abstract_VM/src
// 
// Made by jonathan.collinet
// Login   <collin_b@epitech.net>
// 
// Started on  Wed Feb 12 16:14:47 2014 jonathan.collinet
// Last update Wed Feb 12 18:16:08 2014 jonathan.collinet
//

#ifndef PARSER_HPP_
# define PARSER_HPP_

# include <fstream>
# include <iostream>
# include <string>
# include <map>

class				Parser
{
public:
  Parser();
  ~Parser() {}

  std::map<std::string, 
	   std::string>		getMap() const;
  void				setMap(const std::map<std::string, std::string> &);
  void				parse(const char *);
  bool				isKey(const std::string &) const;
  int				getFirstPos_of(std::string str, char c) const;

private:
  std::map<std::string, std::string>		_map;
};

#endif
