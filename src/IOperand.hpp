//
// IOperand.hpp for header in /home/collin_b/project/abstract_vm/abstract_VM
// 
// Made by jonathan.collinet
// Login   <collin_b@epitech.net>
// 
// Started on  Wed Feb 12 11:26:57 2014 jonathan.collinet
// Last update Wed Feb 12 11:30:43 2014 jonathan.collinet
//

#ifndef IOPERAND_HPP_
# define IOPERAND_HPP_

class	IOperand
{
public:
  virtual ~IOperand() {};

  virtual std::string const & toString() const = 0;
  virtual int getPrecision() const = 0;
  virtual eOperantType getType() const = 0;

  virtual IOperand * operator+(const IOperand &rhs) const = 0;
  virtual IOperand * operator-(const IOperand &rhs) const = 0;
  virtual IOperand * operator*(const IOperand &rhs) const = 0;
  virtual IOperand * operator/(const IOperand &rhs) const = 0;
  virtual IOperand * operator%(const IOperand &rhs) const = 0;
};

#endif
