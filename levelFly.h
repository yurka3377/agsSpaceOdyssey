
#ifndef __LEVELFLY_H__
#define __LEVELFLY_H__
#include "Arduino.h"
#include "AsyncUDP.h"

void handlePacketFly(AsyncUDPPacket packet);
void levelFlySetup();
void levelFlyLoop();

#endif
