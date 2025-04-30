#include <Adafruit_NeoPixel.h>

#define SERIAL_BAUD 9600   // baud rate
#define NUM_LEDS_TOTAL 10  // 總LED數量
#define LED_PIN 11         // 連接第一個LED的腳位
#define BUTTON_PINS 2      // 連接按鈕的腳位

Adafruit_NeoPixel leds(NUM_LEDS_TOTAL, LED_PIN, NEO_GRB + NEO_KHZ800);  //定義ws2812燈條

bool last_status;
bool status;
int unit = 0;

void setup() {
  Serial.begin(SERIAL_BAUD);
  Serial.println("start!");
  leds.begin();
  leds.show();
  pinMode(BUTTON_PINS, INPUT_PULLUP);
}

void loop() {

  if (ifBotton()) unit++; //按鈕功能函數, 如果按鈕被按下, unit +1  
  setunitColor(255, 255, 255);  //白色

  if (unit > NUM_LEDS_TOTAL) {  //超過最大燈數
    Serial.println("restart!");
    setunitColor(0, 0, 0);  //暗
    unit = 0;
  }

  Serial.println(status);
  delay(100);  //防止死機
}

void setunitColor(int red, int green, int blue) {  // 設定LED顏色
  for (int i = 0; i < unit; i++) {
    leds.setPixelColor(i, red, green, blue);
  }
  leds.show();
}

bool ifBotton() {                      // 檢查按鈕狀態
  status = !digitalRead(BUTTON_PINS);  // 取得按鈕狀態

  if (!last_status && status){
    last_status = status;                // 紀錄按鈕的狀態
    return true;
  }
  else{
    last_status = status;                // 紀錄按鈕的狀態
    return false;
  }
}
