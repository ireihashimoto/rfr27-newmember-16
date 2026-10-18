const int MUX_PIN= A0;// to do match with schematic
const int NUM_CHANNELS = 16;
void setup() {
  // put your setup code here, to run once:
}
 float readingtotemp(int steps){
      //convert voltage reading to temperature
  }
  //helper functions
  float stepstovoltage(int steps){
    //converts reading to voltage
  }
  float voltagetotemp(float voltage){
    //converts voltage to temp
  } 
  bool checkled(float temp){
    //checks highest temperature reading above 60C
    //outputs true false
  }
  float findhighest(const float temp[], int count){
    // finds highest temperature in array of temperatures
  }
  void channelselector(int channel){
    //takes in channeel and selects
  }
void loop(){
  float temp[NUM_CHANNELS]; //sets up array of 
  for(int i =0; i<NUM_CHANNELS; i++){ //loops array 
    channelselector(i);
    int adcRead = analogRead(MUX_PIN);
    temp[i]= readingtotemp(adcRead);//takes result and puts it into array
  }
  float maxTemp = findhighest(temp,NUM_CHANNELS);
}

 
