#ifndef ICE_H
#define ICE_H

#include <iostream>
#include <string>
#include <AMateria.hpp>
class Ice : public AMateria
{
public:
	Ice();
	virtual ~Ice();
   Ice(const Ice& src);
   Ice& operator=(const Ice& src);
   virtual AMateria* clone() const;
   virtual void use(ICharacter& target);
private:

};

#endif     //ICE_H
