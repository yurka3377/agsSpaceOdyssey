#ifndef __NET_H__
#define __NET_H__

#include "Arduino.h"
#include "WiFi.h"
#include <AsyncUDP.h>

extern AsyncUDP udpLevel;
extern AsyncUDP udpControl;

void userSelectWiFi();
void setupWiFi();

#endif
