int RELAY1 = D0;
int RELAY2 = D1;
int HUMIDIFIER_CONTROL = D2;
int HUMIDIFIER_RATE = D3;

void setup()
{
   pinMode(RELAY1, OUTPUT);
   pinMode(RELAY2, OUTPUT);
   pinMode(HUMIDIFIER_CONTROL, OUTPUT);
   pinMode(HUMIDIFIER_RATE, OUTPUT);

   digitalWrite(RELAY1, HIGH);
   digitalWrite(RELAY2, LOW);
   digitalWrite(HUMIDIFIER_CONTROL, HIGH);
   digitalWrite(HUMIDIFIER_CONTROL, LOW);
   
   //register the Spark function
   Spark.function("humfanspeed", fanSpeed);
   Spark.function("humoutrate", humidiferOutput);
}

void loop()
{
   // This loops for ever
}

int fanSpeed(String command)
{
  int relayState = 0;
  
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

int humidiferOutput(String command)
{
  int relayState = 0;
  
  if (command == "OFF") {
      digitalWrite(HUMIDIFIER_CONTROL, 0);
  }
  else if (command == "HIGH") {
      digitalWrite(HUMIDIFIER_CONTROL, 1);
      digitalWrite(HUMIDIFIER_RATE, 1);
  }
  else if (command == "LOW") {
      digitalWrite(HUMIDIFIER_CONTROL, 1);
      digitalWrite(HUMIDIFIER_RATE, 0);
  }
  return 1;
}
