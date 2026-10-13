void setup() {
  // put your setup code here, to run once:

}
 float reading_to_temp(int steps){
      //convert voltage reading to temperature
  }
  //helper functions
  float steps_to_voltage(int steps){
    //converts reading to voltage
  }
  float voltage_to_temp(float voltage){
    //converts voltage to temp
  } 
  bool check_led(float temp){
    //checks highest temperature reading above 60C
    //outputs true false
  }
  float find_highest(const float temp[], int count){
    // finds highest temperature in array of temperatures
  }
  void channel_selector(){
    //takes in channeel
  }
void loop(){
  float temp[16]; //sets up array of 
  for(int i =0; i<16; i++){ //loops array 
    temp[i]= reading_to_temp(i);//takes result and puts it into array
    //need to fix once i learn to select channel
  }


}

 
