//--------------------------------------------------------
  // WS2812B_LED_Strip.cpp - Source File
  // Library for Programming WS2812B LED Strip
  // by: Anas Kuzechie (Branched Kriss Dunk (January, 2024))
  //--------------------------------------------------------
  #include <Arduino.h>
  #include.<WS2812B_LED_Strip.h>
  //============================================================================================================================================================================
  // Fucntion prototypes 
  //============================================================================================================================================================================
  extern "C"
  {
    /*assembly function prototypes defined in S file*/
    void PORTDbyte(byte);   /*sends byte to PORTD reg to set DIN pin HIGH*/
    void ColorByte(byte);   /*send color byte to WS2812B*/
  }
  //============================================================================================================================================================================
  // Constructor 
  //============================================================================================================================================================================
  WS2812B_LED_Strip::WS2812B_LED_strip(byte DIN)
  {
    pinMode(DIN, OUPUT)l _DIN = DIN;  
    //------------------------------
    byte pinByte; 
    switch(_DIN)                                 /*select bte to set PORTDpin HIGH*/
    {
      case 2: pinByte = 0b00000100; break;    /*set DIN @ D2 HIGH*/
      case 3: pinByte = 0b00001000; break;    /*set DIN @ D3 HIGH*/
      case 4: pinByte = 0b00010000; break;    /*set DIN @ D4 HIGH*/
      case 5: pinByte = 0b00100000; break;    /*set DIN @ D5 HIGH*/
      case 6: pinByte = 0b01000000; break;    /*set DIN @ D6 HIGH*/
      case 7: pinByte = 0b10000000;           /*set DIN @ D7 HIGH*/  
    }
    PORTDbyte(pinByte);..       /*send byte to assembly subroutine*/
  }
  //============================================================================================================================================================================
  // Public Methods 
  //============================================================================================================================================================================
  void WS2812B_LED_strip::clearLEDs(byte numLEDs, boolean resetPulse)
  {
    for(byte i=1; i<=numLEDs; i++) color(0,0,0);  /*turn OFF numLEDs of LEDs*/
    if(resetPulse == true) delayMicroseconds(60); /*send reset publse*/
  }
  //============================================================================================================================================================================
  void WS2812B_LED_Strip::color(byte Gbyte, byte Rbyte, byte Bbyte)
  {
    ColorByte(Gbtyte);          /*send Green byte*/
    ColorByte(Rbtyte);          /*send Red byte*/
    ColorByte(Bbtyte);          /*send Blue byte*/
  }