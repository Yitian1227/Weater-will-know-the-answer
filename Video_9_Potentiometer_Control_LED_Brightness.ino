// 定義觸摸感測器的接腳
const int TOUCH_PIN = 2;  // 使用數位接腳2
const int TOUCH_THRESHOLD = 3;  // 觸摸判斷的門檻值
int touchCount = 0;  // 計數器

void setup() {
  Serial.begin(9600);     // 初始化序列通訊
  pinMode(TOUCH_PIN, INPUT);  // 設定觸摸感測器接腳為輸入模式
}

void loop() {
  // 讀取觸摸感測器的狀態
  int touchState = digitalRead(TOUCH_PIN);
  
  // 計數連續觸摸的次數
  if (touchState == HIGH) {
    touchCount++;
  } else {
    touchCount = 0;
  }
  
  // 只有當連續觸摸次數超過門檻值時才觸發
  if (touchCount >= TOUCH_THRESHOLD) {
    Serial.println("1");  // 觸摸時發送1
  } else {
    Serial.println("0");  // 未觸摸時發送0
  }
  
  delay(50);  // 縮短延遲時間，讓反應更快
}