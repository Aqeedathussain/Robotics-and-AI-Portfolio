## Program Overview

This project is a simple C++ calculator that performs basic arithmetic operations using a switch-case structure.  
It demonstrates user input handling, conditional logic, and basic error checking.

---

## Step-by-Step Explanation

### Taking User Input  
The program first asks the user to enter two numbers.  
It then prompts for the arithmetic operation they wish to perform (+, -, *, /).

### Switch-Case Decision Structure  
A switch statement evaluates the operation provided by the user.  
Each case corresponds to an arithmetic function:
- `+` for addition  
- `-` for subtraction  
- `*` for multiplication  
- `/` for division  

### Performing the Selected Operation  
Depending on the selected operator, the matching case executes  
and the appropriate mathematical expression is evaluated.

### Division by Zero Check  
Before performing division, the program checks if the second number is zero.  
If it is, an error message is displayed and the program exits safely.

### Handling Invalid Operations  
If the user enters any operator other than +, -, *, or /,  
the default case triggers an error message and terminates the program.

### Displaying the Result  
If everything is valid, the program prints the final calculated result.  
This ensures a clean end-to-end user experience.

---

## Key Concepts Demonstrated
- User input handling  
- Switch-case decision making  
- Arithmetic operations  
- Error handling for invalid input  
- Division-by-zero safety check  
