/*
** main.cpp for main in /home/debas_e_elementary/Project/abstract_VM
**
** Made by DEBAS
** Login   <debas_e_elementary@epitech.net>
**
** Started on  Tue Feb 11 23:37:50 2014 DEBAS
// Last update Sun Feb 23 01:53:46 2014 Etienne
*/

#include "Abstract.hpp"
#include "Exception.hpp"
#include <iostream>

void	usage()
{
  std::cout << "Usage : ./avm [filename]" << std::endl;
}

int		main(int ac, char *av[])
{
  Abstract	abstract;
  // std::map<Parser::ELexer, std::string> _values;

  if (ac > 2)
    usage();
  else
    try
      {
	abstract.execute(av[1]);
	// a.getParser().parseOnFlow(av[1]);
      }
    catch (Exception &p)
      {
	std::cerr << "Error : line " << p.where() << " : " << p.what() << std::endl;
      }
  return (0);
}
