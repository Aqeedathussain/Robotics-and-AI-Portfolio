#include <iostream>
using namespace std;

class SmartLight {
private:
    bool isOn;
    int brightness; // Range 0-100
public:
    SmartLight() : isOn(false), brightness(0) {}

    void turnOn() {
        isOn = true;
        cout << "Light is now ON." << endl;
    }
    void turnOff() {
        isOn = false;
        cout << "Light is now OFF." << endl;
    }
    void setBrightness(int b) {
        if (b < 0 || b > 100) {
            cout << "Invalid brightness. Please enter a value between 0 and 100." << endl;
        } else {
            brightness = b;
            cout << "Brightness set to " << brightness << "." << endl;
        }
    }
    void showStatus() const {
        cout << "Light is " << (isOn ? "ON" : "OFF")
             << " with brightness " << brightness << "." << endl;
    }
};

class SmartThermostat {
private:
    bool isOn;
    double temperature; // e.g., 10.0 to 30.0 degrees Celsius
public:
    SmartThermostat() : isOn(false), temperature(20.0) {}

    void turnOn() {
        isOn = true;
        cout << "Thermostat is now ON." << endl;
    }
    void turnOff() {
        isOn = false;
        cout << "Thermostat is now OFF." << endl;
    }
    void setTemperature(double t) {
        if (t < 10.0 || t > 30.0) {
            cout << "Invalid temperature. Please enter a value between 10 and 30." << endl;
        } else {
            temperature = t;
            cout << "Temperature set to " << temperature << " degrees Celsius." << endl;
        }
    }
    void showStatus() const {
        cout << "Thermostat is " << (isOn ? "ON" : "OFF")
             << " set to " << temperature << " degrees." << endl;
    }
};

class SmartDoorLock {
private:
    bool locked;
public:
    SmartDoorLock() : locked(true) {}

    void lock() {
        locked = true;
        cout << "Door is now LOCKED." << endl;
    }
    void unlock() {
        locked = false;
        cout << "Door is now UNLOCKED." << endl;
    }
    void showStatus() const {
        cout << "Door is " << (locked ? "LOCKED" : "UNLOCKED") << "." << endl;
    }
};

int main() {
    SmartLight light;
    SmartThermostat thermostat;
    SmartDoorLock doorLock;
    int choice;

    while (true) {
        cout << "\nSmart Home Control Menu:" << endl;
        cout << "1. Control Light" << endl;
        cout << "2. Control Thermostat" << endl;
        cout << "3. Control Door Lock" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int action;
            while (true) {
                cout << "\nLight Control:" << endl;
                cout << "1. Turn ON" << endl;
                cout << "2. Turn OFF" << endl;
                cout << "3. Set Brightness" << endl;
                cout << "4. Show Status" << endl;
                cout << "5. Back to Main Menu" << endl;
                cout << "Choose an action: ";
                cin >> action;

                if (action == 1) {
                    light.turnOn();
                } else if (action == 2) {
                    light.turnOff();
                } else if (action == 3) {
                    int brightness;
                    cout << "Enter brightness (0-100): ";
                    cin >> brightness;
                    light.setBrightness(brightness);
                } else if (action == 4) {
                    light.showStatus();
                } else if (action == 5) {
                    break; // Exit light control loop
                } else {
                    cout << "Invalid choice. Please try again." << endl;
                }
            }
        }
        else if (choice == 2) {
            int action;
            while (true) {
                cout << "\nThermostat Control:" << endl;
                cout << "1. Turn ON" << endl;
                cout << "2. Turn OFF" << endl;
                cout << "3. Set Temperature" << endl;
                cout << "4. Show Status" << endl;
                cout << "5. Back to Main Menu" << endl;
                cout << "Choose an action: ";
                cin >> action;

                if (action == 1) {
                    thermostat.turnOn();
                } else if (action == 2) {
                    thermostat.turnOff();
                } else if (action == 3) {
                    double temp;
                    cout << "Enter temperature (10-30): ";
                    cin >> temp;
                    thermostat.setTemperature(temp);
                } else if (action == 4) {
                    thermostat.showStatus();
                } else if (action == 5) {
                    break; // Exit thermostat loop
                } else {
                    cout << "Invalid choice. Please try again." << endl;
                }
            }
        }
        else if (choice == 3) {
            int action;
            while (true) {
                cout << "\nDoor Lock Control:" << endl;
                cout << "1. Lock" << endl;
                cout << "2. Unlock" << endl;
                cout << "3. Show Status" << endl;
                cout << "4. Back to Main Menu" << endl;
                cout << "Choose an action: ";
                cin >> action;

                if (action == 1) {
                    doorLock.lock();
                } else if (action == 2) {
                    doorLock.unlock();
                } else if (action == 3) {
                    doorLock.showStatus();
                } else if (action == 4) {
                    break; // Exit door lock loop
                } else {
                    cout << "Invalid choice. Please try again." << endl;
                }
            }
        }
        else if (choice == 4) {
            cout << "Exiting Smart Home System. Goodbye!" << endl;
            break;
        }
        else {
            cout << "Invalid selection. Please try again." << endl;
        }
    }

    return 0;
}