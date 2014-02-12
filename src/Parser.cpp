//
// Parser.cpp for cpp in /home/collin_b/project/abstract_vm/abstract_VM/src
// 
// Made by jonathan.collinet
// Login   <collin_b@epitech.net>
// 
// Started on  Wed Feb 12 16:22:07 2014 jonathan.collinet
// Last update Wed Feb 12 18:27:13 2014 jonathan.collinet
//

#include "Parser.hpp"

Parser::Parser()
{
}

int		Parser::getFirstPos_of(std::string str, char c) const
{
  int		i = -1;
  std::string	n = "";

  while (str[++i] == c);
  return (i);
}

bool		Parser::isKey(const std::string &str) const
{
  std::string	key[] = {";", "push", "pop", "dump", "assert", "add","sub", "mul", "div", "mod", "print", "exit", ""};
   int		i = -1;

   while (key[++i] != "")
     if (key[i] == str)
       return (true);
   return (false);
}

std::map<std::string, std::string>		Parser::getMap() const
{
  return (_map);
}

void				Parser::setMap(const std::map<std::string, std::string> &map)
{
  _map = map;
}

void			Parser::parse(const char *file)
{
  if (file)
    {
      std::ifstream	my_file(file);

      if (my_file.is_open())
	{
	  std::string	line = "";
	  std::string	key = "";

	  while (getline(my_file, line))
	    {
	      line = line.erase(0, getFirstPos_of(line, ' '));
	      if (line[0] != ';')
		{
		  key = line.substr(0, line.find(" "));
		  if (key.empty())
		    key = key.substr(0, key.find("\n"));
		  if (isKey(key))
		    std::cout << "good stuff motherfucker !" << std::endl;
		  else
		    std::cout << "Your \"" << key << "\" is bad fucking motherfucker's fucker you are. Bitch." << std::endl;
		}
	    }
	  my_file.close();
	}
      else
	std::cout << "Error : File isn't openable." << std::endl;
    }
}

