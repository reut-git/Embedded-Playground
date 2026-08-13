constexpr int FOURTH_BIT = 2;
constexpr int THIRD_BIT = 4;
constexpr int SECOND_BIT = 5;
constexpr int FIRST_BIT = 18;

constexpr int leds[] = {
    FIRST_BIT,
    SECOND_BIT,
    THIRD_BIT,
    FOURTH_BIT
};

constexpr int NUM_BITS = 4;
int counter = 0; 
unsigned long lastChange = 0;

void setup() {
  pinMode(FOURTH_BIT, OUTPUT);  
  pinMode(THIRD_BIT, OUTPUT);
  pinMode(SECOND_BIT, OUTPUT);
  pinMode(FIRST_BIT, OUTPUT);
}

void loop() {
    if(millis() - lastChange >= 500){

      counter = (counter + 1) % (1 << NUM_BITS);

      for (int i = 0; i < NUM_BITS; i++) {
          digitalWrite(leds[i],counter & (1 << i) ? HIGH : LOW );
      }
      
      lastChange = millis();
    }
   
}
