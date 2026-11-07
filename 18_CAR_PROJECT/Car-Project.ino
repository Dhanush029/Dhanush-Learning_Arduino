#include <IRremote.hpp>
#define remotepin 12

// order: FR, RR, RL, FL
const int EN[4] = {5,6,9,10};
const int I1[4] = {A0,A2,A4,4};
const int I2[4] = {A1,A3,A5,7};
int DIR[4] = {1,1,1,1};

int speed = 215;

const uint32_t BTN_FWD    = 0xE718FF00;
const uint32_t BTN_BACK   = 0xAD52FF00;
const uint32_t BTN_LEFT   = 0xF708FF00;
const uint32_t BTN_RIGHT  = 0xA55AFF00;
const uint32_t BTN_FOR_R = 0xA15EFF00;
const uint32_t BTN_FOR_L = 0xF30CFF00;
const uint32_t BTN_BAC_R = 0xB54AFF00;
const uint32_t BTN_BAC_L = 0xBD42FF00;
const uint32_t BTN_ROT_R  = 0xBC43FF00;
const uint32_t BTN_ROT_L  = 0xBF40FF00;
const uint32_t BTN_STOP   = 0xE31CFF00;
const uint32_t BTN_PLUS   = 0xF609FF00;
const uint32_t BTN_MINUS   = 0xEA15FF00;

void setMotor(int motor, int spd){
  if (DIR[motor]==1){
    digitalWrite(I1[motor], HIGH);
    digitalWrite(I2[motor], LOW);
  }
  else{
    digitalWrite(I2[motor], HIGH);
    digitalWrite(I1[motor], LOW);
  }
  analogWrite(EN[motor], spd);
}


void setup() {
  //easily looping through pins to initialise because all are output
  for (int i = 0; i<4; i++){
    pinMode(EN[i], OUTPUT);
    pinMode(I1[i], OUTPUT);
    pinMode(I2[i], OUTPUT);
  }
  Serial.begin(115200);
  IrReceiver.begin(remotepin, ENABLE_LED_FEEDBACK);
}

void loop() {
  if (IrReceiver.decode()) {
    IrReceiver.printIRResultShort(&Serial);
    uint32_t cmd = IrReceiver.decodedIRData.decodedRawData;
    Serial.println(cmd, HEX);
    IrReceiver.resume();

    if (cmd == BTN_FWD){
      for (int i=0; i<4; i++){
        DIR[i] = 1;
      }
      setMotor(0, speed);
      setMotor(1, speed);
      setMotor(2, speed);
      setMotor(3, speed);
    }
    else if (cmd == BTN_BACK){
      for (int i=0; i<4; i++){
        DIR[i] = -1;
      }
      setMotor(0, speed);
      setMotor(1, speed);
      setMotor(2, speed);
      setMotor(3, speed);
    }
    else if (cmd == BTN_LEFT){
      DIR[0] = 1;
      DIR[1] = -1;
      DIR[2] = 1;
      DIR[3] = -1;

      setMotor(0, speed);
      setMotor(1, speed);
      setMotor(2, speed);
      setMotor(3, speed);
    }
    else if (cmd == BTN_RIGHT){
      DIR[0] = -1;
      DIR[1] = 1;
      DIR[2] = -1;
      DIR[3] = +1;

      setMotor(0, speed);
      setMotor(1, speed);
      setMotor(2, speed);
      setMotor(3, speed);
    }
    else if (cmd == BTN_FOR_R){
      DIR[1] = 1;
      DIR[3] = 1;

      setMotor(1, speed);
      setMotor(3, speed);
    }
    else if (cmd == BTN_FOR_L){
      DIR[0] = 1;
      DIR[2] = 1;

      setMotor(0, speed);
      setMotor(2, speed);
    }
    else if (cmd == BTN_BAC_R){
      DIR[0] = -1;
      DIR[2] = -1;

      setMotor(0, speed);
      setMotor(2, speed);
    }
    else if (cmd == BTN_BAC_L){
      DIR[1] = -1;
      DIR[3] = -1;

      setMotor(1, speed);
      setMotor(3, speed);
    }
    else if (cmd == BTN_ROT_R){
      DIR[0] = -1;
      DIR[1] = -1;
      DIR[2] = 1;
      DIR[3] = 1;

      setMotor(0, speed);
      setMotor(1, speed);
      setMotor(2, speed);
      setMotor(3, speed);
    }
    else if (cmd == BTN_ROT_L){
      DIR[0] = 1;
      DIR[1] = 1;
      DIR[2] = -1;
      DIR[3] = -1;

      setMotor(0, speed);
      setMotor(1, speed);
      setMotor(2, speed);
      setMotor(3, speed);
    }
    else if (cmd == BTN_PLUS){
      speed = constrain(speed + 20, 100, 255);
    }
    else if (cmd == BTN_MINUS){
      speed = constrain(speed - 20, 100, 255);
    }
    else if (cmd == BTN_STOP){
      for (int i=0; i<4; i++){
        digitalWrite(I1[i], LOW);
        digitalWrite(I2[i], LOW);
      }
    }
  }
}

// #include <IRremote.hpp>

// void setup() {
//   Serial.begin(115200);
//   IrReceiver.begin(12, ENABLE_LED_FEEDBACK);
//   Serial.println("ready");
// }

// void loop() {
//   if (IrReceiver.decode()) {
//     IrReceiver.printIRResultShort(&Serial);
//     IrReceiver.resume();
//   }
// }



