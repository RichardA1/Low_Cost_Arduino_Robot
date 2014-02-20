const int servo1 = 0;  // Servo control line (orange) on Trinket Pin #0
const int servo2 = 1;   // Servo control line (orange) on Trinket Pin #1
const int sonarTrig = 2;   // Connect the sonar signal pin to this pin on the Trinket.
const int sonarEcho = 3;

// Number in cm when the rover will reverse and try to navigate around.
const int obstacle = 8;

// Duration of a ping, distance in inches, distance converted to cm.
long duration, inches, cm;

//For delayMicroseconds: Half way is 745. +745 gose CW, -745 gose CCW
// 604 microseconds at 30 times = CW 360%
// 876 microseconds at 30 times = CCW 360%
const int turnCW = 604;
const int turnCCW = 856;

int var = 0;  // Used to loop the servo movements
int randNumber = 0;  // Used to choose a direction to turn

void setup()
{
  pinMode(servo1, OUTPUT);
  pinMode(servo2, OUTPUT);
  pinMode(sonarTrig, OUTPUT);
  pinMode(sonarEcho, INPUT);
}

void Go_forward(){ // Drive drive forward
    // Start to turn the left wheel CCW.
    digitalWrite(servo1, HIGH);
    delayMicroseconds(turnCCW);
    digitalWrite(servo1, LOW);
    // Start to turn the right wheel CW.
    digitalWrite(servo2, HIGH);
    delayMicroseconds(turnCW);
    digitalWrite(servo2, LOW);
    delay(10);
}
void Go_backward(){ // Drive drive backward
    // Start to turn the left wheel CW.
    digitalWrite(servo1, HIGH);
    delayMicroseconds(turnCW);
    digitalWrite(servo1, LOW);
    // Start to turn the right wheel CCW.
    digitalWrite(servo2, HIGH);
    delayMicroseconds(turnCCW);
    digitalWrite(servo2, LOW);
    delay(10);
}
void TurnL(){ // Turn Left
    // Start to turn the left wheel CCW.
    digitalWrite(servo1, HIGH);
    delayMicroseconds(turnCCW);
    digitalWrite(servo1, LOW);
    // Start to turn the right wheel CCW.
    digitalWrite(servo2, HIGH);
    delayMicroseconds(turnCCW);
    digitalWrite(servo2, LOW);
    delay(10);
}
void TurnR(){ // Turn Right
    // Start to turn the left wheel CW.
    digitalWrite(servo1, HIGH);
    delayMicroseconds(turnCW);
    digitalWrite(servo1, LOW);
    // Start to turn the right wheel CW.
    digitalWrite(servo2, HIGH);
    delayMicroseconds(turnCW);
    digitalWrite(servo2, LOW);
    delay(10);
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
    // back_track * delay(15) = distance the rover will back-up during 
    // obstacle avoidance.
      var = 0;
      while(var < 30){
        Go_backward();
        var++;
      }
      var = 0;
      randNumber = random(200);
      if (randNumber < 99) {
        while(var < 15){
          TurnL();
          var++;
          }
      } else {
        while(var < 15){
          TurnR();
          var++;
        }
      }
    }
}

/* The Hack-E-Bot can now be programmed to move by giving it instructions like:
Go_forward(); -- to drive forward
Go_backward(); -- to drive backward
TurnR(); -- to turn right
TurnL(); -- to turn left
*/
void loop()
{  
   SonarPing();
   //SonarScan();
  var = 0;
  while(var < 5){
    Go_forward();
    var++;
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
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
