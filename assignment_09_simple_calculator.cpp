// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================



#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Function declarations
void showMenu();
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
bool divide(double a, double b, double& result);
bool modOperation(long long a, long long b, long long& result);
double exponentiate(double base, double exponent);
bool getTwoNumbers(double& a, double& b);

int main() {
    int choice;
    cout << fixed << setprecision(2);

    while (true) {
        showMenu();
        cout << "Select an operation (1-7): ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number between 1 and 7.\n\n";
            continue;
        }

        if (choice == 7) {
            cout << "Goodbye!\n";
            break;
        }

        if (choice < 1 || choice > 7) {
            cout << "Invalid choice. Please enter a number between 1 and 7.\n\n";
            continue;
        }

        double a, b;
        if (!getTwoNumbers(a, b)) {
            cout << "Invalid number entered. Please try again.\n\n";
            continue;
        }

        if (choice == 1) {
            cout << "Result: " << a << " + " << b << " = " << add(a, b) << "\n\n";
        } else if (choice == 2) {
            cout << "Result: " << a << " - " << b << " = " << subtract(a, b) << "\n\n";
        } else if (choice == 3) {
            cout << "Result: " << a << " * " << b << " = " << multiply(a, b) << "\n\n";
        } else if (choice == 4) {
            double result;
            if (divide(a, b, result)) {
                cout << "Result: " << a << " / " << b << " = " << result << "\n\n";
            } else {
                cout << "Error: Cannot divide by zero.\n\n";
            }
        } else if (choice == 5) {
            long long result;
            if (modOperation((long long)a, (long long)b, result)) {
                cout << "Result: " << (long long)a << " % " << (long long)b
                     << " = " << result << " (remainder)\n\n";
            } else {
                cout << "Error: Cannot perform modulus by zero.\n\n";
            }
        } else if (choice == 6) {
            cout << "Result: " << a << " ^ " << b << " = " << exponentiate(a, b) << "\n\n";
        }
    }

    return 0;
}

void showMenu() {
    cout << "====================================\n";
    cout << "         SIMPLE CALCULATOR\n";
    cout << "====================================\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "5. Modulus\n";
    cout << "6. Exponentiation\n";
    cout << "7. Quit\n";
}

bool getTwoNumbers(double& a, double& b) {
    cout << "Enter first number : ";
    if (!(cin >> a)) {
        cin.clear();
        cin.ignore(10000, '\n');
        return false;
    }

    cout << "Enter second number: ";
    if (!(cin >> b)) {
        cin.clear();
        cin.ignore(10000, '\n');
        return false;
    }

    return true;
}

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

bool divide(double a, double b, double& result) {
    if (b == 0) return false;
    result = a / b;
    return true;
}

bool modOperation(long long a, long long b, long long& result) {
    if (b == 0) return false;
    result = a % b;
    return true;
}

double exponentiate(double base, double exponent) {
    return pow(base, exponent);
}

