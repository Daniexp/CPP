#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <iostream>
#include <sstream>
#include <PmergeMe.hpp>
#include <exception>
#include <stdexcept>
#include <cstring>

void test_invalid_sequence(const char* argv[]) {
    PmergeMe obj(const_cast<char**>(argv));
    try {
        obj.shortContainersWithTimers();
        CHECK(false); // This should not be reached if an exception is thrown
    } catch (const std::exception& e) {
        CHECK(strcmp(e.what(), "ERROR") == 0);
    }
}
void test_valid_sequence(const char* argv[]) {                                   
    PmergeMe obj(const_cast<char**>(argv));                                      
    try {                                                                        
        obj.shortContainersWithTimers();                                         
        const std::vector<unsigned int>& container = obj.getFirstContainer();
        
        // Check if the container is sorted
        bool is_sorted = std::is_sorted(container.begin(), container.end());
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
    test_invalid_sequence(argv);
}

TEST_CASE("Invalid - sequence with negative int") {
    const char* argv[] = {"-1", "2", "3", NULL};
    test_invalid_sequence(argv);
}

TEST_CASE("Invalid - sequence with double value") {
    const char* argv[] = {"1.5", "2", "3", NULL};
    test_invalid_sequence(argv);
}

TEST_CASE("Invalid - sequence with float value") {
    const char* argv[] = {"1.0f", "2", "3", NULL};
    test_invalid_sequence(argv);
}

TEST_CASE("Invalid - sequence with 'aaa98983'") {
    const char* argv[] = {"aaa98983", NULL};
    test_invalid_sequence(argv);
}

TEST_CASE("Invalid - sequence with '98983$·$&)'") {
    const char* argv[] = {"98983$·$&)", NULL};
    test_invalid_sequence(argv);
}

TEST_CASE("Invalid - sequence with 'dsjiowe'") {
    const char* argv[] = {"dsjiowe", NULL};
    test_invalid_sequence(argv);
}

TEST_CASE("Invalid - sequence with 'A'") {
    const char* argv[] = {"A", NULL};
    test_invalid_sequence(argv);
}

TEST_CASE("Invalid - sequence with '-10'") {
    const char* argv[] = {"-10", NULL};
    test_invalid_sequence(argv);
}

TEST_CASE("Invalid - sequence with '87e'") {
    const char* argv[] = {"87e", NULL};
    test_invalid_sequence(argv);
}

/* other usefull tests
lengths 11 and 10
lengths 2999 and 3000
Short - even sequence with no repeats
Short - odd sequence with no repeats
Short - even sequence with two ocurrences of the same integer
Short - odd sequence with only repeated characters
Short - even sequence with two ocurrences of the same integer
Short - odd sequence with only repeated characters
*/
