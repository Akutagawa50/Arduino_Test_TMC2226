const int DIR  = 17;
const int STEP = 16;
const int EN = 18;
const int pwmch = 0;
const int LED = 19;
uint8_t counter = 0;

void setup() {
  Serial.begin(115200);
  pinMode(DIR, OUTPUT);
  pinMode(EN, OUTPUT);
  pinMode(LED, OUTPUT);
  digitalWrite(DIR, LOW);
  digitalWrite(EN, LOW);
  digitalWrite(LED, LOW);
  
  ledcSetup(pwmch, 1, 8);
  ledcAttachPin(STEP, pwmch);
  ledcWrite(pwmch, 128);
}

void loop() {
  digitalWrite(DIR, counter & 0x02);
  digitalWrite(LED, counter & 0x01);
  digitalWrite(EN, counter & 0x01);
  ledcSetup(pwmch, 800, 8);
  ledcWrite(pwmch, 16);
  Serial.println(counter);
  counter++;
  delay(2000);
  /*
  for (int i = 500; i < 6000; i += 500) {
    ledcSetup(pwmch, i, 8);
    ledcWrite(pwmch, 128);
    Serial.println(i);
    delay(500);
  }
  */
}
