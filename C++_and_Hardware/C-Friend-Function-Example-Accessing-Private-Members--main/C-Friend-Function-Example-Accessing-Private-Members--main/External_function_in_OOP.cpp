#include <iostream>
using namespace std;

class Box {
private:
    double length;

public:
    Box() : length(0) {}

    void setLength(double len) {
        length = len;
    }

    // Friend function declaration
    friend void printLength(Box b);
};

// External function (not a member of class)
void printLength(Box b) {
    // Can access private member because it's a friend
    cout << "Length of box: " << b.length << endl;
}

int main() {
    Box b;
    b.setLength(10.5);

    // Call external function
    printLength(b);

    return 0;
}
