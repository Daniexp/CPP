#ifndef EMPTY_H
#define EMPTY_H

#include <iostream>
#include <string>
class Empty
{
public:
	Empty();
	~Empty();
   Empty(const Empty& src);
   Empty& operator=(const Empty& src);
	int getValue();
private:
	int value;
};

#endif     //EMPTY_H
