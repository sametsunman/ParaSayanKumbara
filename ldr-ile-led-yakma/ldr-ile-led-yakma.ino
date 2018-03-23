const int ldrPin=A0;
const int ldr2Pin=A1;


void setup() {
 Serial.begin(9600);
 pinMode(ldrPin,INPUT);
  pinMode(ldr2Pin,INPUT);
}

void loop() {
  int ldrStatus=analogRead(ldrPin);
    int ldr2Status=analogRead(ldr2Pin);
  if (ldrStatus<=300){
    Serial.println("LDR is Dark");
  
  }

    if (ldr2Status<=300){
    Serial.println("LDR2 is Dark");
  
  }

}
