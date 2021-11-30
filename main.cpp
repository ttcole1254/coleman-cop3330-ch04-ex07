/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Tyler Coleman
 */

/*
* Modify the “mini calculator” from exercise 5 to accept (just) single-digit numbers written as either digits or spelled out.
* 
* Write a program that performs as a very simple calculator. Your calculator should be able to handle the four basic math
* operations — add, subtract, multiply, and divide — on two input values. Your program should prompt the user to enter
* three arguments: two double values and a character to represent an operation. If the entry arguments are 35.6, 24.1, and
* '+', the program output should be The sum of 35.6 and 24.1 is 59.7. In Chapter 6 we look at a much more
* sophisticated simple calculator.
*/

#include "std_lib_facilities.h"
// Init vars
vector<string> numbers;
int readNumber()
{
    // Sets number as a constant but var as a copy to ensure we know the difference
    const int number = numbers.size();
    int var = number;
    // If input is a number, return it back
    if (cin >> var) return var;
    // Here, reading the input as a integer has failed. Clearing the input to try reading as a string instead.
    cin.clear();
    string numberAsString;
    cin >> numberAsString;

    // Test if input string matches any of the preset numbers as strings.
    // If a match is found, set var to the position.
    for (int i = 0; i < numbers.size(); ++i) {
        if (numbers[i] == numberAsString) var = i;
    }
    if (var == number) {
        error("You haven't entered a valid number: ", numberAsString);
    }
    return var;
}
int main()
{
    try {
        numbers.push_back("zero");
        numbers.push_back("one");
        numbers.push_back("two");
        numbers.push_back("three");
        numbers.push_back("four");
        numbers.push_back("five");
        numbers.push_back("six");
        numbers.push_back("seven");
        numbers.push_back("eight");
        numbers.push_back("nine");
        cout << "Please enter two single-digit numbers separated by a space followed by a simple operator (+, -, *, /): ";
        while (true) {
            int var1 = readNumber();
            int var2 = readNumber();
            // Reset op to 0 between runs
            char op = 0;
            cin >> op;
            string oper;
            double result;
            switch (op) {
                case '+':
                    oper = " added to ";
                    result = var1 + var2;
                    break;
                case '-':
                    oper = " subtracted from ";
                    result = var1 - var2;
                    break;
                case '*':
                    oper = " multiplied by ";
                    result = var1 * var2;
                    break;
                case '/':
                    oper = " divided by ";
                    if (var2 == 0) error("Cannot divide by 0.");
                    result = var1 % var2;
                    break;
                default:
                    error("Unknown Operator. Please only use +, -, *, or /.");
            }
            cout << var2 << oper << var1 << " is " << result << ".\n";
            cout << "Try again: ";
        }
    } catch (runtime_error e) {
        cout << e.what() << "\n";
    }
}