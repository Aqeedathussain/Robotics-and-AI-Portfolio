#include <iostream>
using namespace std;

class Rectangle {
private:
    int length;
    int width;

public:
    // Default Constructor
    Rectangle() {
        length = 1;
        width = 1;
        cout << "Default constructor called!" << endl;
    }

    // Parameterized Constructor
    Rectangle(int l, int w) {
        length = l;
        width = w;
        cout << "Parameterized constructor called!" << endl;
    }

    // Method to calculate and display area
    void displayArea() {
        cout << "Length: " << length << ", Width: " << width 
             << ", Area: " << length * width << endl;
    }
};

int main() {
    // Using default constructor
    Rectangle r1;
    r1.displayArea();

    // Using parameterized constructor
    Rectangle r2(5, 3);
    r2.displayArea();

    return 0;
}
