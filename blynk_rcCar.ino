#define BLYNK_TEMPLATE_ID "TMPL6WKxPh01q"
#define BLYNK_TEMPLATE_NAME "VC car"          // You will get the above two lines from the Blynk console as well
#define BLYNK_AUTH_TOKEN ""     // Your authtoken in the string

#define BLYNK_PRINT Serial

#define IN1 D0
#define IN2 D1
#define IN3 D2
#define IN4 D3

#include <LedControl.h>

// Pin assignments for ESP8266
#define DATA_IN  D7   // DIN (MOSI)
#define CLOCK_PIN D5  // CLK (SCK)
#define LOAD_PIN  D8  // CS

// Initialize LedControl (DIN, CLK, CS, number of devices)
LedControl lc = LedControl(DATA_IN, CLOCK_PIN, LOAD_PIN, 1); // 1 device


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Wire.h> 

BlynkTimer timer;

bool toggleFlag = false;

void allStop() {
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);  
  digitalWrite(IN1, LOW);
}

// FORWARD
BLYNK_WRITE(V0)     
{
  // Set incoming value from pin V0 to a variable
  int temp = param.asInt();
  if (temp == 1) {
    Blynk.virtualWrite(V1, 0);  // OMG ULTRAKILL REFERENCE??/?//?
    Blynk.virtualWrite(V2, 0);
    Blynk.virtualWrite(V3, 0);

    allStop();                  // Reset motor from any transient state

    digitalWrite(IN1, LOW);    // Motor A anti-clockwise
    digitalWrite(IN2, HIGH);

    digitalWrite(IN3, LOW);    // Motor B anti-clockwise
    digitalWrite(IN4, HIGH);

    timer.setTimeout(5000L, allStop);

  }
}
// BACKWARD
BLYNK_WRITE(V1)                 
{
  // Set incoming value from pin V1 to a variable
  int temp = param.asInt();
  if (temp == 1) {
    Blynk.virtualWrite(V0, 0);
    Blynk.virtualWrite(V2, 0);  // OMG ULTRAKILL REFERENCE??/?//?
    Blynk.virtualWrite(V3, 0);
    
    allStop();                  // Reset motor from any transient state

    digitalWrite(IN1, HIGH);    // Motor A clockwise
    digitalWrite(IN2, LOW);

    digitalWrite(IN3, HIGH);    // Motor B clockwise
    digitalWrite(IN4, LOW);

    timer.setTimeout(5000L, allStop);

  }
}

// RIGHT
BLYNK_WRITE(V2)                 
{
  // Set incoming value from pin V2 to a variable
  int temp = param.asInt();
  if (temp == 1) {
    Blynk.virtualWrite(V0, 0);
    Blynk.virtualWrite(V1, 0);  // OMG ULTRAKILL REFERENCE??/?//?
    Blynk.virtualWrite(V3, 0);
    
    allStop();                  // Reset motor from any transient state

    digitalWrite(IN1, LOW);    // Motor A off
    digitalWrite(IN2, LOW);

    digitalWrite(IN3, LOW);    // Motor B anti-clockwise
    digitalWrite(IN4, HIGH);

    timer.setTimeout(1000L, allStop);

  }
}

// LEFT
BLYNK_WRITE(V3)                 
{
  // Set incoming value from pin V3 to a variable
  int temp = param.asInt();
  if (temp == 1) {
    Blynk.virtualWrite(V0, 0);
    Blynk.virtualWrite(V1, 0);  // OMG ULTRAKILL REFERENCE??/?//?
    Blynk.virtualWrite(V2, 0);
    
    allStop();                  // Reset motor from any transient state

    digitalWrite(IN1, LOW);    // Motor A anti-clockwise
    digitalWrite(IN2, HIGH);

    digitalWrite(IN3, LOW);    // Motor B off
    digitalWrite(IN4, LOW);

    timer.setTimeout(1000L, allStop);

  }
}

// STOP
BLYNK_WRITE(V4)                 
{
  // Set incoming value from pin V4 to a variable
  int temp = param.asInt();
  if (temp == 1) {
    Blynk.virtualWrite(V0, 0);
    Blynk.virtualWrite(V1, 0);  // OMG ULTRAKILL REFERENCE??/?//?
    Blynk.virtualWrite(V2, 0);
    Blynk.virtualWrite(V3, 0);
    
    allStop();                  // Reset motor from any transient state

  }
}

// SPIN
BLYNK_WRITE(V6)                 
{
  // Set incoming value from pin V3 to a variable
  int temp = param.asInt();
  if (temp == 1) {
    Blynk.virtualWrite(V0, 0);
    Blynk.virtualWrite(V1, 0);  // OMG ULTRAKILL REFERENCE??/?//?
    Blynk.virtualWrite(V2, 0);
    Blynk.virtualWrite(V3, 0);
    
    allStop();                  // Reset motor from any transient state

    digitalWrite(IN1, LOW);    // Motor A anti-clockwise
    digitalWrite(IN2, HIGH);

    digitalWrite(IN3, HIGH);    // Motor B clockwise
    digitalWrite(IN4, LOW);

    timer.setTimeout(5000L, allStop);

    
    resetLED();
  // Light up a pattern
    lc.setLed(0, 1, 0, true);
    lc.setLed(0, 1, 1, true);
    lc.setLed(0, 2, 2, true);
    lc.setLed(0, 3, 0, true);
    lc.setLed(0, 3, 1, true);

    lc.setLed(0, 1, 6, true);
    lc.setLed(0, 1, 7, true);
    lc.setLed(0, 2, 5, true);
    lc.setLed(0, 3, 7, true);
    lc.setLed(0, 3, 6, true);

    lc.setLed(0, 5, 2, true);
    lc.setLed(0, 5, 3, true);
    lc.setLed(0, 5, 4, true);
    lc.setLed(0, 5, 5, true);

    timer.setTimeout(2000L, resetLED);
  
  }

}



void resetLED() {
// Wake up MAX7219
  lc.shutdown(0, false);  
  // Set brightness (0-15)
  lc.setIntensity(0, 15);  
  // Clear the display
  lc.clearDisplay(0);
}

void bigSmile() {
  resetLED();
  // Light up a pattern
  lc.setLed(0, 1, 1, true);
  lc.setLed(0, 1, 2, true);
  lc.setLed(0, 2, 1, true);
  lc.setLed(0, 2, 2, true);
  lc.setLed(0, 3, 1, true);
  lc.setLed(0, 3, 2, true);
  lc.setLed(0, 2, 6, true);

  lc.setLed(0, 1, 5, true);
  lc.setLed(0, 1, 6, true);
  lc.setLed(0, 2, 5, true);
  lc.setLed(0, 2, 6, true);
  lc.setLed(0, 3, 5, true);
  lc.setLed(0, 3, 6, true);

  for (int i = 1; i <= 6; i++) {
    lc.setLed(0, 5, i, true);
  }

  lc.setLed(0, 6, 2, true);
  lc.setLed(0, 6, 5, true);
  lc.setLed(0, 7, 3, true);
  lc.setLed(0, 7, 4, true);
}

void smile() {
  resetLED();
  // Light up a pattern
  lc.setLed(0, 1, 1, true);
  lc.setLed(0, 1, 2, true);
  lc.setLed(0, 2, 1, true);
  lc.setLed(0, 2, 2, true);
  lc.setLed(0, 2, 6, true);
  lc.setLed(0, 3, 1, true);
  lc.setLed(0, 3, 2, true);

  lc.setLed(0, 1, 5, true);
  lc.setLed(0, 1, 6, true);
  lc.setLed(0, 2, 5, true);
  lc.setLed(0, 2, 6, true);
  lc.setLed(0, 3, 5, true);
  lc.setLed(0, 3, 6, true);

  lc.setLed(0, 5, 2, true);
  lc.setLed(0, 5, 5, true);
  lc.setLed(0, 6, 3, true);
  lc.setLed(0, 6, 4, true);
  lc.setLed(0, 6, 2, true);
  lc.setLed(0, 6, 5, true);
  lc.setLed(0, 5, 1, true);
  lc.setLed(0, 5, 6, true);
}

void alternateFunctions() {
  if (toggleFlag)
    bigSmile();
  else
    smile();
  toggleFlag = !toggleFlag;
}
char ssid[] = "you looked here";
char pass[] = "";    // Change to current wifi credentials

void setup() {
  Serial.begin(115200);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  timer.setInterval(5000L, alternateFunctions);

}

void loop() {
  Blynk.run();
  timer.run();
}
