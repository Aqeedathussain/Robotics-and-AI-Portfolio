
#include <iostream>
using namespace std;

class Student {
    public:
        string name;
        int age;

        // Constructor
        Student(string n, int a) {
            name = n;
            age = a;
        }

        void display() {
            cout << "Name: " << name << ", Age: " << age << endl;
        }
};

int main() {
    // Creating an object and calling the constructor
    Student s1("Alice", 20);
    s1.display();

    return 0;
}
