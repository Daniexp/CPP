#!/bin/bash
# Colors
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'  # No Color

# Función para comparar dos cadenas y mostrar el resultado
compare_strings() {
    if [ "$1" == "$2" ]; then
        echo -e "${NC}${3}: ${GREEN}$1${NC}"
    else
        echo -e "${NC}${3}: ${RED}$1${NC} - ${GREEN}$2${NC}"
    fi
}

# Function to print test title
print_test_title() {
    if [ "$1" == "PASS" ]; then
        echo -e "${GREEN}----------\n$2\n----------${NC}"
    else
        echo -e "${RED}----------\n$2\n----------${NC}"
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
char_error=$(echo "$output" | grep "char:" | awk -F ': ' '{print $2}' | sed 's/^[ \t]*//;s/[ \t]*$//')
int_error=$(echo "$output" | grep "int:" | awk -F ': ' '{print $2}' | sed 's/^[ \t]*//;s/[ \t]*$//')
float_error=$(echo "$output" | grep "float:" | awk -F ': ' '{print $2}' | sed 's/^[ \t]*//;s/[ \t]*$//')
double_error=$(echo "$output" | grep "double:" | awk -F ': ' '{print $2}' | sed 's/^[ \t]*//;s/[ \t]*$//')


    print_test_title "PASS" "$example"
    compare_strings "$char_error" "$expected_char" "char"
    compare_strings "$int_error" "$expected_int" "int"
    compare_strings "$float_error" "$expected_float" "float"
    compare_strings "$double_error" "$expected_double" "double"
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

# Positive Integer Valid
run_test "5" "Non displayable" "5" "5.0f" "5.0"
