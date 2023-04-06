#ifndef MATERIALSOURCE_H
#define MATERIALSOURCE_H

#include <iostream>
#include <string>
#include <IMateriaSource.hpp>
class MateriaSource : public IMateriaSource
{
public:
	MateriaSource();
	virtual ~MateriaSource();
   MateriaSource(const MateriaSource& src);
   MateriaSource& operator=(const MateriaSource& src);
   virtual void learnMateria(AMateria*);
   virtual AMateria* createMateria(std::string const & type);
protected:
	AMateria* materia[4];
	int num_mat;
	std::string materiaName[2];
};

#endif     //MATERIALSOURCE_H
