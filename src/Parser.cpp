//
// Parser.cpp for cpp in /home/collin_b/project/abstract_vm/abstract_VM/src
// 
// Made by jonathan.collinet
// Login   <collin_b@epitech.net>
// 
// Started on  Wed Feb 12 16:22:07 2014 jonathan.collinet
// Last update Thu Feb 13 22:56:30 2014 jonathan.collinet
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

void		Parser::getInnerBrackets(size_t pos, std::string &str, 
					 const std::string &key_arg_instr,  
					 const std::string &key_arg_value)
{
  str = str.substr(pos, str.size());
  if ((pos = str.find(")")) != std::string::npos)
    {
      str = str.substr(key_arg_value.size(), pos - 1);
      std::cout << "Cool, i want to \""+ key_arg_instr + "\" the type \"" + key_arg_value.substr(0, key_arg_value.size() - 1) + "\" with number : \"" << str.substr(0, str.size() - 1) << "\"." << std::endl;
      return ;
    }
  throw new Exception(std::string("Error : brackets not closed. Re-Read your syntax."));
}

void		Parser::parseInstrWithArg(std::string &str, size_t pos, 
					  const std::string &key_arg_instr)
{
  std::string	key_arg_value[] = {"int8(", "int16(", "int32(", "float(", "double(", "" };
  int		j = -1;

  str = str.erase(0, (pos + key_arg_instr.size()));
  if (str.find(" ") == std::string::npos)
    throw new Exception(std::string("Error : wrong separator. Must be \" \" (space)."));
  while (key_arg_value[++j] != "")
    if ((pos = str.find(key_arg_value[j])) != std::string::npos)
      {
	getInnerBrackets(pos, str, key_arg_instr, key_arg_value[j]);
	return ;
      }
  throw new Exception(std::string("Error : \"" + key_arg_instr + "\" must have a valid argument, not like \"" + key_arg_value[j] + "\""));
}

void		Parser::isKey(std::string &str)
{
  std::string	key_instr[] = {"pop", "dump", "add","sub", "mul",
			 "div", "mod", "print", "exit", ""};
  std::string	key_arg_instr[] = {"push", "assert", ""};
  size_t	pos = 0;
  int		i = -1;

   while (key_arg_instr[++i] != "")
     if ((pos = str.find(key_arg_instr[i])) != std::string::npos)
       {
	 parseInstrWithArg(str, pos, key_arg_instr[i]);
	 return ;
       }
   i = -1;
   while (key_instr[++i] != "")
     if ((pos = str.find(key_instr[i])) != std::string::npos)
       {
	 std::cout << "Just want to \"" << key_instr[i] << "\"." << std::endl;
	 if (key_instr[i] == "exit")
	   throw new Exception(std::string("Programm Exited."));
	 return ;
       }
   throw new Exception(std::string("Error : " + str + " is not a valid keyword."));
}

void			Parser::checkLine(std::string &line)
{
  if (line[0] != ';' && line != "")
    isKey(line);
}

void			Parser::parseFile(const char *file)
{
  std::ifstream	my_file(file);
  if (my_file.is_open())
    {
      std::string	line = "";
      while (getline(my_file, line))
	checkLine(line);
      my_file.close();
    }
  else
    throw new Exception(std::string("Error : cannot open the file : \"") + file + "\".");
}

void			Parser::parseIn()
{
  std::string		line = "";

  while (1)
    {
      std::cin >> line;
      if (line != ";;")
	checkLine(line);
      else
	throw new Exception(std::string("Programm Exited."));
    }
}

void			Parser::parseAndPush(/* Memory m, */ const char *file)
{
  if (file)
    parseFile(file);
  else
    parseIn();
}
