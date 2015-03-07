#include <Servo.h>
 
Servo RightS;
Servo LeftS;
 
const int servoR = 5;  // Right Servo control line (orange) on Pin #13
const int servoL = 6;   // Left Servo control line (orange) on Pin #8
const int sonarTrig = 3;   // Connect the sonar signal pin to this pin on the Trinket.
const int sonarEcho = 4;
 
// Number in cm when the rover will reverse and try to navigate around.
const int obstacle = 8;
 
// Duration of a ping, distance in inches, distance converted to cm.
long duration, inches, cm;
 
int moveSpeed = 22; // This will make the robot move at 25% of full speed.
int moveTime = 10;
int randNumber = 0;  // Used to choose a direction to turn
 
void setup()
{
  RightS.attach(servoR);
  LeftS.attach(servoL);
  pinMode(sonarTrig, OUTPUT);
  pinMode(sonarEcho, INPUT);
}
 
void loop()
{  
  SonarPing();
  MoveF(moveSpeed, 20);
}
 
/* The Hack-E-Bot can now be programmed to move by giving it instructions like:
MoveStop(stopTime); -- to stop moving
MoveF(moveSpeed, moveTime); -- to drive forward
MoveB(moveSpeed, moveTime); -- to drive backward
TurnR(moveSpeed, moveTime); -- to turn right
TurnL(moveSpeed, moveTime); -- to turn left

stopTime and moveTime are mesured in miliseconds.
moveSpeed is a number between 0 to 90 with 0 being no movment and 90 being full speed.
*/
 
void MoveStop(int T){ // Stop moving, T = stopTime.
  RightS.write(90);
  LeftS.write(90);
  delay(T);
}
 
void MoveF(int S, int T){ // Move forward, S = moveSpeed, T = moveTime.
  RightS.write(90 - S);
  LeftS.write(S + 90);
  delay(T);
}
 
void MoveB(int S, int T){ // Move backward, S = moveSpeed, T = moveTime.
  RightS.write(S + 90);
  LeftS.write(90 - S);
  delay(T);
}
 
void TurnL(int S, int T){ // Turn Left, S = moveSpeed, T = moveTime.
  RightS.write(90 - S);
  LeftS.write(90 - S);
  delay(T);
}
 
void TurnR(int S, int T){ // Turn Right, S = moveSpeed, T = moveTime.
  RightS.write(S + 90);
  LeftS.write(S + 90);
  delay(T);
}
 
void SonarPing() {
  /* The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  Give a short LOW pulse beforehand to ensure a clean HIGH pulse:*/
  digitalWrite(sonarTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(sonarTrig, HIGH);
  delayMicroseconds(5);
  digitalWrite(sonarTrig, LOW);
  /* The sonarEcho pin is used to read the signal from the PING))): a HIGH
  pulse whose duration is the time (in microseconds) from the sending
  of the ping to the reception of its echo off of an object.*/
  duration = pulseIn(sonarEcho, HIGH);
  
  // convert the time into a distance.
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  
  if ( cm < obstacle ) {
    // obstacle avoidance.
      MoveB(moveSpeed, 300);
      randNumber = random(200);
      if (randNumber < 99) {
        TurnL(moveSpeed, 300);
      } else {
        TurnR(moveSpeed, 300);
      }
    }
}
 
long microsecondsToInches(long microseconds)
{
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}
 
long microsecondsToCentimeters(long microseconds)
{
  // The moveSpeed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
