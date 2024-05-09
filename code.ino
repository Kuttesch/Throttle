
#include <Joystick.h>

    // Updated button pins
int buttons[] = {20, 21, 22, 0, 1, 2, 5, 4, 3};                                                 // Usage: int 'buttonName'[] = {'pin1', 'pin2', ..., 'pinN'};

    // Joystick pins
    int joystickX = A2;                                                                         // Usage: int 'joystickX' = 'pin';
    int joystickY = A1;                                                                         // Usage: int 'joystickY' = 'pin';


void setup() {
        Serial.begin(115200);                                                                   // Initialize serial communication at 115200 baud rate                                                
        for (int i = 0; i < 9; i++) {                                                           // Loop through all the buttons
            pinMode(buttons[i], INPUT_PULLUP);                                                  // Set the button pins as input with pull-up resistors
        }
        Joystick.begin();                                                                       // Initialize the Joystick library
}

void loop() {
    //Button
            for (int i = 0; i < 9; i++) {
            if (digitalRead(buttons[i]) == LOW) {
                Joystick.button(i+1, true);
            } else {
                Joystick.button(i+1, false);
            }
        }
        Joystick.send_now();                                                                    // Send button states to the host computer
    //Button

    //Joystick
        Joystick.Z(constrain(map(analogRead(joystickY), 100, 1000, 0, 1000), 0, 1000));         // Usage: Joystick.'axis'(constrain(map(analogRead('pin'), 'min', 'max', 'min', 'max'), 'min', 'max'));
        Joystick.Zrotate(constrain(map(analogRead(joystickX), 20, 870, 0, 1000), 0, 1000));     // Usage: Joystick.'axis'(constrain(map(analogRead('pin'), 'min', 'max', 'min', 'max'), 'min', 'max'));

        Joystick.send_now();                                                                    // Send the joystick state to the host computer
    //Joystick

    //Dev
        int zValue = constrain(map(analogRead(joystickY), 100, 1000, 0, 1000), 0, 1000);        // Read the Z-axis value from the joystick
        int rzValue = constrain(map(analogRead(joystickX), 20, 870, 0, 1000), 0, 1000);         // Read the Rz-axis value from the joystick
        Serial.print("Z: ");
        Serial.print(zValue);
        Serial.print(", Rz: ");
        Serial.println(rzValue);
    //Dev
}
