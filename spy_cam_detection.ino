const int pinAdc = A0;
const int pinLight = A3;
const int buttonPin = 2;
const int ledPin=11;
int buttonState = 0;

void setup()
{
    pinMode(ledPin, OUTPUT);
    pinMode(buttonPin, INPUT);
    Serial.begin(9600);
}

void loop()
{
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
}
