#include <Base.hpp>
#include <A.hpp>
#include <B.hpp>
#include <C.hpp>
void leaks(void)
{
	system("leaks ex02");
}

int main(void)
{
//	atexit(leaks);
	A example;
	B b;
	C c;
	Base baseExample;
	identify(example);
	identify(&example);
	identify(b);
	identify(&b);
	identify(c);
	identify(&c);
	identify(baseExample);
	identify(&baseExample);
}
