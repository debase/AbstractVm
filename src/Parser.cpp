//
// Parser2.cpp for cpp in /home/collin_b/project/abstract_vm/abstract_VM
// 
// Made by jonathan.collinet
// Login   <collin_b@epitech.net>
// 
// Started on  Mon Feb 17 18:44:05 2014 jonathan.collinet
// Last update Fri Feb 21 15:20:15 2014 jonathan.collinet
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
  _lexer["("] = P_LEFT;
  _lexer[")"] = P_RIGHT;
  _lexer_type["int8"] = INT8;
  _lexer_type["int16"] = INT16;
  _lexer_type["int32"] = INT32;
  _lexer_type["float"] = FLOAT;
  _lexer_type["double"] = DOUBLE;
  _get_sum_nf[INT8] = std::numeric_limits<char>::max();
  _get_sum_nf[INT16] = std::numeric_limits<short>::max();
  _get_sum_nf[INT32] = std::numeric_limits<int>::max();
  _get_sum_f[FLOAT] = std::numeric_limits<float>::max();
  _get_sum_f[DOUBLE] = std::numeric_limits<double>::max();
  _cur_line = 0;
  _p_left = false;
  _p_right = false;
  _min_one = false;
}

std::map<Parser::ELexer, std::string>	Parser::getValues()
{
  return (_values);
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
    if (str[i] != c)
      *it += str[i];
    else
      {
	while (str[i] == c)
	  ++i;
	--i;
	l.push_back("");
	++it;
      }
  l.push_back("");
  return (l);
}

std::string		Parser::parseType(const std::string &val, EType &type)
{
  if (_lexer[val] != TYPE)
    throw new BadOperand(val, _cur_line);
  type = _lexer_type[val];
  return (val);
}

std::string		Parser::checkType(std::string &val, EType &type, std::list<std::string>::iterator &it)
{
  size_t		pos = 0;
  std::string		ret = "";

  if ((pos = val.find_first_of("(")) != std::string::npos)
    {
      _p_left = true;
      ret = parseType(val.substr(0, pos), type);
      if (val[pos + 1] == '\0')
	val = *(++it);
      return (ret);
    }
  else if (_lexer[val] == TYPE)
    {
      ret = parseType(val, type);
      val = *(++it);
      return (ret);
    }
  else
    throw new BadOperand(val, _cur_line);
}

unsigned int		getSumAsciiOf(const std::string &val)
{
  int			i = -1;
  unsigned int		sum = 0;

  while (val[++i])
    sum += ((unsigned int)val[i]);
  return (sum);
}

void			Parser::checkNonFloatantOverflow(const std::string &val, const bool &neg, const EType &t)
{
  unsigned int	ascii_sum = _get_sum_nf[t];
  std::string	max_val_str;
  std::stringstream	str_s;

  if (neg)
    ascii_sum = ((ascii_sum * -1) - 1);
  str_s << ascii_sum;
  str_s >> max_val_str;
  if (getSumAsciiOf(max_val_str) < getSumAsciiOf(val) && !neg)
    throw new Overflow(val, _cur_line);
  else if (getSumAsciiOf(max_val_str) < getSumAsciiOf(val))
    throw new Underflow(val, _cur_line);
}

void			Parser::checkFloatantOverflow(const std::string &val, const bool &neg, const EType &t)
{
  if (t == FLOAT)
    {
      float		f = 0.0;
      float		f1 = 0.0;
      std::string	str = "";
      std::stringstream	str_f;
      std::stringstream	str_f1;

      str_f << val;
      str_f >> f;
      std::cout << "f : " << f << std::endl;
      str_f1 << f;
      str_f1 >> f1;
      std::cout << "f1 : " <<  f1 << std::endl;
      std::cout <<  "str : " << str_f1.str() << std::endl;
      if (f != f1)
	throw new Overflow(val, _cur_line);
    }
  else
    {
    }
}

void			Parser::checkOverflow(const std::string &val, const bool &neg, const EType &t)
{
  unsigned int	ascii_sum_nf = 0;
  double       	ascii_sum_f = 0.0;
  std::string	max_val_str = "";
  std::stringstream	str_s;

  (t < FLOAT) ? (ascii_sum_nf = _get_sum_nf[t]) : (ascii_sum_f = _get_sum_f[t]);
  if (t < FLOAT)
    {
      //      std::cout << _get_sum_nf[t] << std::endl;
      if (neg)
	ascii_sum_nf = ((ascii_sum_nf * -1) - 1);
      str_s << ascii_sum_nf;
      str_s >> max_val_str;
      //std::cout << max_val_str << std::endl;
      if (getSumAsciiOf(max_val_str) < getSumAsciiOf(val) && !neg)
	throw new Overflow(val, _cur_line);
      else if (getSumAsciiOf(max_val_str) < getSumAsciiOf(val))
	throw new Underflow(val, _cur_line);
    }
  else
    {
      if (neg)
	ascii_sum_f = ((ascii_sum_f * -1) - 1);
      str_s << std::setprecision(200) << ascii_sum_f;
      str_s >> max_val_str;
      //std::cout << max_val_str << std::endl;
      //std::cout << val << std::endl;
      if (getSumAsciiOf(max_val_str) < getSumAsciiOf(val) && !neg)
	throw new Overflow(val, _cur_line);
      else if (getSumAsciiOf(max_val_str) < getSumAsciiOf(val))
	throw new Underflow(val, _cur_line);
    }
}

void			Parser::isValidNumber(const std::string &val, const EType &t)
{
  int			i = -1;
  bool			dot = false;
  bool			hnb = false;
  bool			hnbad = false;
  bool			neg = false;

  if (val == "")
    throw new NullValue("", _cur_line);
  while (val[++i])
    if (isNumber(val[i]))
      {
	hnb = true;
	if (t < FLOAT && dot)
	  throw new BadNumber(val, _cur_line);
	if (dot && !hnbad)
	  hnbad = true;
      }
    else
      if (val[i] == '.' && !dot && hnb)
	dot = true;
      else if (val[i] == '-' && !neg && !hnb)
	neg = true;
      else
	throw new BadNumber(val, _cur_line);
  if (t >= FLOAT && !dot)
    throw new BadFloatNumber(val, _cur_line);
  if (dot && !hnbad)
    throw new BadFloatNumber(val, _cur_line);
  checkOverflow(val, neg, t);
}

std::string		Parser::checkValidValue(std::string &val, const EType &t, size_t &posl)
{
  std::string		number = "";
  size_t		posr = 0;

  if ((posr = val.find_first_of(")")) != std::string::npos)
    {
      _p_right = true;
      number = val.substr((posl + 1), posr - (posl + 1));
      isValidNumber(number, t);
      return (number);
    }
  else
    {
      val = val.erase(0, posl + 1);
      isValidNumber(val, t);
      return (val);
    }
}

std::string		Parser::checkValue(std::string &val, const EType &t)
{
  size_t		posl = 0;

  if ((posl = val.find_first_of("(")) != std::string::npos)
    {
      _p_left = true;
      return (checkValidValue(val, t, posl));
    }
  else
    return (checkValidValue(val, t, posl));
}

void			Parser::parseInstrWithArg(std::list<std::string>::iterator it)
{
  std::string				next_it = "";
  EType					t = ERR;

  _min_one = true;
  _values[INSTR] = *it;
  next_it = *(++it);
  _values[TYPE] = checkType(next_it, t, it);
  if (_lexer[next_it] == P_LEFT)
    {
      _p_left = true;
      next_it = *(++it);
    }
  else if (_lexer[*(++it)] == P_RIGHT)
    _p_right = true;
  _values[VALUE] = checkValue(next_it, t);
  if (_lexer[*(++it)] == P_RIGHT)
    _p_right = true;
}

bool			Parser::parseLine(std::string &line)
{
  std::string				ret = "";
  std::list<std::string>		line_parse;
  std::list<std::string>::iterator	it;

  line_parse = explodeString(line, ' ');
  it = line_parse.begin();
  if (*it == "")
    return (true);
  if (_lexer[*it] == INSTR)
    _values[INSTR] = *it;
  else if (_lexer[*it] == INSTR_ARG)
    parseInstrWithArg(it);
  else if (_lexer[*it] == EXIT_PROG)
    return (false);
  else
    throw new BadInstr(*it, _cur_line);
  return (true);
}

bool			Parser::checkLine(std::string &line)
{
  if (line[0] != ';' && line != "" && line[0] != '\n')
    if (!parseLine(line))
      return (false);
  return (true);
}

void			Parser::reinitValues()
{
  _values[INSTR] = "";
  _values[TYPE] = "";
  _values[VALUE] = "";
  _p_left = false;
  _p_right = false;
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
	  std::cout << "line : \""+line+"\"" << std::endl;
	  if (!_p_right && _values[VALUE] != "")
	    throw new LeftClosedParth(line, _cur_line);

	  // debug a degager
	  std::cout << "Instruction : \""+_values[Parser::INSTR] << "\"" << std::endl;
	  	  std::cout << "Type : \""+_values[Parser::TYPE] << "\""<< std::endl;
	  	  std::cout << "Value : \""+_values[Parser::VALUE] << "\"" << std::endl;

	  reinitValues();
	  ++_cur_line;
	}
      if (!_min_one)
	throw new FileEmpty(file, _cur_line);
      my_file.close();
    }
  else
    throw new FileNotOpened(file, _cur_line);
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
