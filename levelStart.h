
#ifndef __LEVELSTART_H__
#define __LEVELSTART_H__
#include "Arduino.h"
#include "AsyncUDP.h"

void handlePacketStart(AsyncUDPPacket packet);
void levelStartSetup();
void levelStartLoop();

#endif
