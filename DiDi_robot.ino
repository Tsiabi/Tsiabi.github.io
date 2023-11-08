#include <Adafruit_MotorShield.h>
#include <Servo.h> 



long duration;         // Duration of ultrasonic pulse
int distanceCm;        // Distance in centimeters

Servo myservo;	// create servo object to control a servo
int pos = 0;	// variable to store the servo position

void setup() {
  Serial.begin(9600);
  pinMode(A1, OUTPUT);  // Analog pin A1 connected to TRIG
  pinMode(A0, INPUT);   // Analog pin A0 connected to ECHO
  	
	myservo.attach(10);   // attaches the servo on pin 10 to the servo object
}

void loop() {
  digitalWrite(A1, LOW);
  delayMicroseconds(2);
  digitalWrite(A1, HIGH);    // Give a pulse of 10 microseconds on TRIG
  delayMicroseconds(10);
  digitalWrite(A1, LOW);
  duration = pulseIn(A0, HIGH);  // Check the time elapsed in receiving back the pulse on ECHO
  distanceCm = duration * 0.034 / 2;  // Convert to distance in centimeters

  if (distanceCm <= 50) {
    Serial.println(distanceCm);  // If the distance is less than or equal to 20cm, display it
    delay(500);
   } 
	
	// sweeps from 0 degrees to 180 degrees
	for(pos = 0; pos <= 180; pos += 1) 
	{
		myservo.write(pos);
		delay(15);
	}
	// sweeps from 180 degrees to 0 degrees
	for(pos = 180; pos>=0; pos-=1)
	{
		myservo.write(pos);
		delay(15);
	}
}
  
