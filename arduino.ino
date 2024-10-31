const int ledPin = 13;  // Pin where LED is connected

void setup() {
    pinMode(ledPin, OUTPUT);
    Serial.begin(9600);  // Start serial communication at 9600 baud rate
}

void loop() {
    // Check if data is available on the serial port
    if (Serial.available() > 0) {
        // Read the incoming data as a string
        String command = Serial.readStringUntil('\n');
        command.trim();  // Remove any trailing newline or whitespace

        // Check the command and control the LED accordingly
        if (command == "on") {
            digitalWrite(ledPin, HIGH);  // Turn the LED on
            Serial.println("LED is ON");
        } else if (command == "off") {
            digitalWrite(ledPin, LOW);   // Turn the LED off
            Serial.println("LED is OFF");
        } else {
            Serial.println("Unknown command");
        }
    }
}
