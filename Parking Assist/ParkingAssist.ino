int triggerPin = 9;
int echoPin = 8;
int redPin=7;
int greenPin=6;




long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT); // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return 0.01723 * pulseIn(echoPin, HIGH);
}



void setup()
{
    delay(1000);
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
}


void loop()
{
  int value=readUltrasonicDistance(triggerPin,echoPin);
  if(value<40){
    analogWrite(redPin, 255);
    analogWrite(greenPin, 0);
  }else if(value<60){
    analogWrite(redPin, 255);
    analogWrite(greenPin, 80);
  }else if(value<80){
    analogWrite(redPin, 255);
    analogWrite(greenPin, 150);
  }else if(value<100){
    analogWrite(redPin, 200);
    analogWrite(greenPin, 255);
  }else{
    analogWrite(redPin, 0);
    analogWrite(greenPin, 255);
  }

  delay(100); // Delay a little bit to improve simulation performance
}
