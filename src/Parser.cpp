//
// Parser2.cpp for cpp in /home/collin_b/project/abstract_vm/abstract_VM
// 
// Made by jonathan.collinet
// Login   <collin_b@epitech.net>
// 
// Started on  Mon Feb 17 18:44:05 2014 jonathan.collinet
// Last update Tue Feb 18 14:53:49 2014 jonathan.collinet
//

#include "Parser.hpp"

Parser::Parser()
{
  _lexer["exit"] = EXIT_PROG;
  _lexer["pop"] = INSTR;
  _lexer["dump"] = INSTR;
  _lexer["add"] = INSTR;
  _lexer["sub"] = INSTR;
  _lexer["mul"] = INSTR;
  _lexer["div"] = INSTR;
  _lexer["mod"] = INSTR;
  _lexer["print"] = INSTR;
  _lexer["push"] = INSTR_ARG;
  _lexer["assert"] = INSTR_ARG;  
  _lexer["int8"] = TYPE;
  _lexer["int16"] = TYPE;
  _lexer["int32"] = TYPE;
  _lexer["float"] = TYPE;
  _lexer["double"] = TYPE;
  _lexer_type["int8"] = INT8;
  _lexer_type["int16"] = INT16;
  _lexer_type["int32"] = INT32;
  _lexer_type["float"] = FLOAT;
  _lexer_type["double"] = DOUBLE;
  _cur_line = 0;
}

bool			Parser::isNumber(const char &c)
{
  int		i = -1;
  std::string	nbr = "0123456789";

  while (nbr[++i])
    if (c == nbr[i])
      return (true);
  return (false);
}

int			Parser::getLastFirstPos_of(std::string &str, const char c) const
{
  int		i = -1;
  std::string	n = "";

  while (str[++i] == c);
  return (i);
}

std::list<std::string>	Parser::explodeString(const std::string &str, const char c)
{
  int					i = -1;
  std::list<std::string>		l(1, "");
  std::list<std::string>::iterator	it = l.begin();

  l.push_back("");
  while (str[++i])
    {
      if (str[i] != c)
	*it += str[i];
      if (str[i] == c)
	{
	  while (str[i] == c)
	    ++i;
	  --i;
	  l.push_back("");
	  ++it;
	}
    }
  return (l);
}

std::string		Parser::checkType(const std::string &val, EType &type)
{
  size_t		pos = 0;
  std::string		ret = "";

  if ((pos = val.find_first_of("(")) != std::string::npos)
    {
      ret = val.substr(0, pos);
      if (_lexer[ret] != TYPE)
	throw new Exception(std::string("operand isn't exist : \"") + ret + "\"", _cur_line);
      type = _lexer_type[ret];
      return (ret);
    }
  throw new Exception(std::string("open parenthesis \"(\" isn't exist in string \"") + val + "\"", _cur_line);
}

void			Parser::checkOUNderflow(const std::string &val, bool neg, const EType &t)
{
  (void)val;
  (void)neg;
  (void)t;
}

void			Parser::isValidNumber(const std::string &val, const EType &t)
{
  int			i = -1;
  bool			dot = false;
  bool			hnb = false;
  bool			neg = false;

  while (val[++i])
    if (isNumber(val[i]))
      {
	hnb = true;
	if (t < FLOAT)
	  if (dot)
	    throw new Exception(std::string("have a float number in a wrong type : \"") + val + "\"", _cur_line);
      }
    else
      if (val[i] == '.' && !dot && hnb)
	dot = true;
      else if (val[i] == '-' && !neg && !hnb)
	neg = true;
      else
	throw new Exception(std::string("wrong syntaxe number \"") + val + "\"", _cur_line);
  if (t >= FLOAT && !dot)
    throw new Exception(std::string("havn't float number in float type : \"") + val + "\"", _cur_line);
  checkOUNderflow(val, neg, t);
}

std::string		Parser::checkValue(const std::string &val, const EType &t)
{
  std::string		number = "";
  size_t		posl = 0;
  size_t		posr = 0;

  if ((posl = val.find_first_of("(")) != std::string::npos)
    {
      if ((posr = val.find_first_of(")")) != std::string::npos)
	{
	  number = val.substr((posl + 1), posr - (posl + 1));
	  isValidNumber(number, t);
	  return (number);
	}
      throw new Exception(std::string("clone parenthesis \")\" isn't exist in string \"") + val + "\"", _cur_line);
    }
  throw new Exception(std::string("open parenthesis \"(\" isn't exist in string \"") + val + "\"", _cur_line);
}

void			Parser::setValues(const std::string &instr, const std::string &type, const std::string &value)
{
  std::cout << "------------------" << std::endl
	    << instr << std::endl;
  std::cout << type << std::endl;
  std::cout << value << std::endl 
	    << "------------------" << std::endl;
  _values[INSTR] = instr;
  _values[TYPE] = type;
  _values[VALUE] = value;
}

bool			Parser::parseLine(std::string &line)
{
  std::string				ret = "";
  std::string				next_it = "";
  std::list<std::string>		line_parse;
  std::list<std::string>::iterator	it;
  EType					t = ERR;

  line_parse = explodeString(line, ' ');
  it = line_parse.begin();
  if (_lexer[*it] == INSTR)
    setValues(*it, "", "");
  else if (_lexer[*it] == INSTR_ARG)
    {
      next_it = *(++it);
      ret = checkType(next_it, t);
      setValues(*(--it), ret, checkValue(next_it, t));
    }
  else if (_lexer[*it] == EXIT_PROG)
    return (false);
  else
    throw new Exception(std::string("syntax problem : \"" + *it + "\" : isn't a good word."), _cur_line);
  return (true);
}

bool			Parser::checkLine(std::string &line)
{
  if (line[0] != ';' && line != "" && line[0] != '\n')
    if (!parseLine(line))
      return (false);
  return (true);
}

void			Parser::parseFile(const char *file)
{
  std::ifstream		my_file(file);
  std::string		line = "";

  if (my_file.is_open())
    {
      ++_cur_line;
      while (getline(my_file, line))
	{
	  if (!checkLine(line))
	    {
	      std::cout << "Programm exited. Good bye !" << std::endl;
	      return ;
	    }
	  ++_cur_line;
	}
      my_file.close();
    }
  else
    throw new Exception(std::string("cannot open the file : \"") + file + "\".", _cur_line);
}

void			Parser::parseIn()
{
  std::string		all = "";
  std::string		line = "";
  size_t		pos = 0;
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
      _cur_line += first;
      all = all.erase(0, first);
      pos = all.find_first_of("\n");
      line = all.substr(0, pos);
      if (!checkLine(line))
	{
	  std::cout << "Programm exited. Good bye !" << std::endl;
	  return ;
	}
      all = all.erase(0, pos);
    }
}

void			Parser::parseOnFlow(/* Memory m, */ const char *file)
{
  if (file)
    parseFile(file);
  else
    parseIn();
}
