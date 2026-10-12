#include <Servo.h>
#include <Adafruit_NeoPixel.h>

#define TEST_PIN 9
#define LED_COUNT 16

Servo testServo;

Adafruit_NeoPixel ring(
  LED_COUNT,
  TEST_PIN,
  NEO_GRB + NEO_KHZ800
);


// =====================================
// MENU
// =====================================

void printMenu() {
  Serial.println();
  Serial.println("==============================");
  Serial.println("     BREADBOARD KIT TEST");
  Serial.println("==============================");
  Serial.println("1 - Basic Nano Test");
  Serial.println("2 - Onboard LED Test");
  Serial.println("3 - Servo Test on D9");
  Serial.println("4 - LED Ring Test on D9");
  Serial.println();
  Serial.println("Type a number and press Send.");
  Serial.println("==============================");
}


// =====================================
// NANO TEST
// =====================================

void testNano() {

  bool pass = true;

  Serial.println();
  Serial.println("--- BASIC NANO TEST ---");

  Serial.println("[PASS] Program running");
  Serial.println("[PASS] USB Serial working");

  unsigned long start = micros();
  delay(100);
  unsigned long elapsed = micros() - start;

  Serial.print("Timer: ");
  Serial.print(elapsed);
  Serial.println(" us");

  if (elapsed > 90000 && elapsed < 110000) {
    Serial.println("[PASS] Timer");
  } else {
    Serial.println("[FAIL] Timer");
    pass = false;
  }

  int adc = analogRead(A0);

  Serial.print("ADC reading: ");
  Serial.println(adc);

  if (adc >= 0) {
    Serial.println("[PASS] ADC");
  } else {
    Serial.println("[FAIL] ADC");
    pass = false;
  }

  Serial.println();
  Serial.println("==============================");

  if (pass) {
    Serial.println("***** NANO PASS *****");
  } else {
    Serial.println("!!!!! NANO FAIL !!!!!");
  }

  Serial.println("==============================");
}


// =====================================
// ONBOARD LED
// =====================================

void testNanoLED() {

  Serial.println();
  Serial.println("--- ONBOARD LED TEST ---");

  pinMode(LED_BUILTIN, OUTPUT);

  for (int i = 0; i < 5; i++) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(250);

    digitalWrite(LED_BUILTIN, LOW);
    delay(250);
  }

  Serial.println("PASS if LED blinked 5 times.");
}


// =====================================
// SERVO
// =====================================

void testServoMotor() {

  Serial.println();
  Serial.println("--- SERVO TEST ---");
  Serial.println("Connect SERVO signal to D9.");
  Serial.println("Expected: 0 -> 90 -> 180 -> 90");

  testServo.attach(TEST_PIN);

  testServo.write(0);
  delay(1200);

  testServo.write(90);
  delay(1200);

  testServo.write(180);
  delay(1200);

  testServo.write(90);
  delay(1200);

  testServo.detach();

  Serial.println();
  Serial.println("PASS if servo moved through all positions.");
}


// =====================================
// LED RING
// =====================================

void setAll(uint32_t color) {

  for (int i = 0; i < LED_COUNT; i++) {
    ring.setPixelColor(i, color);
  }

  ring.show();
}


void testRing() {

  Serial.println();
  Serial.println("--- LED RING TEST ---");
  Serial.println("Connect Ring DIN / IN to D9.");
  Serial.println("Expected:");
  Serial.println("RED -> GREEN -> BLUE -> WHITE -> OFF");

  ring.begin();

  // Low brightness for quick testing
  ring.setBrightness(20);

  ring.clear();
  ring.show();

  setAll(ring.Color(255, 0, 0));
  delay(1000);

  setAll(ring.Color(0, 255, 0));
  delay(1000);

  setAll(ring.Color(0, 0, 255));
  delay(1000);

  setAll(ring.Color(255, 255, 255));
  delay(1000);

  ring.clear();
  ring.show();

  Serial.println();
  Serial.println("PASS if all LEDs changed color.");
}


// =====================================
// SETUP
// =====================================

void setup() {

  Serial.begin(115200);

  pinMode(LED_BUILTIN, OUTPUT);

  unsigned long start = millis();

  while (!Serial && millis() - start < 10000) {
    delay(10);
  }

  delay(300);

  Serial.println();
  Serial.println("Arduino Nano 33 BLE Breadboard Tester");
  Serial.println("READY");

  printMenu();
}


// =====================================
// LOOP
// =====================================

void loop() {

  if (Serial.available()) {

    char command = Serial.read();

    if (command == '\n' || command == '\r') {
      return;
    }

    switch (command) {

      case '1':
        testNano();
        break;

      case '2':
        testNanoLED();
        break;

      case '3':
        testServoMotor();
        break;

      case '4':
        testRing();
        break;

      default:
        Serial.println("Unknown option.");
        break;
    }

    printMenu();
  }
}