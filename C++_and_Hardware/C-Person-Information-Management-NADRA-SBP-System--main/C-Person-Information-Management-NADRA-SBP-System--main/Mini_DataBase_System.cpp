#include <iostream>
using namespace std;

class NADRA {
private:
    string name;
    string cnic;
    string address;
public:
    void input() {
        cin.ignore(); // Ignore buffer from previous input
        cout << "Please enter the name: ";
        getline(cin, name);
        
        cout << "Please enter the CNIC number: ";
        cin >> cnic;
        cin.ignore(); // Ignore buffer from previous input
        
        cout << "Please enter your address: ";
        getline(cin, address);
    }

    void output() {
        cout << "The name is: " << name << endl;
        cout << "The CNIC number is: " << cnic << endl;
        cout << "The address is: " << address << endl;
    }

    string fetch() {
        return cnic;
    }
};

class SBP : public NADRA {
private:
    int acc_no;
    int active_acc;
public:
    void get() {
        cout << "Please enter the number of accounts the user has: ";
        cin >> acc_no;

        cout << "Please enter the number of active accounts the user has: ";
        cin >> active_acc;
    }

    void show() {
        cout << "The number of accounts the user has: " << acc_no << endl;
        cout << "The number of active accounts: " << active_acc << endl;
    }
};

class Person : public SBP {
private:
    string job;
    string condition;
public:
    void in() {
        cin.ignore();
        cout << "Please enter the job the person does: ";
        getline(cin, job);

        cout << "Please enter whether the person is a filer or non-filer: ";
        cin >> condition;
    }

    void out() {
        cout << "The job the person does is: " << job << endl;
        cout << "The condition of the user (filer/non-filer) is: " << condition << endl;
    }
};

int main() {
    const int numPersons = 3;
    Person s[numPersons];

    // Taking input
    for (int i = 0; i < numPersons; i++) {
        cout << "\nPlease enter the details of person " << i + 1 << ":" << endl;
        s[i].input();
        s[i].get();
        s[i].in();
    }

    // Searching for CNIC
    string searchCnic;
    cout << "\nEnter CNIC to search: ";
    cin >> searchCnic;

    bool found = false;
    for (int i = 0; i < numPersons; i++) {
        if (s[i].fetch() == searchCnic) {
            cout << "\nCNIC found!\n";
            s[i].output();
            s[i].show();
            s[i].out();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "CNIC not found.\n";
    }

    return 0;
}
