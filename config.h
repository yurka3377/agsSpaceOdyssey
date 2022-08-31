#ifndef __CONFIG_H__
#define __CONFIG_H__

const int MAX_COUNT_SSID = 3;

typedef struct{
    int currentSsid;
    struct{
        char ssid[24];
        char password[24];
    }wifiPoints[MAX_COUNT_SSID];
}Config;

extern Config config;

void configBegin();
void configSave();
void configLoad();
void configEdit();

#endif
