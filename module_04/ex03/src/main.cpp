#include <ex03.hpp>
#include <MateriaSource.hpp>
#include <IMateriaSource.hpp>
#include <ICharacter.hpp>
#include <Character.hpp>
#include <Cure.hpp>
#include <Ice.hpp>
#include <AMateria.hpp>

#include <cstdlib>
#include <sstream>
void check_leaks() {
	std::stringstream cmd;
	cmd << "leaks -q ex03";
	std::system(cmd.str().c_str());
}

int main(void)
{
	std::atexit(check_leaks);
 IMateriaSource* src = new MateriaSource();

    // Learning new Materias
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    // Creating a new Character
    ICharacter* me = new Character("me");

    // Equipping Materias
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    // Creating a new Character
    ICharacter* bob = new Character("bob");

    // Using Materias on bob
    me->use(0, *bob);
    me->use(1, *bob);

    // Equipping additional Materias
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);

    // Using Materias on bob and the Character itself
    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *me);
    me->use(3, *me);

    // Trying to equip a Materia in a full inventory slot
    tmp = src->createMateria("cure");
    me->equip(tmp);
	delete(tmp);

    // Trying to use an unexisting Materia slot
    me->use(5, *bob);

    // Unequipping a Materia and using it on bob
	tmp = me->getMateria(0);
    me->unequip(0);
    me->use(0, *bob);
    me->equip(tmp);

    // Cloning a Materia and equipping it
    tmp = me->getMateria(1)->clone();
    //tmp = me->getMateria(1)->clone();
    me->equip(tmp);

    // Creating a new Character and trying to equip a Materia
    ICharacter* alice = new Character("alice");
    tmp = src->createMateria("cure");
    alice->equip(tmp);

    // Deleting objects
    delete alice;
    delete bob;
    delete me;
    delete src;

    return 0;
}
