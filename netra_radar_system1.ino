#define trigpin 3
#define echopin 2
#define buzzer 7


void setup()
{
    pinMode(trigpin, OUTPUT);
    pinMode(buzzer, OUTPUT);
    pinMode(echopin, INPUT);
    digitalWrite(buzzer, LOW);
    Serial.begin(9600);
}
void loop()
{
    int duration, distance;
    digitalWrite(trigpin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(trigpin, LOW);

    duration = pulseIn(echopin, HIGH);
    distance = (duration / 2) / 29.1;
    if (distance < 0 || distance >= 330)
    {
        Serial.println("out of Range");
    }

    if ((distance >= 0) && (distance <= 100) && (distance < 330))
    {

        digitalWrite(buzzer, HIGH);
      Serial.print("Distance from us :");
    Serial.print(distance);
    Serial.print("Centimeters \n");
    }

    if (distance > 50 && (distance < 330))
    {
        digitalWrite(buzzer, LOW);
      Serial.print("Distance from us :");
    Serial.print(distance);
    Serial.print("Centimeters \n");
    }
    
    


}