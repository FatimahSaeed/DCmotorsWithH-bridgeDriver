// C++ code
//
// Motor A connections
int enA = 9;
int in1 = 8;
int in2 = 7;

// Motor B connections
int enB = 3;
int in3 = 5;
int in4 = 4;

//button and switch to change speed and direction
int switchPinDir = 2;
int switchPinSp = 12;  

void setup() {
  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  //Set input values
  pinMode(switchPinDir, INPUT);
  pinMode(switchPinSp, INPUT);
  
}

void loop() {
  directionControl();
  delay(500);
  speedControl();
  delay(500);
}

// This function lets you control spinning direction of motors
void directionControl() {
  
  boolean reverse = digitalRead(switchPinDir);
  
  digitalWrite(in1, !reverse);
  digitalWrite(in2, reverse);
  digitalWrite(in3, !reverse);
  digitalWrite(in4, reverse);
}
  // This function lets you control speed of the motors
void speedControl() {
  
  int ValueOFswitch;  
  ValueOFswitch = digitalRead(switchPinSp); 
  
  if (ValueOFswitch == HIGH)   
  {  
   // Set motors to maximum speed
  // For PWM maximum possible values are 0 to 255
  analogWrite(enA, 255);
  analogWrite(enB, 255); 
  }else{  
   // Accelerate from zero to maximum speed
  for (int i = 0; i < 256; i++) {
    analogWrite(enA, i);
    analogWrite(enB, i);
    delay(20);
  }
  }  
  
  // Now turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

}