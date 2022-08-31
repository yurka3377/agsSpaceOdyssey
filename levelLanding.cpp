
#include "levelLanding.h"
#include "net.h"
#include "Wire.h"
#include "Arduino.h"


const int PIN_CONTROL_DIGIT_0 = 13;
const int PIN_CONTROL_DIGIT_1 = 12;
const int PIN_CONTROL_DIGIT_2 = 14;
const int PIN_CONTROL_DIGIT_3 = 27;


void levelLandingSetup(){
    Serial.println("LEVEL LANDING!");
    pinMode(PIN_CONTROL_DIGIT_0, INPUT);
    pinMode(PIN_CONTROL_DIGIT_1, INPUT);
    pinMode(PIN_CONTROL_DIGIT_2, INPUT);
    pinMode(PIN_CONTROL_DIGIT_3, INPUT);
}

void levelLandingLoop(){
    int r = digitalRead(PIN_CONTROL_DIGIT_0) << 0 |
            digitalRead(PIN_CONTROL_DIGIT_1) << 1 |
            digitalRead(PIN_CONTROL_DIGIT_2) << 2 |
            digitalRead(PIN_CONTROL_DIGIT_3) << 3;
    IPAddress addr(192, 168, 1, 36);
    uint8_t data[1];
    if (udpLevel.connect(addr, 8051)){
        data[0] = r;
        udpLevel.writeTo((uint8_t *)&data, 1, addr, 8051);
    }else{
        Serial.println("connect error!");
    }
    udpLevel.close();
    delay(50);
}

void handlePacketLanding(AsyncUDPPacket packet){

}
