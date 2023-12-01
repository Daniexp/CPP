#!/bin/bash
header='Running ex00 ScalarConvert::convert function'

# Function to compare two strings and print the result
compare_strings() {
    if [ "$1" == "$2" ]; then
        echo "Pass"
    else
        echo "Fail: Expected '$2', but got '$1'"
    fi
}

# Function to run the test and check the output
run_test() {
    example="$1"
    expected_char="$2"
    expected_int="$3"
    expected_float="$4"
    expected_double="$5"

    output=$(./ex00 "$example")
    char_error=$(echo "$output" | grep "char:" | awk '{print $2}')
    int_error=$(echo "$output" | grep "int:" | awk '{print $2}')
    float_error=$(echo "$output" | grep "float:" | awk '{print $2}')
    double_error=$(echo "$output" | grep "double:" | awk '{print $2}')

    echo "Test Case: $example"
    compare_strings "$char_error" "$expected_char"
    compare_strings "$int_error" "$expected_int"
    compare_strings "$float_error" "$expected_float"
    compare_strings "$double_error" "$expected_double"
}

# Test Case 1
run_test "-inff" "impossible" "impossible" "-inff" "-inf"

# Test Case 2
run_test "-inf" "impossible" "impossible" "-inff" "-inf"

# Test Case 3
run_test "+inff" "impossible" "impossible" "+inff" "+inf"

# Test Case 4
run_test "+inf" "impossible" "impossible" "+inff" "+inf"

# Test Case 5
run_test "nanf" "impossible" "impossible" "nanf" "nan"

# Test Case 6
run_test "nan" "impossible" "impossible" "nanf" "nan"

