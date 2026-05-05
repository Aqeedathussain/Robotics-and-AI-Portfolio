## Program Overview

This project demonstrates how **structures**, **pass-by-value**, and **pointers** operate in C++ through a simple Book management example.  
It highlights how data is stored, accessed, and manipulated using both static objects and dynamically allocated memory.

---

## Step-by-Step Explanation

### Defining the Structure  
A `Book` structure is created with three members: title, author, and price.  
This structure serves as a lightweight container for storing book information.

### Display Function (Pass-by-Value)  
A function is defined to print book details.  
It receives the structure **by value**, meaning it works on a separate copy and does *not* modify the original data.

### Creating a Static Book  
Inside `main()`, a book object is initialized with predefined values.  
This object is passed to the display function, demonstrating that the original structure remains unchanged.

### Verifying No Changes  
After the function call, the program prints the original structure again  
to prove that pass-by-value does not alter the original data.

### Using Pointers for Dynamic Books  
Two bookstore books are created using **dynamic memory allocation** (`new`).  
Pointers store the memory addresses of these Book objects, simulating books stored in different bookstores.

### Working With Dynamically Allocated Books  
The program dereferences the pointers to access and display the data.  
This demonstrates how pointers interact with structures.

### Memory Cleanup  
All dynamically allocated Book objects are released using `delete`  
to prevent memory leaks and maintain good memory management practices.

---

## Key Concepts Demonstrated
- Struct creation  
- Pass-by-value behavior  
- Pointers and dynamic memory allocation  
- Dereferencing pointers  
- Memory cleanup using `delete`  
