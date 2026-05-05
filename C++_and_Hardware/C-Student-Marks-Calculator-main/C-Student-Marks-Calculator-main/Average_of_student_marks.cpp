#include <iostream>
using namespace std;

int main() {
    // Declare variables
    int marks[5], sum = 0;

    // Input marks for five subjects
    cout << "Enter marks for five subjects:" << endl;
    for(int i = 0; i < 5; i++) {
        cout << "Subject " << i + 1 << ": ";
        cin >> marks[i];
        sum += marks[i]; // Calculate sum
    }

    // Calculate aggregate and average
    int totalSubjects = 5;
    float average = sum / static_cast<float>(totalSubjects); // Calculate average

    // Display aggregate and average
    cout << "Aggregate marks: " << sum << endl;
    cout << "Average marks: " << average << endl;

    return 0;
}
