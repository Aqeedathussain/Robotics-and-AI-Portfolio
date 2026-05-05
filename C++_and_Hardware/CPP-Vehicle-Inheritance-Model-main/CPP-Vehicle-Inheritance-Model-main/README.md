## Vehicle Inheritance Program – Overview

This program showcases how **inheritance** is used in C++ to build reusable and organized class structures.  
A base `Vehicle` class is extended into specialized types, demonstrating real-world modeling of cars and trucks.

---

## 🔍 Step-by-Step Explanation

### 1- Creating the Base Class  
A `Vehicle` class is defined with shared attributes such as **brand** and **number of wheels**.  
It also contains functions to set and display these attributes, allowing code reuse in child classes.

### 2- Establishing Reusability  
The base class uses `protected` members so that derived classes can access brand and wheel count directly while still maintaining encapsulation.

### 3- Passenger Car Class  
A `PassCar` class is created using public inheritance.  
It adds a **seating capacity** attribute and uses base class methods to handle common vehicle details.  
Its final output displays both inherited and extended information.

### 4- Cargo Truck Class  
A `CargoTruck` class is also built by inheriting from `Vehicle`.  
It includes a **load capacity** attribute measured in tons.  
Like the car class, it calls base class functions to avoid repeating code.

### 5- Object Creation in main()  
Two objects are created:  
- A passenger car with brand, wheels, and seating capacity  
- A cargo truck with brand, wheels, and load capacity  

Each object is initialized using dedicated setter functions.

### 6- Displaying Output  
Both derived classes provide their own display functions.  
These functions call the base `showDetails()` and then print specific attributes, clearly showing how inheritance organizes shared and unique data.

---

## Key Concepts Demonstrated
- Single inheritance  
- Base and derived class relationship  
- Protected data members  
- Code reuse through member functions  
- Real-world modeling in OOP  

