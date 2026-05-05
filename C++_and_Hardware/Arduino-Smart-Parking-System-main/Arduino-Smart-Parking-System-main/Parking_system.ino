#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Servo.h> 

LiquidCrystal_I2C lcd(0x27, 16, 2);    
Servo myservo;

int IR1 = 2;        
int IR2 = 3;        
int servoPin = 9;   

int totalSlots = 4;       
int occupiedSlots = 0;    

int flag1 = 0;  
int flag2 = 0;  

void setup() {
  Serial.begin(9600); 
  
  lcd.init();
  lcd.backlight();
  
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  
  myservo.attach(servoPin);
  myservo.write(90);  
  
  lcd.setCursor(0, 0);
  lcd.print("    ARDUINO     ");
  lcd.setCursor(0, 1);
  lcd.print(" PARKING SYSTEM ");
  delay(2000);
  lcd.clear();
  
  updateDisplay();
}

void loop() { 
  
  if (digitalRead(IR1) == LOW && flag1 == 0) {
    int availableSlots = totalSlots - occupiedSlots;
    
    if (availableSlots > 0) {
      Serial.println("Car detected at entry");
      flag1 = 1;  
      
      if (flag2 == 0) {  
        myservo.write(0);  
        lcd.setCursor(0, 0);
        lcd.print("  Gate Opening  ");
        lcd.setCursor(0, 1);
        lcd.print("  Please Enter  ");
      }
    } else {
      lcd.setCursor(0, 0);
      lcd.print("    SORRY :(    ");  
      lcd.setCursor(0, 1);
      lcd.print("  Parking Full  "); 
      delay(3000);
      updateDisplay();
    }
  }
  
  if (digitalRead(IR2) == LOW && flag2 == 0) {
    Serial.println("Car detected at IR2");
    flag2 = 1;  
    
    if (flag1 == 0 && occupiedSlots > 0) {
      myservo.write(0);  
      lcd.setCursor(0, 0);
      lcd.print("  Gate Opening  ");
      lcd.setCursor(0, 1);
      lcd.print("  Please Exit   ");
    }
  }
  
  if (flag1 == 1 && flag2 == 1) {
    delay(1000);  
    myservo.write(90);  
    
    occupiedSlots++;
    Serial.print("Car entered. Occupied slots: ");
    Serial.println(occupiedSlots);
    
    flag1 = 0;
    flag2 = 0;
    updateDisplay();
  }
  
  if (flag1 == 0 && flag2 == 1 && digitalRead(IR2) == HIGH) {
    delay(1000);  
    myservo.write(90);  
    
    if (occupiedSlots > 0) {
      occupiedSlots--;
      Serial.print("Car exited. Occupied slots: ");
      Serial.println(occupiedSlots);
    }
    
    flag2 = 0;
    updateDisplay();
  }
  
  delay(100);  
}

void updateDisplay() {
  int availableSlots = totalSlots - occupiedSlots;
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("    WELCOME!    ");
  lcd.setCursor(0, 1);
  lcd.print("Slots Left: ");
  lcd.print(availableSlots);
  
  Serial.print("Available slots: ");
  Serial.println(availableSlots);
}