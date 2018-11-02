#include <Servo.h>
Servo myServo;

int const buttonpin=4;
int const potpin=A0;
int potval;
int angle;
int buttonstate=0;
int counter=0;
void setup() {
myServo.attach(9);
Serial.begin(9600);
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(buttonpin,INPUT);

}

void loop() {
 buttonstate=digitalRead(buttonpin);
 
 if (buttonstate==HIGH) {
   button();
 } 
 else if (buttonstate == LOW) 
  {
    counter++;
    delay(150);
    if (counter>4){
      counter=0;
    }
  
 potval=analogRead(potpin);
 angle=map(potval, 0, 1023, 0, 179);
 delay(15);
 
  if (angle<90){
  digitalWrite(2, HIGH);
  digitalWrite(3,LOW);
 
 }  
 else if (angle>90){
  digitalWrite(3, HIGH);
  digitalWrite(2,LOW);
 }
 }
 printstuff();
myServo.write(angle);
}
void printstuff(){
  Serial.print("potval:");
 Serial.print(potval);

  Serial.print(",angle:");
 Serial.println(angle);

 Serial.print(",buttonstate:");
 Serial.print(buttonstate);

 Serial.print("counter:");
 Serial.print(counter);
 }
  void button() {

  

  if(counter == 0)
    angle=20;  
  else if(counter == 1)
    angle=90;
  else if(counter == 2)
    angle=150; 
  else if(counter == 3)  
    angle=180;
 
}
