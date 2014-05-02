
int servoL = 0;
int servoR = 4;
const int lineTrigL = 1;   // pin#2 on the Trinket is Anolog Pin#1 and connected to the left line sensor.
const int lineTrigR = 3;   // pin#3 on the Trinket is Anolog Pin#3 and connected to the right line sensor.

//For delayMicroseconds: Half way is 745. +745 gose CW, -745 gose CCW
// 604 microseconds at 30 times = CW 360%
// 876 microseconds at 30 times = CCW 360%
const int turnCW = 604;
const int turnCCW = 856;

int lineReadL = 0;  // Reading of the left sensor
int lineReadR = 0;  // Reading of the right sensor

int lineMaxL = 300;//(analogRead(1) + 223);  // nuber that defines Black
int lineMaxR = 300;//(analogRead(3) + 223);  // nuber that defines Black

int var = 0;  // Used to loop the servo movements
int randNumber = 0;  // Used to choose a direction to turn

void setup()
{
 pinMode(servoL, OUTPUT);
 pinMode(servoR, OUTPUT);
 //pinMode(2, INPUT);
 //pinMode(4, INPUT);
  //valb = analogRead(2);    // read the input pin
}

void Go_forward(){ // Drive drive forward
    // Start to turn the left wheel CCW.
    digitalWrite(servoL, HIGH);
    delayMicroseconds(turnCCW);
    digitalWrite(servoL, LOW);
    // Start to turn the right wheel CW.
    digitalWrite(servoR, HIGH);
    delayMicroseconds(turnCW);
    digitalWrite(servoR, LOW);
    delay(10);
}
void Go_backward(){ // Drive drive backward
    // Start to turn the left wheel CW.
    digitalWrite(servoL, HIGH);
    delayMicroseconds(turnCW);
    digitalWrite(servoL, LOW);
    // Start to turn the right wheel CCW.
    digitalWrite(servoR, HIGH);
    delayMicroseconds(turnCCW);
    digitalWrite(servoR, LOW);
    delay(10);
}
void TurnL(){ // Turn Left
    // Start to turn the left wheel CCW.
    digitalWrite(servoL, HIGH);
    delayMicroseconds(turnCCW);
    digitalWrite(servoL, LOW);
    // Start to turn the right wheel CCW.
    digitalWrite(servoR, HIGH);
    delayMicroseconds(turnCCW);
    digitalWrite(servoR, LOW);
    delay(100);
}
void TurnR(){ // Turn Right
    // Start to turn the left wheel CW.
    digitalWrite(servoL, HIGH);
    delayMicroseconds(turnCW);
    digitalWrite(servoL, LOW);
    // Start to turn the right wheel CW.
    digitalWrite(servoR, HIGH);
    delayMicroseconds(turnCW);
    digitalWrite(servoR, LOW);
    delay(100);
}

void loop()
{
 lineReadL = analogRead(lineTrigL);  // Reading of the left sensor
 lineReadR = analogRead(lineTrigR);  // Reading of the right sensor
 
 if (lineReadR < lineMaxR && lineReadL < lineMaxL){
   Go_forward();
    randNumber = random(200);
    //lineMaxL = (analogRead(lineTrigL) + 223);  // nuber that defines Black
    //lineMaxR = (analogRead(lineTrigR) + 223);  // nuber that defines Black
 }else if (lineReadL > lineMaxL && lineReadR > lineMaxR){
   if (randNumber < 99) {
     TurnL();
     TurnL();
    TurnL();
    TurnL();
   } else {
     TurnR();
     TurnR();
     TurnR();
     TurnR();
   }
  }else if (lineReadR > lineMaxR){
   TurnL();
 }else if (lineReadL > lineMaxL){
   TurnR();
 }
}

