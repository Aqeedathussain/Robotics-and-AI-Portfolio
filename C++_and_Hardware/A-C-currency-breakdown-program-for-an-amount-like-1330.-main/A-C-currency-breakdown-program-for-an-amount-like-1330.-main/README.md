# Currency Denomination Calculator in C++
## Description
This is a simple C++ program that calculates the number of currency notes required for a given total amount. The program uses a switch statement to determine the number of notes for denominations of 100, 50, 20, and 1.
⚠️ Note: The program demonstrates the use of switch without break statements, so all cases after the matched one will execute due to fall-through behavior.
# Features
1-Calculates the number of 100, 50, 20, and 1 currency notes.

2-Demonstrates switch statement and fall-through behavior in C++.

3-Prints a final message indicating completion of the calculation.
# How It Works
The total amount is stored in the variable total.

A switch statement is used with 100 as the case to start the calculation.

Each case calculates the number of notes of that denomination and updates the remaining amount.

The program prints the number of notes for each denomination.
# Example Output
For total = 1330, the output will be:
The notes of 100 are 13
The notes of 50 are 0
The notes of 20 are 1
The notes of 1 are 10
You have got your payment
# How to Compile and Run
Open a Visual Studio Code.
Open a folder containing the C++ file (currency_calculator.cpp).
Compile the program using a C++ compiler:
Run the programe.
# Dependencies
C++ compiler (e.g., g++, clang++)

No additional libraries required.
No additional libraries required.

# Author
Aqeedat Hussain
