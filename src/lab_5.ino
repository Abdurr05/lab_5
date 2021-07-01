SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);
u_int16_t minValue;
u_int16_t maxValue;
// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.
  pinMode(D7,OUTPUT);
  pinMode(A5,INPUT);
  minValue = 4095;
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  u_int16_t value;
  value = analogRead(A5);
  minValue = min(minValue, value);
  maxValue = max(maxValue, value);
  u_int16_t v;
  v = map(value, maxValue, minValue, 0, 255);
  analogWrite(D7,v);
  
}