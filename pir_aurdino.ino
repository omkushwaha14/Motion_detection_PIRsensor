//motion detection using pirsensor by aurdino _____project by om nath kushwaha//

int ledpin = 13;               // set led indication when pir is high,when pir is high led is also high
int pirpin = 2;                // set pir pin to 2
int val;                       // variable to be high or low
int speakerpin = 10;           //Set speaker to positive to 10 and negative to GND

void setup() {
  pinMode(ledpin, OUTPUT);     
  pinMode(pirpin, INPUT);      
  pinMode(speakerpin, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  val = digitalRead(pirpin);    // read input value
  if (val == HIGH) {            // check if the input is HIGH
    digitalWrite(ledpin, HIGH); // turn LED ON
    playTone(300, 160);
    Serial.println("motion detected playing tone on");
    delay(150);
} else {
      digitalWrite(ledpin, LOW); // turn LED OFF
      playTone(0, 0);
       Serial.println("motion ended playing tone off");
      delay(300);    
    
  }
}
// duration in mSecs, frequency in hertz
void playTone(long duration, int freq) {
    duration *= 1000;
    int period = (1.0 / freq) * 1000000;
    long elapsed_time = 0;
    while (elapsed_time < duration) {
        digitalWrite(speakerpin,HIGH);
        delayMicroseconds(period / 2);
        digitalWrite(speakerpin, LOW);
        delayMicroseconds(period / 2);
        elapsed_time += (period);
    }
}
