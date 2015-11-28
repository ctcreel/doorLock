#include <Adafruit_PN532.h>
#include <Time.h>
#include <TimeAlarms.h>
#include <Wire.h>
#include <SPI.h>
#include <ticketManager.h>

ticketManager *tm;

#define MAG_LOCK_POWER 52
#define RELAY_POWER 50
#define BUTTON 48

void setup() {
  Serial.begin(19200);
  tm = new ticketManager;
  pinMode(MAG_LOCK_POWER, OUTPUT);
  pinMode(RELAY_POWER, OUTPUT);
  pinMode(BUTTON, INPUT);
  digitalWrite(RELAY_POWER, HIGH);
  digitalWrite(MAG_LOCK_POWER, HIGH);
  Serial.println("Get ready...");
}

void loop() {

  if(tm->waitForCard()) {
    Serial.println("Card Detected, turning power on.");
    digitalWrite(MAG_LOCK_POWER,LOW);
    Alarm.delay(10000);
    Serial.println("Turning power off.");
    digitalWrite(MAG_LOCK_POWER,HIGH);
  }
}
