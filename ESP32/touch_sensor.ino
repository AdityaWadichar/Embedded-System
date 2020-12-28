int touch;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); // baud rate 
  pinMode (4, INPUT);   // setting pin 4 as input
  pinMode (2, OUTPUT);  // setting pin 2 as output to show output on built in led

}

void loop() {
  // put your main code here, to run repeatedly:
  touch= touchRead(4);  // reading the values
  Serial.print(touch);  // printing values on serial monitor
  Serial.print('\n');
  if (touch<80) digitalWrite (2, HIGH);  // display of output on LED
  else digitalWrite (2, LOW);
  delay(500);
}
}
