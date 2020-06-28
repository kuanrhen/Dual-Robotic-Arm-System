//Constant in Robotic Arm 1 ( unit in millimeter)
#define a3 180.0
#define d1 106.7
#define a4 140.0
#define a5 49.25
#define d6 21.35
#define a7 50.0
#define pi 3.142
#define distance_between_robot_and_tree 280.0  
#define diameter_of_tree 100.0                  

float x,y,z,o_deg,o_rad;
float theta2,theta7,theta3,theta4,theta2_rad,theta7_rad,theta3_rad,theta4_rad;
float k1,k2;
float delta2,delta3,delta4;
float deltastep2,deltastep3,deltastep4;
float t;

// Desired orientation of end effector was converted into yaw angle (unit in degree)
float desired_deg[]={ 149.9058 , 149.6330 , 149.1920 , 148.5940 , 147.8502 , 146.9718 , 145.9700,  144.8561,  143.6411 , 142.3364,140.9531 , 139.5025, 137.9956 , 136.4438 , 134.8583  ,133.2501 , 131.6306 , 130.0110 , 128.3996,  126.7944 , 125.1904,123.5826,  121.9661 , 120.3360 , 118.6874 , 117.0152 , 115.3146  ,113.5806 , 111.8084,  109.9929 , 108.1309 , 106.2255,104.2816,  102.3040 , 100.2975  , 98.2669  , 96.2170 ,  94.1527  , 92.0788  , 90.0000  , 87.9212 ,  85.8473 ,  83.7830,81.7331,   79.7025,   77.6960 ,  75.7184  , 73.7745 ,  71.8691  , 70.0071 ,  68.1916 ,  66.4194,   64.6854,   62.9848,61.3126 ,  59.6640,   58.0339 ,  56.4174  , 54.8096  , 53.2056  , 51.6004  , 49.9890 ,  48.3694,   46.7499,   45.1417 ,43.5562 ,  42.0044  , 40.4975,   39.0469  ,37.6636  , 36.3589 ,  35.1439  , 34.0300 ,  33.0282   ,32.1498,   31.4060,30.8080 ,  30.3670  , 30.0942 ,  30};

void tapping() 
{
digitalWriteFast(dirbase,HIGH); // Direction of rotation of stepper motor
digitalWriteFast(dir1,HIGH);    // Direction of rotation of stepper motor
digitalWriteFast(dir2,HIGH);    // Direction of rotation of stepper motor

travel(2466,1274,8,4000000);   // move end effector to starting point

 current2=69.36;    // position of theta2
 current3=71.68;    // position of theta3
 current4=-0.43;    // this angle is measured from horizontal line, -sign is upward , +sign is downward
delay(500);
servo1.write(171);  // move end effector yaw angle to starting orientation
delay(200);
  
for(int i=1;i<81;i++)
{
  if (i<19)
  {
    t=i/10.0;
    x=0.6097*t*t*t-4.5419*t*t+43.3;    // desired position for x coordinate
    y=1.6719*t*t*t-7.1144*t*t+255;     // desired position for y coordinate
    z=0.946*t*t*t-4.814*t*t+300;       // desired position for z coordinate
  }
  else if (i<31)
  {
    t=(i-18)/10.0;
    x=-0.4231*t*t*t-1.2495*t*t-10.4246*t+32.14;     // desired position for x coordinate
    y=-0.1176*t*t*t+1.914*t*t-9.3607*t+241.7;       // desired position for y coordinate
    z=-0.4239*t*t*t+0.2947*t*t-8.1348*t+289.92;     // desired position for z coordinate
  }
  else if (i<41)
  {
    t=(i-30)/10.0;
    x=0.9243*t*t*t-2.7729*t*t-15.2514*t+17.1;     // desired position for x coordinate
    y=0.7647*t*t*t+1.4906*t*t-5.2753*t+233.02;    // desired position for y coordinate
    z=0.4105*t*t*t-1.2315*t*t-9.259*t+279.85;     // desired position for z coordinate
  }  
  else if (i<51)
  {
    t=(i-40)/10.0;
    x=0.9243*t*t*t-18.0243*t;            // desired position for x coordinate
    y=-0.7647*t*t*t+3.7847*t*t+230;      // desired position for y coordinate
    z=0.4105*t*t*t-10.4905*t+269.77;     // desired position for z coordinate
  }
  else if (i<63)
  {
    t=(i-50)/10.0;
    x=-0.4231*t*t*t+2.7729*t*t-15.2514*t-17.1;   // desired position for x coordinate
    y=0.1176*t*t*t+1.4906*t*t+5.2753*t+233.02;   // desired position for y coordinate
    z=-0.4239*t*t*t+1.2315*t*t-9.259*t+259.69;   // desired position for z coordinate
  }
  else if (i<81)
  {
    t=(i-62)/10.0;
    x=0.6097*t*t*t+1.2495*t*t-10.4246*t-32.14;   // desired position for x coordinate
    y=-1.6719*t*t*t+1.914*t*t+9.3607*t+241.7;    // desired position for y coordinate
    z=0.946*t*t*t-0.2947*t*t-8.1348*t+249.62;    // desired position for z coordinate
  }
  
  if(i==65)
  {
    o_deg=45.1417;           // get desired orientation time t
  }
  else
  {
    o_deg=desired_deg[i-1];  // get desired orientation time t
  }
o_rad=(o_deg/180.0)*pi;  // convert angle to radian

theta2_rad= atan2(( y-(a7*sin(o_rad))),(x-(a7*cos(o_rad))) );         // inverse kinematics equation for theta2
theta2= (theta2_rad/pi)*180;   // convert radian to angle

theta7_rad= o_rad-theta2_rad;                                         // inverse kinematics equation for theta7
theta7= o_deg-theta2;  

k1=( y-(a7*sin(o_rad))-(a5*sin(theta2_rad)))/sin(theta2_rad);         
k2=z-d1-d6;

theta4_rad= acos(((k1*k1)+(k2*k2)-(a3*a3)-(a4*a4) ) /(2.0*a3*a4)) ;   // inverse kinematics equation for theta4
theta4= (theta4_rad/pi)*180;   // convert radian to angle

theta3_rad= atan2(k2,k1)+atan2((a4*sin(theta4_rad)),((a4*cos(theta4_rad))+a3));   // inverse kinematics equation for theta3
theta3= (theta3_rad/pi)*180;   // convert radian to angle


delta2=theta2-current2;             // get difference in angle between current and desired theta2
delta3=theta3-current3;             // get difference in angle between current and desired theta3
delta4=theta4-theta3-current4;      // get difference in angle between current and desired theta4

deltastep2=delta2*1600/90;          // covert difference in angle to number of steps required
deltastep3=delta3*800/90;           // covert difference in angle to number of steps required
deltastep4=delta4*800/90;           // covert difference in angle to number of steps required

if (deltastep2>=0)
{
  digitalWrite(dirbase,HIGH);            // set direction of rotation
}
else
{
   digitalWrite(dirbase,LOW);            // set direction of rotation
   deltastep2=-deltastep2;               // change steps required into positive value
}
if (deltastep3>=0)
{
  digitalWrite(dir1,HIGH);            // set direction of rotation
}
else
{
   digitalWrite(dir1,LOW);            // set direction of rotation
    deltastep3=-deltastep3;           // change steps required into positive value
}
if (deltastep4>=0)
{
  digitalWrite(dir2,LOW);            // set direction of rotation
}
else
{
   digitalWrite(dir2,HIGH);          // set direction of rotation
    deltastep4=-deltastep4;          // change steps required into positive value
}

deltastep2=int(deltastep2);   // round down steps required for theta 2
deltastep3=int(deltastep3);   // round down steps required for theta 3
deltastep4=int(deltastep4);   // round down steps required for theta 4

homestep1=2.0*deltastep2;
homestep2=2.0*deltastep3;
homestep3=2.0*deltastep4;
travel(homestep1,homestep2,homestep3,100000);  // move end effector to desired position and orientation in 0.1 second

theta7=int(theta7);                            // round down steps required for theta 7
servo1.write(theta7+83.0);                     // move end effector to desired position and orientation in 0.1 second

current2=theta2;            // set current angle for theta2
current3=theta3;            // set current angle for theta3
current4=theta4-theta3;     // set current angle for theta4

}

delay(200);
servo1.write(83);                     // return end effector to initial position and orientation
delay(500);

digitalWrite(dir1,HIGH);
  for(int j=0;j<200;j++)
  {
    digitalWrite(step1,HIGH);
    delay(3);
    digitalWrite(step1,LOW);
    delay(3); 
  }
digitalWrite(dirbase,LOW);
  digitalWrite(dir2,LOW);
  
homeduration=3000000;
homestep1=2.0*1930;
homestep2=2.0*480;
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
  if ((digitalRead(endstopbase)==LOW)&&(digitalRead(endstop2)==LOW))
{
  break;
}

  if ((micros() - pre1 >= interval1)&&(digitalRead(endstopbase)==HIGH))
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
  if ((micros() - pre2 >= interval2)&&(digitalRead(endstop2)==HIGH))
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

 digitalWrite(dir1,LOW);
  digitalWrite(dir2,HIGH);
 
homeduration=3000000;
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

 current2=0.00;    // theta 2 = 0 in home position
 current3=0.00;    // theta 3 = 0 in home position
 current4=0.00;    // theta 4 = 0 in home position
}
