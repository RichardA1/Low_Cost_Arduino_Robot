/*
 * Braitenberg vehicle
 * This code was adapted to work with the robot found at:
 * http://richardalbritton.wordpress.com/arduino-robot/
 * Original code is from http://tinkerlog.com/2009/04/18/arduino-powered-braitenberg-vehicle/
 */

int right = 1; // For PWM
int left = 4; // For PWM
int R_photo = 2; // For Analog IN
int L_photo = 3; // For Analog IN
//int extra = 0; // For I2C or SPI Data IN
int R_turn = 0;
int L_turn = 0;

// the setup routine runs once when you press reset:
void setup() {
// initialize the digital pin as an output.
pinMode(right, OUTPUT);
pinMode(left, OUTPUT);
}

void loop() {
  // sensor values between 50..900
  R_turn = (analogRead(R_photo) / 4);
  L_turn = (analogRead(L_photo) / 4);
  analogWrite(right, (220 - R_turn));
  analogWrite(left, (220 - L_turn));
  delay(10);
}
