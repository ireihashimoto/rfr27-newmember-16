//takes in voltage from mux, converts to temperature, finds max temperature from 16 inputs
//then reports highest temp through I2C and flags if it is above 60C
//takes in voltage from mux, converts to temperature, finds max temperature from 16 inputs
//then reports highest temp through I2C and flags if it is above 60C

const int MUX_PIN = A0; // MUX analog pin
// MUX digital pins
const int pin_A = 7;
const int pin_B = 8;
const int pin_C = 9;
const int pin_D = 10;
const int LED_PIN = 6;
const int NUM_CHANNELS = 16;
const float AMP_GAIN = 2
const float SENSOR_VOLTAGE[33] ={2.44, 2.42, 2.40, 2.38, 2.35, 2.32, 2.27, 2.23, 2.17, 2.11, 2.05,
1.99, 1.92, 1.86, 1.80, 1.74, 1.68, 1.63, 1.59, 1.55, 1.51, 1.48,
1.45, 1.43, 1.40, 1.38, 1.37, 1.35, 1.34, 1.33, 1.32, 1.31, 1.30};
const float startTemp = -40.0f;
const float stepTemp = 5.0f;
void setup() {
  pinMode(MUX_PIN, INPUT);

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  
  pinMode(pin_A, OUTPUT);
  pinMode(pin_B, OUTPUT);
  pinMode(pin_C, OUTPUT);
  pinMode(pin_D, OUTPUT);
  
  digitalWrite(pin_A, LOW);
  digitalWrite(pin_B, LOW);
  digitalWrite(pin_C, LOW);
  digitalWrite(pin_D, LOW);
}
 float readingToTemp(int steps){
      // converts steps to voltage to temp
      return voltageToTemp(stepsToVoltage(steps));
  }

  float stepsToVoltage(int steps){
    return steps*5.0f/1024/AMP_GAIN;
  }
  float voltageToTemp(float voltage){
    // might have to check if voltage is out of bounds here
    for (int i = 0; i < 32; i += 1) {
      if (SENSOR_VOLTAGE[i] == voltage) {
        return startTemp+i*stepTemp;
      }
      else if(voltage < SENSOR_VOLTAGE[i] && voltage > SENSOR_VOLTAGE[i+1]) {
        float vHigh = SENSOR_VOLTAGE[i];
        float vLow = SENSOR_VOLTAGE[i+1];
        float weight = (vHigh-voltage)/(vHigh-vLow);
        return startTemp+(i+weight)*stepTemp;
      }
    }
    return startTemp+32*stepTemp;
  } 

  bool checkLed(float temp){
    //checks highest temperature reading above 60C
    // outputs bool
    if (temp > 60) {
      return true;
    }
    return false;
  }
  float findHighest(const float temp[], int count){
    float currMax = temp[0];
    for (int i = 1; i < count; i += 1) {
      if (temp[i] > currMax) {
        currMax = temp[i];
      } 
    }
    return currMax;
  }
  
  void channelSelector(int channel){
    //takes in channeel and selects
  }
  void ledControl(bool check){
    if (check) {
      digitalWrite(LED_PIN, HIGH);
    }
  }
  void i2cSend (float highestTemp){
    // takes in highest temp and sends to I2C
  }
void loop(){
  float temp[NUM_CHANNELS]; //sets up array of 
  for(int i =0; i < NUM_CHANNELS; i++){ //loops array 
    channelSelector(i);
    delayMicroseconds(1);
    int adcRead = analogRead(MUX_PIN);
    temp[i]= readingToTemp(adcRead);//takes result and puts it into array
  }
  float maxTemp = findHighest(temp,NUM_CHANNELS);
  bool checks = checkLed(maxTemp);
  ledControl(checks);
  i2cSend(maxTemp);
}

 
