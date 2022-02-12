const int TOPpin = 5;
const int MIDpin = 3;
const int BOTpin = 6;
const int indicatorLED = 11;
const int systemLED = 12;
const int sigTop = 10;

# include <Servo.h>

Servo TOP;
Servo MID;
Servo BOT;
void setup() {
  // put your setup code here, to run once:
  pinMode(indicatorLED, OUTPUT);
  pinMode(systemLED, OUTPUT);
  pinMode(sigTop, INPUT);
  TOP.attach(TOPpin);
  MID.attach(MIDpin);
  BOT.attach(BOTpin);
  MID.write(0);
  TOP.write(0);
  BOT.write(0);
  digitalWrite(systemLED, HIGH);
  Serial.begin(115200);
}

void loop() {
 process();
 //press(MID);
}


void process(){
  if(Serial.available()){
    
  String intByte = Serial.readStringUntil('\n');
  
  if(intByte == "1"){
    digitalWrite(indicatorLED, HIGH);
    press(TOP);
  }else if(intByte == "2"){
    digitalWrite(indicatorLED, HIGH);
    press(MID);
  }else if(intByte == "3"){
    digitalWrite(indicatorLED, HIGH);
    press(BOT);
  }else if(intByte != "0"){
    digitalWrite(indicatorLED, HIGH);
    }
  }
  digitalWrite(indicatorLED,LOW);
}

 void press(Servo servo){
  int  std = 70;
  // put your main code here, to run repeatedly:
  for(int x = 0; x < std; x++){
    servo.write(x);
    delay(15);
  }
  for(int y = std; y > 0; y--){
    servo.write(y);
    delay(10);
    
  }
}
