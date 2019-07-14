int t1 = 12;  
int t2 = 2;
int t3 = 5;
int t4 = 7; 
  
int e1 = 13;   
int e2 = 4;
int e3 = 6;
int e4 = 8;

int m1 = 3;
int m2 = 9;
int m3 = 11;
int b = 10;

// TRIGGER apoi ECHO
long d1,d2,d3, cm1,cm2,cm3,h,cm4;
 
void setup() {
  //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(t1, OUTPUT);
  pinMode(e1, INPUT);
   pinMode(t2, OUTPUT);
  pinMode(e2, INPUT);
   pinMode(t3, OUTPUT);
  pinMode(e3, INPUT);
   pinMode(t4, OUTPUT);
  pinMode(e4, INPUT);

  pinMode(m1,OUTPUT); //make pin 3 an output
  pinMode(m2,OUTPUT); 
  pinMode(m3,OUTPUT); 
  pinMode(b, OUTPUT); // Set buzzer - pin 9 as an output
  
  TCCR2B = (TCCR2B & 0xF8) | 2; //set PWM frequency to 3906 Hz for pin 3 (and 11)
  TCCR1B = (TCCR1B & 0xF8) | 2;  // PWM freq of 9 and 10
}
 
void loop() {
  digitalWrite(t1, LOW);
  delayMicroseconds(2);
  digitalWrite(t1, HIGH);
  delayMicroseconds(10);
  digitalWrite(t1, LOW);
 
  pinMode(e1, INPUT);
  d1 = pulseIn(e1, HIGH);
 
  cm1 = (d1/2) / 29.1;  
    
  if (cm1<50) 
  {
     analogWrite(m1,250); //do 50% PWM on pin 3 at the frequency set in TCCR2B 
     delay (5);
  }
  else if (cm1<100)
  {
    analogWrite(m1,100);
    delay (5);
  }
  else if (cm1>100)
  {
    analogWrite(m1,1);
  }

//////////////////////////////////////////////
  delay(1); 
//////////////////////////////////////////////
digitalWrite(t2, LOW);
  delayMicroseconds(2);
  digitalWrite(t2, HIGH);
  delayMicroseconds(10);
  digitalWrite(t2, LOW);
 
  pinMode(e2, INPUT);
  d2 = pulseIn(e2, HIGH);
 
  cm2 = (d2/2) / 29.1;  
    
  if (cm2<50) 
  {
     analogWrite(m2,250); //do 50% PWM on pin 3 at the frequency set in TCCR2B 
     delay (5);
  }
  else if (cm2<100)
  {
    analogWrite(m2,100);
    delay (5);
  }
   else if (cm2>100)
  {
    analogWrite(m2,1);
  }
 
/////////////////////////////////////////////////
  delay(1); 
/////////////////////////////////////////////////
digitalWrite(t3, LOW);
  delayMicroseconds(2);
  digitalWrite(t3, HIGH);
  delayMicroseconds(10);
  digitalWrite(t3, LOW);
 
  pinMode(e3, INPUT);
  d3 = pulseIn(e3, HIGH);
 
  cm3 = (d3/2) / 29.1;   

   if (cm3<50) 
  {
     analogWrite(m3,250); //do 50% PWM on pin 3 at the frequency set in TCCR2B 
     delay (5);
  }
  else if (cm3<100)
  {
    analogWrite(m3,100);
    delay (5);
  }
  else if (cm3>100)
  {
    analogWrite(m3,1);
  }
/////////////////////////////////////////////////
  delay(1); 
/////////////////////////////////////////////////
digitalWrite(t4, LOW);
  delayMicroseconds(2);
  digitalWrite(t4, HIGH);
  delayMicroseconds(10);
  digitalWrite(t4, LOW);
 
  pinMode(e4, INPUT);
  h = pulseIn(e4, HIGH);
 
  cm4 = (h/2) / 29.1;  

   if (cm4>350)
   {
    delay(1);
   }
  else if (cm4>60) 
  {
     
    tone(b, 1000); // Send 1KHz sound signal...
    delay(20);        
    noTone(b);     // Stop sound...
  }
  else if (cm4>40)
  {
    analogWrite(b,500);
    delay (20);
    noTone(b);     // Stop sound...
  }
 
///////////////////////////////////////////////

  Serial.print(cm1);
  Serial.print("=cm_1");
  Serial.println();
  
  delay(1);
  
  Serial.print(cm2);
  Serial.print("=cm_2");
  Serial.println();
  
  delay(1);
  
  Serial.print(cm3);
  Serial.print("=cm_3");
  Serial.println();

  delay (1);

  Serial.print(cm4);
  Serial.print("=h");
  Serial.println();
  
  delay(5);
}
