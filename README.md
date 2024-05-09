# Throttle

This project aims to give an example on how to use a Raspberry Pi Pico as an USB-HID device. The Pico is used to control a throttle for a flight simulator. The throttle is connected to the Pico via USB. The Pico is connected to the host computer via USB. The Pico is recognized as a USB HID device by the host computer. The throttle is recognized as a joystick by the host computer. The throttle has a main potentiometer that acts as the throttle itself. The throttle has a secondary potentiometer that acts as a joystick. The throttle has 8 buttons that can be used to control the flight simulator.

## Table of Contents

- [Structure](#structure)
- [Code](#code)
- [Hardware](#hardware)
  - [Main Potentiometer](#Main-Potentiometer)
  - [Secondary Potentiometer](#Secondary-Potentiometer)
  - [Buttons](#Buttons)
  - [Wiring Diagram](#Wiring-Diagram)
- [Dependencies](#dependencies)
- [Bugs and Future Features](#Bugs-and-Future-Features)
  - [Bugs](#Bugs)
  - [Future Features](#Future-Features)
- [Usage](#usage)
- [Contributing](#contributing)

## Structure

The project is structured into two main parts:

1. `Core0`: This core is responsible for handling the button inputs. It reads the state of each button and sends the button states to the host computer.

2. `Core1`: This core is responsible for handling the joystick inputs. It reads the analog values from the joystick, maps these values to a specific range, and sends the joystick state to the host computer. It also prints the mapped values of the joystick axes to the serial monitor for debugging purposes.

## Code

The main code `code_mt.ino` (mt for multithreading) is located in the root of the project. In the `dev` folder you can find the code split up into its two cores as described above. The `bin` folder contains old versions of the code.

## Hardware

The used microcontroller is an [Raspberry Pi Pico](https://www.raspberrypi.com/products/raspberry-pi-pico/). Due to its dual core architecture, the code can be split up into two cores to handle the joystick and button inputs separately and simultaneously. 
The Pico is connected to the host computer via USB. The Pico is powered by the host computer. The Pico is connected to the host computer as a USB HID device. \
For me personally I used the Throttle part of an [Thrustmaster T.Flight Hotas X](https://www.thrustmaster.com/de-de/products/t-flight-hotas-x/). The throttle is connected to the Pico via a USB cable. The throttle and Joystick were separated and the controlling of the throttle was replaced by the Pico.\
You can use any throttle you want, or build your own.

### Main Potentiometer

The main potentiometer is connected to pin `A1`. It acts as the throttle itself. The potentiometer is connected to the 5V and GND pins of the Arduino. The wiper of the potentiometer is connected to pin `A1`.

### Secondary Potentiometer

The secondary potentiometer is connected to pin `A2`. It acts as the joystick. The potentiometer is connected to the 5V and GND pins of the Arduino. The wiper of the potentiometer is connected to pin `A2`. \
In the Software it is split up into two axes. One from the middle position to the left (30 - 440) and the other to the right (560 - 1000) with a buffer in the middle.

### Buttons

There are 8 buttons connected to pins `20, 21, 22, 0, 1, 2, 5, 4, 3`. The buttons are connected to the 5V and GND pins of the Arduino. The other side of the buttons are connected to the pins. The buttons are read using the `digitalRead()` function.

### Wiring Diagram

For my personal project the wiring looks as follows:

The wiring diagram of the throttle will be added in the future.

Until then, the wiring is as follows:
- Main Potentiometer: 5V, GND, A1
- Secondary Potentiometer: 5V, GND, A2
- Buttons: GND, 20, 21, 22, 0, 1, 2, 5, 4, 3

## Dependencies

This project depends on the Joystick library from [Benjamin Aigner](https://github.com/benjaminaigner/Joystick). Make sure to install this library before running the code.

## Bugs and Future Features

### Bugs
Currently there are no known bugs.

### Future Features

- Implement two Profiles that can be switched using button (GP 21) so that the throttle has effectively double the amount of buttons.
- Adding the wiring diagram of the throttle to the README.

## Usage

If you are using the same Hardware as me, follow the wiring diagram above. If you are using different hardware, make sure to adjust the code accordingly. \
The code can be uploaded to the Pico using the Arduino IDE. Make sure to select the correct board and port in the IDE.
After uploading the code, the Pico should be recognized as a USB HID device. The joystick should be recognized by the host computer.

## Contributing

Contributions are welcome. Please open an issue or submit a pull request if you would like to contribute to this project.

## License

[MIT](https://choosealicense.com/licenses/mit/)