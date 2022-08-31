
#ifndef __DRIVER_H__
#define __DRIVER_H__

const int ARD_A0 = 14;
const int ARD_A1 = 15;
const int ARD_A2 = 16;
const int ARD_A3 = 17;
const int ARD_A4 = 18;
const int ARD_A5 = 19;

const int PIN_KEY = 34;

const struct{
  int pinArd;
  int pinControl;
}mapPins[] = {
  { 2, 13 }, 
  { 3, 12 }, 
  { 4, 14 }, 
  { 5, 27 }, 
  { 6, 33 }, 
  { 7, 17 },  // TX 
  { 8, 16 },  // RX
  { 9, 32 }, 
  { 10, 5 },
  { 11, 23 }, 
  { 12, 19 }, 
  { 13, 18 }, 
  { ARD_A0, 2  }, 
  { ARD_A1, 4  }, 
  { ARD_A2, 26 },   // DAC1
  { ARD_A3, 25 },   // DAC0
  { ARD_A4, 21 },   // SDA
  { ARD_A5, 22 },   // SCL
  { 0,  0  }
};


#endif

