#include <DCMotor.h>

DCMotor mydc;

// ピン番号
const int dcPin1 = 7;
const int dcPin2 = 8;
const int pmPin  = 6;

const int minM = -150;  // DCモータパラメータの最小値
const int maxM = 150;   // DCモータパラメータの最大値

int iMotor;             // DCモータ駆動用のパラメータ変数

void setup()
{
  
  mydc.attach(dcPin1,dcPin2,pmPin); // DCドライバとの接続定義 
  iMotor = 0;                       // パラメータの初期値
}

void loop()
{  

  for ( iMotor = minM ; iMotor <= maxM; iMotor += 10 )
  {
    mydc.write(iMotor);             // DCモータへ出力
    delay(500);
  }
 
}
