#include <Array.hpp>
void leaks(void)
{
	system("leaks ex02");
}

int main(void)
{
	atexit(leaks);

	Array<int> example = Array<int>();
	example.size();
	try
	{
		example[100];
	}
	catch(std::exception& message)
	{
		std::cout << message.what() << std::endl;
	}
	int length = 5;
	Array<std::string> classExample = Array<std::string>(length);
	for (int i = 0 ; i < length; i++)
		classExample[i] = "HelloWorld!";
	for (int i = 0 ; i < length; i++)
		std::cout << classExample[i] << std::endl;
	const Array<std::string> classConst = classExample;
	for (int i = 0 ; i < length; i++)
		std::cout << classConst[i] << std::endl;
}
