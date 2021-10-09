#include <Servo.h>


Servo motor;
int level;
int ang;

void setup()
{
    // put your setup code here, to run once:
    pinMode(8, INPUT_PULLUP);
    Serial.begin(9600);
    pinMode(A0, INPUT);
    motor.attach(3, 1000, 2000);
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
    level = analogRead(A0);



    // put your main code here, to run repeatedly:
    if (!digitalRead(8))
    {
        digitalWrite(LED_BUILTIN, HIGH);
        
        if (level < 100) {
         level = 0;
         
         }

        level -= 100;

        if (level < 0) {
          level = 0;}
        
        ang = map(level, 0, 1023 - 100, 0, 180);
        motor.write(ang);

        Serial.print(level);
        Serial.print(" : ");
        Serial.println(ang);
    }
    else
    {
        digitalWrite(LED_BUILTIN, LOW);
        Serial.println("OFF");
        motor.write(0);
    }

    delay(100);
}
