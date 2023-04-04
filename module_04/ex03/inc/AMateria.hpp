#ifndef AMATERIA_H
#define AMATERIA_H

#include <iostream>
#include <string>
class AMateria
{
public:
	AMateria();
	~AMateria();
   AMateria(const AMateria& src);
   AMateria(std::string const & type);
   AMateria& operator=(const AMateria& src);
   std::string const & getType() const;
   virtual AMateria* clone() const = 0;
   virtual void use(ICharacter& target);
private:

protected:

};

#endif     //AMATERIA_H
