
#include <Servo.h>
String string;
bool boolState;
Servo servoLeft; 
Servo servoRight; 
int LedL=11;  
int LedM=8; 
int LedR=3; 
int k = 0;
int flag = 0;
void confusion(int i);

void setup() 
{
Serial.begin(9600); 
servoLeft.attach(13); 
servoRight.attach(12);
servoLeft.writeMicroseconds(1500); 
servoRight.writeMicroseconds(1500);
pinMode(LedL,OUTPUT); 
pinMode(LedR,OUTPUT);
pinMode(LedM,OUTPUT);
}

void loop() 
{
int a[9] = {2,0,1,2,2,1,0,1,9};

Serial.print("A3 = ");
Serial.print(Left(A3));
Serial.println("Left");

Serial.print("A4 = "); 
Serial.print(Middle(A4));
Serial.println("Middle");

Serial.print("A5 = "); 
Serial.print(Right(A5));
Serial.println("Right");
delay(1000);  


if (Left(A3) < 3.5) 
{
digitalWrite(LedL,LOW); 
}
else
  {
    digitalWrite(LedL,HIGH); 
  }


if(Middle(A4) > 3.5) 
{
digitalWrite(LedM,LOW); 
    }
else
  {
    digitalWrite(LedM,HIGH);
  }

if(Right(A5) < 3.5) 
{
digitalWrite(LedR,LOW); 
}
else
  {
    digitalWrite(LedR,HIGH); 
  }


if(Left(A3) < 3.5 && Right(A5) < 3.5 && Middle(A4) < 3.5){
  if(flag == 0){
confusion(a[k]);
Serial.print("Command = "); 
Serial.print(a[k] );
k++;
flag =1;}
}

if(Middle(A4) < 3.5 && Right(A5) < 3.5 && Left(A3) > 3.5) 
{
right();
}

if(Middle(A4) < 3.5 && Left(A3) < 3.5 && Right(A5) > 3.5) 
{
left();
    
}
 if(Left(A3) > 3.5 && Right(A5) > 3.5 && Middle(A4) < 3.5) 
{
forward();
    if (flag == 1)
      flag = 0;
}
}

void confusion(int i){  
if((Left(A3) < 3.5 || Right(A5) < 3.5) && Middle(A4) < 3.5 && (i == 0))
{
  stop1();
right90();
}
if((Left(A3) < 3.5 || Right(A5) < 3.5) && Middle(A4) < 3.5 && (i == 1))
{
  stop1();
left90();
}
if((Left(A3) < 3.5 || Right(A5) < 3.5) && Middle(A4) < 3.5 && (i == 2))
{
  stop1();
forward();
}
if((Left(A3) < 3.5 || Right(A5) < 3.5) && Middle(A4) < 3.5 && (i == 3))
{
stop1();
delay(10000);
}
}

void left()
{
  servoLeft.writeMicroseconds(1650); 
    servoRight.writeMicroseconds(1400);
}

void right()
{
  servoLeft.writeMicroseconds(1650); 
    servoRight.writeMicroseconds(1400);
}

void forward()
{
  servoLeft.writeMicroseconds(1450); 
  servoRight.writeMicroseconds(1550);
}

void left90()
{
  servoLeft.writeMicroseconds(1700); 
    servoRight.writeMicroseconds(0);
}

void right90()
{
  
  servoLeft.writeMicroseconds(0); 
    servoRight.writeMicroseconds(1700);
}

void stop1()
{
servoLeft.writeMicroseconds(1500); 
    servoRight.writeMicroseconds(1500);
    
}

float Left(int A3) 
{
return float(analogRead(A3)) * 5.0 / 1024.0;
}

float Middle(int A4)
{
return float(analogRead(A4)) * 5.0 / 1024.0;
}

float Right(int A5) 
{
return float(analogRead(A5)) * 5.0 / 1024.0;
}
