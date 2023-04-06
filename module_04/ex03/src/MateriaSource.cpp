#include <MateriaSource.hpp>
#include <Ice.hpp>
#include <Cure.hpp>

MateriaSource::MateriaSource()
{
//Const
	num_mat = 0;
	materiaName[0] = "ice";
	materiaName[1] = "cure";
	for (int i=0; i < 4; i++)
		materia[i] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource& src)
{
//Copy Const
	*this = src;
}

MateriaSource::~MateriaSource()
{
//Dest
	std::cout << "Destructor MaterialSource()" << std::endl;
	for (int i=0 ; i < 4 ; i++)
		if (materia[i])
			delete materia[i];
}

MateriaSource& MateriaSource::operator = (const MateriaSource& src)
{
	if (this != &src)
	{
		num_mat = src.num_mat;
		for (int i=0; i < num_mat; i++)
			//materia[i] = src.materia[i]->clone();
			materia[i] = src.materia[i];
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* src)
{
	if (src != nullptr && num_mat < 4)
		materia[num_mat++] = src;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	if (type == "ice")
		return new Ice();
	else if (type == "cure")
		return new Cure();
	return nullptr;
}
