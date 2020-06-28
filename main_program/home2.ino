void home2()
{
  digitalWrite(dirbase2,LOW);                 // move theta2 to 0 degree
  while(digitalRead(endstopbase2)==HIGH)
  {
    digitalWrite(stepbase2,HIGH);
    delay(1);
    digitalWrite(stepbase2,LOW);
    delay(1);
  }
  servo2.write(120);                          // move d6 to 0mm
}
