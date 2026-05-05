#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;

public:
    // Constructor
    Book(string t, string a) {
        title = t;
        author = a;
        cout << "Constructor called for \"" << title << "\" by " << author << endl;
    }

    // Destructor
    ~Book() {
        cout << "Destructor called for \"" << title << "\"" << endl;
    }

    // Display function
    void display() {
        cout << "Title: " << title << ", Author: " << author << endl;
    }
};

int main() {
    Book b1("1984", "George Orwell");
    Book b2("The Alchemist", "Paulo Coelho");

    b1.display();
    b2.display();

    return 0;
}
