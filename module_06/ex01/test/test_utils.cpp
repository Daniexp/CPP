#include <test.hpp>

testData* startTest(void)
{
	testData* testData = new (struct testData);
	testData->data.x = 0;
	testData->data.y = 0;
	testData->data.add = 0;
	testData->data.sub = 0;
	testData->data.div = 0;
	testData->data.mul = 0;
	testData->intData = Serializer::serialize(&testData->data);
	testData->convertData = Serializer::deserialize(testData->intData);
	return testData;
}

void endTest(testData* testData)
{
	delete testData;
}

void saveValues(int x, int y, testData* arg)
{
	arg->data.x = x;
	arg->data.y = y;
}

void calcValues(testData* arg)
{
	arg->data.add = arg->data.x + arg->data.y;
	arg->data.sub = arg->data.x - arg->data.y;
	arg->data.mul = arg->data.x * arg->data.y;
	arg->data.div = arg->data.x / arg->data.y;
}

void calcValues(Data* data)
{
	data->add = data->x + data->y;
	data->sub = data->x - data->y;
	data->mul = data->x * data->y;
	data->div = data->x / data->y;
}

void checkValues(Data* data, int add, int sub, int mul, int div)
{
	CHECK(data->add == add);
	CHECK(data->sub == sub);
	CHECK(data->mul == mul);
	CHECK(data->div == div);
}
