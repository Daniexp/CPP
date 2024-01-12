#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include <sstream>
#include "MutantStack.hpp"

TEST_CASE("Example Test_Case")
{
	MESSAGE("Example test case is executed successfully...");
}

TEST_CASE("Compare subject main usign MutantStack and list")
{
	MutantStack<int> mstack;
	std::list<int> mslist;
	mstack.push(5);
	mstack.push(17);
	mslist.push_back(5);
	mslist.push_back(17);

	CHECK(mstack.top() == 17);
	CHECK(17 == mslist.back());
	mstack.pop();
	mslist.pop_back();

	CHECK(mstack.size() == 1);
	CHECK(mslist.size() == 1);
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mslist.push_back(3);
	mslist.push_back(5);
	mslist.push_back(737);
//[...]
	mstack.push(0);
	mslist.push_back(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	std::list<int>::iterator itList = mslist.begin();
	std::list<int>::iterator iteList = mslist.begin();
	++it;
	--it;
	++itList;
	--itList;
	while (it != ite && itList != iteList)
	{
		CHECK(*it == *itList);
	++it;
	++itList;
	}
	std::stack<int> s(mstack);
	std::list<int> ss(mslist);
}

TEST_CASE("MutanStack<strings>  and vector")
{
	MutantStack<std::string> mstack;
	std::vector<std::string> mslist;
	mstack.push("primero");
	mstack.push("segundo");
	mslist.push_back("primero");
	mslist.push_back("segundo");

	CHECK(mstack.top() == "segundo");
	CHECK("segundo" == mslist.back());
	mstack.pop();
	mslist.pop_back();

	CHECK(mstack.size() == 1);
	CHECK(mslist.size() == 1);
	mstack.push("tercero");
	mstack.push("cuarto");
	mstack.push("quinto");
	mslist.push_back("tercero");
	mslist.push_back("cuarto");
	mslist.push_back("quinto");
//[...]
	mstack.push("sexto");
	mslist.push_back("sexto");
	MutantStack<std::string>::iterator it = mstack.begin();
	MutantStack<std::string>::iterator ite = mstack.end();
	std::vector<std::string>::iterator itList = mslist.begin();
	std::vector<std::string>::iterator iteList = mslist.begin();
	++it;
	--it;
	++itList;
	--itList;
	while (it != ite && itList != iteList)
	{
		CHECK(*it == *itList);
	++it;
	++itList;
	}
	std::stack<std::string> s(mstack);
	std::vector<std::string> ss(mslist);
}
