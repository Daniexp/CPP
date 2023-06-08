#include <ShrubberyCreationForm.hpp>

/*
ShrubberyCreationForm::ShrubberyCreationForm()
{
//Const
}
*/

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
{
//Copy Const
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
//Dest
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm(target, 137, 145)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator = (const ShrubberyCreationForm& src)
{
//	return AForm::operator=(src);
	if (this != &src)
		setIsSigned(src.getIsSigned());
	return *this;
}

void ShrubberyCreationForm::doAction(const std::string& target) const
{
	//Create a file <target>_shrubbery in the working directory, and writes ASCII trees inside it.
	std::ofstream file;
	std::ifstream asciiTrees[5];
	std::string filenameTree;
	int x = 0, y = 4;
	int random = 0;
	int caracter;

	for (int i=0; i < 5; i++)
	{
		filenameTree = "./AsciiTrees/tree0" + std::to_string(i + 1) + ".txt";
		asciiTrees[i].open(filenameTree.c_str(), std::ifstream::in);
	}
	file.open("./" + target + "_shruberry");
	if (!file.is_open())
	{
		std::cerr << "Couldn't open target_shruberry." << std::endl;
		return ;
	}
	 // Generar una semilla basada en el tiempo actual
  std::srand(static_cast<unsigned int>(std::time(nullptr)));

	for (int i = 0; i < 10; i++)
	{
  		// Generar un número aleatorio en el rango [x, y]
		random  =  x + (std::rand() % (y - x + 1));
		if (asciiTrees[random].is_open())
		{
			while ((caracter = asciiTrees[random].get()) != EOF)
				file.put(caracter);
			asciiTrees[random].clear();
			asciiTrees[random].seekg(0, std::ios::beg);
		}
	}
	file.close();
	for (int i=0; i < 5; i++)
		asciiTrees[i].close();
}

std::string ShrubberyCreationForm::buildTree(int h, char node, char left, char right) const
{
	if (h == 0)
		return "";	
	std::string leftSubtree = buildTree(h-1, node, left, right);
	std::string rightSubtree = buildTree(h-1, node, left, right);
	std::string root = std::string(1, node);
	std::string branch = std::string(1, left) + std::string(h-1, '-') + std::string(1, right);
    return (leftSubtree + branch + rightSubtree + "\n");
}


