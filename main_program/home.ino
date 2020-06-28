void home()
{
  digitalWrite(dir1,HIGH);            // raise theta 3 to 90 degree
  for(int i=0;i<800;i++)
  {
    digitalWrite(step1,HIGH);
    delay(3);
    digitalWrite(step1,LOW);
    delay(3);
    
  }
  digitalWrite(dir2,LOW);                // move theta 4 to home position
  while(digitalRead(endstop2)==HIGH)
  {
    digitalWrite(step2,HIGH);
    delay(4);
    digitalWrite(step2,LOW);
    delay(4);
  }
  digitalWrite(dirbase,LOW);             // move theta 2 to home position
  delay(500);
  while(digitalRead(endstopbase)==HIGH)
  {
    digitalWrite(stepbase,HIGH);
    delay(1);
    digitalWrite(stepbase,LOW);
    delay(1);
  }
  delay(1000);
  digitalWrite(dir1,LOW);
  digitalWrite(dir2,HIGH);
 
homeduration=3000000;                   // move theta2, theta3, theta4 and theta7 to 0 degree
homestep1=1600;
homestep2=1360;
state1=LOW;
state2=LOW;
count1=0;
count2=0;
interval1=homeduration/homestep1;
interval2=homeduration/homestep2;
pre1=micros();
pre2=micros();
  for(;;)
  {
  if ((count1>=homestep1)&&(count2>=homestep2))
{
  break;
}

  if ((micros() - pre1 >= interval1)&&(count1<homestep1))
  {
    pre1=micros();
    count1++;
    if(state1==LOW)
    {
      state1=HIGH;
      digitalWriteFast(step1,state1);
    }
    else
    {
      state1=LOW;
      digitalWriteFast(step1,state1);
    }
    
  }
  if ((micros() - pre2 >= interval2)&&(count2<homestep2))
  {
    pre2=micros();
    count2++;
    if(state2==LOW)
    {
      state2=HIGH;
      digitalWriteFast(step2,state2);
    }
    else
    {    
      state2=LOW;
      digitalWriteFast(step2,state2); 
    }
    
  }
 }
 servo1.write(83);
 current2=0.00;           // set current theta2 = 0
 current3=0.00;           // set current theta3 = 0
 current4=0.00;           // set current theta4 = 0
} 
