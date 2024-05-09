
#include <Joystick.h>

    // Updated button pins
int buttons[] = {20, 21, 22, 0, 1, 2, 5, 4, 3};                                                 // Usage: int 'buttonName'[] = {'pin1', 'pin2', ..., 'pinN'};

    // Joystick pins
    int joystick1 = A1;                                                                         // Usage: int 'joystickY' = 'pin';
    int joystick2 = A2;                                                                         // Usage: int 'joystickX' = 'pin';

//Core0
    void setup() {
            Serial.begin(115200);                                                                   // Initialize serial communication at 115200 baud rate                                                
            for (int i = 0; i < 9; i++) {                                                           // Loop through all the buttons
                pinMode(buttons[i], INPUT_PULLUP);                                                  // Set the button pins as input with pull-up resistors
            }
            Joystick.begin();                                                                       // Initialize the Joystick library
    }

    void loop() {
                for (int i = 0; i < 9; i++) {
                if (digitalRead(buttons[i]) == LOW) {
                    Joystick.button(i+1, true);
                } else {
                    Joystick.button(i+1, false);
                }
            }
            Joystick.send_now();                                                                    // Send button states to the host computer
    }
//Core0

//Core1
    void setup1() {
            Serial.begin(115200);                                                                   // Initialize serial communication at 115200 baud rate                                                
            Joystick.begin();                                                                       // Initialize the Joystick library
    }

    void loop1() {
        //Joystick
            Joystick.Z(constrain(map(analogRead(joystick1), 110, 990, 0, 1000), 0, 1000));         // Usage: Joystick.'axis'(constrain(map(analogRead('pin'), 'min', 'max', 'min', 'max'), 'min', 'max'));
            Joystick.sliderRight(constrain(map(analogRead(joystick2), 560, 860, 0, 1000), 0, 1000));         // Usage: Joystick.'axis'(constrain(map(analogRead('pin'), 'min', 'max', 'min', 'max'), 'min', 'max'));
            Joystick.sliderLeft(constrain(map(analogRead(joystick2), 30, 440, 1000, 0), 0, 1000));          // Usage: Joystick.'axis'(constrain(map(analogRead('pin'), 'min', 'max', 'min', 'max'), 'min', 'max'));

            Joystick.send_now();                                                                   // Send the joystick state to the host computer
        //Joystick

        //Dev
            int zValue = constrain(map(analogRead(joystick1), 110, 990, 0, 1000), 0, 1000);        // Read the Z-axis value from the joystick
            int yValue = constrain(map(analogRead(joystick2), 560, 860, 0, 1000), 0, 1000);        // Read the Rz-axis value from the joystick
            int xValue = constrain(map(analogRead(joystick2), 30, 440, 1000, 0), 0, 1000);  
            //Serial.print("z: ");
            //Serial.print(zValue);
            Serial.print(", y: ");
            Serial.print(yValue);
            Serial.print(", x: ");
            Serial.println(xValue);
        //Dev
    }
//Core1