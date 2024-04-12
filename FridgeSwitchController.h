#ifndef FridgeSwitchController_h
#define FridgeSwitchController_h

#include "Arduino.h"

class FridgeSwitchController {
  public:
    FridgeSwitchController(int _board0Pulse, int _board0DemuxA, int _board0DemuxB, int _board0DemuxC, int _board0MuxDemuxEnable, int _board0MuxA, int _board0MuxB, int _board0MuxC, 
                                                int _board1Pulse, int _board1DemuxA, int _board1DemuxB, int _board1DemuxC, int _board1MuxDemuxEnable, int _board1MuxA, int _board1MuxB, int _board1MuxC,
                                                int _board2Pulse, int _board2DemuxA, int _board2DemuxB, int _board2DemuxC, int _board2MuxDemuxEnable, int _board2MuxA, int _board2MuxB, int _board2MuxC,
                                                int _board3Pulse, int _board3DemuxA, int _board3DemuxB, int _board3DemuxC, int _board3MuxDemuxEnable, int _board3MuxA, int _board3MuxB, int _board3MuxC);
    void pulse(int boardNum, int posNum, int negNum);

  private:
    // Board 0 Pins
    int board0Pulse;
    int board0DemuxA;
    int board0DemuxB;
    int board0DemuxC;
    int board0MuxDemuxEnable;
    int board0MuxA;
    int board0MuxB;
    int board0MuxC;
    // Board 1 Pins
    int board1Pulse;
    int board1DemuxA;
    int board1DemuxB;
    int board1DemuxC;
    int board1MuxDemuxEnable;
    int board1MuxA;
    int board1MuxB;
    int board1MuxC;
    // Board 2 Pins
    int board2Pulse;
    int board2DemuxA;
    int board2DemuxB;
    int board2DemuxC;
    int board2MuxDemuxEnable;
    int board2MuxA;
    int board2MuxB;
    int board2MuxC;
    // Board 3 Pins
    int board3Pulse;
    int board3DemuxA;
    int board3DemuxB;
    int board3DemuxC;
    int board3MuxDemuxEnable;
    int board3MuxA;
    int board3MuxB;
    int board3MuxC;

    // Methods
    void pinHigh(int pin);
    void pinLow(int pin);
    void enableMuxDemux(int boardNum);
    void disableMuxDemux(int boardNum);
    void pinSelect0(int pinC, int pinB, int pinA);
    void pinSelect1(int pinC, int pinB, int pinA);
    void pinSelect2(int pinC, int pinB, int pinA);
    void pinSelect3(int pinC, int pinB, int pinA);
    void pinSelect4(int pinC, int pinB, int pinA);
    void pinSelect5(int pinC, int pinB, int pinA);
    void pinSelect6(int pinC, int pinB, int pinA);
    void pinSelect7(int pinC, int pinB, int pinA);
    void pinSelect(int num, int pinC, int pinB, int pinA);
    void pulsePositiveSelect(int boardNum, int binNum);
    void pulseNegativeSelect(int boardNum, int binNum);
    void pulsePinOn(int boardNum);
    void pulsePinOff(int boardNum);
    void pulsePin(int boardNum);

};

#endif