# Breadboard Kit Quick Test Guide

This guide is intended to quickly test the Breadboard Kit.

The goal is to check that the Arduino Nano 33 BLE Sense, micro servo, and RGB LED ring are working.

No extra equipment is required beyond the kit and a computer with Arduino IDE.

[Use this code to test the Breadboard Kit]( ../equipment/Breadboard-Kit-Test-Code.ino)

## Connections

Place the Arduino Nano 33 BLE Sense on the breadboard and connect it to the computer using the USB cable.

For the quick test, both the servo and LED ring use D9 as the signal pin, so test them one at a time.

### Servo Motor

* **Servo red wire** -> 3.3V
* **Servo brown/black** -> GND
* **Servo orange/yellow** -> D9

### RGB LED Ring

* **Ring VCC** -> 3.3V
* **Ring GND** -> GND
* **Ring DIN / IN** -> D9

Make sure the ring is connected to IN or DIN, not OUT or DOUT.

Do not connect both the servo signal and LED ring data input to D9 at the same time.

## Arduino IDE Setup

Select:

Tools -> Board -> Arduino Nano 33 BLE

Then select the connected port:

Tools -> Port -> /dev/cu.usbmodem...

Upload the Breadboard Kit test sketch using the normal Upload arrow.

## Open Serial Monitor

Open:

Tools -> Serial Monitor

You can also use the Serial Monitor icon in the top-right corner of Arduino IDE.

Set the baud rate to:

115200

You should see:

Arduino Nano 33 BLE Breadboard Tester
READY

## Run the Tests

Enter a number in Serial Monitor and press Send.

* 1 - Basic Nano Test
* 2 - Onboard LED Test
* 3 - Servo Test
* 4 - LED Ring Test

### 1. Basic Nano Test

Run:

1

The test checks that the program is running, USB Serial communication works, the timer responds, and the analog input can be read.

A working board should finish with:

***** NANO PASS *****

### 2. Onboard LED Test

Run:

2

The onboard LED should blink several times.

### 3. Servo Test

Connect the servo signal wire to D9 and run:

3

The servo should move approximately:

0 -> 90 -> 180 -> 90 degrees

If the servo moves through several clear positions, it passes the quick test.

### 4. LED Ring Test

Disconnect the servo signal wire from D9.

Connect the LED ring DIN or IN connection to D9 and run:

4

The ring should cycle through:

Red -> Green -> Blue -> White -> Off

If all LEDs light and change color, the ring passes the test.

## Required Libraries

The LED ring test requires the Adafruit NeoPixel library.

In Arduino IDE, open:

Tools -> Manage Libraries

Search for:

Adafruit NeoPixel

Install Adafruit NeoPixel by Adafruit.

The servo test uses the Servo library.


## Further Help

### Arduino is not detected

Disconnect and reconnect the USB cable.

Check:

Tools -> Port

Select the current /dev/cu.usbmodem... port.

If the board still does not appear, try another USB cable, USB port, or adapter.

Some USB cables provide power only and do not support data.

If necessary, quickly press the RESET button twice and check the port list again.

### Arduino shows [not connected]

The previously selected serial port is no longer available.

Reconnect the board and select the new port under:

Tools -> Port

macOS may assign a different port number after reconnecting the board.

### Nothing appears in Serial Monitor

Make sure the baud rate is set to:

115200

Press RESET once and wait for the test menu to appear.

### Adafruit_NeoPixel.h is missing

Install the Adafruit NeoPixel library from:

Tools -> Manage Libraries

Then compile the sketch again.

### OpenOCD or GDB error appears

The debugger was started instead of a normal upload.

Use the normal Upload arrow in Arduino IDE.

### Servo makes a buzzing sound but does not move

Check all three servo connections.

A loose jumper wire or breadboard connection can cause the servo to buzz without moving.

Check:

* **Red wire** -> 3.3V
* **Brown/black** -> GND
* **Orange/yellow** -> D9

Try another jumper wire or another breadboard row if necessary.

Do not leave the servo buzzing for a long time.

### Servo does nothing

Check that the signal wire is actually connected to D9.

Try testing the servo by itself with the LED ring disconnected.

If the servo previously worked and suddenly stops, check for loose connections before changing the code.

### LED ring does not light

Check:

* **VCC** -> 3.3V
* **GND** -> GND
* **DIN** -> D9

Make sure the Arduino data wire is connected to DIN or IN, not DOUT or OUT.

Also inspect the solder joints on the ring.

### LED ring flashes only briefly

This can indicate a loose power, ground, data, or solder connection.

Try another jumper wire and inspect the solder joints.

If another ring works using the same Arduino and code, the original ring is likely damaged.

### Breadboard circuit suddenly stops working

Breadboard connections can easily move by one row.

Before changing the code, check that every jumper is still connected to the correct Arduino pin and breadboard row.

When troubleshooting, disconnect other components and test one device at a time.

### Standard LEDs do not work

Standard LEDs are relatively fragile and can fail more often than other components.

Try another LED and check its polarity before troubleshooting the Arduino or breadboard.

### 3.3 V and 5 V

The Arduino Nano 33 BLE uses 3.3 V logic.

Do not feed 5 V directly into its GPIO pins.

For the Breadboard Kit quick test, use the wiring and voltage specified in the test guide.
