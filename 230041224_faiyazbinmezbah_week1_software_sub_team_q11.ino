String s; 
void setup()
{
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}

void loop()
{
  if(Serial.available()){
    s=Serial.readStringUntil('\n');
    s.trim();
    if(s=="light"){
      digitalWrite(13,LOW);
    }
    else if(s=="dark"){
      digitalWrite(13,HIGH);
    }
  }
}