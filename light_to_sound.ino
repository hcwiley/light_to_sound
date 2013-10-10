// pin defines
int BLUE_PIN = 2;
int RED_PIN = 0;
int GREEN_PIN = 1;
int SPEAKER_PIN = 5;

// mininum value for the leds to count as getting light.
// tested this by grabbing led and the pushing up value till it cut off the noise
int min_val = 110;

// max_val varies based on lighting in the area.
// if you have a lot bright lites, make it higher, if not make it lower.
// 300 - 450 is a good default
int max_val = 380;

void setup(){
//  Serial.begin(9600);
  // setup pin in and outs
  pinMode(BLUE_PIN, INPUT);
  pinMode(RED_PIN, INPUT);
  pinMode(GREEN_PIN, INPUT);
  pinMode(SPEAKER_PIN, OUTPUT);
}

void loop(){
  int red_val = analogRead(RED_PIN);
  if(red_val >= max_val)
      red_val = max_val - 1;
  if(red_val > min_val * 1)
    red_val = map(red_val,min_val, max_val, 28000, 10000);
  else
    red_val = 0;
//  
  int blue_val = analogRead(BLUE_PIN);
  if(blue_val >= max_val)
      blue_val = max_val - 1;
  if(blue_val > min_val * 1)
    blue_val = map(blue_val, min_val, max_val, 5000, 1000);
  else
    blue_val = 0;
//  
  int green_val = analogRead(GREEN_PIN);
  if(green_val >= max_val)
      green_val = max_val - 1;
  if(green_val > min_val * 1)
    green_val = map(green_val, min_val, max_val, 400, 100);
  else
    green_val = 0;

  // my PWM is way better...
  for(int i = 0; i < 5; i++){
    if(red_val > 0){
      digitalWrite(SPEAKER_PIN, HIGH);
      delayMicroseconds(red_val);
      digitalWrite(SPEAKER_PIN,LOW);
      delayMicroseconds(red_val);
    }
    if(blue_val > 0) {
      digitalWrite(SPEAKER_PIN, HIGH);
      delayMicroseconds(blue_val);
      digitalWrite(SPEAKER_PIN,LOW);
      delayMicroseconds(blue_val);
    }
    if(green_val > 0){
      digitalWrite(SPEAKER_PIN, HIGH);
      delayMicroseconds(green_val);
      digitalWrite(SPEAKER_PIN,LOW);
      delayMicroseconds(green_val);
    }
  }
}
