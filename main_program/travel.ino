void travel(long long homestep1,long long homestep2, long long homestep3,long long homeduration)
{
state1=LOW;
state2=LOW;
state3=LOW;
count1=0;
count2=0;
count3=0;
interval1=homeduration/homestep1;    // interval per step/2 for theta2
interval2=homeduration/homestep2;    // interval per step/2 for theta3
interval3=homeduration/homestep3;    // interval per step/2 for theta4
pre1=micros();   // set current time
pre2=micros();   // set current time
pre3=micros();   // set current time
  for(;;)
  {
  if ((count1>=homestep1)&&(count2>=homestep2))     
{
  if(count3>=homestep3)
  {
  break;                        // break the loop after reach desired angle for theta2, theta3 and theta4
  }
}

  if ((micros() - pre1 >= interval1)&&(count1<homestep1))    // rotate theta2 to desired angle with desired timing
  {
    pre1=micros();
    count1++;
    if(state1==LOW)
    {
      state1=HIGH;
      digitalWriteFast(stepbase,state1);
    }
    else
    {
      state1=LOW;
      digitalWriteFast(stepbase,state1);
    }
    
  }
  if ((micros() - pre2 >= interval2)&&(count2<homestep2))   // rotate theta3 to desired angle with desired timing
  {
    pre2=micros();
    count2++;
    if(state2==LOW)
    {
      state2=HIGH;
      digitalWriteFast(step1,state2);
    }
    else
    {    
      state2=LOW;
      digitalWriteFast(step1,state2); 
    }
    
  }
  if ((micros() - pre3 >= interval3)&&(count3<homestep3))     // rotate theta4 to desired angle with desired timing
  {
    pre3=micros();
    count3++;
    if(state3==LOW)
    {
      state3=HIGH;
      digitalWriteFast(step2,state3);
    }
    else
    {    
      state3=LOW;
      digitalWriteFast(step2,state3); 
    }
    
  }
 }  
}
