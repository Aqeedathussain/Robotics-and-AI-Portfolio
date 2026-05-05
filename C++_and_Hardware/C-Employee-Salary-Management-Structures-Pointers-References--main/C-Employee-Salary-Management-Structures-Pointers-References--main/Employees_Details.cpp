#include <iostream>
#include <string>

using namespace std;

// Define the Employee structure
struct Employee {
    string name;
    int id;
    double salary;
};

// Function to increase the salary by 10% (pass by reference)
void increaseSalary(Employee& emp) {
    emp.salary *= 1.10; // Increase salary by 10%
}

// Function to display employee details using pointers
void displayEmployeeDetails(Employee* emp) {
    cout << "Employee Details:" << endl;
    cout << "Name: " << emp->name << endl;
    cout << "ID: " << emp->id << endl;
    cout << "Salary: $" << emp->salary << endl;
}

int main() {
    // Create an Employee structure
    Employee emp1 = {"John Doe", 101, 5000.00};

    // Display original details
    cout << "Original Employee Details:" << endl;
    displayEmployeeDetails(&emp1);

    // Increase the salary by 10%
    increaseSalary(emp1);

    // Display updated details
    cout << "\nUpdated Employee Details (After Salary Increase):" << endl;
    displayEmployeeDetails(&emp1);

    return 0;
}
