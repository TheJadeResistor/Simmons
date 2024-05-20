#include "Arduino.h"
#include <Servo.h>

/*
         ---------------
        |     O   O     |
        |---------------|
RU  <== |               | <== LU 
         ---------------
            ||     ||
            ||     ||
RL  ==>   -----   ------  <== LL 
         |-----   ------|
*/

/* Hardware interface mapping*/
#define RU_PIN 3 //right upper 
#define RL_PIN 0 //right lower 
#define LU_PIN 2
#define LL_PIN 1

#define N_SERVOS 4
Servo servos[N_SERVOS];
int pos = 0;

//int bounds[4][2] = {{50,100},{50,100},{50,100},{50,100}}; //RUmin,RUmax,RLmin,RLmax,LUmin,LUmax,LLmin,LLmax
int bounds[8] = {50,130,40,180,50,130,50,180};


void testServo(int min, int max, int servo){ //servo 0-3
  for (pos = min; pos <= max; pos += 1) {
    servos[servo].write(pos);
		delay(15);
	}

  delay(500);

  for (pos = max; pos >= min; pos -= 1) {
    servos[servo].write(pos);
		delay(15);
	}

  delay(100);
}

void testAllServos(){
  for(int j=0; j<4; j++){
    for(int i=0; i<7; i++){
      testServo(bounds[i], bounds[i+1],j);
    }
  delay(1000);
  }
}

void zeroAll(){
  servos[0].write(75);
  servos[1].write(115);
  servos[2].write(90);
  servos[3].write(100);
  delay(5);
}



void setup(){
  servos[0].attach(RU_PIN);//, 580, 2300);
  servos[1].attach(RL_PIN);//, 580, 2300);
  servos[2].attach(LU_PIN);//, 580, 2300);
  servos[3].attach(LL_PIN);//, 580, 2300);

  zeroAll();
  delay(50);
}

void loop(){
  //testAllServos();
  //zeroAll();
  //testServo(bounds[0], bounds[1],0); //test1 Lleg
  //testServo(bounds[2], bounds[3],1); //test2 Rfoot
  //testServo(bounds[4], bounds[5],2); //test3 Rleg
  //testServo(bounds[6], bounds[7],3); //test4 Lfoot


}
