
int CE_pin = 0; /* Chip Enable */
int CK_pin = 1; /* Data Shift Clock  */
int DI_pin = 2; /* Data Input */


typedef uint8_t DisplayDataElement; 
typedef struct DisplayData { 
  /* http://stackoverflow.com/questions/4523497/typedef-fixed-length-array */
  DisplayDataElement data_array[7]; 
} DisplayData;

void setup() {
  pinMode(CE_pin, OUTPUT);
  pinMode(CK_pin, OUTPUT);
  pinMode(DI_pin, OUTPUT);
}

void display_bits(DisplayData data) {
  /* 56 bits used: 28 in start and 28 in end */
  digitalWrite(CK_pin, LOW);
  digitalWrite(CE_pin, HIGH);
  uint8_t bit;
  while (bit) {
    digitalWrite(DI_pin, start);
    bit >>= 1;
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}