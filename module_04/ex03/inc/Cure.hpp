#ifndef CURE_H
#define CURE_H

#include <iostream>
#include <string>
#include <AMateria.hpp>
class Cure : public AMateria
{
public:
	Cure();
	virtual ~Cure();
   Cure(const Cure& src);
   Cure& operator=(const Cure& src);
   virtual AMateria* clone() const;
   virtual void use(ICharacter& target);
private:

};

#endif     //CURE_H
