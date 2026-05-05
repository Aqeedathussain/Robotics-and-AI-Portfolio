#include <iostream>
#include <string>
using namespace std;

// Base class
class Vehicle {
protected:
    string brand;
    int wheels;

public:
    void setDetails(string b, int w) {
        brand = b;
        wheels = w;
    }

    void showDetails() {
        cout << "Brand: " << brand << endl;
        cout << "Number of Wheels: " << wheels << endl;
    }
};

// Derived class 1
class PassCar : public Vehicle {
private:
    int seatingCapacity;

public:
    void setCarDetails(string b, int w, int seats) {
        setDetails(b, w);  // call base class function
        seatingCapacity = seats;
    }

    void showCarDetails() {
        cout << "--- Passenger Car Details ---" << endl;
        showDetails();  // call base class function
        cout << "Seating Capacity: " << seatingCapacity << endl;
    }
};

// Derived class 2
class CargoTruck : public Vehicle {
private:
    float loadCapacity;  // in tons

public:
    void setTruckDetails(string b, int w, float load) {
        setDetails(b, w);  // call base class function
        loadCapacity = load;
    }

    void showTruckDetails() {
        cout << "--- Cargo Truck Details ---" << endl;
        showDetails();  // call base class function
        cout << "Load Capacity: " << loadCapacity << " tons" << endl;
    }
};

int main() {
    // Create objects
    PassCar car;
    CargoTruck truck;

    // Set values
    car.setCarDetails("Toyota", 4, 5);
    truck.setTruckDetails("Volvo", 6, 10.5);

    // Display values
    cout << endl;
    car.showCarDetails();
    cout << endl;
    truck.showTruckDetails();

    return 0;
}
