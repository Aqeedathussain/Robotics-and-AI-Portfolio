## Overview of the Program

This C++ program demonstrates **Object-Oriented Programming (OOP)** concepts using a `Book` class that showcases how **constructors**, **destructors**, and **object methods** work together.

---

## Step-by-Step Explanation

### Class Definition
- A `Book` class is created with private properties: `title` and `author`.
- This represents a simple structure for storing book information.

###  Constructor Execution
- The constructor accepts a title and author.
- When each object is created, the constructor runs automatically and prints a message indicating which book was created.

###  Destructor Execution
- The destructor prints a message when the object is destroyed.
- This happens automatically when the program ends or when the object goes out of scope.

### Display Function
- A public method `display()` prints the book’s title and author.
- Demonstrates object behavior and encapsulation.

### Creating Objects in `main()`
- Two objects (`b1` and `b2`) are created using the constructor.
- Each object's data is displayed using the `display()` method.

### End of Program Behavior
- As the program ends, destructors are called for each object.
- This shows automatic memory cleanup in C++.

---

## Key Concepts Demonstrated
- Object creation  
- Constructors & destructors  
- Encapsulation  
- Scope-based object lifecycle  
