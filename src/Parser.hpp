//
// Parser.hpp for parser in /home/debas_e/Project/abstract_VM
//
// Made by Etienne
// Login   <debas_e@epitech.net>
//
// Started on  Sat Feb 22 23:57:05 2014 Etienne
// Last update Fri Feb 28 17:03:59 2014 jonathan.collinet
//

#ifndef PARSER_HH
#define PARSER_HH

#include <vector>
#include <map>
#include <list>
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <limits>
#include "Exception.hpp"
#include "IOperand.hpp"
#include "Memory.hpp"
#include "Instruction.hpp"
#include "OperandFactory.hpp"

#define COMMENT ';'
#define TOKEN_LEFT '('
#define TOKEN_RIGHT ')'

class		Parser {
private:
typedef enum	Lexer
  {
    INSTR,
    INSTR_ARG,
    TYPE,
    VALUE,
    EXIT_PROG
  }		ELexer;

  OperandFactory		factory;

  int				_line_number;
  std::vector<std::string>	argument;
  std::map<std::string, ELexer> _lexer;
  std::map<std::string, eOperandType>  _lexer_type;
  std::stringstream		line_stream;
  std::list<Instruction *>	_instruction;

public:
  Parser();
  bool				isEndIn(const std::string &line) const;
  bool				isCommentLine(const std::string &line) const;
  std::list<Instruction *>	execute(const char *file);
  void				parseLine(std::string &line);
  void				rmComment(std::string &line);
  bool				checkParantheses(const std::string &arg_instr) const;
  void				initLimits(const bool neg);
  void				checkOverflow(const std::string &val, const bool neg, const eOperandType t);
  bool				isValidNumber(const std::string &val, const eOperandType type);
  std::string			formatArgInstr();
  std::string			getInstruction();
  std::string			getValue(const std::string &arg_instr);
  std::string			getOperande();
  std::string			getNextWord();
  void				addInstruction(const std::string &instruction,
					       const std::string &operande = "",
					       const std::string &value = "");
};

#endif
