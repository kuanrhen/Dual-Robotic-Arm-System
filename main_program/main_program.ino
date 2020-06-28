#include <digitalWriteFast.h>
#include <Servo.h>

//Robotic Arm 1 Pin Declaration
#define dir1 55      // HIGH to raise, LOW to lower
#define step1 54     // 800 steps for 90 deg
#define en1 38       // LOW to hold torque

#define dir2 48      // HIGH to raise, LOW to lower
#define step2 46     // 800 steps for 90 deg
#define en2 62       // LOW to hold torque

#define dirbase 28   // HIGH to CCW, LOW to CW
#define stepbase 26  // 1600 steps for 90 deg
#define enbase 24    // LOW to hold torque

#define endstop2 3      // Trigger to LOW
#define endstopbase 2   // Trigger to LOW

//Robotic Arm 2 Pin Declaration
#define dirbase2 61      // LOW to CW, HIGH to CCW
#define stepbase2 60     // 1600 steps for 90 deg
#define enbase2 56       // LOW to hold torque

#define dir3 34      // LOW to raise, HIGH to lower
#define step3 36     // 2400 steps for 90 deg
#define en3 30       // LOW to hold torque

#define endstopbase2 14  // Trigger to LOW

//Servo Motor Pin Declaration
Servo servo1,servo2;           // 0 degree is to the right, 180 is to the left

#define mode1 32    // Press to LOW
#define mode2 47    // Press to LOW
#define mode3 45    // Press to LOW
#define mode4 43    // Press to LOW
#define mode5 41    // Press to LOW

long long homeduration;
long long homestep1;
long long homestep2;
long long homestep3;
long long interval1,interval2,interval3;
int state1,state2,state3;
int count1,count2,count3;
unsigned long  pre1,pre2,pre3;

bool hold=false; // EN state of stepper motor

float current2,current3,current4; // current angle of theta2, theta3 and theta4, same variables are used for both robotic arms

void setup() {
pinMode(dir1,OUTPUT);
pinMode(step1,OUTPUT);
pinMode(en1,OUTPUT);

pinMode(dir2,OUTPUT);
pinMode(step2,OUTPUT);
pinMode(en2,OUTPUT);

pinMode(dir3,OUTPUT);
pinMode(step3,OUTPUT);
pinMode(en3,OUTPUT);

pinMode(dirbase,OUTPUT);
pinMode(stepbase,OUTPUT);
pinMode(enbase,OUTPUT);

pinMode(dirbase2,OUTPUT);
pinMode(stepbase2,OUTPUT);
pinMode(enbase2,OUTPUT);

digitalWrite(en1,HIGH);      // Disable stepper motor
digitalWrite(en2,HIGH);      // Disable stepper motor
digitalWrite(en3,HIGH);      // Disable stepper motor
digitalWrite(enbase,HIGH);   // Disable stepper motor
digitalWrite(enbase2,HIGH);  // Disable stepper motor

pinMode(endstop2,INPUT_PULLUP);
pinMode(endstopbase,INPUT_PULLUP);
pinMode(endstopbase2,INPUT_PULLUP);

pinMode(mode1,INPUT_PULLUP);
pinMode(mode2,INPUT_PULLUP);
pinMode(mode3,INPUT_PULLUP);
pinMode(mode4,INPUT_PULLUP);
pinMode(mode5,INPUT_PULLUP);

servo1.attach(15);
servo2.attach(19);

servo1.write(83);
servo2.write(135);
}

void loop() {
  
  if(digitalRead(mode1)==LOW)
  {
    if(hold==true)
    {
      hold=false;
      digitalWrite(en1,HIGH);      // Disable stepper motor
      digitalWrite(en2,HIGH);      // Disable stepper motor
      digitalWrite(en3,HIGH);      // Disable stepper motor
      digitalWrite(enbase,HIGH);   // Disable stepper motor
      digitalWrite(enbase2,HIGH);  // Disable stepper motor
      delay(500);      // Avoid tactile switch retrigger again
    }
    else
    {
      hold=true;
       digitalWrite(en1,LOW);      // Enable stepper motor
       digitalWrite(en2,LOW);      // Enable stepper motor
       digitalWrite(en3,LOW);      // Enable stepper motor
       digitalWrite(enbase,LOW);   // Enable stepper motor
       digitalWrite(enbase2,LOW);  // Enable stepper motor
       delay(500);    // Avoid tactile switch retrigger again
    }
  }
  else if(digitalRead(mode2)==LOW)
  {
     hold=true;
     digitalWrite(en1,LOW);        // Enable stepper motor for Robotic Arm 1
     digitalWrite(en2,LOW);        // Enable stepper motor for Robotic Arm 1
     digitalWrite(enbase,LOW);     // Enable stepper motor for Robotic Arm 1
  
     home();   // Home action of Robotic Arm 1
  }
  else if(digitalRead(mode3)==LOW)
  {
    hold=true;
     digitalWrite(en1,LOW);      // Enable stepper motor for Robotic Arm 1
     digitalWrite(en2,LOW);      // Enable stepper motor for Robotic Arm 1
     digitalWrite(enbase,LOW);   // Enable stepper motor for Robotic Arm 1
    tapping();    // Start rubber tapping process
  }
 else if(digitalRead(mode4)==LOW)
  {
     hold=true;
     digitalWrite(en3,LOW);      // Enable Stepper motor for Robotic Arm 2
     digitalWrite(enbase2,LOW);  // Enable Stepper motor for Robotic Arm 2
     
     home2();   // Home action of Robotic Arm 1
  }
  else if(digitalRead(mode5)==LOW)
  {
     hold=true;
     digitalWrite(en3,LOW);      // Enable Stepper motor for Robotic Arm 2
     digitalWrite(enbase2,LOW);  // Enable Stepper motor for Robotic Arm 2
     pick_and_place();    // Start pick-and-place task
  }
  



}
