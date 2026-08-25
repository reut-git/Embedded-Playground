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

constexpr int Sequence[] = {
    9, 6, 15, 0, 5, 10
};



constexpr int NUM_BITS = 4;
constexpr int SEQUENCE_SIZE = 6;

unsigned long lastChange = 0;

int index = 0;

void setup() {

  for(int i = 0 ; i < NUM_BITS ; i++){

      pinMode(leds[i], OUTPUT);  
  }

}

void loop() {
  if(millis() - lastChange >= 500){

    for (int i = 0 ; i < NUM_BITS ; i++) {
         digitalWrite(leds[i], Sequence[index] & (1 << i) ? HIGH : LOW );
    }

    index++;
      
    if(index == SEQUENCE_SIZE) index = 0;

    lastChange = millis();

  }
   
}
