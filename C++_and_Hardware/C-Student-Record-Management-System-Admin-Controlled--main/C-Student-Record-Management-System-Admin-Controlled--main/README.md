# C++ Student Record Management System

This project is a console-based Student Record Management System developed in C++.  
It demonstrates how an administrator can securely manage and update different aspects of a student’s profile using Object-Oriented Programming concepts.

---

## System Overview
The system stores and manages a student’s:
- Personal and academic details
- Grades and performance
- Extra-curricular activities
- Disciplinary records
- Library account information
- Sports participation details  

Only an authorized **admin** can edit the records using a verified ID.

---

## Core OOP Concepts Used
- Classes and Objects  
- Encapsulation (private & protected data)  
- Friend Classes for controlled access  
- Constructors for default initialization  
- Menu-driven program structure  
- Input validation and control flow  

---

## Main Components
- **Academic Details Module**  
  Stores name, roll number, and grades.

- **Extra-Curricular Module**  
  Manages club memberships and achievements.

- **Disciplinary Records Module**  
  Keeps track of disciplinary status.

- **Library Account Module**  
  Handles issued books and clearance status.

- **Sports Participation Module**  
  Records game participation and position.

- **Admin Module**  
  Acts as a controller with special privileges to edit all records.

---

## Admin Authentication
- Editing access is protected by an ID check  
- Only the admin can update student records  
- Unauthorized access is denied automatically  

---

## Program Flow
1. Display complete student profile  
2. Ask for admin ID verification  
3. Show editing menu upon successful login  
4. Allow selective updates for each module  
5. Display updated information immediately  
6. Exit safely from edit mode  

---

## Possible Enhancements
- File handling for permanent data storage  
- Multiple student records support  
- Password-based admin authentication  
- Inheritance-based module design  
- Graphical user interface (GUI)  

---

##  Suggested Project Structure
