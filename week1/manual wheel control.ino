
int chan[8]; 
String finalSring="";    

void setup(){
  Serial.begin(115200);
  Serial1.begin(115200);  
}

void loop(){
  readChannel();
  for(int i=0;i<8;i++){
    Serial.print(chan[i]);
    Serial.print(" ");
  }
  Serial.println();
  delay(100);
}
void readChannel(){
  while(Serial1.available()){
    char ch=Serial1.read();
    finalSring+=ch;
    if (ch=='>'){
      int m=finalSring.indexOf('<');
      int n=finalSring.indexOf('>');
      if(m!=-1 && n!=-1 && n>m){
        String s=finalSring.substring(m+1,n);
        convertInt(s);
      }
      finalSring=finalSring.substring(n+1);
    }
  }
}
void convertInt(String s){
  int pre=0;
  for (int i=0;i<8;i++) {
    int last=s.indexOf(' ',pre);
    String val;

    if(last==-1){
      val=s.substring(pre);
    } 
    else{
      val=s.substring(pre,last);
      pre=last+1;
    }
    chan[i]=val.toInt();
  }
}
