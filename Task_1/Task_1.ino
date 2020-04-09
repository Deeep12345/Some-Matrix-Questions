int IR_pin = 8; //Attached to digital pin 8
bool IR_data ;  //Variable to save data from the sensor white: 1 and Black : 0

int Black_lines, White_lines;

void setup() {
  pinMode(8,INPUT);                  //Setting pinmode as input
  Serial.begin(115200);              //Starting Serial port at 115200
  Serial.println("Starting bot");    //Welcome message
  delay(1000);                       //Wait for system to stabilise 
}

void loop() {
  // put your main code here, to run repeatedly:
  sensor_Read();
  count_Lines();
  print_Data();
}

void sensor_Read(){
  IR_data = digitalRead(8);          //Continuously Reading Sensor data after each iteration
}

void count_Lines(){                  //Continously Finds the type of line and increases the counter accordingly
  if(IR_data == 1){
  while(IR_data == 1){
    sensor_Read();
  }
  White_lines++;
  }
  else if(IR_data == 0){
  while(IR_data == 0){
    sensor_Read();
  }
  Black_lines++;
  }
}

void print_Data(){                  //Does Printing of data in each cycle 
  Serial.print("Black Lines : ");Serial.print(Black_lines);
  Serial.print(", White Lines : ");Serial.println(White_lines);
}



