//
// Parser.cpp for parser in /home/debas_e/Project/abstract_VM
//
// Made by Etienne
// Login   <debas_e@epitech.net>
//
// Started on  Sun Feb 23 01:05:27 2014 Etienne
// Last update Fri Feb 28 17:01:10 2014 jonathan.collinet
//

#include "Parser.hpp"

Parser::Parser()
{
  _line_number = 0;
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

  _lexer_type["int8"] = Int8;
  _lexer_type["int16"] = Int16;
  _lexer_type["int32"] = Int32;
  _lexer_type["float"] = Float;
  _lexer_type["double"] = Double;

}

void                    Parser::addInstruction(const std::string &instruction,
                                               const std::string &operande,
                                               const std::string &value)
{
  IOperand              *new_ioperand = NULL;
  Instruction           *new_instru = NULL;
  eOperandType          type;

  type = _lexer_type[operande];
  if (value != "")
    new_ioperand = factory.createOperand(type, value);
  new_instru = new Instruction(new_ioperand, instruction, _line_number);
  _instruction.push_back(new_instru);
}

bool			Parser::isEndIn(const std::string &line) const
{
  std::stringstream	ss(line);
  std::string		tmp;

  ss >> tmp;
  if ((tmp.find(";;") == 0) && (tmp.size() == 2))
    return true;
  return false;
}

std::string		Parser::getNextWord()
{
  std::string		word;

  line_stream >> word;
  return word;
}

std::string		Parser::getInstruction()
{
  std::string		instr;

  line_stream >> instr;
  if (_lexer.find(instr) == _lexer.end())
    throw BadInstr(instr, _line_number);
  return instr;
}

bool			Parser::isCommentLine(const std::string &line) const
{
  std::stringstream	ss(line);
  std::string		word;

  ss >> word;
  if (word[0] == COMMENT || word == "")
    return true;
  return false;
}

bool			Parser::checkParantheses(const std::string &format) const
{
  size_t		first;
  size_t		second;

  if (std::count(format.begin(), format.end(), TOKEN_LEFT)
      + std::count(format.begin(), format.end(), TOKEN_RIGHT) > 2)
    throw ParenthesisError(format, _line_number);
  first = format.find(TOKEN_LEFT);
  second = format.find(TOKEN_RIGHT);
  if (first == std::string::npos
      ||second == std::string::npos || first > second
      || first + 1 == second)
    return false;
  return true;
}

std::string			Parser::formatArgInstr()
{
  std::string		tmp;
  std::string		format;
  std::string		withoutPar;

  while (line_stream >> tmp)
    format += tmp;
  format.erase(std::remove(format.begin(), format.end(), ' '), format.end());
  format.erase(std::remove(format.begin(), format.end(), '\t'), format.end());
  line_stream.clear();
  line_stream << format;
  line_stream >> format;
  if (checkParantheses(format) == false)
    throw ParenthesisError(format, _line_number);
  withoutPar = format;
  std::replace(withoutPar.begin(), withoutPar.end(), TOKEN_LEFT, ' ');
  std::replace(withoutPar.begin(), withoutPar.end(), TOKEN_RIGHT, ' ');
  line_stream.clear();
  line_stream << withoutPar;
  return format;
}

std::string		Parser::getOperande()
{
  std::string		op;

  op = getNextWord();
  if (_lexer_type.find(op) == _lexer_type.end())
    throw BadOperand(op, _line_number);
  return op;
}

bool                    Parser::isValidNumber(const std::string &val, const eOperandType type)
{
  int			i = 0;
  bool                  dot = false;
  std::string		number;

  if (val[i] == '-')
    {
      i++;
    }
  number = val.substr(i, val.size());
  if (number == "")
    throw NullValue(val, _line_number);
  for (size_t j = 0 ; number[j] ; j++)
    if (number[j] == '.')
      {
	if (type < Float)
	  throw BadFloatNumber(val, _line_number);
	else if (type >= Float && (dot == true || j == number.size() - 1 || j == 0))
	  throw BadFloatNumber(val, _line_number);
	else
	  dot = true;
      }
    else if (std::isdigit(number[j]) == false)
      return false;
  return true;
}

std::string		Parser::getValue(const std::string &operande)
{
  std::string		value;

  value = getNextWord();
  if (isValidNumber(value, _lexer_type[operande]) == false)
    throw BadNumber(value, _line_number);
  return value;
}

void			Parser::rmComment(std::string &line)
{
  size_t		pos;

  pos = line.find_first_of(COMMENT);
  if (pos != std::string::npos)
    line = line.substr(0, pos);
}

void			Parser::parseLine(std::string &line)
{
  std::string		instr = "";
  std::string		arg_instr;
  std::string		operande = "";
  std::string		value = "";
  std::string		tmp;

  if (isCommentLine(line) == false)
    {
      rmComment(line);
      line_stream << line;
      instr = getInstruction();
      if (_lexer[instr] == INSTR_ARG)
	{
	  arg_instr = formatArgInstr();
	  operande = getOperande();
	  value = getValue(operande);
	}
      if (line_stream >> tmp)
	throw SyntaxError(tmp, _line_number);
      addInstruction(instr, operande, value);
    }
  line_stream.clear();
}

std::list<Instruction *>	Parser::execute(const char *file)
{
  std::string			cur_line;

  if (file == NULL)
    {
      std::vector<std::string>::iterator it;
      std::vector<std::string>	vec;

      while (1)
	{
	  getline(std::cin, cur_line, '\n');
	  if (isEndIn(cur_line) == true)
	    break;
	  vec.push_back(cur_line);
	}
      for (it = vec.begin() ; it != vec.end() ; it++)
	{
	  _line_number++;
	  parseLine(*it);
	}
    }
  else
    {
      std::ifstream	input(file);

      if (input.is_open())
	while (getline(input, cur_line, '\n'))
	  {
	    _line_number++;
	    parseLine(cur_line);
	  }
      else
	throw FileNotOpened(file, _line_number);
    }
  return _instruction;
}
