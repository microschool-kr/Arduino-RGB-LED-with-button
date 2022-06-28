#define BUTTON 2
#define RED 4
#define GREEN 5
#define BLUE 6
//RGB 모듈, 버튼 핀번호

int state = 0;
int old_btn = 0;
unsigned long last_time = millis();
unsigned long current_time;
//변수 생성

void setup()
{
  Serial.begin(9600);
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  analogWrite(RED, 0);
  analogWrite(GREEN, 0);
  analogWrite(BLUE, 0);
} // 모듈 초기화

void loop()
{
  int btn = digitalRead(BUTTON);   // 버튼이 눌리면 시리얼 모니터에 1표시 (안눌리면 0)
  Serial.println(btn);
  current_time = millis();
  if (old_btn == 0 && btn == 1 && current_time - last_time > 50)
  {
    if (state == 0) //상태 1 : 빨간색  /////////////////////////////////
    {
      state = 1;  
      analogWrite(RED, 255);  //RED, GREE, BLUE 옆 숫자를 조정해 색깔 조정
      analogWrite(GREEN, 0);
      analogWrite(BLUE, 0);
    }
    else if (state == 1) //상태 2 : 초록색  /////////////////////////////////
    {
      state = 2;
      analogWrite(RED, 0);    //RED, GREE, BLUE 옆 숫자를 조정해 색깔 조정
      analogWrite(GREEN, 255);
      analogWrite(BLUE, 0);
    }
    else if (state == 2) //상태 3 : 파란색  /////////////////////////////////
    {
      state = 3;
      analogWrite(RED, 0);     //RED, GREE, BLUE 옆 숫자를 조정해 색깔 조정
      analogWrite(GREEN, 0);
      analogWrite(BLUE, 255);
    }
    else if (state == 3) //상태 4 : 꺼짐 (이 부분은 수정하지 말아주세요)  //////////
    {
      state = 0;
      analogWrite(RED, 0);
      analogWrite(GREEN, 0);
      analogWrite(BLUE, 0);
    }
  }
  else if (old_btn == 1 && btn == 0)
  {
    last_time = current_time;
  }
  old_btn = btn;
}
