#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#include <iostream>
#include <string>
#include <IMateriaSource.hpp>
#include <AMateria.hpp>
class MateriaSource : public IMateriaSource
{
public:
	MateriaSource();
	virtual ~MateriaSource();
   MateriaSource(const MateriaSource& src);
   MateriaSource& operator=(const MateriaSource& src);
   virtual void learnMateria(AMateria* src);
   virtual AMateria* createMateria(std::string const & type);
protected:
	AMateria* materia[4];
	int num_mat;
	std::string materiaName[2];
};

#endif     //MATERIALSOURCE_H
