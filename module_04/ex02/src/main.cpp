#include <ex02.hpp>
#include <Brain.hpp>
#include <WrongCat.hpp>
#include <WrongAnimal.hpp>
#include <Cat.hpp>
#include <Dog.hpp>
#include <Animal.hpp>
#include <cstdlib>  // para system
#include <sstream>  // para stringstream

void check_leaks() {
    std::stringstream cmd;
    cmd << "leaks -q ex02";
    std::system(cmd.str().c_str());
}

int main(void)
{
	std::atexit(check_leaks);
/*
 * The class Animal now is not instanciable.
 // Animal
    std::cout << "-----Animal-----" << std::endl;
    const Animal* a = new Animal();
    std::cout << "Type: " << a->getType() << std::endl;
    a->makeSound();
	delete a;
*/

    // Dog
    std::cout << "-----Dog-----" << std::endl;
    const Animal* d = new Dog();
    std::cout << "Type: " << d->getType() << std::endl;
    d->makeSound();
	delete d;

    // Cat
    std::cout << "-----Cat-----" << std::endl;
    const Animal* c = new Cat();
    std::cout << "Type: " << c->getType() << std::endl;
    c->makeSound();
	delete c;

    // WrongAnimal
    std::cout << "-----WrongAnimal-----" << std::endl;
    const WrongAnimal *wa = new WrongAnimal();
    std::cout << "Type: " << wa->getType() << std::endl;
    wa->makeSound();
	delete wa;

    // WrongCat
    std::cout << "-----WrongCat-----" << std::endl;
    const WrongAnimal *wc = new WrongCat();
    std::cout << "Type: " << wc->getType() << std::endl;
    wc->makeSound();
	delete wc;

    // Polymorphism with pointers
    std::cout << "-----Polymorphism with pointers-----" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << "Type of j: " << j->getType() << std::endl;
    std::cout << "Type of i: " << i->getType() << std::endl;
    i->makeSound();
    j->makeSound();

    // Polymorphism with references
    std::cout << "-----Polymorphism with references-----" << std::endl;
    const Animal& j_ref = *j;
    const Animal& i_ref = *i;
    std::cout << "Type of j_ref: " << j_ref.getType() << std::endl;
    std::cout << "Type of i_ref: " << i_ref.getType() << std::endl;
    i_ref.makeSound();
    j_ref.makeSound();

    // Deletion of pointers
    delete j;
    delete i;

	std::cout << "-----Test Brain and deep copy-----" << std::endl;
    const int num_animals = 10;
    Animal* animal_array[num_animals];
    
    for(int i = 0; i < num_animals; i++) {
        if(i % 2 == 0) {
            animal_array[i] = new Dog();
        } else {
            animal_array[i] = new Cat();
        }
    }
    
    for(int i = 0; i < num_animals; i++) {
        delete animal_array[i];
    }
    
    Dog dog1;
    dog1.setIdea(0, "idea1");
    std::cout << "Dog1 type: " << dog1.getType() << std::endl;
    std::cout << "Dog1 idea 0: " << dog1.getIdea(0) << std::endl;
    
    Dog dog2(dog1);
    dog2.setIdea(0, "idea2");
    std::cout << "Dog2 type: " << dog2.getType() << std::endl;
    std::cout << "Dog2 idea 0: " << dog2.getIdea(0) << std::endl;
    std::cout << "Dog1 idea 0: " << dog1.getIdea(0) << std::endl;
    return 0;
}
