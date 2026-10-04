# Infix to Postfix Calculator

A C++ program that converts mathematical expressions from infix notation
to postfix notation and evaluates the result.

## Features
- Converts infix expressions to postfix
- Evaluates postfix expressions
- Supports +, -, *, /, and ^
- Supports parentheses
- Supports decimal numbers
- Uses a custom stack implementation
- Uses C++ templates and linked lists

## Example

Input:
(3 + 4) * 2

Postfix:
3 4 + 2 *

Result:
14

## Files
- `main.cpp` - Expression conversion, evaluation, and user interface
- `stack.h` - Stack and node class declarations
- `stack.cpp` - Stack implementation
