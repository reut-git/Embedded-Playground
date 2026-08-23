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
unsigned long lastChange = 0;
int currentLed = 0;
int direction = 1;

void setup() {

  for(int i = 0 ; i < NUM_BITS ; i++){
      pinMode(leds[i], OUTPUT);  
  }

}

void loop() {
  if(millis() - lastChange >= 500){

    for (int i = 0 ; i < NUM_BITS ; i++) {
         digitalWrite(leds[i], i == currentLed ? HIGH : LOW );
    }

    currentLed += direction;
      
    if(currentLed == NUM_BITS - 1){
      direction = -1;
    }
    
    else if(currentLed == 0){
      direction = 1;
    }

    lastChange = millis();

  }
   
}
