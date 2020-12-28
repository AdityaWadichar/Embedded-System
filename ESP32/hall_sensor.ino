int val = 0;
void setup() {
  Serial.begin(9600);  // baud rate
  pinMode (2, OUTPUT); // inbuilt led as output
    }

void loop() {
  val = hallRead();  // reading sensor values
  if (val <=0) digitalWrite (2, HIGH);
  else digitalWrite (2, LOW);
  // print the results to the serial monitor:
  Serial.print("sensor = ");
  Serial.println(val);
  delay(500);
}
