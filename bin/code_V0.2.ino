#include <Joystick.h>

// Define the size of the moving average window
#define WINDOW_SIZE 10

// Variables to store the sum of the last WINDOW_SIZE readings
int sumZ = 0, sumRz = 0;

// Arrays to store the last WINDOW_SIZE readings
int readingsZ[WINDOW_SIZE] = {0}, readingsRz[WINDOW_SIZE] = {0};

// Variables to keep track of the current index in the readings arrays
int indexZ = 0, indexRz = 0;

// Variables to keep track of the minimum and maximum readings
int minZ = 1023, maxZ = 0, minRz = 1023, maxRz = 0;

// Updated button pins
int buttons[] = {20, 21, 22, 0, 1, 2, 5, 4, 3};

// Joystick pins
int joystickX = A2;
int joystickY = A1;

int prevZ = 0, prevRz = 0;


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
      Joystick.send_now();
    } else {
      Joystick.button(i+1, false);
      Joystick.send_now();
    }
  }

  int zValue = analogRead(joystickY); // Now maps to Z
  int rzValue = analogRead(joystickX); // Now maps to Rz

  // Subtract the last reading
  sumZ -= readingsZ[indexZ];
  sumRz -= readingsRz[indexRz];

  // Read the new value and add it to the sum
  readingsZ[indexZ] = zValue;
  readingsRz[indexRz] = rzValue;
  sumZ += zValue;
  sumRz += rzValue;

  // Increment the index
  indexZ = (indexZ + 1) % WINDOW_SIZE;
  indexRz = (indexRz + 1) % WINDOW_SIZE;

  // Calculate the average
  int avgZ = sumZ / WINDOW_SIZE;
  int avgRz = sumRz / WINDOW_SIZE;

  // Update the minimum and maximum values
  minZ = min(minZ, avgZ);
  maxZ = max(maxZ, avgZ);
  minRz = min(minRz, avgRz);
  maxRz = max(maxRz, avgRz);

  // Map the joystick values to the range -127 to 127
  zValue = map(avgZ, minZ, maxZ, 0, 1032);
  rzValue = map(avgRz, minRz, maxRz, 0, 1032);

  // Log the joystick values
  Serial.print("Z: ");
  Serial.print(zValue);
  Serial.print(", Rz: ");
  Serial.println(rzValue);

  
Joystick.Z(zValue);
Joystick.Zrotate(rzValue);

// Send the state to the host computer
  if (zValue != prevZ || rzValue != prevRz) {
    Joystick.Z(zValue);
    Joystick.Zrotate(rzValue);
    Joystick.send_now();
  }

  // Update the previous joystick values
  prevZ = zValue;
  prevRz = rzValue;
}