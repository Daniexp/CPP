#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <iostream>
#include <sstream>
#include <PmergeMe.hpp>
#include <exception>
#include <stdexcept>
#include <cstring>
#define minNmb 1
#define maxNmb 10000
#define oddLength 3000
#define evenLength 3001

static std::string error = "Error: invalid positive integer \"";

vector generateInput(int min, int max, bool repeat)
{
	vector input;
	int length;

	if (min == max)
		length = min;
	else
		length = rand() % (max- min + 1) + min; 
	if (repeat == true)
		for (int i = 0; i < length; i++)
			input.push_back(rand() % (maxNmb - minNmb + 1) + minNmb);
	else
		for (int i = 0; i < length; i++)
		{
			input.push_back(i);
			std::random_shuffle(input.begin(), input.end());
		}
	return input;
}


void test_invalid_sequence(const char* argv[], std::string error) {
    try {
    	PmergeMe obj(const_cast<char**>(argv));
        obj.shortContainersWithTimers();
        CHECK(false); // This should not be reached if an exception is thrown
    } catch (const std::exception& e) {
        CHECK(std::string(e.what()) == error);
        //CHECK(strcmp(e.what(), error) == 0);
    }
}

void test_valid_sequence(const char* argv[]) {                                   
    try {                                                                        
    	PmergeMe obj(const_cast<char**>(argv));                                      
        obj.shortContainersWithTimers();                                         
        const std::vector<unsigned int>& container = obj.getFirstContainer();
        const std::list<unsigned int>& container2 = obj.getSecondContainer();
        
        // Check if the container is sorted
        bool is_sorted = std::is_sorted(container.begin(), container.end());
        CHECK(is_sorted); // This should be true if the container is sorted
        is_sorted = std::is_sorted(container2.begin(), container2.end());
        CHECK(is_sorted); // This should be true if the container is sorted
    } catch (const std::exception& e) {                                          
        CHECK(false); // This should not be reached if an exception is not thrown
    }                                                                            
} 

void test_valid_sequence(vector& argv) {                                   
    try {                                                                        
    	PmergeMe obj(argv);                                      
        obj.shortContainersWithTimers();
        const std::vector<unsigned int>& container = obj.getFirstContainer();
        const std::list<unsigned int>& container2 = obj.getSecondContainer();
        
        // Check if the container is sorted
        bool is_sorted = std::is_sorted(container.begin(), container.end());
        CHECK(is_sorted); // This should be true if the container is sorted
        is_sorted = std::is_sorted(container2.begin(), container2.end());
        CHECK(is_sorted); // This should be true if the container is sorted
    } catch (const std::exception& e) {                                          
        CHECK(false); // This should not be reached if an exception is not thrown
    }                                                                            
} 

TEST_CASE("Short valid integer sequence")
{
    const char* argv[] = {"99", "23424", "01", "11", "11", "89724", "891238427", "500", NULL};
    test_valid_sequence(argv);
}

TEST_CASE("Invalid - sequence with nmb > max_int") {
    const char* argv[] = {"999999999999999999999999999999", NULL};
    test_invalid_sequence(argv, error + "999999999999999999999999999999\"");
}

TEST_CASE("Invalid - sequence with negative int") {
    const char* argv[] = {"-1", "2", "3", NULL};
    test_invalid_sequence(argv, error + "-1\"");
}

TEST_CASE("Invalid - sequence with double value") {
    const char* argv[] = {"1.5", "2", "3", NULL};
    test_invalid_sequence(argv, error + "1.5\"");
}

TEST_CASE("Invalid - sequence with float value") {
    const char* argv[] = {"1.0f", "2", "3", NULL};
    test_invalid_sequence(argv, error + "1.0f\"");
}

TEST_CASE("Invalid - sequence with 'aaa98983'") {
    const char* argv[] = {"aaa98983", NULL};
    test_invalid_sequence(argv, error + "aaa98983\"");
}

TEST_CASE("Invalid - sequence with '98983$·$&)'") {
    const char* argv[] = {"98983$·$&)", NULL};
    test_invalid_sequence(argv, error + "98983$·$&)\"");
}

TEST_CASE("Invalid - sequence with 'dsjiowe'") {
    const char* argv[] = {"dsjiowe", NULL};
    test_invalid_sequence(argv, error + "dsjiowe\"");
}

TEST_CASE("Invalid - sequence with 'A'") {
    const char* argv[] = {"A", NULL};
    test_invalid_sequence(argv, error + "A\"");
}

TEST_CASE("Invalid - sequence with '-10'") {
    const char* argv[] = {"-10", NULL};
    test_invalid_sequence(argv, error + "-10\"");
}

TEST_CASE("Invalid - sequence with '87e'") {
    const char* argv[] = {"87e", NULL};
    test_invalid_sequence(argv, error + "87e\"");
}

TEST_CASE("Short - even sequence with no repeats")
{
	vector input = generateInput(evenLength, evenLength, false);
	test_valid_sequence(input);
}
TEST_CASE("Short - odd sequence with no repeats")
{
	vector input = generateInput(oddLength, oddLength, false);
	test_valid_sequence(input);
}
TEST_CASE("Short - even sequence with two ocurrences of the same integer")
{
	vector input = generateInput(evenLength, evenLength, true);
	test_valid_sequence(input);
}
TEST_CASE("Short - odd sequence with only repeated characters")
{
	vector input = generateInput(oddLength, oddLength, true);
	test_valid_sequence(input);
}
/* other usefull tests
TEST_CASE("Short - even sequence with two ocurrences of the same integer")
{
}
TEST_CASE("Short - odd sequence with only repeated characters")
{
	vector input = generateInput(oddLength, oddLength, true);
	test_valid_sequence(input);
}

*/
