# HaptiJordon - Arduino

HaptiJordon is a wrist-worn wearable technology prototype with the goal of conveying colour information via haptic feedback.
This repository contains the Arduino sketch for the HaptiJordon project and can be run in conjunction with [HaptiJordon](https://github.com/jordones/haptijordon)

# Getting started

To get the Arduino sketch running on an arduino:

- Clone this repo
- Install the [Arduino IDE](https://www.arduino.cc/en/Main/Software)
- `upload` the sketch to an Arduino Uno (note: an additional hardware circuit is required)

## Using HaptiJordon

- Follow `Getting Started` to set up the hardware
- Run the local web application found [here](https://github.com/jordones/haptijordon)

## Extending HaptiJordon

The local web application can be replaced with different input modalities.
Requirements for interfacing with HaptiJordon:

- I2C Serial connection
- Baud Rate of 57600

## Possible inputs to HaptiJordon

| Input | Colour Term |
|-------|-------------|
| 0     | Teal        |
| 1     | Blue        |
| 2     | Green       |
| 3     | Yellowgreen |
| 4     | Red         |
| 5     | Purple      |
| 6     | Magenta     |
| 7     | Pink        |
| 8     | Brown       |
| 9     | Orange      |
| a     | Yellow      |
| b     | Tan         |
| c     | Black       |
| d     | Grey        |
| e     | Beige       |
| f     | White       |

# Code Overview

## Dependencies

- [Wire.h](https://www.arduino.cc/en/reference/wire) - This library allows you to communicate with I2C / TWI devices.
- [Adafruit DRV2605 Library](https://github.com/adafruit/Adafruit_DRV2605_Library) - Library for the Adafruit DRV2605L Haptic Driver.

## References

[Adafruit I2C Multiplexer Documentation][1]
[Adafruit DRV2605 Documentation][2]

[1]: https://learn.adafruit.com/adafruit-tca9548a-1-to-8-i2c-multiplexer-breakout/wiring-and-test
[2]: https://learn.adafruit.com/adafruit-drv2605-haptic-controller-breakout

