#include <ex00.hpp>
#include <WrongCat.hpp>
#include <WrongAnimal.hpp>
#include <Cat.hpp>
#include <Dog.hpp>
#include <Animal.hpp>
int main(void)
{
 // Animal
    std::cout << "-----Animal-----" << std::endl;
    const Animal* a = new Animal();
    std::cout << "Type: " << a->getType() << std::endl;
    a->makeSound();

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
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << "Type of j: " << j->getType() << std::endl;
    std::cout << "Type of i: " << i->getType() << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    // Polymorphism with references
    std::cout << "-----Polymorphism with references-----" << std::endl;
    const Animal& meta_ref = *meta;
    const Animal& j_ref = *j;
    const Animal& i_ref = *i;
    std::cout << "Type of j_ref: " << j_ref.getType() << std::endl;
    std::cout << "Type of i_ref: " << i_ref.getType() << std::endl;
    i_ref.makeSound();
    j_ref.makeSound();
    meta_ref.makeSound();

    // Deletion of pointers
    delete meta;
    delete j;
    delete i;

    return 0;
}
