# Quick Test Guide: Grove Kit for First-Year Students

This quick test checks that the Arduino Nano 33 BLE, Grove Shield, Grove cables, and main Grove modules are working. No extra equipment is needed beyond the kit and a PC. (Initially tested on MacOS)

# Use This Code for Arduino IDE to Test Kit's Functionality

[Grove Kit Test Code](../equipment/Grove-Kit-Test-Code.ino)


## 1. Connect the hardware

Place the Arduino Nano 33 BLE into the Grove Shield and connect the Nano to the Mac using the USB cable.

Use these Grove ports:

A0  → Potentiometer
D2  → Button
D4  → Passive Buzzer -> When Done Replace with LED Stick and test again
D6  → Vibration Motor

The buzzer and LED Stick are tested one at a time because they use the same D4 port.


## 2. Select the board and port

• In Arduino IDE, select: Tools → Board → Arduino Nano 33 BLE
• Then select the connected port: Tools → Port → /dev/cu.usbmodem...

If several ports are listed, choose the one that appears when the Arduino is plugged in.


## 3. Upload the test code

Open the Grove Quick Test sketch and click the normal Upload arrow near the top-left of Arduino IDE.
Wait until the upload finishes successfully.



## 4. Open Serial Monitor

• Open: Tools → Serial Monitor

You can also click the Serial Monitor icon in the top-right corner of Arduino IDE.

Set the baud rate at the bottom of Serial Monitor to: 115200

You should see: Arduino Nano 33 BLE Grove Tester | READY


## 5. Run the tests

Type a number into the input box in Serial Monitor and press Send (enter):

1 - Potentiometer
2 - Button
3 - Passive Buzzer
4 - Vibration Motor
5 - LED Stick
6 - Onboard LED
7 - Basic Nano Test

For a quick check:

	•	7, Nano: confirms that the program is running and USB serial communication is working.
	•	1, Potentiometer: connect to A0 and turn the knob. The values should change.
	•	2, Button: connect to D2 and press the button. The state should change.
	•	3, Buzzer: connect to D4. You should hear several tones.
	•	4, Vibration Motor: connect to D6. It should vibrate several times.
	•	5, LED Stick: connect to D4 instead of the buzzer. The LEDs should change color.
	•	6, Onboard LED: the LED on the Nano should blink.

For this first-year Grove kit, these tests are enough for a fast functional check. The OLED can be tested separately if needed.


## Troubleshooting

If something does not work:

	•	No Arduino port appears: unplug and reconnect the Nano. Try another USB cable, USB port, or adapter. The cable must support data.
	•	Arduino shows [not connected]: go to Tools → Port and select the current /dev/cu.usbmodem... port again.
	•	No device found on cu.usbmodem...: reconnect the Nano and select the new port. macOS may assign a different port after reconnecting.
	•	Board still not detected: quickly press the Nano RESET button twice, then check Tools → Port again.
	•	Nothing appears in Serial Monitor: make sure the baud rate is set to 115200, then press RESET once.
	•	Adafruit_NeoPixel.h is missing: install Adafruit NeoPixel from Tools → Manage Libraries.
	•	OpenOCD or GDB error: the debugger was started accidentally. Use the normal Upload arrow instead.
	•	One Grove module does not respond: check that it is connected to the correct port and try another Grove cable before marking the module as faulty.


## Further Help

For common setup problems, connection issues, and important notes about **3.3 V vs 5 V**, see:

[Frequent Issues](../frequent-issues.md)



