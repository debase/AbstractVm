/*
** main.cpp for main in /home/debas_e_elementary/Project/abstract_VM
**
** Made by DEBAS
** Login   <debas_e_elementary@epitech.net>
**
** Started on  Tue Feb 11 23:37:50 2014 DEBAS
// Last update Wed Feb 12 22:39:27 2014 jonathan.collinet
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
    {
      try 
	{
	  a.getParser().parse(av[1]);
	}
      catch (ParserException *p)
	{
	  std::cerr << p->what() << std::endl;
	}
    }
  return (0);
}
