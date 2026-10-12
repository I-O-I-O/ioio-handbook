#include <Adafruit_NeoPixel.h>

/*
   GROVE QUICK TEST
   Arduino Nano 33 BLE / Nano 33 BLE Sense

   QUICK CONNECTIONS:

   Potentiometer    -> A0
   Button           -> D2
   Passive Buzzer   -> D4
   LED Strip        -> D4   (test instead of buzzer)
   Vibration Motor  -> D6

   Serial Monitor: 115200 baud

   IMPORTANT:
   Test one D4 device at a time:
   either Buzzer OR LED Strip.
*/

// ---------------- PINS ----------------

const int POT_PIN    = A0;
const int BUTTON_PIN = 2;
const int BUZZER_PIN = 4;
const int MOTOR_PIN  = 6;
const int LED_PIN    = LED_BUILTIN;

// Addressable LED strip
const int STRIP_PIN = 4;

// CHANGE THIS if your strip has more LEDs
const int NUM_LEDS = 10;

Adafruit_NeoPixel strip(
  NUM_LEDS,
  STRIP_PIN,
  NEO_GRB + NEO_KHZ800
);


// =====================================================
// MENU
// =====================================================

void printMenu() {

  Serial.println();
  Serial.println("================================");
  Serial.println("       GROVE QUICK TEST");
  Serial.println("================================");
  Serial.println("1 - Potentiometer");
  Serial.println("2 - Button");
  Serial.println("3 - Passive Buzzer");
  Serial.println("4 - Vibration Motor");
  Serial.println("5 - Addressable LED Strip");
  Serial.println("6 - Nano Onboard LED");
  Serial.println("7 - Basic Nano Test");
  Serial.println();
  Serial.println("Type a number and press Send.");
  Serial.println("================================");
}


// =====================================================
// POTENTIOMETER
// =====================================================

void testPotentiometer() {

  Serial.println();
  Serial.println("--- POTENTIOMETER TEST ---");
  Serial.println("Turn the knob.");
  Serial.println("The value should change smoothly.");
  Serial.println();

  unsigned long start = millis();

  while (millis() - start < 7000) {

    int value = analogRead(POT_PIN);

    Serial.print("Potentiometer: ");
    Serial.println(value);

    delay(200);
  }

  Serial.println();
  Serial.println("PASS if values changed when turning.");
}


// =====================================================
// BUTTON
// =====================================================

void testButton() {

  Serial.println();
  Serial.println("--- BUTTON TEST ---");
  Serial.println("Press and release the button.");
  Serial.println();

  pinMode(BUTTON_PIN, INPUT);

  unsigned long start = millis();

  int lastState = -1;
  bool changed = false;

  while (millis() - start < 7000) {

    int state = digitalRead(BUTTON_PIN);

    if (state != lastState) {

      Serial.print("Button state: ");

      if (state == HIGH) {
        Serial.println("HIGH");
      } else {
        Serial.println("LOW");
      }

      if (lastState != -1) {
        changed = true;
      }

      lastState = state;
    }

    delay(20);
  }

  Serial.println();

  if (changed) {
    Serial.println("PASS - Button state changed.");
  } else {
    Serial.println("CHECK - No button change detected.");
  }
}


// =====================================================
// BUZZER
// =====================================================

void testBuzzer() {

  Serial.println();
  Serial.println("--- BUZZER TEST ---");
  Serial.println("You should hear 3 different tones.");
  Serial.println();

  pinMode(BUZZER_PIN, OUTPUT);

  tone(BUZZER_PIN, 500);
  delay(400);
  noTone(BUZZER_PIN);

  delay(200);

  tone(BUZZER_PIN, 1000);
  delay(400);
  noTone(BUZZER_PIN);

  delay(200);

  tone(BUZZER_PIN, 1500);
  delay(400);
  noTone(BUZZER_PIN);

  Serial.println("PASS if you heard 3 tones.");
}


// =====================================================
// VIBRATION MOTOR
// =====================================================

void testMotor() {

  Serial.println();
  Serial.println("--- VIBRATION MOTOR TEST ---");
  Serial.println("Motor should vibrate 3 times.");
  Serial.println();

  pinMode(MOTOR_PIN, OUTPUT);

  for (int i = 0; i < 3; i++) {

    digitalWrite(MOTOR_PIN, HIGH);
    delay(600);

    digitalWrite(MOTOR_PIN, LOW);
    delay(400);
  }

  Serial.println("PASS if you felt 3 vibrations.");
}


// =====================================================
// ADDRESSABLE LED STRIP
// =====================================================

void setStripColor(uint32_t color) {

  for (int i = 0; i < NUM_LEDS; i++) {
    strip.setPixelColor(i, color);
  }

  strip.show();
}

void testLEDStrip() {

  Serial.println();
  Serial.println("--- LED STRIP TEST ---");
  Serial.println("The LEDs should show:");
  Serial.println("RED -> GREEN -> BLUE -> WHITE");
  Serial.println();

  strip.begin();

  // Keep brightness low for testing
  strip.setBrightness(40);

  strip.clear();
  strip.show();

  // RED
  Serial.println("RED");
  setStripColor(strip.Color(255, 0, 0));
  delay(1000);

  // GREEN
  Serial.println("GREEN");
  setStripColor(strip.Color(0, 255, 0));
  delay(1000);

  // BLUE
  Serial.println("BLUE");
  setStripColor(strip.Color(0, 0, 255));
  delay(1000);

  // WHITE
  Serial.println("WHITE");
  setStripColor(strip.Color(255, 255, 255));
  delay(1000);

  // OFF
  strip.clear();
  strip.show();

  Serial.println();
  Serial.println("PASS if LEDs displayed all 4 colors.");
}


// =====================================================
// NANO ONBOARD LED
// =====================================================

void testOnboardLED() {

  Serial.println();
  Serial.println("--- ONBOARD LED TEST ---");
  Serial.println("Nano LED should blink 5 times.");
  Serial.println();

  pinMode(LED_PIN, OUTPUT);

  for (int i = 0; i < 5; i++) {

    digitalWrite(LED_PIN, HIGH);
    delay(250);

    digitalWrite(LED_PIN, LOW);
    delay(250);
  }

  Serial.println("PASS if the onboard LED blinked.");
}


// =====================================================
// BASIC NANO TEST
// =====================================================

void testNano() {

  Serial.println();
  Serial.println("--- BASIC NANO TEST ---");
  Serial.println();

  Serial.println("[PASS] Program is running");
  Serial.println("[PASS] USB Serial communication");

  // Timer test
  unsigned long startTime = micros();

  delay(100);

  unsigned long elapsed = micros() - startTime;

  Serial.print("Timer result: ");
  Serial.print(elapsed);
  Serial.println(" us");

  if (elapsed > 90000 && elapsed < 110000) {
    Serial.println("[PASS] Timer");
  } else {
    Serial.println("[CHECK] Timer");
  }

  // ADC test
  int adc = analogRead(POT_PIN);

  Serial.print("A0 ADC reading: ");
  Serial.println(adc);

  Serial.println("[PASS] ADC responded");

  Serial.println();
  Serial.println("Basic Nano test complete.");
}


// =====================================================
// SETUP
// =====================================================

void setup() {

  Serial.begin(115200);

  pinMode(BUTTON_PIN, INPUT);
  pinMode(MOTOR_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  digitalWrite(MOTOR_PIN, LOW);
  digitalWrite(LED_PIN, LOW);

  // Wait for Serial Monitor
  unsigned long start = millis();

  while (!Serial && millis() - start < 10000) {
    delay(10);
  }

  delay(300);

  Serial.println();
  Serial.println("Arduino Nano 33 BLE Grove Tester");
  Serial.println("READY");

  printMenu();
}


// =====================================================
// LOOP
// =====================================================

void loop() {

  if (Serial.available()) {

    char command = Serial.read();

    // Ignore Enter/newline characters
    if (command == '\n' || command == '\r') {
      return;
    }

    switch (command) {

      case '1':
        testPotentiometer();
        break;

      case '2':
        testButton();
        break;

      case '3':
        testBuzzer();
        break;

      case '4':
        testMotor();
        break;

      case '5':
        testLEDStrip();
        break;

      case '6':
        testOnboardLED();
        break;

      case '7':
        testNano();
        break;

      default:
        Serial.println("Unknown option.");
        break;
    }

    printMenu();
  }
}
