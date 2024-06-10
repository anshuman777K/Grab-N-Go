#include <SoftwareSerial.h>
#include <Servo.h>

char character;
Servo myservo1, myservo2, myservo3;

int bluetoothTx = 0;
int bluetoothRx = 1;

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup() {
  // put your setup code here, to run once: 
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(11,OUTPUT);
  

  myservo1.attach(3);
  myservo2.attach(9);
  myservo3.attach(6);
 
  
  Serial.begin(9600);
  bluetooth.begin(9600);


}
void loop() {
if(Serial.available()){
  character = Serial.read();
  Serial.println(character);
}

if(bluetooth.available()> 0)
  {
    int servopos = bluetooth.read();
    int realservo = servopos;
   if(realservo >= 10 && realservo <60) {
      int servo1 = realservo;
      servo1 = map(servo1, 10, 60, 0, 90);
      myservo1.write(servo1);
      Serial.println("Servo1 ON");
      delay(10);
    }
    
    if(realservo >= 102 && realservo <200) {
      int servo2 = realservo;
      servo2 = map(servo2, 102, 200, 0, 90);
      myservo2.write(servo2);
      Serial.println("Servo2 ON");
      delay(10);
    }
     if(realservo >= 202 && realservo <250) {
      int servo3 = realservo;
      servo3 = map(servo3, 202, 220, 0, 60);
      myservo3.write(servo3);
      Serial.println("Servo3 ON");
      delay(10);
    }
    
    
  }
 if (character == 'D') {
digitalWrite(7,HIGH);
digitalWrite(8,LOW);
digitalWrite(12,HIGH);
digitalWrite(13,LOW);
analogWrite(5,250);
analogWrite(11,250);
character=0;
} 
else if (character =='E') {
  digitalWrite(7,LOW);
digitalWrite(8,HIGH);
digitalWrite(12,LOW);
digitalWrite(13,HIGH);
analogWrite(5,250);
analogWrite(11,250);
character=0;   
}
else if (character =='C') {
   digitalWrite(7,LOW);
digitalWrite(8,HIGH);
digitalWrite(12,HIGH);
digitalWrite(13,LOW);
analogWrite(5,250);
analogWrite(11,250);
character=0;

}
else if (character =='B') {
  digitalWrite(7,HIGH);
digitalWrite(8,LOW);
digitalWrite(12,LOW);
digitalWrite(13,HIGH);
analogWrite(5,250);
analogWrite(11,250);
character=0;
}

else if (character =='b') {
analogWrite(5,0);
analogWrite(11,0);
}
else if (character =='c') {
analogWrite(5,0);
analogWrite(11,0);
}
else if (character =='d') {
analogWrite(5,0);
analogWrite(11,0);
}
else if (character =='e') {
analogWrite(5,0);
analogWrite(11,0);
}

}