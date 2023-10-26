#include <Serializer.hpp>

int main(void)
{
	Data data;
	uintptr_t convert;
	Data* deserialize;
	data.x = 10;
	data.y = 10;
	convert = Serializer::serialize(&data);
	deserialize = Serializer::deserialize(convert);
	std::cout << "Prev values - x: " << data.x << " y: " << data.y << std::endl;
	std::cout << "Post values - x: " << deserialize->x << " y: " << deserialize->y << std::endl;
}
