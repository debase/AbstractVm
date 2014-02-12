//
// Parser.cpp for cpp in /home/collin_b/project/abstract_vm/abstract_VM/src
// 
// Made by jonathan.collinet
// Login   <collin_b@epitech.net>
// 
// Started on  Wed Feb 12 16:22:07 2014 jonathan.collinet
// Last update Wed Feb 12 23:18:00 2014 jonathan.collinet
//

#include "Parser.hpp"

Parser::Parser()
{
}

ParserException::ParserException(std::string message) throw()
{
  _message = message;
}

ParserException::~ParserException() throw()
{
}

const char*	ParserException::what() const throw()
{
  return (_message.c_str());
}

// get last pos of c only while is it
int		Parser::getFirstPos_of(std::string str, char c) const
{
  int		i = -1;
  std::string	n = "";

  while (str[++i] == c);
  return (i);
}

// init k to the keyword, return true if keyword_line is in key array
bool		Parser::isKey(const std::string &str, std::string &k)
{
  std::string	mk = "";
  std::string	key[] = {";", "push", "pop", "dump", "assert",
			 "add","sub", "mul", "div", "mod", "print", "exit", ""};
   int		i = -1;

   mk = str.substr(0, str.find(" "));
   if (mk.empty())
     mk = str.substr(0, str.find("\n"));
   if (mk.empty())
     return (false);
   while (key[++i] != "")
     if (key[i] == mk)
       {
	 k = mk;
	 return (true);
       }
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

// not finished
void			Parser::parse(const char *file)
{
  if (file)
    {
      std::ifstream	my_file(file);
      std::string	key = "";

      if (my_file.is_open())
	{
	  std::string	line = "";

	  while (getline(my_file, line))
	    {
	      if (line[0] != ';' && line != "")
		{
		  if (isKey(line, key))
		    {
		      std::cout << "olol" << std::endl;
		    }
		  else
		    {
		      throw new ParserException(std::string("Error : " + key + " is not a valid keyword."));
		    }
		}
	    }
	  my_file.close();
	}
      else
	throw new ParserException(std::string("Error : cannot open the file : \"") + file + "\".");
    }
}

