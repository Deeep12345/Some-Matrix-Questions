// Hexadecimal to Binary Lookup Table
int hexalookup[16][4] = {
{0, 0, 0, 0}, //0
{0, 0, 0, 1}, //1
{0, 0, 1, 0}, //2
{0, 0, 1, 1}, //3
{0, 1, 0, 0}, //4
{0, 1, 0, 1}, //5
{0, 1, 1, 0}, //6
{0, 1, 1, 1}, //7
{1, 0, 0, 0}, //8
{1, 0, 0, 1}, //9
{1, 0, 1, 0}, //A
{1, 0, 1, 1}, //B
{1, 1, 0, 0}, //C
{1, 1, 0, 1}, //D
{1, 1, 1, 0}, //E
{1, 1, 1, 1}, //F
};

String input = "";                                 //Variable to store the incomming data
String hex_M = "0x",hex_R = "0x";                  //Strings to store Hexdecimal value of each table
int matrix_1[8][8],matrix_m[8][8],matrix_r[8][8];  //Matrix to store the different forms of the input for later display
 
void setup() {                                     //Code runs once here
  Serial.begin(115200);                            //Start Serial output for input and output                        
}

void loop() {                                      //continues to run here infinitely
  read_input();                                    //Inputting hexadecimal from user
  hex_to_matrix();                                 //Converting the input Hexadecimal code to a matrix 
  matrix_to_hex();                                 //After performing the actions, turning the table back to Hexadecimal form to display
  write_output();                                  //Providing out put to the user;
}

void read_input(){                                 //Read hexadecimal data from user/terminal 
  for(int i=0;i<18;i++){
    while(!Serial.available()){
  }
  if(Serial.available()){
      char c = Serial.read();
      input+=c;
  }
  }
  Serial.println(input);
  input.remove(0,2);
}

void hex_to_matrix(){                              //Function to convert Hexadecimal to Matrix 
    for(int i = 15;i>=0;i-=2){
      char R = input.charAt(i);
      char L = input.charAt(i-1);
      int R_int, L_int;
      if(R == '0'){ R_int=0;}
      if(R == '1'){ R_int=1;}
      if(R == '2'){ R_int=2;}
      if(R == '3'){ R_int=3;}
      if(R == '4'){ R_int=4;}
      if(R == '5'){ R_int=5;}
      if(R == '6'){ R_int=6;}
      if(R == '7'){ R_int=7;}
      if(R == '8'){ R_int=8;}
      if(R == '9'){ R_int=9;}   
      if(R == 'A'){ R_int=10;}
      if(R == 'B'){ R_int=11;}
      if(R == 'C'){ R_int=12;}
      if(R == 'D'){ R_int=13;}
      if(R == 'E'){ R_int=14;}
      if(R == 'F'){ R_int=15;}
      if(L == '0'){ L_int=0;}
      if(L == '1'){ L_int=1;}
      if(L == '2'){ L_int=2;}
      if(L == '3'){ L_int=3;}
      if(L == '4'){ L_int=4;}
      if(L == '5'){ L_int=5;}
      if(L == '6'){ L_int=6;}
      if(L == '7'){ L_int=7;}
      if(L == '8'){ L_int=8;}
      if(L == '9'){ L_int=9;}  
      if(L == 'A'){ L_int=10;}
      if(L == 'B'){ L_int=11;}
      if(L == 'C'){ L_int=12;}
      if(L == 'D'){ L_int=13;}
      if(L == 'E'){ L_int=14;}
      if(L == 'F'){ L_int=15;}
      for(int j = 4;j<8;j++){
        int out = hexalookup[R_int][j-4];
        matrix_1[(15-i)/2][j] = out; 
      }
      for(int j = 0;j<4;j++){
        int out = hexalookup[L_int][j];
        matrix_1[(15-i)/2][j] = out; 
      }
  }
  //Mirroring the matrix
    for(int i=0;i<8;i++){
      for(int j = 0;j<8;j++){
        matrix_m[i][7-j] = matrix_1[i][j];
      }
    }
  //Rotating the matrix
    for(int i=0;i<8;i++){
      for(int j=0;j<8;j++){
        matrix_r[j][7-i] = matrix_1[i][j];
      }
    }
}

void matrix_to_hex(){                              //Function to convert Matrix to Hexadecimal
  //Coverting Mirrored matrix to Hex
  for(int i=7;i>=0;i--){
    int hex_r = 0;
    int hex_l = 0;
    for(int j=0;j<4;j++){  //0xFE010101010101FE
      hex_l += (power(2,(3-j)))*(matrix_m[i][j]);
    }
    for(int j=4;j<8;j++){
      hex_r += (power(2,7-j))*(matrix_m[i][j]);
    }
    hex_M = hex_M + String(hex_l,HEX)+ String(hex_r,HEX);
    }
  //Converting Rotated matrix to Hex
  for(int i=7;i>=0;i--){
    int hex_r = 0;
    int hex_l = 0;
    for(int j=0;j<4;j++){  //0xFE010101010101FE
      hex_l += (power(2,(3-j)))*(matrix_r[i][j]);
    }
    for(int j=4;j<8;j++){
      hex_r += (power(2,7-j))*(matrix_r[i][j]);
    }
    hex_R = hex_R + String(hex_l,HEX)+ String(hex_r,HEX);
    }
}

void write_output(){
  //Printing the original Recieved Matrix for Reference 
  for(int i =0;i<8;i++){
    for(int j=0;j<8;j++){
      Serial.print(matrix_1[i][j]);Serial.print(" ");
    }Serial.println();
  }Serial.print("    ");
  //Printing the Mirrored Matrix and Hexa
  Serial.println("Mirror");
  for(int i =0;i<8;i++){
    for(int j=0;j<8;j++){
      Serial.print(matrix_m[i][j]);Serial.print(" ");
    }Serial.println();
  }Serial.print("--> ");Serial.println(hex_M);
  //Printing the Rotated Matrix and Hexa
  Serial.print("    ");
  Serial.println("Rotated");
  for(int i =0;i<8;i++){
    for(int j=0;j<8;j++){
      Serial.print(matrix_r[i][j]);Serial.print(" ");
    }Serial.println();
  }Serial.print("--> ");Serial.println(hex_R);
  //Dropping saved values for next calculations
  hex_M = "0x";
  hex_R = "0x";
  input = "";
}

int power(int base,int index){        //A function to calculate power 
  int out=1;
  for(int i=index;i>0;i--){
    out*=2;
  }
  return out;                         //Return calculated value
}
