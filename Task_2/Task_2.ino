String input = "";

// Hexadecimal to Binary Lookup Table
const int rowshexa = 16;
const int columnshexa = 4;
int hexalookup[rowshexa][columnshexa] = {
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


int matrix_1[4][4];
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  get_Data();
}

void loop() {
  // put your main code here, to run repeatedly: 
  hex_Tomatrix('R');
  print_matrix_1();
  matrix_Tohex();
}

void matrix_Tohex(){
  for(int i=3;i>=0;i--){
    int hex = 0;
    for(int j=0;j<4;j++){
      hex += (power(2,j))*(matrix_1[i][j]);
    }
    char hex_char;
    if(hex == 0){ hex_char = '0';}
    if(hex == 1){ hex_char = '1';}
    if(hex == 2){ hex_char = '2';}
    if(hex == 3){ hex_char = '3';}
    if(hex == 4){ hex_char = '4';}
    if(hex == 5){ hex_char = '5';}
    if(hex == 6){ hex_char = '6';}
    if(hex == 7){ hex_char = '7';}
    if(hex == 8){ hex_char = '8';}
    if(hex == 9){ hex_char = '9';}
    if(hex == 10){ hex_char = 'A';}
    if(hex == 11){ hex_char = 'B';}
    if(hex == 12){ hex_char = 'C';}
    if(hex == 13){ hex_char = 'D';}
    if(hex == 14){ hex_char = 'E';}
    if(hex == 15){ hex_char = 'F';}
    Serial.print(hex_char);
  }
  delay(1000000000);
}

int power(int base,int index){
  int out=1;
  for(int i=index;i>0;i--){
    out*=2;
  }
  return out;
}
void print_matrix_1(){
  for(int i =0;i<4;i++){
    for(int j=0;j<4;j++){
      Serial.print(matrix_1[i][j]);
    }
    Serial.println();
  }
}

void get_Data(){
  for(int i=0;i<6;i++){
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

void hex_Tomatrix(char type){
  if(type == 'M'){
  //Convering hexa input to 4 digit hexa code 
  for(int j=0;j<4;j++){
    char c = input.charAt(3-j);
    int c_int;
    if(c == '0'){ c_int=0;}
    if(c == '1'){ c_int=1;}
    if(c == '2'){ c_int=2;}
    if(c == '3'){ c_int=3;}
    if(c == '4'){ c_int=4;}
    if(c == '5'){ c_int=5;}
    if(c == '6'){ c_int=6;}
    if(c == '7'){ c_int=7;}
    if(c == '8'){ c_int=8;}
    if(c == '9'){ c_int=9;}
    if(c == 'A'){ c_int=10;}
    if(c == 'B'){ c_int=11;}
    if(c == 'C'){ c_int=12;}
    if(c == 'D'){ c_int=13;}
    if(c == 'E'){ c_int=14;}
    if(c == 'F'){ c_int=15;}
    for(int i=0;i<4;i++){
      int out = hexalookup[c_int][i];
      matrix_1[j][i] = out;
    }
  }
  }
  else if(type == 'R'){
  //Convering hexa input to 4 digit hexa code 
  for(int j=0;j<4;j++){
    char c = input.charAt(3-j);
    int c_int;
    if(c == '0'){ c_int=0;}
    if(c == '1'){ c_int=1;}
    if(c == '2'){ c_int=2;}
    if(c == '3'){ c_int=3;}
    if(c == '4'){ c_int=4;}
    if(c == '5'){ c_int=5;}
    if(c == '6'){ c_int=6;}
    if(c == '7'){ c_int=7;}
    if(c == '8'){ c_int=8;}
    if(c == '9'){ c_int=9;}
    if(c == 'A'){ c_int=10;}
    if(c == 'B'){ c_int=11;}
    if(c == 'C'){ c_int=12;}
    if(c == 'D'){ c_int=13;}
    if(c == 'E'){ c_int=14;}
    if(c == 'F'){ c_int=15;}
    for(int i=0;i<4;i++){
      int out = hexalookup[c_int][i];
      matrix_1[i][j] = out;
    }
  }
  }
  
}


