#include <iostream>
#include <string>
#include <Serializer.hpp>
#include <doctest.h>

struct testData
{
	Data data;
	Data* convertData;
	uintptr_t intData;
};

testData* startTest(void);
void endTest(testData* testData);
void saveValues(int x, int y, testData* arg);
void calcValues(testData* arg);
void calcValues(Data* data);
void checkValues(Data* data, int add, int sub, int mul, int div);
