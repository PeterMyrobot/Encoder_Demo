#include "Timer.h"
Timer t;
float timeChange=20;
float dt=timeChange*0.001;

int A,B;
int isAChange = 0 , isBChange = 0;
int BackCount = 0, ForwardCount = 0;
int Backlast , ForwardLast; 
float Velocity;

int MotorA = 6; //When angle is negative
int MotorB = 5; //When angle is positive
int EnablePin = 9;


void setup() {
    Serial.begin(9600);//初始化

    pinMode(EnablePin,OUTPUT);
    digitalWrite(EnablePin,HIGH);
    analogWrite(MotorA,0);
    analogWrite(MotorB,0);
    
    attachInterrupt(0, Aplus, RISING);
    attachInterrupt(1, Bplus, RISING);
    
    int Event1 = t.every(timeChange , CalculatorV);

}

void loop() {
  t.update();
}

void CalculatorV(){
  
//  Velocity = (ForwardCount - BackCount)/timeChange;
//  ForwardCount = 0; BackCount = 0;
  Serial.print(" ForwardCount :");
  Serial.print(ForwardCount);
  Serial.print("   BackCount :");
  Serial.println(BackCount);
  ForwardCount = 0; BackCount = 0;
}
  
void Aplus(){
  if(isBChange == 1){
      BackCount ++ ;      isBChange = 0;
  }
  else{
    isAChange = 1;
  }
}
void Bplus(){
  if(isAChange == 1){
    ForwardCount ++;      isAChange = 0;
  }
  else{
    isBChange = 1;
  }
}
  
