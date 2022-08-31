
#include "levelStart.h"
#include "net.h"
#include "Wire.h"
#include "Arduino.h"


const int PIN_KEY_START = 13;


void levelStartSetup(){
    pinMode(PIN_KEY_START, INPUT);
    Serial.println("LEVEL START!");
}


void levelStartLoop(){
    //Serial.println(String("key == ")+String(digitalRead(PIN_KEY_START)));
    if (digitalRead(PIN_KEY_START) == 0){
        IPAddress addr(192, 168, 1, 36);
        uint8_t data[1];
        if (udpLevel.connect(addr, 8051)){
            Serial.println("Send Start!");
            data[0] = '1';
            udpLevel.writeTo((uint8_t *)&data, 1, addr, 8051);
        }else{
            Serial.println("connect error!");
        }
        udpLevel.close();
        delay(1000);
    }
    delay(100);
}

void handlePacketStart(AsyncUDPPacket packet){

}
