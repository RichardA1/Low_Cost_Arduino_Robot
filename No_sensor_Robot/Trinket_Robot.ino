      /*
  Robot script
*/
 
int right = 2;
int left = 3;

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(right, OUTPUT);
  pinMode(left, OUTPUT);
  digitalWrite(right, LOW);
  digitalWrite(left, LOW);
}

void Go_forward(){ // moves about 1 inch.
  digitalWrite(right, HIGH);
  digitalWrite(left, HIGH);
  delay(50);
  digitalWrite(right, LOW);
  digitalWrite(left, LOW);
  delay(100);
  digitalWrite(right, HIGH);
  digitalWrite(left, HIGH);
  delay(50);
  digitalWrite(right, LOW);
  digitalWrite(left, LOW);
  delay(100);
  digitalWrite(right, HIGH);
  digitalWrite(left, HIGH);
  delay(50);
  digitalWrite(right, LOW);
  digitalWrite(left, LOW);
  delay(100);
  digitalWrite(right, HIGH);
  digitalWrite(left, HIGH);
  delay(50);
  digitalWrite(right, LOW);
  digitalWrite(left, LOW);
  delay(100);
}

void Go_right(){
  digitalWrite(right, LOW);
  digitalWrite(left, HIGH);
  delay(500);
  digitalWrite(left, LOW);
  delay(100);
}

void Go_left(){
  digitalWrite(right, HIGH);
  digitalWrite(left, LOW);
  delay(1000);
  digitalWrite(right, LOW);
  delay(100);
}

void Full_stop(){
  digitalWrite(right, LOW);
  digitalWrite(left, LOW);
}

// the loop routine runs over and over again forever:
void loop() {
  Go_forward();
  Go_left();
  Go_right();
  
  
}
    
