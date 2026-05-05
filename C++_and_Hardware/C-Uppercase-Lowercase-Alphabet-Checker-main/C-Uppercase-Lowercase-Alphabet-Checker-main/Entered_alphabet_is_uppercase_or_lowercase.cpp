#include <iostream>
#include <cctype>  // For isupper() and islower()

int main() {
    char ch;

    // Get a character input from the user
    std::cout << "Enter a character: ";
    std::cin >> ch;

    // Check if the input is a valid alphabet
    if (!isalpha(ch)) {
        std::cout << "Invalid input. Please enter a single alphabet character." << std::endl;
    } else {
        // Check if the character is uppercase or lowercase
        if (isupper(ch)) {
            std::cout << ch << " is an uppercase alphabet." << std::endl;
        } else if (islower(ch)) {
            std::cout << ch << " is a lowercase alphabet." << std::endl;
        }
    }

    return 0;
}
