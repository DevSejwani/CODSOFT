#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0)); // seed random number generator
    int secretNumber = rand() % 100 + 1; // random number between 1 and 100
    int guess = 0;
    int numGuesses = 0;
    cout << "I'm thinking of a number between 1 and 100." << endl;
    while (guess != secretNumber) {
        cout << "Enter your guess: ";
        cin >> guess;
        numGuesses++;
        if (guess < secretNumber) {
            cout << "Your guess is too low." << endl;
        } else if (guess > secretNumber) {
            cout << "Your guess is too high." << endl;
        }
    }
    cout << "Congratulations! You guessed the number in " << numGuesses << " tries." << endl;
    return 0;
}
