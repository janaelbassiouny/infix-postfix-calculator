
#include <iostream>
#include <string>
#include <cmath>
#include "stack.h"

using namespace std;

// Check precedence of operators
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Check if operator is right-associative
bool isRightAssociative(char op) {
    return op == '^';
}

// Apply operator to two operands
double applyOperator(double a, double b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    case '^': return pow(a, b);
    default: return 0;
    }
}

// Convert infix to postfix (space-separated)
string infixToPostfix(string infix) {
    stack<char> ops;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        if (ch == ' ') continue;

        // If digit or '.', read full number (supports decimals)
        if (isdigit(ch) || ch == '.') {
            while (i < infix.length() && (isdigit(infix[i]) || infix[i] == '.')) {
                postfix += infix[i];
                i++;
            }
            postfix += ' ';
            i--; // Adjust index
        }
        // Opening parenthesis
        else if (ch == '(') {
            ops.push(ch);
        }
        // Closing parenthesis
        else if (ch == ')') {
            while (!ops.is_empty() && ops.peek() != '(') {
                postfix += ops.pop();
                postfix += ' ';
            }
            if (!ops.is_empty()) ops.pop(); // Pop '('
        }
        // Operator
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            while (!ops.is_empty() && ops.peek() != '(' &&
                (precedence(ops.peek()) > precedence(ch) ||
                    (precedence(ops.peek()) == precedence(ch) && !isRightAssociative(ch)))) {
                postfix += ops.pop();
                postfix += ' ';
            }
            ops.push(ch);
        }
    }

    // Pop any remaining operators
    while (!ops.is_empty()) {
        postfix += ops.pop();
        postfix += ' ';
    }

    return postfix;
}

// Evaluate postfix expression
double evaluatePostfix(string postfix) {
    stack<double> values;
    string number = "";

    for (int i = 0; i < postfix.length(); i++) {
        char ch = postfix[i];

        if (ch == ' ') continue;

        // Parse number
        if (isdigit(ch) || ch == '.') {
            number = "";
            while (i < postfix.length() && (isdigit(postfix[i]) || postfix[i] == '.')) {
                number += postfix[i];
                i++;
            }
            values.push(stod(number)); // Convert to double
            i--; // Adjust index
        }
        // Operator
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            if (values.is_empty()) {
                cout << "Error: Not enough operands." << endl;
                return 0;
            }
            double b = values.pop();
            if (values.is_empty()) {
                cout << "Error: Not enough operands." << endl;
                return 0;
            }
            double a = values.pop();
            double result = applyOperator(a, b, ch);
            values.push(result);
        }
    }

    return values.pop(); // Final result
}

int main() {
    cout << "***Welcome to infix to postfix converter***" << endl;
    char choice;
    do {
        string infix;
        cout << "Enter an infix expression: ";
        getline(cin, infix);

        string postfix = infixToPostfix(infix);
        cout << "Postfix expression: " << postfix << endl;

        double result = evaluatePostfix(postfix);
        cout << "Evaluation result: " << result << endl;

        cout << endl;
        cout << "Do you want to do more conversions??(write y or Y if yes):" << endl;
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    return 0;
}
