//takes in voltage from mux, converts to temperature, finds max temperature from 16 inputs
//then reports highest temp through I2C and flags if it is above 60C
const int MUX_PIN= X;// PLACEHOLDER WAIT UNTIL SCHEMATIC
const int NUM_CHANNELS = 16;
const float SENSOR_VOLTAGE[33] ={2.44, 2.42, 2.40, 2.38, 2.35, 2.32, 2.27, 2.23, 2.17, 2.11, 2.05,
1.99, 1.92, 1.86, 1.80, 1.74, 1.68, 1.63, 1.59, 1.55, 1.51, 1.48,
1.45, 1.43, 1.40, 1.38, 1.37, 1.35, 1.34, 1.33, 1.32, 1.31, 1.30};
void setup() {
  // put your setup code here, to run once:
}
 float readingToTemp(int steps){
      //convert voltage reading to temperature
      //outputs float
      return 0.0; // placeholder
  }
  //helper functions
  float stepsToVoltage(int steps){
    //converts reading to voltage
    return 0.0; //placeholder
  }
  float voltageToTemp(float voltage){
    //converts voltage to temp
    //outputs float
  } 

  bool checkLed(float temp){
    //checks highest temperature reading above 60C
    //outputs bool
    return true; //placeholder
  }
  float findHighest(const float temp[], int count){
    // finds highest temperature in array of temperatures
    //output float
    return 0.0; //placeholder
  }
  void channelSelector(int channel){
    //takes in channeel and selects
  }
  void ledControl(bool check){
    //takes in bool controls led
  }
  void i2cSend (float highestTemp){
    // takes in highest temp and sends to I2C
  }
void loop(){
  float temp[NUM_CHANNELS]; //sets up array of 
  for(int i =0; i<NUM_CHANNELS; i++){ //loops array 
    channelSelector(i);
    int adcRead = analogRead(MUX_PIN);
    temp[i]= readingToTemp(adcRead);//takes result and puts it into array
  }
  float maxTemp = findHighest(temp,NUM_CHANNELS);
  bool checks = checkLed(maxTemp);
  ledControl(checks);
  i2cSend(maxTemp);
}

 
