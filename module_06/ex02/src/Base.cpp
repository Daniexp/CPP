#include <Base.hpp>


Base::~Base()
{
//Dest
}
Base* Base::generate(void)
{
	Base* randomClass;
	srand(time(NULL));
	int randomNumber = 1 + rand() % (TOTAL_DERIVED_CLASSES - 1); 	
	switch (randomNumber)
	{
		case 1:
			randomClass = dynamic_cast<Base*>(new A());
		case 2:
			randomClass = dynamic_cast<Base*>(new B());
		case 3:
			randomClass = dynamic_cast<Base*>(new C());
	}
	return randomClass;
}
