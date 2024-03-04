float temp;
int tempin=A0;
void setup() {
  Serial.begin(9600);
}

void loop() {
  temp=analogRead(tempin);
  temp=temp*0.480845; 
  Serial.print("Temperature");
  Serial.print(temp);
  Serial.print("%c");
  Serial.println();
  delay(1000);

}
