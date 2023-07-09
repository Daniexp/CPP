#include <test.hpp>

void	 imprimirCentrado(const std::string& message, int maxlen, char fillchar) {
    int messageLength = static_cast<int>(message.length());
    int padding = maxlen - messageLength;
	int leftPadding;
	int rightPadding;

    if (padding <= 0)
        std::cout << message << std::endl;
     else {
        leftPadding = padding / 2;
        rightPadding = padding - leftPadding;

        for (int i = 0; i < leftPadding; ++i)
            std::cout << fillchar;
        std::cout << message;

        for (int i = 0; i < rightPadding; ++i)
            std::cout << fillchar;

        std::cout << std::endl;
    }
}

void	tryCatch(void (*testBureaucratFunction)(void))
{
	int messageLength = 60;
	char fillchar = '-';
	static int countTest = 0;
	

	imprimirCentrado("TEST " + std::to_string(countTest++), messageLength, fillchar); 
	try
	{
		testBureaucratFunction();
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
	}
}
void	tryCatch2(void (*testBureaucratFunction)(AForm *), AForm *formExample)
{
	int messageLength = 60;
	char fillchar = '-';
	static int countTest = 0;
	

	imprimirCentrado("TEST " + std::to_string(countTest++), messageLength, fillchar); 
	try
	{
		testBureaucratFunction(formExample);
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
	}
}
