#include <iostream>
#include <vector>
using namespace std;

class Car {
private:
    string car_id;
    string brand;
    string model;
    bool isAvailable;

public:
    Car() {
        isAvailable = true;
    }

    void getCarDetails() {
        cout << "Enter Car ID: "<<endl;
        cin >> car_id;
        cout << "Enter Brand: "<<endl;
        cin >> brand;
        cout << "Enter Model: "<<endl;
        cin >> model;
        isAvailable = true; 
    }

    void displayCarInfo() const {
        cout << "Car ID: " << car_id << ", Brand: " << brand << ", Model: " << model
             << ", Availability: " << (isAvailable ? "Available" : "Not Available") << endl;
    }

    string getID() const {
        return car_id;
    }

    bool getAvailability() const {
        return isAvailable;
    }

    void setAvailability(bool status) {
        isAvailable = status;
    }
};

class Customer {
private:
    string customer_id;
    Car* rentedCar;

public:
    Customer() {
        rentedCar = nullptr;
    }

    void getCustomerDetails() {
        cout << "Enter Customer ID: "<<endl;
        cin >> customer_id;
    }

    void rentCar(Car* car) {
        if (car->getAvailability()) {
            rentedCar = car;
            car->setAvailability(false);
            cout << "Car rented successfully!"<<endl;
        } else {
            cout << "Sorry, car is not available."<<endl;
        }
    }

    void displayCustomerInfo() const {
        cout << "Customer ID: " << customer_id;
        if (rentedCar != nullptr) {
            cout << " | Rented Car ID: " << rentedCar->getID() << endl;
        } else {
            cout << " | No car rented."<<endl;
        }
    }
};

int main() {
    int numCars, numCustomers;
    vector<Car> cars;
    vector<Customer> customers;

    cout << "Enter number of cars to add: "<<endl;
    cin >> numCars;
    for (int i = 0; i < numCars; ++i) {
        Car c;
        cout << "\nEnter details for Car " << i + 1 << ":"<<endl;
        c.getCarDetails();
        cars.push_back(c);
    }

    cout << "Available Cars:"<<endl;
    for (const auto& car : cars) {
        car.displayCarInfo();
    }

    cout << "Enter number of customers: "<<endl;
    cin >> numCustomers;
    for (int i = 0; i < numCustomers; ++i) {
        Customer cust;
        cout << "Enter details for Customer " << i + 1 << ":"<<endl;
        cust.getCustomerDetails();

        string carToRent;
        cout << "Enter Car ID to rent: "<<endl;
        cin >> carToRent;

        bool found = false;
        for (auto& car : cars) {
            if (car.getID() == carToRent) {
                cust.rentCar(&car);
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Car not found."<<endl;
        }

        customers.push_back(cust);
    }

    cout << "Final Customer Records:"<<endl;
    for (const auto& cust : customers) {
        cust.displayCustomerInfo();
    }

    return 0;
}
