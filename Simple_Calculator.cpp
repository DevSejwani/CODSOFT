#include <iostream>

using namespace std;

int main() {
    char operation;
    double num1, num2;

    cout << "Simple Calculator\n";
    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter an operation (+, -, *, /): ";
    cin >> operation;

    cout << "Enter second number: ";
    cin >> num2;

    double result;

    switch (operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                cout << "Error: Cannot divide by zero.\n";
                return 1; // Exit program with an error code
            }
            break;
        default:
            cout << "Error: Invalid operation.\n";
            return 1; // Exit program with an error code
    }

    cout << "Result: " << result << endl;

    return 0; // Exit program with a success code
}
