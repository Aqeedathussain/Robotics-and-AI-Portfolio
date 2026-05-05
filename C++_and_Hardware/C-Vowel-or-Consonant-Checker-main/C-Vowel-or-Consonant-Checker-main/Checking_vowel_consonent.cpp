#include <iostream>
#include <cctype>  // For tolower()

int main() {
    char ch;

    // Get an alphabet input from the user
    std::cout << "Enter an alphabet: ";
    std::cin >> ch;

    // Convert to lowercase for uniformity
    ch = tolower(ch);

    // Check if the input is a valid alphabet
    if (!isalpha(ch)) {
        std::cout << "Invalid input. Please enter a single alphabet." << std::endl;
    } else {
        // Check if the character is a vowel
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            std::cout << ch << " is a vowel." << std::endl;
        } else {
            std::cout << ch << " is a consonant." << std::endl;
        }
    }

    return 0;
}
