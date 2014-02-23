//
// Abstract.cpp for cpp in /home/collin_b/project/abstract_vm/abstract_VM/src
//
// Made by jonathan.collinet
// Login   <collin_b@epitech.net>
//
// Started on  Wed Feb 12 16:30:04 2014 jonathan.collinet
// Last update Sun Feb 23 19:19:52 2014 Etienne
//

#include "Abstract.hpp"

Abstract::Abstract() {
  this->memory = new Memory();
  this->parser = new Parser();
  this->cpu = new Cpu(this->memory);
}

Abstract::~Abstract() {
  delete this->memory;
  delete this->parser;
  delete this->cpu;
}

void		Abstract::execute(const char *file) {
  std::list<Instruction *> instruction;

  instruction = parser->execute(file);
  cpu->execute(instruction);
}
