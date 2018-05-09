#include <Keypad.h>
const byte ROWS = 4; // 4 Rows
const byte COLS = 4; // 4 Columns
// 定義 Keypad 的按鍵
char keys[ROWS][COLS] = {
{'0', 'B', 'A', 'F'},
{'1','2','3', 'E'},
{'4', '5', '6', 'D'}, 
{'7', '8', '9', 'C'}
};// 定義 Keypad 連到 Arduino 的接腳
byte rowPins[ROWS] = {5,4,3,2};// 連到 Keypad 的 4 個 Rows
byte colPins[COLS] = {8,9,10,11};
Keypad keypad =
Keypad( makeKeymap(keys), rowPins,colPins, ROWS, COLS );
int i;
int j;
const byte num[10]={B00111111, B00000110,
                    B01011011, B01001111,
                    B01100110, B01101101,
                    B01111101, B00000111,
                    B01111111, B01101111 };
const int seg[]={6,7,12,13,14,15,16};
void setup(){
  Serial.begin(9600); 
  for(i=0;i<8;i++)
  pinMode(seg[i],OUTPUT);
}
void loop(){
char key = keypad.getKey(); // 讀取 Keypad的輸入
if (key != NO_KEY)
  {
  i=key-48;
Serial.println(key);
  for(j=0;j<8;j++)
      {
    if(bitRead(num[i],j))
        digitalWrite(seg[j],HIGH);//若位元值為1,設定顯示器該小段為HIGH
    else
        digitalWrite(seg[j],LOW);
      }
    }
  }
