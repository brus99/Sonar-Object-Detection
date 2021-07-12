#include <Servo.h>       // import arduino's servo library
Servo s1;                // initialize my servo data type

long cm;
long dur;
int currPosition = 0;
const int out=12;
const int in=13;
void setup() {
  // put your setup code here, to run once:
  s1.attach(2);         // attaches servo to pin 2
  Serial.begin(9600);    // begin serial counter at 9600 baud rate
  pinMode(in, INPUT);
  pinMode(out, OUTPUT);
}


void loop() {
  digitalWrite(out,LOW);
  delayMicroseconds(2);
  digitalWrite(out,HIGH);
  delayMicroseconds(10);
  digitalWrite(out,LOW);
  dur =pulseIn(in,HIGH);
  int calcDist =calcCenti(dur);
  Serial.println(String(calcDist));

  
  for (int i = 0; i < 18; i++) {
    if(calcDist > 10) {
      currPosition += 10; 
      s1.write(currPosition);
    }
    else if (calcDist <= 10) {
      Serial.println("I FOUND IT I FOUND IT I FOUND IT");
    }
    }
  }

  
  
  


long calcCenti(long duration){
  return (dur*.0343)/2; 
}
