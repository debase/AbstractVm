//
// Parser.cpp for cpp in /home/collin_b/project/abstract_vm/abstract_VM/src
// 
// Made by jonathan.collinet
// Login   <collin_b@epitech.net>
// 
// Started on  Wed Feb 12 16:22:07 2014 jonathan.collinet
// Last update Sun Feb 16 14:29:01 2014 jonathan.collinet
//

#include "Parser.hpp"

Parser::Parser()
{
}

bool		Parser::isNumber(const char &c)
{
  int		i = -1;
  std::string	nbr = "0123456789";

  while (nbr[++i])
    if (c == nbr[i])
      return (true);
  return (false);
}

void		Parser::isValidNumber(const std::string &str, const short &type, int nbline)
{
  int		i = -1;
  bool		hd = false;
  bool		hnad = false;
  std::string	key_arg_value[] = {"int8", "int16", "int32", "float", "double", "" };

  while (str[++i])
    {
      if (!isNumber(str[i]))
	{
	  if (type <= 2)
	    throw new Exception(std::string("\"" + str + "\" isn't a valid number for type " + key_arg_value[type] + "."), nbline);
	  else if (str[i] != '.' && type > 2)
	    throw new Exception(std::string("\"" + str + "\" isn't a valid number or dot for type " + key_arg_value[type] + "."), nbline);
	  else if (str[i] == '.' && type > 2)
	    hd = true;
	}
      else if (hd && type > 2)
	hnad = true;
    }
  if (type > 2 && !hd)
    throw new Exception(std::string("\"" + str + "\" have " + key_arg_value[type] + " type without dot."), nbline);
  else if (type > 2 && hd && !hnad)
    throw new Exception(std::string("\"" + str + "\" have " + key_arg_value[type] + " type without number after dot."), nbline);
}

// get last pos of c only while is it
int		Parser::getLastFirstPos_of(std::string &str, const char c) const
{
  int		i = -1;
  std::string	n = "";

  while (str[++i] == c);
  return (i);
}

void		Parser::getInnerBrackets(size_t pos, std::string &str,
					 const std::string &key_arg_instr,
					 const std::string &key_arg_value,
					 const short &type, 
					 int nbline)
{
  std::string	nbr = "";

  str = str.substr(pos, str.size());
  if ((pos = str.find(")")) != std::string::npos)
    {
      str = str.substr(key_arg_value.size(), pos - 1);
      nbr = str.substr(0, str.size() - 1);
      isValidNumber(nbr, type, nbline);
      std::cout << "Cool, i want to \""+ key_arg_instr + "\" the type \"" 
	+ key_arg_value.substr(0, key_arg_value.size() - 1) + "\" with number : \"" 
		<< nbr << "\"." << std::endl;
      return ;
    }
  throw new Exception(std::string("brackets not closed. Re-Read your syntax."), nbline);
}

void		Parser::parseInstrWithArg(std::string &str, size_t pos, 
					  const std::string &key_arg_instr, int nbline)
{
  std::string	key_arg_value[] = {"int8(", "int16(", "int32(", "float(", "double(", "" };
  int		j = -1;

  str = str.erase(0, (pos + key_arg_instr.size()));
  if (str.find(" ") == std::string::npos)
    throw new Exception(std::string("wrong separator. Must be \" \" (space)."), nbline);
  while (key_arg_value[++j] != "")
    if ((pos = str.find(key_arg_value[j])) != std::string::npos)
      {
	getInnerBrackets(pos, str, key_arg_instr, key_arg_value[j], j, nbline);
	return ;
      }
  throw new Exception(std::string("\"" + key_arg_instr + "\" must have a valid argument, not like \"" + str + "\""), nbline);
}

bool		Parser::isKey(std::string &str, int nbline)
{
  std::string	key_instr[] = {"pop", "dump", "add","sub", "mul", "div", "mod", "print", "exit", ""};
  std::string	key_arg_instr[] = {"push", "assert", ""};
  size_t	pos = 0;
  int		i = -1;

   while (key_arg_instr[++i] != "")
     if ((pos = str.find(key_arg_instr[i])) != std::string::npos)
       {
	 parseInstrWithArg(str, pos, key_arg_instr[i], nbline);
	 return (true);
       }
   i = -1;
   while (key_instr[++i] != "")
     if ((pos = str.find(key_instr[i])) != std::string::npos)
       {
	 std::cout << "Just want to \"" << key_instr[i] << "\"." << std::endl;
	 if (key_instr[i] == "exit")
	   return (false) ;
	 return (true);
       }
   throw new Exception(std::string("\"" + str + "\" is not a valid keyword."), nbline);
}

bool			Parser::checkLine(std::string &line, int nbline)
{
  if (line[0] != ';' && line != "" && line[0] != '\n')
    if (!isKey(line, nbline))
      return (false);
  return (true);
}

void			Parser::parseFile(const char *file)
{
  int			nbline = 1;
  std::ifstream		my_file(file);

  if (my_file.is_open())
    {
      std::string	line = "";
      while (getline(my_file, line))
	{
	  if (!checkLine(line, nbline))
	    {
	      std::cout << "Programm exited. Good bye !" << std::endl;
	      return ;
	    }
	  ++nbline;
	}
      my_file.close();
    }
  else
    throw new Exception(std::string("cannot open the file : \"") + file + "\".", nbline);
}

void			Parser::parseIn()
{
  std::string		all = "";
  std::string		line = "";
  size_t		pos = 0;
  int			nbline = 1;
  int			first = 1;

  getline(std::cin, line, '\n');
  while (line != ";;")
    {
      all += line + "\n";
      getline(std::cin, line, '\n');
    }
  while (all != "")
    {
      if (all[0] == '\n' && all[1] == '\0')
	break;
      first = getLastFirstPos_of(all, '\n');
      nbline += first;
      all = all.erase(0, first);
      pos = all.find_first_of("\n");
      line = all.substr(0, pos);
      if (!checkLine(line, nbline))
	{
	  std::cout << "Programm exited. Good bye !" << std::endl;
	  return ;
	}
      all = all.erase(0, pos);
    }
}

void			Parser::parseAndPush(/* Memory m, */ const char *file)
{
  if (file)
    parseFile(file);
  else
    parseIn();
}
