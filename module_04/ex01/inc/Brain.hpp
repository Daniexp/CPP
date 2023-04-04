#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>
#include <string>
class Brain
{
public:
	Brain();
	~Brain();
   Brain(const Brain& src);
   Brain& operator=(const Brain& src);
   std::string getIdea(int pos) const;
   void	setIdea(int pos, const std::string& idea);
private:
   std::string ideas[100];
};

#endif     //BRAIN_H
