#include <iostream>
using namespace std;

void calculator() {
    double num1, num2, result;
    char op;

    cout << "\n🧮 Welcome to the Interactive Calculator!" << endl;
    cout << "You can perform: Addition (+), Subtraction (-), Multiplication (*), Division (/)\n";

    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    cout << "Choose operation (+, -, *, /): ";
    cin >> op;

    switch(op) {
        case '+': result = num1 + num2; break;
        case '-': result = num1 - num2; break;
        case '*': result = num1 * num2; break;
        case '/':
            if (num2 != 0)
                result = num1 / num2;
            else {
                cout << "🚫 Error: Division by zero.\n";
                return;
            }
            break;
        default:
            cout << "❌ Invalid operation.\n";
            return;
    }

    cout << "✅ Result: " << num1 << " " << op << " " << num2 << " = " << result << "\n";
}

int main() {
    calculator();
    return 0;
}