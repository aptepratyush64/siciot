int led = 32; //Pin that the LED is attached to
int sensor = 23; //Pin that the sensor is attached to
int state = HIGH; // by default, no motion detected
int val = 0; // variable to sensor status (value)
void setup() {
  pinMode(led, OUTPUT); // Initialize LED as an output
  pinMode(sensor, INPUT); // Initialize sensor as an input
  Serial.begin(115200); // initialize serial
}
void loop(){
val = digitalRead(sensor); // read sensor value
if (val == HIGH) { // check if the sensor is HIGH
digitalWrite(led, HIGH); // turn LED ON
delay(100); // delay 100 milliseconds
if (state == LOW) {
Serial.println("Motion detected!");
state = HIGH; // update variable state to HIGH
}
}
else {
digitalWrite(led, LOW); // turn LED OFF
delay(200); // delay 200 milliseconds
if (state == HIGH){
Serial.println("Motion stopped!");
state = LOW; // update variable state to LOW
}
}
}