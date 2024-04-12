#include "FridgeSwitchController.h"

FridgeSwitchController::FridgeSwitchController(int _board0Pulse, int _board0DemuxA, int _board0DemuxB, int _board0DemuxC, int _board0MuxDemuxEnable, int _board0MuxA, int _board0MuxB, int _board0MuxC, 
                                                int _board1Pulse, int _board1DemuxA, int _board1DemuxB, int _board1DemuxC, int _board1MuxDemuxEnable, int _board1MuxA, int _board1MuxB, int _board1MuxC,
                                                int _board2Pulse, int _board2DemuxA, int _board2DemuxB, int _board2DemuxC, int _board2MuxDemuxEnable, int _board2MuxA, int _board2MuxB, int _board2MuxC,
                                                int _board3Pulse, int _board3DemuxA, int _board3DemuxB, int _board3DemuxC, int _board3MuxDemuxEnable, int _board3MuxA, int _board3MuxB, int _board3MuxC) {
  // Board 0 Pins
  board0Pulse = _board0Pulse;
  board0DemuxA = _board0DemuxA;
  board0DemuxB = _board0DemuxB;
  board0DemuxC = _board0DemuxC;
  board0MuxDemuxEnable = _board0MuxDemuxEnable;
  board0MuxA = _board0MuxA;
  board0MuxB = _board0MuxB;
  board0MuxC = _board0MuxC;
  // Board 1 Pins
  board1Pulse = _board1Pulse;
  board1DemuxA = _board1DemuxA;
  board1DemuxB = _board1DemuxB;
  board1DemuxC = _board1DemuxC;
  board1MuxDemuxEnable = _board1MuxDemuxEnable;
  board1MuxA = _board1MuxA;
  board1MuxB = _board1MuxB;
  board1MuxC = _board1MuxC;
  // Board 2 Pins
  board2Pulse = _board2Pulse;
  board2DemuxA = _board2DemuxA;
  board2DemuxB = _board2DemuxB;
  board2DemuxC = _board2DemuxC;
  board2MuxDemuxEnable = _board2MuxDemuxEnable;
  board2MuxA = _board2MuxA;
  board2MuxB = _board2MuxB;
  board2MuxC = _board2MuxC;
  // Board 3 Pins
  board3Pulse = _board3Pulse;
  board3DemuxA = _board3DemuxA;
  board3DemuxB = _board3DemuxB;
  board3DemuxC = _board3DemuxC;
  board3MuxDemuxEnable = _board3MuxDemuxEnable;
  board3MuxA = _board3MuxA;
  board3MuxB = _board3MuxB;
  board3MuxC = _board3MuxC;

  // Board 0 Pins Setup
  pinMode(board0Pulse, OUTPUT);
  pinMode(board0DemuxA, OUTPUT);
  pinMode(board0DemuxB, OUTPUT);
  pinMode(board0DemuxC, OUTPUT);
  pinMode(board0MuxDemuxEnable, OUTPUT);
  pinMode(board0MuxA, OUTPUT);
  pinMode(board0MuxB, OUTPUT);
  pinMode(board0MuxC, OUTPUT);
  // Board 1 Pins Setup
  pinMode(board1Pulse, OUTPUT);
  pinMode(board1DemuxA, OUTPUT);
  pinMode(board1DemuxB, OUTPUT);
  pinMode(board1DemuxC, OUTPUT);
  pinMode(board1MuxDemuxEnable, OUTPUT);
  pinMode(board1MuxA, OUTPUT);
  pinMode(board1MuxB, OUTPUT);
  pinMode(board1MuxC, OUTPUT);
  // Board 2 Pins Setup
  pinMode(board2Pulse, OUTPUT);
  pinMode(board2DemuxA, OUTPUT);
  pinMode(board2DemuxB, OUTPUT);
  pinMode(board2DemuxC, OUTPUT);
  pinMode(board2MuxDemuxEnable, OUTPUT);
  pinMode(board2MuxA, OUTPUT);
  pinMode(board2MuxB, OUTPUT);
  pinMode(board2MuxC, OUTPUT);
  // Board 3 Pins Setup
  pinMode(board3Pulse, OUTPUT);
  pinMode(board3DemuxA, OUTPUT);
  pinMode(board3DemuxB, OUTPUT);
  pinMode(board3DemuxC, OUTPUT);
  pinMode(board3MuxDemuxEnable, OUTPUT);
  pinMode(board3MuxA, OUTPUT);
  pinMode(board3MuxB, OUTPUT);
  pinMode(board3MuxC, OUTPUT);
}

void FridgeSwitchController::pinHigh(int pin) {
  digitalWrite(pin, HIGH);
}

void FridgeSwitchController::pinLow(int pin) {
  digitalWrite(pin, LOW);
}

/* Input:  The number between 0 and 3 of the board you want to enable:   boardNum
 * Result: That board's Mux and Demux being enabled
 */
void FridgeSwitchController::enableMuxDemux(int boardNum) {
  if(boardNum == 0) {
    pinHigh(board0MuxDemuxEnable);
  }
  else if(boardNum == 1) {
    pinHigh(board1MuxDemuxEnable);
  }
  else if(boardNum == 2) {
    pinHigh(board2MuxDemuxEnable);
  }
  else if(boardNum == 3) {
    pinHigh(board3MuxDemuxEnable);
  }
  else {
    Serial.println("Improper board number for enableMuxDemux");
  }
}

/* Input:  The number between 0 and 3 of the board you want to disable:    boardNum
 * Result: That board's Mux and Demux being disabled
 */
void FridgeSwitchController::disableMuxDemux(int boardNum) {
  if(boardNum == 0) {
    pinLow(board0MuxDemuxEnable);
  }
  else if(boardNum == 1) {
    pinLow(board1MuxDemuxEnable);
  }
  else if(boardNum == 2) {
    pinLow(board2MuxDemuxEnable);
  }
  else if(boardNum == 3) {
    pinLow(board3MuxDemuxEnable);
  }
  else {
    Serial.println("Improper board number for disableMuxDemux");
  }
}

/* Inputs:  The pin of the most significant bit:    pinC
 *          The pin of the middle significant bit:  pinB
 *          The pin of the least Significant bit:   pinA
 * Result: 0 in binary being set on the three pins
 */
void FridgeSwitchController::pinSelect0(int pinC, int pinB, int pinA) {
  pinLow(pinC);
  pinLow(pinB);
  pinLow(pinA);
}

/* Inputs:  The pin of the most significant bit:    pinC
 *          The pin of the middle significant bit:  pinB
 *          The pin of the least Significant bit:   pinA
 * Result: 1 in binary being set on the three pins
 */
void FridgeSwitchController::pinSelect1(int pinC, int pinB, int pinA) {
  pinLow(pinC);
  pinLow(pinB);
  pinHigh(pinA);
}

/* Inputs:  The pin of the most significant bit:    pinC
 *          The pin of the middle significant bit:  pinB
 *          The pin of the least Significant bit:   pinA
 * Result: 2 in binary being set on the three pins
 */
void FridgeSwitchController::pinSelect2(int pinC, int pinB, int pinA) {
  pinLow(pinC);
  pinHigh(pinB);
  pinLow(pinA);
}

/* Inputs:  The pin of the most significant bit:    pinC
 *          The pin of the middle significant bit:  pinB
 *          The pin of the least Significant bit:   pinA
 * Result: 3 in binary being set on the three pins
 */
void FridgeSwitchController::pinSelect3(int pinC, int pinB, int pinA) {
  pinLow(pinC);
  pinHigh(pinB);
  pinHigh(pinA);
}

/* Inputs:  The pin of the most significant bit:    pinC
 *          The pin of the middle significant bit:  pinB
 *          The pin of the least Significant bit:   pinA
 * Result: 4 in binary being set on the three pins
 */
void FridgeSwitchController::pinSelect4(int pinC, int pinB, int pinA) {
  pinHigh(pinC);
  pinLow(pinB);
  pinLow(pinA);
}

/* Inputs:  The pin of the most significant bit:    pinC
 *          The pin of the middle significant bit:  pinB
 *          The pin of the least Significant bit:   pinA
 * Result: 5 in binary being set on the three pins
 */
void FridgeSwitchController::pinSelect5(int pinC, int pinB, int pinA) {
  pinHigh(pinC);
  pinLow(pinB);
  pinHigh(pinA);
}

/* Inputs:  The pin of the most significant bit:    pinC
 *          The pin of the middle significant bit:  pinB
 *          The pin of the least Significant bit:   pinA
 * Result: 6 in binary being set on the three pins
 */
void FridgeSwitchController::pinSelect6(int pinC, int pinB, int pinA) {
  pinHigh(pinC);
  pinHigh(pinB);
  pinLow(pinA);
}

/* Inputs:  The pin of the most significant bit:    pinC
 *          The pin of the middle significant bit:  pinB
 *          The pin of the least Significant bit:   pinA
 * Result: 7 in binary being set on the three pins
 */
void FridgeSwitchController::pinSelect7(int pinC, int pinB, int pinA) {
  pinHigh(pinC);
  pinHigh(pinB);
  pinHigh(pinA);
}

/* Inputs:  The number between 0 and 7 to be displayed: num
 *          The pin of the most significant bit:        pinC
 *          The pin of the middle significant bit:      pinB
 *          The pin of the least Significant bit:       pinA
 * Result: The desired number in binary being set on the three pins
 */
void FridgeSwitchController::pinSelect(int num, int pinC, int pinB, int pinA) {
  if(num == 0) {
    pinSelect0(pinC, pinB, pinA);
  }
  else if(num == 1) {
    pinSelect1(pinC, pinB, pinA);
  }
  else if(num == 2) {
    pinSelect2(pinC, pinB, pinA);
  }
  else if(num == 3) {
    pinSelect3(pinC, pinB, pinA);
  }
  else if(num == 4) {
    pinSelect4(pinC, pinB, pinA);
  }
  else if(num == 5) {
    pinSelect5(pinC, pinB, pinA);
  }
  else if(num == 6) {
    pinSelect6(pinC, pinB, pinA);
  }
  else if(num == 7) {
    pinSelect7(pinC, pinB, pinA);
  }
  else {
    Serial.println("Improper number for pinSelect");
  }
}

/* Inputs:  The number between 0 and 3 of the board to be selected:             boardNum
 *          The number between 0 and 7 of the pin to be selected on the demux:  binNum
 *  Result: The desired pin on the desired board being selected as positive for the pulse
 */
void FridgeSwitchController::pulsePositiveSelect(int boardNum, int binNum){
  if((binNum <= 7) && (0 <= binNum)) {
    if(boardNum == 0) {
      pinSelect(binNum, board0DemuxC, board0DemuxB, board0DemuxA);
    }
    else if(boardNum == 1) {
      pinSelect(binNum, board1DemuxC, board1DemuxB, board1DemuxA);
    }
    else if(boardNum == 2) {
      pinSelect(binNum, board2DemuxC, board2DemuxB, board2DemuxA);
    }
    else if(boardNum == 3) {
      pinSelect(binNum, board3DemuxC, board3DemuxB, board3DemuxA);
    }
    else {
      Serial.println("Improper board number for pulsePositive");
    }
  }
  else {
    Serial.println("Improper binary number for pulsePositive");
  }
}

/* Inputs:  The number between 0 and 3 of the board to be selected:             boardNum
 *          The number between 0 and 7 of the pin to be selected on the mux:    binNum
 *  Result: The desired pin on the desired board being selected as negative for the pulse
 */
void FridgeSwitchController::pulseNegativeSelect(int boardNum, int binNum){
  if((binNum <= 7) && (0 <= binNum)) {
    if(boardNum == 0) {
      pinSelect(binNum, board0MuxC, board0MuxB, board0MuxA);
    }
    else if(boardNum == 1) {
      pinSelect(binNum, board1MuxC, board1MuxB, board1MuxA);
    }
    else if(boardNum == 2) {
      pinSelect(binNum, board2MuxC, board2MuxB, board2MuxA);
    }
    else if(boardNum == 3) {
      pinSelect(binNum, board3MuxC, board3MuxB, board3MuxA);
    }
    else {
      Serial.println("Improper board number for pulseNegative");
    }
  }
  else {
    Serial.println("Improper binary number for pulseNegative");
  }
}

/* Inputs:  The number between 0 and 3 of the board to have its pulse pin set high: boardNum
 * Result: The board of the desired number having its pulse pin set high.
 */
void FridgeSwitchController::pulsePinOn(int boardNum) {
  if(boardNum == 0) {
    pinHigh(board0Pulse);
  }
  else if(boardNum == 1) {
    pinHigh(board1Pulse);
  }
  else if(boardNum == 2) {
    pinHigh(board2Pulse);
  }
  else if(boardNum == 3) {
    pinHigh(board3Pulse);
  }
  else {
    Serial.println("Improper board number for pulsePinOn");
  }
}

/* Inputs:  The number between 0 and 3 of the board to have its pulse pin set low: boardNum
 * Result: The board of the desired number having its pulse pin set low.
 */
void FridgeSwitchController::pulsePinOff(int boardNum) {
  if(boardNum == 0) {
    pinLow(board0Pulse);
  }
  else if(boardNum == 1) {
    pinLow(board1Pulse);
  }
  else if(boardNum == 2) {
    pinLow(board2Pulse);
  }
  else if(boardNum == 3) {
    pinLow(board3Pulse);
  }
  else {
    Serial.println("Improper board number for pulsePinOff");
  }
}

/* Inputs:  The number between 0 and 3 of the board to be pulsed: boardNum
 * Result: The board of the desired number pulsing.
 */
void FridgeSwitchController::pulsePin(int boardNum) {
  if((boardNum <= 3) && (0 <= boardNum)) {
    pulsePinOn(boardNum);
    delayMicroseconds(16000);   //Determines the max time of the pulse
    pulsePinOff(boardNum);
  }
  else {
    Serial.println("Improper board number for pulsePin");
  }
}

/* Inputs:  The number of the board the pins are to be pulsed on:   boardNum
 *          The pin that is to be pulsed positive:                  posNum
 *          The pin that is to be pulsed negative:                  negNum
 * Result: The desired pins on the desired board are pulsed
 */
void FridgeSwitchController::pulse(int boardNum, int posNum, int negNum) {
  if((0 <= boardNum) && (boardNum <=3)) {
    if(posNum != negNum) {
      if((0 <= posNum) && (posNum <= 7)) {
        if((0 <= negNum) && (negNum <= 7)) {
          enableMuxDemux(boardNum);
          pulsePositiveSelect(boardNum, posNum);
          pulseNegativeSelect(boardNum, negNum);
          delayMicroseconds(100);    //Necessary to give the relays some time to get up to voltage
          pulsePin(boardNum);
          disableMuxDemux(boardNum);
        }
        else {
          Serial.println("Improper negative number for pulse");
        }
      }
      else {
        Serial.println("Improper positive number for pulse");
      }
    }
    else {
      Serial.println("The positive and negative pins cannot be equal in pulse");
    }
  }
  else {
    Serial.println("Improper board number for pulse");
  }
}
