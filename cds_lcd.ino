#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
int cds = A0; // Analog input pin that the potentiometer is attached to //cds를 a0에 연결
int cdsValue = 0; // value read from the pot //가라지 데이터를 방지하기 위해서 초기값을 0으로 맞춘다
void setup() {
Serial.begin(9600); //
lcd.init();    //lcd초기화             // initialize the lcd 
                // Print a message to the LCD.
             lcd.backlight();
             lcd.setCursor(3,0);
             lcd.print("Hello, world!"); //set up에 있는 부분을 ioop에 넣으면 이 부분들을 계속 거치기 때문에 속도가 느려진다
}
void loop() {
             
             cdsValue  = analogRead(cds); // read the analog in value:  //analogread는 값을 읽는 것
             Serial.print("sensor = "); // print the results to the serial monitor: //sensor = 을 프린트한다
             Serial.println(cdsValue); //cdsvalue값을 넣고 line 즉 엔터를 친다
             delay(1000);
             lcd.setCursor(0,1); //1번째 칸, 2번째줄
             lcd.print("cds_value= "); // 위에 지정한 곳에 cds_value= 을 출력
             lcd.setCursor(11,1); //12번째 칸, 2번째 줄
             lcd.print(cdsValue); //cdsvalue값을 출력
                // for the analog-to-digital converter to settle // after the last reading:
             delay(20); // wait 2 milliseconds before the next loop
}
