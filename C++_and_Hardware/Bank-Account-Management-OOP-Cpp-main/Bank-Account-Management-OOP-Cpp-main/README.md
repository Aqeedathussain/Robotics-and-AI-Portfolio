#  Bank Account Management System (C++)

This project demonstrates a simple yet structured banking system using **Object-Oriented Programming (OOP)** principles in C++. It covers account details, bank management information, and transaction processing using **multiple classes and a friend function** for controlled access.

---

##  Program Overview (Step-by-Step)

### 1 **Account Holder Initialization**
- The user is prompted to enter details such as account number, name, and starting balance.  
- These details are stored inside a dedicated `Acc_holder` class with private data for security.

### 2 **Bank Manager Information**
- A separate `Bank_M` class collects manager name and branch code.  
- This ensures managerial and organizational data remain modular and independent.

### 3 **Transaction Setup**
- A `transaction` class gathers transaction ID, amount, and type from the user.  
- It encapsulates transaction-specific details while maintaining clean separation from account data.

### 4 **Friend Function for Transaction Processing**
- A specialized function is granted access to private data of all three classes.  
- This function performs **Deposit** or **Withdraw** based on user input.  
- It calculates and displays the updated balance while ensuring the withdrawal amount does not exceed the available funds.

### 5 **Execution Flow**
- Objects of all classes are created in the main function.  
- Each object collects its own data.  
- The friend function is then called to process the selected transaction and show results.

---

##  Key Features
- Encapsulation with private data members  
- Friend function for secure controlled access  
- Modular class design  
- Deposit & Withdrawal operations  
- Clear step-by-step input/output interaction

---

##  Author
This repository is created for academic practice and understanding of **OOP concepts in C++**.

