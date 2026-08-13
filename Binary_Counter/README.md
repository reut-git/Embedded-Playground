# ESP32 Binary Counter

A 4-bit binary counter implemented using an ESP32 and four LEDs.

The counter increments every 500 milliseconds from 0 to 15.
Each LED represents one bit of the current number.

## Hardware

- ESP32
- 4 LEDs
- 4 resistors

## Concepts Practiced

- GPIO output
- Binary representation
- Bitwise AND (`&`)
- Bit shifting (`<<`)
- `millis()` for non-blocking timing
- `constexpr`

## How It Works

Each LED represents one bit of the counter.

For each bit, the program checks whether it is set using:

`counter & (1 << i)`

If the bit is set, the corresponding LED is turned on.
Otherwise, it is turned off.
