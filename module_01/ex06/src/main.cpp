#include <ex06.hpp>
#include <HarlF.hpp>
int main(void)
{
	std::string tags[5] = {"DEBUG", "INFO", "WARNING", "ERROR", "badtag"};
	HarlF	harlfilter;
	int tag = 0;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(0, 4);
	for (int i=0; i < 10; i++)
	{
		tag = dist(gen);
		std::cout << "The tag generate is: " << tags[tag] << std::endl;
		harlfilter.complain(tags[tag]);
	}
}
