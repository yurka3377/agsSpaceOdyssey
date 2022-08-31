
#ifndef __LEVEL_H__
#define __LEVEL_H__

enum{
    LEVEL_START=1,
    LEVEL_FLY,
    LEVEL_LANDING
};

extern int currentLevel;
void levelSetup();
void levelLoop();

#endif
