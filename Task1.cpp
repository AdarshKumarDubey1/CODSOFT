#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void numberGuessingGame() {
    srand(time(0));
    int number = rand() % 100 + 1;
    int guess, attempts = 0;

    cout << "\n🎯 Welcome to the Number Guessing Game!" << endl;
    cout << "I'm thinking of a number between 1 and 100. Try to guess it!" << endl;

    do {
        cout << "🔢 Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess < number)
            cout << "📉 Too low! Try a higher number.\n";
        else if (guess > number)
            cout << "📈 Too high! Try a lower number.\n";
        else
            cout << "🎉 Correct! You guessed it in " << attempts << " attempts.\n";
    } while (guess != number);
}

int main() {
    numberGuessingGame();
    return 0;
}