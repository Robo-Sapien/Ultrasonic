int trigPin = 11;   
int echoPin = 12;    
long duration, r;
float distance;

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(115200); 
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);      // set to LOW trigger's output
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);    // send a 10us pulse to the trigger
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  r = 3.4 * duration / 2;      // here we calculate the distance using duration
  distance = r / 100.00;
  if( duration > 38000 ) 
    Serial.println("out of reach");    // if duration is greater than 38ms, the obstacle is out of reach
  else 
   { 
    Serial.print(distance); 
    Serial.println("cm");
   }
  delay(100);
 }
