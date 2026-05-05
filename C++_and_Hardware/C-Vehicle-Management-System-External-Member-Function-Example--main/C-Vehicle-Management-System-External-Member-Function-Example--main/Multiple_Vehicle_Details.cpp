#include<iostream>
#include<vector>
using namespace std;

class vehicle {
private:
    string v_id;
    string owner_n;
protected:
    string v_type;
public:
    vehicle() {
        // Default constructor
    }

    void input() {
        cout << "Enter the vehicle ID: ";
        cin >> v_id;
        cout << "Enter the owner name: ";
        cin >> owner_n;
        cout << "Enter the vehicle type: ";
        cin >> v_type;
    }

    void disp() {
        cout << "The vehicle ID is: " << v_id << endl;
        cout << "The owner name is: " << owner_n << endl;
        cout << "The vehicle type is: " << v_type << endl;
    }

    string id() { return v_id; }
    string own() { return owner_n; }
    string type() { return v_type; }

    void show(string id, string n, string t); // Declaration
};

// External member function definition
void vehicle::show(string id, string n, string t) {
    cout << "External Show Function:" << endl;
    cout << "ID: " << id << endl;
    cout << "Owner: " << n << endl;
    cout << "Type: " << t << endl;
}

int main() {
    int n;
    cout << "How many vehicles do you want to enter? "<<endl;
    cin >> n;

    vector<vehicle> vehicles(n);

    // Input data for all vehicles
    for (int i = 0; i < n; ++i) {
        cout << "Vehicle #" << (i + 1) << ":"<<endl;
        vehicles[i].input();
    }

    // Display data
    cout << "--- Vehicle Information ---"<<endl;
    for (int i = 0; i < n; ++i) {
        cout << "Vehicle #" << (i + 1) << ":"<<endl;
        vehicles[i].disp();
    }

    return 0;
}
