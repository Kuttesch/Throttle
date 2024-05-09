#define STATE1 0
#define STATE2 1

static int state = STATE1;

// Declare the pin numbers
const int buttonPin = 21; // Change to your button pin number
const int ledPin = 18; // Change to your LED pin number
const int led2Pin = 19; // Change to your second LED pin number

void setup() {
    // Initialize the button and LED pins
    pinMode(buttonPin, INPUT_PULLUP);
    pinMode(ledPin, OUTPUT);
    pinMode(led2Pin, OUTPUT);
}

void loop() {
    bool currentButtonState = digitalRead(buttonPin);

    if (currentButtonState == HIGH) {
        // Button is pressed
        if (state == STATE1) {
            // Switch to STATE2
            digitalWrite(ledPin, LOW);
            digitalWrite(led2Pin, HIGH);
            state = STATE2;
            Serial.println("Switched to STATE2");
        } else if (state == STATE2) {
            // Switch to STATE1
            digitalWrite(ledPin, HIGH);
            digitalWrite(led2Pin, LOW);
            state = STATE1;
            Serial.println("Switched to STATE1");
        }
        // Wait for the button to be released before checking again
        while (digitalRead(buttonPin) == HIGH) {
            delay(10); // Debounce delay
        }
    }
}