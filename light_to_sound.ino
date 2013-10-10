int BLUE_PIN = 2;
int RED_PIN = 0;
int GREEN_PIN =1;
int SPEAKER_PIN = 5;

int min_val = 100;

void setup(){
//  Serial.begin(9600);
  pinMode(BLUE_PIN, INPUT);
  pinMode(RED_PIN, INPUT);
  pinMode(GREEN_PIN, INPUT);
  pinMode(SPEAKER_PIN, OUTPUT);
}

void loop(){
  long red_val = analogRead(RED_PIN);
  if(red_val > min_val * 1){
    red_val = map(red_val,min_val, 380, 28000, 10000);
  }
  else
    red_val = 0;
//  
  int blue_val = analogRead(BLUE_PIN);
  if(blue_val > min_val * 1)
    blue_val = map(blue_val, min_val, 380, 5000, 1000);
  else
    blue_val = 0;
//  
  int green_val = analogRead(GREEN_PIN);
  if(green_val > min_val * 1)
    green_val = map(green_val, min_val, 380, 400, 100);
  else
    green_val = 0;
//  
  for(int i = 0; i < 10; i++){
//    for(int j = 0; j < 2; j++){
  if(red_val > 0){
      digitalWrite(SPEAKER_PIN, HIGH);
      delayMicroseconds(red_val);
      digitalWrite(SPEAKER_PIN,LOW);
      delayMicroseconds(red_val);
    }
//    for(int j = 0; j < 2; j++){  
  if(blue_val > 0) {
      digitalWrite(SPEAKER_PIN, HIGH);
      delayMicroseconds(blue_val);
      digitalWrite(SPEAKER_PIN,LOW);
      delayMicroseconds(blue_val);
    }
//    for(int j = 0; j < 2; j++){  
  if(green_val > 0){
      digitalWrite(SPEAKER_PIN, HIGH);
      delayMicroseconds(green_val);
      digitalWrite(SPEAKER_PIN,LOW);
      delayMicroseconds(green_val);
    }
  }
    
//    tone(5, blue_val);
//}
    //delayMicroseconds(100+blue_val);
  
    
    /*delayMicroseconds(red_val - blue_val);
    analogWrite(SPEAKER_PIN, 0);
    delayMicroseconds(red_val - blue_val);
    */
//  }
//  delayMicroseconds(1000/8);
  //delayMicroseconds(100+red_val);
  //analogWrite(3, green_val);
//  delayMicroseconds(100);
  
}
