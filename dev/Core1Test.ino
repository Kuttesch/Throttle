
#include <Joystick.h>                                             // Usage: int 'buttonName'[] = {'pin1', 'pin2', ..., 'pinN'};

    // Joystick pins
    int joystick1 = A1;                                                                         // Usage: int 'joystickY' = 'pin';
    int joystick2 = A2;                                                                         // Usage: int 'joystickX' = 'pin';
//Core1
    void setup() {
            Serial.begin(115200);                                                                   // Initialize serial communication at 115200 baud rate                                                
            Joystick.begin();                                                                       // Initialize the Joystick library
    }

    void loop() {
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