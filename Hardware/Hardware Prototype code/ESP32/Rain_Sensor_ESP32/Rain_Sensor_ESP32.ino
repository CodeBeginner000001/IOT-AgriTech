

#define RAIN_SENSOR_PIN  15 // The ESP32 pin GPIO25 connected to the sound sensor

int rain_state      = LOW; // current  state of rain sensor's pin
int prev_rain_state = LOW; // previous state of rain sensor's pin

void setup() {
  Serial.begin(9600);              // initialize serial
  pinMode(RAIN_SENSOR_PIN, INPUT); // set ESP32 pin to input mode
}

void loop() {
  prev_rain_state = rain_state;             // store old state
  rain_state  = digitalRead(RAIN_SENSOR_PIN); // read new state

  if (prev_rain_state == LOW && rain_state == HIGH) { // pin state change: LOW -> HIGH
    Serial.println("Rain detected!");
  }
  else
  if (prev_rain_state == HIGH && rain_state == LOW) { // pin state change: HIGH -> LOW
    Serial.println("Rain stopped!");
  }
}
