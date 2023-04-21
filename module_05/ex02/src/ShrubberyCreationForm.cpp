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
	
}

std::string ShrubberyCreationForm::buildTree(int h, int node, char left, char right)
{
	if (h == 0)
		return "";	
	std::string leftSubtree = buildTree(h-1, node, left, right);
	std::string rightSubtree = buildTree(h-1, node, left, right);
	std::string root = std::string(1, node);
	std::string branch = std::string(1, left) + std::string(h-1, '-') + std::string(1, right);
    return (leftSubtree + branch + rightSubtree);
}
