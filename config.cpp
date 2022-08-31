
#include "config.h"
#include <EEPROM.h>

Config config;
/*
 = {
    0,
    {
        { "RIOC-Education2", "123456789r" },
        { "ArduinoQuest3", "Infotech72" },
        { "Tochka kipenia - 2", "123456789r" },
    }
};
*/

char strInput[10];

void ssidPrintList();
void printMenu();
void handleCmd();

void configBegin(){
    EEPROM.begin(sizeof(config));
}


void configSave(){
    EEPROM.put(0, config);
    EEPROM.commit();
}


void configLoad(){
    EEPROM.get(0, config);
}


void configEdit(){
    for(;;){
        ssidPrintList();
        printMenu();
        handleCmd();
    }
}


void getString(){
    static int i=0;
    char c;

    Serial.println("in GetString()");
    for(;;){
        if (Serial.available()){
            c = Serial.read();
            if (c == 10){
                break;
            }
            if (c == 13){
                Serial.println("in GetString() end!");
                strInput[i] = 0;
                i = 0;
                return;
            }else{
                strInput[i] = c;
            }
            i++;
            if (i >= 10){
                i--;
            }
        }
    }
}


void  ssidPrintList(){
    char c;
    char buff[80];

    Serial.println("list ssid:");
    for (int i=0; i < MAX_COUNT_SSID; i++){
        c = (i == config.currentSsid) ? '*' : ' ';
        sprintf(buff, "%c %d) ssid: \"%23s\", password: \"%23s\"", c, i, config.wifiPoints[i].ssid, config.wifiPoints[i].password);
        Serial.println(buff);
    }
}


void printMenu(){
    Serial.println("");
    Serial.println("E<num> - edit ssid, L - list ssid, C<num> - set current ssid");
}


void handleCmd(){
    int n;
    getString();
    switch(strInput[0]){
        case 'C':
            n = strInput[1] - '0';
            if (n >=0 && n <= 2){
                config.currentSsid = n;
                configSave();
            }
            break;
        case 'L':
            ssidPrintList();
            break;
        case 'E':
            Serial.println("in EEE: ");
            n = strInput[1] - '0';
            if (n >=0 && n <= 2){
                Serial.println("SSID: ");
                getString();
                strcpy(config.wifiPoints[n].ssid, strInput);
                Serial.println("password: ");
                getString();
                strcpy(config.wifiPoints[n].password, strInput);
                configSave();
            }
            break;
    }
}