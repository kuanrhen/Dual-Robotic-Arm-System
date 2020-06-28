void pick_and_place()
{
 delay(300);
current2=0.00;       // set theta2 to 0
current3=0.00;       // set theta2 to 0
 
 int angle=134; 
  for(int i=0;i<135;i++)        // extend d6 to 50mm
  {
    servo2.write(angle);
    delay(10);
    angle--;
  }

  digitalWrite(dir3,LOW);       // move theta3 to 10 degree using third order polynomial equation
  for(float i=0.1;i<1.6;i=i+0.1)
  {
    t=i;
    theta3=(13.3333*t*t)-(5.925926*t*t*t);
    
delta3=theta3-current3;
deltastep3=delta3*9600/360;
deltastep3=int(deltastep3);

for(int j=1;j<=deltastep3;j++)
{   
    digitalWrite(step3,HIGH);
    delayMicroseconds(50000/deltastep3);
    digitalWrite(step3,LOW);
   delayMicroseconds(50000/deltastep3);
}
current3=theta3;
  }

  digitalWrite(dirbase2,HIGH);     // move theta2 to 180 degree using linear function with parabolic blend
  for(float i=0.1;i<6.1;i=i+0.1)
  {
    t=i;
    if(i<2.1)
    {
      theta2=11.25*t*t;
    }
    else if(i<4.1)
    {
      theta2=45+45*(t-2);
    }
    else if(i<6.1)
    {
      theta2=180-11.25*(6-t)*(6-t);
    }
    
delta2=theta2-current2;
deltastep2=delta2*6400/360;
deltastep2=int(deltastep2);
for(int j=1;j<=deltastep2;j++)
{   
    digitalWrite(stepbase2,HIGH);
    delayMicroseconds(50000/deltastep2);
    digitalWrite(stepbase2,LOW);
   delayMicroseconds(50000/deltastep2);
}
current2=theta2;
  }

  digitalWrite(dir3,HIGH);     // move down theta3 to 0 degree using third order polynomial equation
  for(float i=0.1;i<1.6;i=i+0.1)
  {
    t=i;
    theta3=10-13.3333*t*t+5.925926*t*t*t;
delta3=theta3-current3;
delta3=-delta3;
deltastep3=delta3*9600/360;
deltastep3=int(deltastep3);
for(int j=1;j<=deltastep3;j++)
{   
    digitalWrite(step3,HIGH);
    delayMicroseconds(50000/deltastep3);
    digitalWrite(step3,LOW);
   delayMicroseconds(50000/deltastep3);
}
current3=theta3;
  }

  angle=1;
  for(int i=0;i<135;i++)      // retract d6 to 0mm
  {
    servo2.write(angle);
    delay(10);
    angle++;
  }
  
  while(1)          // wait for signal to return to original position
  {
    if(digitalRead(mode5)==LOW)
    {
      break;
    }
  }
  
   angle=134;
  for(int i=0;i<135;i++)     // extend d6 to 50mm
  {
    servo2.write(angle);
    delay(10);
    angle--;
  }

  digitalWrite(dir3,LOW);     // move up theta3 to 10 degree using third order polynomial equation
  for(float i=0.1;i<1.6;i=i+0.1)
  {
    t=i;
    theta3=13.3333*t*t-5.925926*t*t*t;
delta3=theta3-current3;
deltastep3=delta3*9600/360;
deltastep3=int(deltastep3);
for(int j=1;j<=deltastep3;j++)
{   
    digitalWrite(step3,HIGH);
    delayMicroseconds(50000/deltastep3);
    digitalWrite(step3,LOW);
   delayMicroseconds(50000/deltastep3);
}
current3=theta3;
  }

  digitalWrite(dirbase2,LOW);     // move theta2 to 0 degree using linear function with parabolic blend
  current2=0;
   for(float i=0.1;i<6.1;i=i+0.1)
  {
    t=i;
    if(i<2.1)
    {
      theta2=11.25*t*t;
    }
    else if(i<4.1)
    {
      theta2=45+45*(t-2);
    }
    else if(i<6.1)
    {
      theta2=180-11.25*(6-t)*(6-t);
    }
    
delta2=theta2-current2;
deltastep2=delta2*6400/360;
deltastep2=int(deltastep2);
for(int j=1;j<=deltastep2;j++)
{   
    digitalWrite(stepbase2,HIGH);
    delayMicroseconds(50000/deltastep2);
    digitalWrite(stepbase2,LOW);
   delayMicroseconds(50000/deltastep2);
}
current2=theta2;
  }
current2=0;

  digitalWrite(dir3,HIGH);     // move down theta3 to 0 degree using third order polynomial equation
  for(float i=0.1;i<1.6;i=i+0.1)
  {
    t=i;
    theta3=10-13.3333*t*t+5.925926*t*t*t;
delta3=theta3-current3;
delta3=-delta3;
deltastep3=delta3*9600/360;
deltastep3=int(deltastep3);
for(int j=1;j<=deltastep3;j++)
{   
    digitalWrite(step3,HIGH);
    delayMicroseconds(50000/deltastep3);
    digitalWrite(step3,LOW);
   delayMicroseconds(50000/deltastep3);
}
current3=theta3;
  }

  angle=1;
  for(int i=0;i<135;i++)      // retract d6 to 0mm
  {
    servo2.write(angle);
    delay(10);
    angle++;
  }
}
