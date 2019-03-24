#include "QuickStats.h"

const int pinAdc = A0;
const int pinLight = A3;
const int buttonPin = 2;
const int ledPin=11;
const int buzzerPin = A1;
int buttonState = 0;
const int interval = 50;
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
    float sounds[interval];
    float lights[interval];
    for (int j=0; j<interval; j++){
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

    float soundStd=stats.stdev(sounds,interval);
    float lightStd=stats.stdev(lights,interval);
    float soundAvg=stats.average(sounds,interval);
    float lightAvg=stats.average(lights,interval);

    int light = analogRead(A3);
    int sound = analogRead(pinAdc);

    if ((sound>soundStd+soundAvg) && (light>lightStd+lightAvg)) {
      digitalWrite(buzzerPin, HIGH);
    }
    else {
      digitalWrite(buzzerPin, LOW);
    }
    
    
}
