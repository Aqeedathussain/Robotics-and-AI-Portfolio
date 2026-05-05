## Program Overview

This project demonstrates **constructor overloading** and **destructor behavior** in C++ using a custom `my_time` class.  
It shows how different constructor versions initialize objects with varying information while maintaining clean object lifecycle management.

---

## Step-by-Step Explanation

### 1- Defining the Time Class  
A class is created to represent time with two private attributes: hours and minutes.  
This encapsulates the time representation within a reusable object.

### 2- Default Constructor  
The default constructor initializes the time to `0:0`.  
It also prints a message so the user can see when it is invoked.

### 3- Single-Parameter Constructor  
This constructor accepts only hours and sets minutes to zero.  
It demonstrates partial initialization and constructor overloading.

### 4- Two-Parameter Constructor  
The most detailed constructor accepts hours and minutes.  
This allows flexible initialization based on user or program needs.

### 5- Display Function  
A simple display method outputs the time in `hours:minutes` format.  
This provides a clear, readable representation of each object.

### 6- Destructor Execution  
Each object triggers its destructor automatically when it goes out of scope.  
The destructor prints the stored time, demonstrating the exact moment each object is destroyed.

### 7- Creating Objects in main()  
Three objects are created using all three constructor versions.  
Their values are displayed to show how each constructor initializes the class differently.

---

## Key Concepts Demonstrated
- Class creation  
- Constructor overloading  
- Default, 1-argument, and 2-argument constructors  
- Object lifecycle and destructor messages  
- Encapsulation and method usage  
