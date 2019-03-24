#include "QuickStats.h"

const int pinAdc = A0;
const int pinLight = A3;
const int buttonPin = 2;
const int ledPin=11;
const int buzzerPin = A1;
int buttonState = 0;
const int interval = 50;
int cumSoundSum=0;
int cumLightSum=0;
int count=0;
float sounds[interval];
float lights[interval];
float currSoundAvg;
float currLightAvg;
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
      count++;
    }

    float soundStd=stats.stdev(sounds,interval);
    float lightStd=stats.stdev(lights,interval);
    float soundSum=stats.average(sounds,interval)*interval;
    float lightSum=stats.average(lights,interval)*interval;

    cumSoundSum+=soundSum;
    cumLightSum+=lightSum;
    currSoundAvg=cumSoundSum/count;
    currLightAvg=cumLightSum/count;

    int light = analogRead(A3);
    int sound = analogRead(pinAdc);

    if ((sound>soundStd+currSoundAvg) && (light>lightStd+currLightAvg)) {
      digitalWrite(buzzerPin, HIGH);
    }
    else {
      digitalWrite(buzzerPin, LOW);
    }
    
    
}
