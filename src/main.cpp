/*
** main.cpp for main in /home/debas_e_elementary/Project/abstract_VM
**
** Made by DEBAS
** Login   <debas_e_elementary@epitech.net>
**
** Started on  Tue Feb 11 23:37:50 2014 DEBAS
// Last update Thu Feb 13 22:24:01 2014 jonathan.collinet
*/

#include "Abstract.hpp"

void	usage()
{
  std::cout << "Usage : ./avm [filename]" << std::endl;
}

int	main(int ac, char *av[])
{
  Abstract a;

  if (ac > 2)
    usage();
  else
    try 
      {
	a.getParser().parse_and_push(av[1]);
      }
    catch (Exception *p)
      {
	std::cerr << p->what() << std::endl;
      }
  return (0);
}
