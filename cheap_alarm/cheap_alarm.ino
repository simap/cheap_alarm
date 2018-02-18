#include <TimerOne.h>

const int mosfet = 3;
const int sensor = 7;
const int led = 13;

void tick() {
  //a pin change interrupt would be cleaner, but I used the wrong pin
  digitalWrite(led, digitalRead(sensor));
}

void setup() {

  Timer1.initialize(10000);
  Serial.begin(115200);

  //turn off mosfet
  digitalWrite(mosfet, LOW);
  pinMode(mosfet, OUTPUT);
  pinMode(sensor, INPUT);
  pinMode(led, OUTPUT);

  digitalWrite(led, HIGH);
  delay(500);
  Serial.println("Chirp test");
  delay(100);
  digitalWrite(mosfet, HIGH);
  delay(100);
  digitalWrite(mosfet, LOW);
  digitalWrite(led, LOW);

  Timer1.attachInterrupt(tick);

  //delay a bit on power on for the PIR sensor to calm down
  //don't want to sound the alarm for a power blip
  Serial.println("Power on delay");
  delay(60000);
  Serial.println("Starting watch");
}

boolean inAlarm = false;
void loop() {
  if (digitalRead(sensor)) {
    Serial.println("Detected");
    //wait 2s then turn on alarm
    if (!inAlarm)
      delay(2000);
    Serial.println("Alarm");
    digitalWrite(mosfet, HIGH);
    delay(30000);
    inAlarm = true;
  } else {
    digitalWrite(mosfet, LOW);
    if (inAlarm) {
      Serial.println("Alarm off");
      inAlarm = false;
    }
  }
}
