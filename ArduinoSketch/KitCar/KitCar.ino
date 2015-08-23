#include <DCMotor.h>
#include <Servo.h>

Servo myservo;
DCMotor mydc;

// ピン番号
const int servoPin = 9;
const int dcPin1 = 7;
const int dcPin2 = 8;
const int pmPin = 6;

// モータ用パラメータ定数
const int incS =  6;     // 一回当りのサーボモータパラメータ変化量
const int maxM = 150;    // DCモータパラメータの最大値
const int minS =  78;    // サーボモータパラメータの最小値
const int maxS = 102;    // サーボモータパラメータの最大値

// モーター用パラメータ変数
int iMotor;        // DCモータ駆動用のパラメータ
int iServo;        // サーボーモータのパラメータ(角度)

int dtime;               // 停止時間[ms]
int diS;                 // サーボ回転方向(１：順回転)

//---------------------------------------------------
// セットアップ関数
//---------------------------------------------------
void setup()
{
  myservo.attach(servoPin);
  mydc.attach(dcPin1,dcPin2,pmPin);
  
  diS    = 1;
  iMotor = maxM;    // DCモータの初期値
  iServo = 90;      // サーボの初期値
  dtime  = 500;
}
//---------------------------------------------------
// メインループ関数
//---------------------------------------------------
void loop()
{  

  mydc.write(iMotor);
  myservo.write(iServo);
  
  if ( iServo == 90 ) {
    dtime = 2000;
  } else {
    dtime = 1000;
  }  
  delay ( dtime );
  
  iServo += (incS * diS);
  
  if ( maxS < iServo ) {
    iServo -= 2*incS;
    diS *= -1;
  } else if ( minS > iServo ) {
    iServo += 2*incS;
    diS *= -1;
  }
  
}
//---------------------------------------------------
