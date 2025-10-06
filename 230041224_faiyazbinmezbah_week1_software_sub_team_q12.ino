int light;
int limit=500;
void setup()
{
 Serial.begin(9600);
}

void loop()
{
  light=analogRead(A0);
  if(light<limit){
    Serial.println("dark");
  }
  else{
    Serial.println("light");
  }
  delay(500);
}