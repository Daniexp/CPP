#ifndef IMATERIASOURCE_H
#define IMATERIASOURCE_H

#include <iostream>
#include <string>
#include <AMateria.hpp>
class IMateriaSource
{
public:
	//IMaterialSource();
	virtual ~IMateriaSource();
   //IMaterialSource(const IMaterialSource& src);
   //IMaterialSource& operator=(const IMaterialSource& src);
   virtual void learnMateria(AMateria*) = 0;
   virtual AMateria* createMateria(std::string const & type) = 0;
private:

};

#endif     //IMATERIALSOURCE_H
