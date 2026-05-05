#include <iostream>
#include <string>

using namespace std;

// Define the Department structure
struct Department {
    string deptName;
    string headName;
};

// Define the Company structure containing a Department
struct Company {
    string companyName;
    Department department;
};

// Function to input company and department details
void inputDetails(Company* company) {
    cout << "Enter company name: ";
    getline(cin, company->companyName);

    cout << "Enter department name: ";
    getline(cin, company->department.deptName);

    cout << "Enter department head name: ";
    getline(cin, company->department.headName);
}

// Function to display company and department details
void displayDetails(Company* company) {
    cout << "\nCompany Details:" << endl;
    cout << "Company Name: " << company->companyName << endl;

    cout << "Department Details:" << endl;
    cout << "Department Name: " << company->department.deptName << endl;
    cout << "Head of Department: " << company->department.headName << endl;
}

int main() {
    // Create a Company object dynamically
    Company* company = new Company;

    // Input details
    inputDetails(company);

    // Display details
    displayDetails(company);

    // Clean up dynamically allocated memory
    delete company;

    return 0;
}
