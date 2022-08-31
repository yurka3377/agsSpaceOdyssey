
#include "driver.h"
#include "net.h"
#include "level.h"
#include "levelStart.h"
#include "config.h"

typedef enum{
    STATE_SETUP_WIFI,
    STATE_LINK_LAGS,
    STATE_WORK
}typeState;

typeState state = STATE_WORK;

struct{
    typeState state;
    void (*f)(void);
}state2function[] = {
    // { STATE_SETUP_WIFI, doStateSetupWiFi },
    // { STATE_LINK_LAGS,  doStateLinkLaGs },
    // { STATE_WORK,       doStateWork }
    //{ NULL, NULL }
};


void setup()
{
    Serial.begin(115200);    
    pinMode(PIN_KEY, INPUT);
    configBegin();
    configLoad();
    if (digitalRead(PIN_KEY) == LOW){
        while(Serial.available()){ 
            Serial.read();
        }
        configEdit();
    }else{
        Serial2.begin(4800);
        setupWiFi();
        levelSetup();
    }
}


void loop(){    
    //return;
    //levelTerminalLoop();
    //delay(1000);

    levelLoop();  
    
    /*
    for (int i=0; state2function[i].f != NULL; i++){
        if (state == state2function[i].state){
            state2function[i].f();
            break;
        }
    }
    */
}


void doStateSetupWiFi(){
    userSelectWiFi();
}


void doStateLinkLaGs(){

}


void doStateWork(){

}

    /*
    Serial2.println("password:");
    delay(50);
    Serial2.println("error");
    delay(50);
    */
    // if (Serial2.available()){
    //     Serial.println(char(Serial2.read()));
    // }
    //kalitkaTest();
    //battleTest();
    //return;