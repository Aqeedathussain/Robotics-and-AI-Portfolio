#include <iostream>
using namespace std;

int main() {
    int amount, twenties, tens, fives, ones;

    // Input
    cout << "Enter a dollar amount: $";
    cin >> amount;

    // Calculation for each type of bill
    twenties = amount / 20;
    amount %= 20;

    tens = amount / 10;
    amount %= 10;

    fives = amount / 5;
    amount %= 5;

    ones = amount;

    // Output
    cout << "$20 bills: " << twenties << endl;
    cout << "$10 bills: " << tens << endl;
    cout << "$5 bills: " << fives << endl;
    cout << "$1 bills: " << ones << endl;

    return 0;
}
