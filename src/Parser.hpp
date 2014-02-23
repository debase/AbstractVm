//
// Parser.hpp for parser in /home/debas_e/Project/abstract_VM
//
// Made by Etienne
// Login   <debas_e@epitech.net>
//
// Started on  Sat Feb 22 23:57:05 2014 Etienne
// Last update Sun Feb 23 16:46:24 2014 Etienne
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
  std::vector<std::string>	argument; //liste d'argument
  std::map<std::string, ELexer> _lexer; //map de mot clé d'intruction
  std::map<std::string, eOperandType>  _lexer_type; //map de type
  std::stringstream		line_stream;
  std::list<Instruction *>	_instruction;
public:
  Parser();
  bool				isEndIn(const std::string &line) const;
  bool				isCommentLine(const std::string line) const;
  std::list<Instruction *>	execute(const char *file);
  void				parseLine(std::string line);
  bool				checkParantheses(const std::string &arg_instr) const;
  bool				isValidNumber(const std::string &val, const eOperandType type);
  std::string			formatArgInstr();
  std::string			getInstruction();
  std::string			getValue(std::string arg_instr);
  std::string			getOperande();
  std::string			getNextWord();
  void				addInstruction(const std::string &instruction,
					       const std::string &operande = "",
					       const std::string &value = "");
};

#endif
