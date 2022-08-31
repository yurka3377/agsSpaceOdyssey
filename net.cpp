
#include "net.h"
#include "level.h"
#include "levelStart.h"
#include "levelFly.h"
#include "config.h"

void handlePacketControl(AsyncUDPPacket packet);
void handlePacketLevel(AsyncUDPPacket packet);


int sl;

void userSelectWiFi(){

}


//const char * ssid; // = "RIOC-Education2";
//const char * password; // = "123456789r";

const char * ssid = "ArduinoQuest";
const char * password = "Infotech72";

AsyncUDP udpLevel;
AsyncUDP udpControl;


void setupWiFi(){
    //ssid = config.wifiPoints[config.currentSsid].ssid;
    //password = config.wifiPoints[config.currentSsid].password;
    Serial.println(ssid);
    Serial.println(password);
    configSave();
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    if (WiFi.waitForConnectResult() != WL_CONNECTED) {
        Serial.println("WiFi Failed");
        while(1) {
            delay(1000);
        }
    }
    if(udpLevel.listen(8050)) {
        Serial.print("UDP Listening on IP: (8050) ");
        Serial.println(WiFi.localIP());
        udpLevel.onPacket([](AsyncUDPPacket packet) {
            /*
            Serial.print("UDP Packet Type: ");
            Serial.print(packet.isBroadcast()?"Broadcast":packet.isMulticast()?"Multicast":"Unicast");
            Serial.print(", From: ");
            Serial.print(packet.remoteIP());
            Serial.print(":");
            Serial.print(packet.remotePort());
            Serial.print(", To: ");
            Serial.print(packet.localIP());
            Serial.print(":");
            Serial.print(packet.localPort());
            Serial.print(", Length: ");
            Serial.print(packet.length());
            Serial.print(", Data: ");
            Serial.print(String(int(packet.data()[0])));
            sl = packet.data()[0];
            //Serial.write(packet.data(), packet.length());
            Serial.println();
            */
            handlePacketLevel(packet);
            //reply to the client
            //packet.printf("Got %u bytes of data", packet.length());
        });
    }

    if(udpControl.listen(8051)) {
        Serial.print("UDP Listening on IP: (8051)");
        Serial.println(WiFi.localIP());
        udpControl.onPacket([](AsyncUDPPacket packet) {
            /*
            Serial.print("UDP Packet Type: ");
            Serial.print(packet.isBroadcast()?"Broadcast":packet.isMulticast()?"Multicast":"Unicast");
            Serial.print(", From: ");
            Serial.print(packet.remoteIP());
            Serial.print(":");
            Serial.print(packet.remotePort());
            Serial.print(", To: ");
            Serial.print(packet.localIP());
            Serial.print(":");
            Serial.print(packet.localPort());
            Serial.print(", Length: ");
            Serial.print(packet.length());
            Serial.print(", Data: ");
            Serial.print(String(int(packet.data()[0])));
            sl = packet.data()[0];
            //Serial.write(packet.data(), packet.length());
            Serial.println();
            */
            handlePacketControl(packet);
            //reply to the client
            //packet.printf("Got %u bytes of data", packet.length());
        });
    }
}


void handlePacketLevel(AsyncUDPPacket packet){
    Serial.println(String("handlePacketLevel - ") + String(int(packet.data()[0])));
    currentLevel = int(packet.data()[1]);
    Serial.println(String("currentLevel - ") + String(int(currentLevel)));
    switch(currentLevel){
        case LEVEL_START:
            handlePacketStart(packet);
            break;
        case LEVEL_FLY:
            handlePacketFly(packet);
            break;
        // case LEVEL_START:
        //     handlePacketStart(packet);
        //     break;
    }
}


void handlePacketControl(AsyncUDPPacket packet){
    int newLevel = int(packet.data()[0]);
    Serial.println(String("handlePacketControl - ") + String(newLevel));
    if (newLevel > 0 && newLevel <= 3){
        Serial.print("new level = ");
        Serial.println(newLevel);
        currentLevel = newLevel;
        levelSetup();
    }
    /*
    if (packet.length() > 0){
        currentLevel = packet.data()[0];
        Serial.print("currentLevel = ");
        Serial.println(currentLevel);
    }
    */
}


void loopWiFi(){
    // dacWrite(26, sl);
    // delay(100);
    //Send broadcast
    //udp.broadcast("Anyone here?");
}