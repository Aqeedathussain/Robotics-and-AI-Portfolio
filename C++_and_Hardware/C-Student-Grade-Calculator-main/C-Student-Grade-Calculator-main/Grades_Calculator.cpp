#include <iostream>
using namespace std;

char calculateGrade(int marks) {
    if (marks >= 85 && marks <= 100)
        return 'A';
    else if (marks >= 80 && marks <= 84)
        return 'A';
    else if (marks >= 75 && marks <= 79)
        return 'B';
    else if (marks >= 71 && marks <= 74)
        return 'B';
    else if (marks >= 68 && marks <= 70)
        return 'B';
    else if (marks >= 64 && marks <= 67)
        return 'C';
    else if (marks >= 60 && marks <= 63)
        return 'C';
    else if (marks >= 57 && marks <= 59)
        return 'C';
    else if (marks >= 53 && marks <= 56)
        return 'D';
    else if (marks >= 50 && marks <= 52)
        return 'D';
    else if (marks < 50)
        return 'F';
    else
        return 'W';
}

int main() {
    int marks;
    cout << "Enter student marks: ";
    cin >> marks;

    char grade = calculateGrade(marks);

    cout << "The grade for " << marks << " marks is " << grade << endl;

    return 0;
}
