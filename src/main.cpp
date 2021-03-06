/*
** main.cpp for main in /home/debas_e_elementary/Project/abstract_VM
**
** Made by DEBAS
** Login   <debas_e_elementary@epitech.net>
**
** Started on  Tue Feb 11 23:37:50 2014 DEBAS
// Last update Fri Feb 28 09:57:22 2014 jonathan.collinet
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

  if (ac > 2)
    usage();
  else
    abstract.execute(av[1]);
  return (0);
}
