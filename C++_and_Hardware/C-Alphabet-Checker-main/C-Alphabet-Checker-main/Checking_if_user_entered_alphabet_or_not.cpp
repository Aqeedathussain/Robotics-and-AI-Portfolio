#include <iostream>
#include <cctype>  // For isalpha()

int main() {
    char ch;

    // Get a character input from the user
    std::cout << "Enter a character: ";
    std::cin >> ch;

    // Check if the character is an alphabet
    if (isalpha(ch)) {
        std::cout << ch << " is an alphabet." << std::endl;
    } else {
        std::cout << ch << " is not an alphabet." << std::endl;
    }

    return 0;
}
