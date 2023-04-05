#ifndef IMATERIALSOURCE_H
#define IMATERIALSOURCE_H

#include <iostream>
#include <string>
class IMaterialSource
{
public:
	IMaterialSource();
	~IMaterialSource();
   IMaterialSource(const IMaterialSource& src);
   IMaterialSource& operator=(const IMaterialSource& src);
   virtual void learnMateria(AMateria*) = 0;
   virtual AMaterial* createMateria(std::string const & type) = 0;
private:

};

#endif     //IMATERIALSOURCE_H
