/*
Robot script
*/

int right = 1;
int left = 4;
int DriveFor = 500; // Change this number to set how far the Robot will move forward.
int TurnFor = 700; // Change this number to set how far the Robot will turn.

// the setup routine runs once when you press reset:
void setup() {
// initialize the digital pin as an output.
pinMode(right, OUTPUT);
pinMode(left, OUTPUT);
digitalWrite(right, LOW);
digitalWrite(left, LOW);
}

void Go_forward(){ // Drive drive forward
digitalWrite(right, HIGH);
digitalWrite(left, HIGH);
delay(DriveFor);
digitalWrite(right, LOW);
digitalWrite(left, LOW);
delay(100);
}

void Go_right(){ // Turn right
digitalWrite(right, LOW);
digitalWrite(left, HIGH);
delay(TurnFor);
digitalWrite(left, LOW);
delay(100);
}

void Go_left(){ // Turn left
digitalWrite(right, HIGH);
digitalWrite(left, LOW);
delay(TurnFor);
digitalWrite(right, LOW);
delay(100);
}

void Full_stop(){ // Stop for a while
digitalWrite(right, LOW);
digitalWrite(left, LOW);
delay(2000);
}

// the loop routine runs over and over again forever:
void loop() {
/* The Hack-E-Bot can now be programmed to move by giving it instructions like:
Go_forward(); -- to drive forward
Go_right(); -- to turn right
Go_left(); -- to turn left
Full_stop(); -- to stop for a while
These should be placed in the order you want the robot to do them in.
Keep in mind that once the robot gets to the end of it's instructions, it will start from the beginning and do them all over again.

To stop the robot from moving for a while, use Full_stop(); in your instructions
*/
Go_forward();
Go_left();
Go_forward();
Full_stop();
Go_right();
Go_right();

}

Edit
