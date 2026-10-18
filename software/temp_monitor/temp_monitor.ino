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
  void channelselector(){
    //takes in channeel
  }
void loop(){
  float temp[16]; //sets up array of 
  for(int i =0; i<16; i++){ //loops array 
    temp[i]= readingtotemp(i);//takes result and puts it into array
    //need to fix once i learn to select channel
  }


}

 
