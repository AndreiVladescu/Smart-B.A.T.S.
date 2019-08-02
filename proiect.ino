// Redarea numelor pinilor : t - Trigger, e - Echo, M - Motor, B - Buzzer
int t1 = 12 ,t2 = 2, t3 = 5, t4 = 7; 

int e1 = 13, e2 = 4, e3 = 6, e4 = 8;

int m1 = 3, m2 = 9, m3 = 11, b = 10;

// Initializarea variabilelor ce vor stoca lungimi
long d1,d2,d3, cm1,cm2,cm3,h,cm4;
 
void setup() {
  //Initializare comunicare serial cu 9600 bits/s
  Serial.begin (9600);
  //Definirea pinilor ca stare
   pinMode(t1, OUTPUT);
  pinMode(e1, INPUT);
   pinMode(t2, OUTPUT);
  pinMode(e2, INPUT);
   pinMode(t3, OUTPUT);
  pinMode(e3, INPUT);
   pinMode(t4, OUTPUT);
  pinMode(e4, INPUT);
   pinMode(m1,OUTPUT); 
   pinMode(m2,OUTPUT); 
   pinMode(m3,OUTPUT); 
   pinMode(b, OUTPUT);

  // Setarea frecventei la 3906 Hz 
  TCCR2B = (TCCR2B & 0xF8) | 2;  // Frecventa PWM pentru pinii 3 si 11 
  TCCR1B = (TCCR1B & 0xF8) | 2;  // Frecventa PWM pentru pinii 9 si 10
}
 
void loop() {
  // Procedeul de initializare al pinului Trigger
  digitalWrite(t1, LOW);
  delayMicroseconds(2);
  digitalWrite(t1, HIGH);
  delayMicroseconds(10);
  digitalWrite(t1, LOW);
  // Preluarea semnalului de la pinul Echo
  // Incarcarea datelor in variabila d1 
  d1 = pulseIn(e1, HIGH);
  // Procesarea informatiei in functie de viteza sunetului prin aer
  cm1 = (d1/2) / 29.1;  

  // 
  if (cm1<60) 
  {
     analogWrite(m1,255); //Se produce un semnal de 100% PWM pentru motorul 1
     delay (5);
  }
  else if (cm1<110)
  {
    analogWrite(m1,200); //Se produce un semnal de 78% PWM pentru motorul 1
    delay (5);
  }
  else if (cm1<130)
  {
    analogWrite(m1,80); // Se produce un semnal de 30% PWM pentru motorul 1
  }
  else analogWrite(m1,0); // Daca niciuna dintre ramuri nu a fost atinsa motorul ramane stins
//////////////////////////////////////////////
  delay(1);  // Intarziere de o milisecunda
//////////////////////////////////////////////
digitalWrite(t2, LOW);
  delayMicroseconds(2);
  digitalWrite(t2, HIGH);
  delayMicroseconds(10);
  digitalWrite(t2, LOW);
 
  pinMode(e2, INPUT);
  d2 = pulseIn(e2, HIGH);
 
  cm2 = (d2/2) / 29.1;  
    
  if (cm2<60) 
  {
     analogWrite(m2,255); //do 50% PWM on pin 3 at the frequency set in TCCR2B 
     delay (5);
  }
  else if (cm2<110)
  {
    analogWrite(m2,200);
    delay (5);
  }
   else if (cm2<130)
  {
    analogWrite(m2,80);
  }
  else analogWrite(m2,0);
 
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

   if (cm3<60) 
  {
     analogWrite(m3,255);
     delay (5);
  }
  else if (cm3<110)
  {
    analogWrite(m3,200);
    delay (5);
  }
  else if (cm3<130)
  {
    analogWrite(m3,80);
  }
   else analogWrite(m3,0);
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

   if (cm4>100)
   {
    tone(b, 2000); // Ton de 2kHz
    delay(20);        
    noTone(b);     // Incetare sunet
   }
  else if (cm4>70) 
  {
     
    tone(b, 1000); // Ton de 1kHz
    delay(20);        
    noTone(b);     // Incetare sunet
  }
  else if (cm4>50)
  {
    tone(b,500); // Ton de 500Hz
    delay (20);
    noTone(b);     // Incetare sunet
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
