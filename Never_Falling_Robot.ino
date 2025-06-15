void setup()
{
  // Set motor control pins as outputs
  pinMode(2, OUTPUT); // Left Motor IN1
  pinMode(3, OUTPUT); // Left Motor IN2
  pinMode(4, OUTPUT); // Right Motor IN1
  pinMode(5, OUTPUT); // Right Motor IN2

  // Set IR sensor pins as inputs
  pinMode(6, INPUT);  // Left IR sensor
  pinMode(7, INPUT);  // Right IR sensor

  // Start serial communication for debugging
  Serial.begin(9600);
}

void loop()
{
  // Read IR sensor values
  int val1 = digitalRead(6); // Left IR sensor
  int val2 = digitalRead(7); // Right IR sensor

  // Case 1: Both sensors detect surface (safe) – move forward
  if (val1 == 1 && val2 == 1)
  {
    digitalWrite(2, HIGH);  // Left motor forward
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);  // Right motor forward
    digitalWrite(5, LOW);
    Serial.println("Forward");
  }

  // Case 2: Left sensor detects edge (no surface), right is safe – turn right
  if (val1 == 0 && val2 == 1)
  {
    digitalWrite(2, HIGH);  // Left motor forward
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);   // Right motor backward
    digitalWrite(5, HIGH);
    Serial.println("Right");
  }

  // Case 3: Right sensor detects edge, left is safe – turn left
  if (val1 == 1 && val2 == 0)
  {
    digitalWrite(2, LOW);   // Left motor backward
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);  // Right motor forward
    digitalWrite(5, LOW);
    Serial.println("Left");
  }

  // Case 4: Both sensors detect edge – stop, reverse, then turn
  if (val1 == 0 && val2 == 0)
  {
    // Stop all motors
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    Serial.println("Stop");
    delay(1000); // Pause for safety

    // Move backward briefly
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    Serial.println("Back");
    delay(300);

    // Turn left to try a new direction
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    Serial.println("Left");
    delay(300);
  }
}
