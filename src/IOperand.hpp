/*
** IOperand.hpp for ioperand in /home/debas_e_elementary/Project/abstract_VM
**
** Made by DEBAS
** Login   <debas_e_elementary@epitech.net>
**
** Started on  Fri Feb 14 13:14:57 2014 DEBAS
** Last update Fri Feb 14 13:52:46 2014 DEBAS
*/

#ifndef IOPERAND_HPP_
# define IOPERAND_HPP_

#include <string>

enum eOperandType {
  Int8 = 0,
  Int16,
  Int32,
  Float,
  Double
};

class	IOperand
{
public:
  virtual ~IOperand() {};

  virtual std::string const & toString() const = 0;
  virtual int getPrecision() const = 0;
  virtual eOperandType getType() const = 0;

  virtual IOperand * operator+(const IOperand &rhs) const = 0;
  virtual IOperand * operator-(const IOperand &rhs) const = 0;
  virtual IOperand * operator*(const IOperand &rhs) const = 0;
  virtual IOperand * operator/(const IOperand &rhs) const = 0;
  virtual IOperand * operator%(const IOperand &rhs) const = 0;
};

#endif
