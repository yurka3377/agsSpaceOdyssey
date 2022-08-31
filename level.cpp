
#include "level.h"
#include "levelStart.h"
#include "levelFly.h"
#include "levelLanding.h"

int currentLevel = LEVEL_START;


void levelSetup(){
    switch(currentLevel){
        case LEVEL_START:
            levelStartSetup();
            break;
        case LEVEL_FLY:
            levelFlySetup();
            break;
        case LEVEL_LANDING:
            levelLandingSetup();
            break;
    }
}


void levelLoop(){
    switch(currentLevel){
        case LEVEL_START:
            levelStartLoop();
            break;
        case LEVEL_FLY:
            levelFlyLoop();
            break;
        case LEVEL_LANDING:
            levelLandingLoop();
            break;
    }
}

