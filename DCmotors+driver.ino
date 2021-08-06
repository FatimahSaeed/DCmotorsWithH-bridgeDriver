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
int button = 2;
int switchPin = 12;  

void setup() {
  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  pinMode(switchPin, INPUT);
  
}

void loop() {
  directionControl();
  speedControl();
}

// This function lets you control spinning direction of motors
void directionControl() {
  
  boolean reverse = digitalRead(button);
  
  if (reverse == 1)   
  {  
  digitalWrite(in1, ! reverse);
  digitalWrite(in2, reverse);
  digitalWrite(in3, ! reverse);
  digitalWrite(in4, reverse);
  }  
    
  else   
  {  
  // Now change motor directions
  digitalWrite(in1, reverse);
  digitalWrite(in2, ! reverse);
  digitalWrite(in3, reverse);
  digitalWrite(in4, ! reverse);
  }  
}

  // This function lets you control speed of the motors
void speedControl() {
  
  int ValueOFswitch;  
  ValueOFswitch = digitalRead(switchPin); 
  
  if (ValueOFswitch == 1)   
  {  
   // Set motors to maximum speed
  // For PWM maximum possible values are 0 to 255
  analogWrite(enA, 255);
  analogWrite(enB, 255); 
  }  
    
  else   
  {  
   // Accelerate from zero to maximum speed
  for (int i = 0; i < 256; i++) {
    analogWrite(enA, i);
    analogWrite(enB, i);
    i+50;
  }
  }  
  
  // Now turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

}