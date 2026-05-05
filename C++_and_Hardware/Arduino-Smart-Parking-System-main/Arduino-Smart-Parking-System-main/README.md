# Arduino Smart Parking System

An automated car parking system designed to manage vehicle entry and exit using infrared sensors and servo motor actuation. This project simulates a real-world parking management solution with real-time slot tracking and visual feedback.

## Features
- **Automated Gate Control:** Servo-based gate mechanism that opens automatically upon vehicle detection.
- **Bidirectional Detection:** Separate IR sensors for entry and exit management.
- **Real-time Slot Tracking:** dynamic counter that updates available parking spots (Max: 4).
- **LCD Interface:** Displays system status, welcome messages, and remaining slot count.
- **Occupancy Logic:** Prevents entry when the parking lot reaches full capacity.

## Hardware Requirements
- Arduino UNO (or compatible board)
- 1x Servo Motor (SG90 or MG995)
- 2x IR Infrared Obstacle Avoidance Sensors
- 1x I2C Liquid Crystal Display (16x2)
- Jumper Wires & Breadboard

## Pin Configuration
| Component | Pin / Type | Description |
|-----------|------------|-------------|
| **Entry Sensor** | D2 | Detects incoming vehicles (IR1) |
| **Exit Sensor** | D3 | Detects departing vehicles (IR2) |
| **Servo Motor** | D9 | Controls the gate arm |
| **LCD (SDA)** | A4 | I2C Data |
| **LCD (SCL)** | A5 | I2C Clock |

## Libraries Used
Ensure the following libraries are installed in your Arduino IDE:
1. `LiquidCrystal_I2C`
2. `Servo` (Built-in)
3. `Wire` (Built-in)

## How It Works
1. **Initialization:** The servo initializes to 90° (closed position), and the LCD displays the welcome screen.
2. **Entry:** When `IR1` detects a car:
   - The system checks for available slots.
   - If slots > 0, the gate opens (0°), and the slot count decreases.
   - If slots = 0, the LCD displays "Parking Full."
3. **Exit:** When `IR2` detects a car leaving:
   - The gate opens to allow exit.
   - The system increments the available slot count.
4. **Debouncing:** The system includes logic flags to prevent false triggers or double-counting during vehicle passage.

## 📄 License
This project is open-source and available for educational and modification purposes.
