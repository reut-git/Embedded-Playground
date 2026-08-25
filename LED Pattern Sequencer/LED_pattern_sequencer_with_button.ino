constexpr int FOURTH_BIT = 2;
constexpr int THIRD_BIT = 4;
constexpr int SECOND_BIT = 5;
constexpr int FIRST_BIT = 18;

constexpr int BUTTON_PIN = 13;


constexpr int leds[] = {
    FIRST_BIT,
    SECOND_BIT,
    THIRD_BIT,
    FOURTH_BIT
};

constexpr int Sequence[] = {
    9, 6, 15, 0, 5, 10
};

constexpr int NUM_BITS = 4;
constexpr int SEQUENCE_SIZE = 6;

unsigned long lastChange = 0;

int sequenceIndex = 0;
bool isRunning = false;
int previousButtonState = LOW;


void setup() {

  pinMode(BUTTON_PIN, INPUT);

  for(int i = 0 ; i < NUM_BITS ; i++){

      pinMode(leds[i], OUTPUT);  
  }

}

void loop() {
  
  int currentButtonState = digitalRead(BUTTON_PIN); 

  if(previousButtonState == LOW && currentButtonState == HIGH ){
    isRunning = !isRunning;
  }

  previousButtonState = currentButtonState;

  if(isRunning){
    
      if(millis() - lastChange >= 500){

      for (int i = 0 ; i < NUM_BITS ; i++) {
          digitalWrite(leds[i], Sequence[sequenceIndex] & (1 << i) ? HIGH : LOW );
      }

      sequenceIndex++;
        
      if(sequenceIndex == SEQUENCE_SIZE) sequenceIndex = 0;

      lastChange = millis();

    }
  } 
     
}
