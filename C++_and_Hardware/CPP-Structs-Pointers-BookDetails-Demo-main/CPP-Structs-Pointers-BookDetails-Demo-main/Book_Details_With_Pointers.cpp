#include <iostream>
#include <string>

using namespace std;

// Define the Book structure
struct Book {
    string title;
    string author;
    double price;
};

// Function to display book details (passed by value)
void displayBookDetails(Book book) {
    cout << "Book Details:" << endl;
    cout << "Title: " << book.title << endl;
    cout << "Author: " << book.author << endl;
    cout << "Price: $" << book.price << endl;
}

// Main function
int main() {
    // Create a Book structure
    Book book1 = {"The Great Gatsby", "F. Scott Fitzgerald", 10.99};

    // Display details using the function
    displayBookDetails(book1);

    // Verify original structure is unchanged
    cout << "\nOriginal Book Structure (Unchanged):" << endl;
    cout << "Title: " << book1.title << endl;
    cout << "Author: " << book1.author << endl;
    cout << "Price: $" << book1.price << endl;

    // Using pointers to work with books for different bookstores
    Book* bookStore1 = new Book{"1984", "George Orwell", 15.50};
    Book* bookStore2 = new Book{"To Kill a Mockingbird", "Harper Lee", 12.99};

    cout << "\nBooks in Different Bookstores:" << endl;
    cout << "Bookstore 1:" << endl;
    displayBookDetails(*bookStore1); // Dereference the pointer to pass by value
    cout << "Bookstore 2:" << endl;
    displayBookDetails(*bookStore2);

    // Clean up dynamically allocated memory
    delete bookStore1;
    delete bookStore2;

    return 0;
}
