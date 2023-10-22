#include <Base.hpp>

Base::~Base()
{
//Dest
}
Base* generate(void)
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

void identify(Base *p)
{
	bool isIdentify;
	int i = 0;
	do
	{
		switch(i)
		{
			case 0:
				isIdentify = dynamic_cast<A*>(p) != nullptr;
			break;
			case 1:
				isIdentify = dynamic_cast<B*>(p) != nullptr;
			break;
			case 2:
				isIdentify = dynamic_cast<C*>(p) != nullptr;
			break;
		}
		if (isIdentify || i == TOTAL_DERIVED_CLASSES)
			std::cout << outputs[i] << std::endl;
		i++;
	} while(!isIdentify && i <= TOTAL_DERIVED_CLASSES);
}
