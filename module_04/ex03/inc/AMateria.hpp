#ifndef AMATERIA_H
#define AMATERIA_H

#include <iostream>
#include <string>
#include "ICharacter.hpp"
class ICharacter;

class AMateria
{
public:
	AMateria();
   virtual ~AMateria();
   AMateria(const AMateria& src);
   AMateria(std::string const & type);
   AMateria& operator=(const AMateria & src);
   std::string const & getType() const;
   virtual AMateria* clone() const = 0;
   virtual void use(ICharacter & target);
private:

protected:
	std::string type;
};
std::ostream& operator << (std::ostream& os, const AMateria& A);
#endif     //AMATERIA_H
