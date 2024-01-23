#include <Serializer.hpp>

void leaks(void)
{
	system("leaks ex01");
}
int main(void)
{
	atexit(leaks);

	Data data;
	uintptr_t convert;
	Data* deserialize;
	data.x = 10;
	data.y = 10;
	convert = Serializer::serialize(&data);
	deserialize = Serializer::deserialize(convert);
	std::cout << "Prev values - x: " << data.x << " y: " << data.y << std::endl;
	std::cout << "Post values - x: " << deserialize->x << " y: " << deserialize->y << std::endl;
	deserialize->x += 10;
	deserialize->y += 10;
	std::cout << "Prev values - x: " << data.x << " y: " << data.y << std::endl;
	std::cout << "Post values - x: " << deserialize->x << " y: " << deserialize->y << std::endl;
}
