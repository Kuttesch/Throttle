
#include <Joystick.h>

    // Updated button pins
    int buttons[] = {20, 21, 22, 0, 1, 2, 5, 4, 3};

    // Joystick pins
    int joystickX = A2;
    int joystickY = A1;


void setup() {
    Serial.begin(115200);
    for (int i = 0; i < 9; i++) {
        pinMode(buttons[i], INPUT_PULLUP);
    }
    Joystick.begin();
}

void loop() {
    for (int i = 0; i < 9; i++) {
        if (digitalRead(buttons[i]) == LOW) {
            Joystick.button(i+1, true); // Button indices start from 1
        } else {
            Joystick.button(i+1, false);
        }
    }
    Joystick.send_now(); // Send button states

    int zValue = analogRead(joystickY); // Now maps to Z
    int rzValue = analogRead(joystickX); // Now maps to Rz

    zValue = map(zValue, 100, 999, 0, 1000);
    rzValue = map(rzValue, 20, 870, 0, 1000);

    // Limit the joystick values to the range 0-1000
    zValue = constrain(zValue, 0, 1000);
    rzValue = constrain(rzValue, 0, 1000);


    // Log the joystick values
    Serial.print("Z: ");
    Serial.print(zValue);
    Serial.print(", Rz: ");
    Serial.println(rzValue);

    Joystick.Z(zValue);
    Joystick.Zrotate(rzValue);
    Joystick.send_now();
}