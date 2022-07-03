const int DIR  = 17;
const int STEP = 16;
const int EN = 18;
const int pwmch = 0;
bool dir_state;

void setup() {
  Serial.begin(115200);
  dir_state = false;
  pinMode(DIR, OUTPUT);
  pinMode(EN, OUTPUT);
  digitalWrite(DIR, LOW);
  digitalWrite(EN, LOW);
  
  ledcSetup(pwmch, 1, 8);
  ledcAttachPin(STEP, pwmch);
  ledcWrite(pwmch, 128);
}

void loop() {
  dir_state = !dir_state;
  digitalWrite(DIR, dir_state);
  
  for (int i = 500; i < 3000; i += 500) {
    ledcSetup(pwmch, i, 8);
    ledcWrite(pwmch, 128);
    Serial.println(i);
    delay(500);
  }
}
