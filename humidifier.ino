int RELAY1 = D0;
int RELAY2 = D1;

void setup()
{
   pinMode(RELAY1, OUTPUT);
   pinMode(RELAY2, OUTPUT);
   digitalWrite(RELAY1, HIGH);
   digitalWrite(RELAY2, LOW);

   //register the Spark function
   Spark.function("humfanspeed", fanSpeed);
}

void loop()
{
   // This loops for ever
}

int fanSpeed(String command)
{
  if (command == "OFF") {
      digitalWrite(RELAY1, 0);
  }
  else if (command == "HIGH") {
      digitalWrite(RELAY1, 1);
      digitalWrite(RELAY2, 1);
  }
  else if (command == "LOW") {
      digitalWrite(RELAY1, 1);
      digitalWrite(RELAY2, 0);
  }
  return 1;
}
