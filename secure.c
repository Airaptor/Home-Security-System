const int PHOTOCELL_PIN = A0;
const int BUZZER_PIN = 3;
const int LED_RED=7;
const int LED_GREEN=2;
// voltage readings are in 0-1023 range
const int THRESHOLD = 350;
int var1 = 0;
void setup() {
  pinMode(PHOTOCELL_PIN, INPUT);
  pinMode(LED_RED, INPUT);
  pinMode(LED_GREEN, INPUT);
  Serial.begin(9600);
}
void loop() 
{
  int level = analogRead(PHOTOCELL_PIN);
  Serial.println(level);
  digitalWrite(LED_GREEN,HIGH);
  int var = 0;
  
  if (level < THRESHOLD )
     {
        digitalWrite(LED_GREEN,LOW);
        var1++;
        
        while(var < 3)
           {
             digitalWrite(LED_RED, HIGH);
             delay(500);
             digitalWrite(LED_RED, LOW);
             delay(500);
             Serial.println(level);
             var++;
           }
 
        int level = analogRead(PHOTOCELL_PIN);
        if( level < THRESHOLD || var1 == 4 )
          {
            var++;
            while(var > 3)
                 {
                   tone(BUZZER_PIN, 500000);
                   digitalWrite(LED_RED, HIGH);
                   digitalWrite(LED_GREEN,LOW);
                   delay(500);
                   digitalWrite(LED_RED, LOW);
                   digitalWrite(LED_GREEN,HIGH);
                   delay(500);
                  }
           } 
         else
             {
               digitalWrite(LED_GREEN,HIGH);
               noTone(BUZZER_PIN);
             }
      }
   else
    {
      digitalWrite(LED_GREEN,HIGH);
      noTone(BUZZER_PIN);
    }
}
