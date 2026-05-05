# — Bank Transaction System (C++)

This is a concise walkthrough of the program structure, flow, and key behaviors.

---

## 1. Purpose
1. Demonstrates **OOP concepts** in C++: classes, constructors, encapsulation, and friend functions.  
2. Simulates a banking workflow: **Account Holder → Bank Manager → Transaction → Process Deposit/Withdraw**.

## 2. High-Level Structure
1. **Three main classes**:
   - `Acc_holder` — stores account number, name, and balance.  
   - `Bank_M` — stores manager name and branch code.  
   - `transaction` — stores transaction ID, amount, and type.  
2. **Friend function** `process_trans()` accesses private data to perform operations.  
3. `main()` creates objects and executes the flow sequentially.

## 3. Input Strategy
1. Constructors prompt user for class-specific details.  
2. Bank manager uses an input method.  
3. Transaction data is captured at object creation.

## 4. Execution Flow
1. Create `Acc_holder` → input account number, name, balance.  
2. Create `Bank_M` → input manager name, branch code.  
3. Create `transaction` → input transaction ID, amount, type.  
4. Call `process_trans()` → ask user Deposit/Withdraw, read amount, compute total, display result.

## 5. Role of Friend Function
1. `process_trans()` can access private members of all three classes.  
2. Handles:
   - Deposit: adds amount to balance.  
   - Withdraw: checks balance before subtracting.  
   - Displays updated total or error messages.

## 6. Behavioral Notes
1. Operation input is **case-sensitive** (expects exact "Deposit" or "Withdraw").  
2. Stored balance is **not updated** after operation (only computed and displayed).  
3. Transaction fields are collected but **not used** in current logic.

## 7. User Interaction Sequence
1. Enter account details.  
2. Enter manager details.  
3. Enter transaction details.  
4. Choose Deposit or Withdraw and enter amount.  
5. View computed total or insufficient balance message.

## 8. Limitations
1. No input validation for non-numeric entries.  
2. Names may not support spaces with standard input.  
3. Balance is not updated in the current code.  

## 9. Suggested Improvements
1. Update stored balance after operations.  
2. Make operation input case-insensitive.  
3. Use `getline()` for names to allow spaces.  
4. Validate numeric input.  
5. Use transaction data in processing for logging.  
6. Reduce friend function use where possible to improve encapsulation.  

---

**Summary:** This project is a practical demonstration of OOP and friend functions in C++.  
It provides a clear, beginner-friendly framework for banking operations, ready for extension into a full-featured banking system.
