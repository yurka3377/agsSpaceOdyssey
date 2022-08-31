
#ifndef __LEVELLANDING_H__
#define __LEVELLANDING_H__
#include "Arduino.h"
#include "AsyncUDP.h"

void handlePacketLanding(AsyncUDPPacket packet);
void levelLandingSetup();
void levelLandingLoop();

#endif
