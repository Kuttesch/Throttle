#include <Joystick.h>

#define STATE1 0
#define STATE2 1

static int state = STATE1;

    // Updated button pins
int buttons[] = {20, 22, 0, 1, 2, 5, 4, 3};                                                         // Usage: int 'buttonName'[] = {'pin1', 'pin2', ..., 'pinN'};
int statebut = 21;


const int ledPin = 18; // Change to your LED pin number
const int led2Pin = 19; // Change to your second LED pin number


//Core0
    void setup() {
        Serial.begin(115200);                                                                   // Initialize serial communication at 115200 baud rate                                                
        for (int i = 0; i < 8; i++) {                                                           // Loop through all the buttons
            pinMode(buttons[i], INPUT_PULLUP);                                                  // Set the button pins as input with pull-up resistors
        }
        Joystick.begin();                                                                       // Initialize the Joystick library
        pinMode(statebut, INPUT_PULLUP);
        pinMode(ledPin, OUTPUT);
        pinMode(led2Pin, OUTPUT);
    }

    void loop() {
    
        bool currentButtonState = digitalRead(statebut);

        if (currentButtonState == LOW) {

            if (state == STATE1) {

                digitalWrite(ledPin, HIGH);
                digitalWrite(led2Pin, LOW);
                
                for (int i = 0; i < 8; i++) {
                    if (digitalRead(buttons[i]) == LOW) {
                        Joystick.button(i+1, true);
                    } else {
                        Joystick.button(i+1, false);
                    }
                }

                state = STATE2;
                Serial.println("Switched to STATE2");
            } else if (state == STATE2) {

                digitalWrite(ledPin, LOW);
                digitalWrite(led2Pin, HIGH);
                
                for (int i = 0; i < 8; i++) {
                    if (digitalRead(buttons[i]) == LOW) {
                        Joystick.button(i+9, true);
                    } else {
                        Joystick.button(i+9, false);
                    }
                }

                state = STATE1;
                Serial.println("Switched to STATE1");
            }
        }
            Joystick.send_now();                                                                    // Send button states to the host computer
        delay(10);
    }
//Core0