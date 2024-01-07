#include <Array.hpp>
int main(void)
{
	std::cout << "The proyect was created sucessfully." << std::endl;
	Array<int> example = Array<int>();
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
}
