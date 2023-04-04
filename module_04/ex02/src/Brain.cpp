#include <Brain.hpp>

Brain::Brain()
{
//Const
	std::cout << "A Brain has been created!" << std::endl;
}

Brain::Brain(const Brain& src)
{
//Copy Const
	std::cout << "A Brain has been copied!" << std::endl;
	for (int i=0; i < 100; i++)
		ideas[i] = src.getIdea(1);
}

Brain::~Brain()
{
//Dest
	std::cout << "A Brain has been destroyed!" << std::endl;
}

Brain& Brain::operator = (const Brain& src)
{
	std::cout << "A Brain has been assigned!" << std::endl;
	if (this != &src)
		for (int i=0; i < 100; i++)
			ideas[i] = src.getIdea(i);
	return *this;
}

std::string Brain::getIdea(int pos) const
{
	if (pos >= 0 && pos <= 99)
		return this->ideas[pos];
	else
		return "";
}

void Brain::setIdea(int pos, const std::string& idea)
{
	if (pos >= 0 && pos <= 99 && idea != "")
		ideas[pos] = idea;
}
