//
// Parser.cpp for cpp in /home/collin_b/project/abstract_vm/abstract_VM/src
// 
// Made by jonathan.collinet
// Login   <collin_b@epitech.net>
// 
// Started on  Wed Feb 12 16:22:07 2014 jonathan.collinet
// Last update Thu Feb 13 16:00:44 2014 jonathan.collinet
//

#include "Parser.hpp"

Parser::Parser()
{
}

// get last pos of c only while is it
int		Parser::getFirstPos_of(std::string &str, const char c) const
{
  int		i = -1;
  std::string	n = "";

  while (str[++i] == c);
  return (i);
}

// init k to the keyword, return true if keyword_line is in key array
bool		Parser::isKey(std::string &str, std::string &k)
{
  std::string	mk = "";
  std::string	key_instr[] = {"pop", "dump", "add","sub", "mul",
			 "div", "mod", "print", "exit", ""};
  std::string	key_arg_instr[] = {"push", "assert", ""};
  std::string	key_arg_value[] = {"int8(", "int16(", "int32(", "float(", "double(", "" };
  size_t	pos = 0;
  int		i = -1, j = -1;

   while (key_arg_instr[++i] != "")
     if ((pos = str.find(key_arg_instr[i])) != std::string::npos)
       {
	 str = str.erase(0, (pos + key_arg_instr[i].size()));
	 if (str.find(" ") == std::string::npos)
	   throw new Exception(std::string("Error : wrong separator. Must be \" \" (space)."));
	 while (key_arg_value[++j] != "")
	   if ((pos = str.find(key_arg_value[j])) != std::string::npos)
	     {
	       str = str.substr(pos, str.size());
	       if ((pos = str.find(")")) != std::string::npos)
		 {
		   str = str.substr(key_arg_value[j].size(), pos - 1);
		   std::cout << "Cool, i want to \""+ key_arg_instr[i] + "\" the type \"" + key_arg_value[j].substr(0, key_arg_value[j].size() - 1) + "\" with number : \"" << str.substr(0, str.size() - 1) << "\"." << std::endl;
		   k = key_arg_instr[i];
		   return (true);
		 }
	       throw new Exception(std::string("Error : brackets not closed. Re-Read your syntax."));
	     }
	 throw new Exception(std::string("Error : \"" + key_arg_instr[i] + "\" must have a valid argument, not like \"" + key_arg_value[j] + "\""));
       }
   i = -1;
   while (key_instr[++i] != "")
     if ((pos = str.find(key_instr[i])) != std::string::npos)
       {
	 k = key_instr[i];
	 std::cout << "Just want to \"" << k << "\"." << std::endl;
	 return (true);
       }
   k = str;
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
void			Parser::parse_and_push(const char *file)
{
  if (file)
    {
      std::ifstream	my_file(file);
      std::string	key = "";

      if (my_file.is_open())
	{
	  std::string	line = "";

	  while (getline(my_file, line))
	    if (line[0] != ';' && line != "")
	      {
		try
		  {
		    if (isKey(line, key))
		      {
		      }
		    else
		      throw new Exception(std::string("Error : " + key + " is not a valid keyword."));
		  }
		catch (Exception *p)
		  {
		    std::cerr << p->what() << std::endl;
		  }
	      }
	  my_file.close();
	}
      else
	throw new Exception(std::string("Error : cannot open the file : \"") + file + "\".");
    }
}
