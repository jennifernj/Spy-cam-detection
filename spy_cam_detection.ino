#include "QuickStats.h"

const int pinAdc = A0;
const int pinLight = A3;
const int buttonPin = 2;
const int ledPin=11;
int buttonState = 0;
QuickStats stats;

void setup()
{
    pinMode(ledPin, OUTPUT);
    pinMode(buttonPin, INPUT);
    Serial.begin(9600);
}

void loop()
{
    float sounds[10];
    float lights[10];
    for (int j=0; j<10; j++){
      buttonState = digitalRead(buttonPin);
      long sum = 0;
      for(int i=0; i<32; i++)
      {
          sum += analogRead(pinAdc);
      }
  
      sum >>= 5;
  
      int light = analogRead(A3);
      Serial.print(light);
      Serial.print(",");
      Serial.println(sum);
      if (buttonState == HIGH) {
        digitalWrite(ledPin, HIGH);
      }
      else {
        digitalWrite(ledPin, LOW);
      }
      delay(10);
      sounds[j]=sum;
      lights[j]=light;
    }

    float soundStd=stats.stdev(sounds,10);
    float lightStd=stats.stdev(lights,10);
    float soundAvg=stats.average(sounds,10);
    float lightAvg=stats.average(lights,10);
    
}#include "QuickStats.h"

const int pinAdc = A0;
const int pinLight = A3;
const int buttonPin = 2;
const int ledPin=11;
const int buzzerPin = A1;
int buttonState = 0;
QuickStats stats;

void setup()
{
    pinMode(ledPin, OUTPUT);
    pinMode(buttonPin, INPUT);
    pinMode(buzzerPin, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    float sounds[10];
    float lights[10];
    for (int j=0; j<10; j++){
      buttonState = digitalRead(buttonPin);
      long sum = 0;
      for(int i=0; i<32; i++)
      {
          sum += analogRead(pinAdc);
      }
  
      sum >>= 5;
  
      int light = analogRead(A3);
      Serial.print(light);
      Serial.print(",");
      Serial.println(sum);
      if (buttonState == HIGH) {
        digitalWrite(ledPin, HIGH);
      }
      else {
        digitalWrite(ledPin, LOW);
      }
      delay(10);
      sounds[j]=sum;
      lights[j]=light;
    }

    digitalWrite(buzzerPin, HIGH);
    delay(1000);
    digitalWrite(buzzerPin, LOW);
    delay(1000);

    float soundStd=stats.stdev(sounds,10);
    float lightStd=stats.stdev(lights,10);
    float soundAvg=stats.average(sounds,10);
    float lightAvg=stats.average(lights,10);
    
}
