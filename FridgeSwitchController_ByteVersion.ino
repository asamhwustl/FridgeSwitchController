
  // Board 0 Pins
  int board0Pulse = 22;
  int board0DemuxA = 24;
  int board0DemuxB = 26;
  int board0DemuxC = 28;
  int board0MuxDemuxEnable = 30;
  int board0MuxA = 32;
  int board0MuxB = 34;
  int board0MuxC = 36;
  // Board 1 Pins
  int board1Pulse = 38;
  int board1DemuxA = 40;
  int board1DemuxB = 42;
  int board1DemuxC = 44;
  int board1MuxDemuxEnable = 46;
  int board1MuxA = 48;
  int board1MuxB = 50;
  int board1MuxC = 52;
  // Board 2 Pins
  int board2Pulse = 23;
  int board2DemuxA = 25;
  int board2DemuxB = 27;
  int board2DemuxC = 29;
  int board2MuxDemuxEnable = 31;
  int board2MuxA = 33;
  int board2MuxB = 35;
  int board2MuxC = 37;
  // Board 3 Pins
  int board3Pulse = 39;
  int board3DemuxA = 41;
  int board3DemuxB = 43;
  int board3DemuxC = 45;
  int board3MuxDemuxEnable = 47;
  int board3MuxA = 49;
  int board3MuxB = 51;
  int board3MuxC = 53;

void setup() {
  Serial.begin(9600);

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

void pinHigh(int pin) {
  digitalWrite(pin, HIGH);
  Serial.println(pin);
}

void pinLow(int pin) {
  digitalWrite(pin, LOW);
  Serial.println(pin);
}

/* Input:  The number between 0 and 3 of the board you want to enable:   boardNum
 * Result: That board's Mux and Demux being enabled
 */
void enableMuxDemux(int boardNum) {
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
void disableMuxDemux(int boardNum) {
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
void pinSelect0(int pinC, int pinB, int pinA) {
  pinLow(pinC);
  pinLow(pinB);
  pinLow(pinA);
}

/* Inputs:  The pin of the most significant bit:    pinC
 *          The pin of the middle significant bit:  pinB
 *          The pin of the least Significant bit:   pinA
 * Result: 1 in binary being set on the three pins
 */
void pinSelect1(int pinC, int pinB, int pinA) {
  pinLow(pinC);
  pinLow(pinB);
  pinHigh(pinA);
}

/* Inputs:  The pin of the most significant bit:    pinC
 *          The pin of the middle significant bit:  pinB
 *          The pin of the least Significant bit:   pinA
 * Result: 2 in binary being set on the three pins
 */
void pinSelect2(int pinC, int pinB, int pinA) {
  pinLow(pinC);
  pinHigh(pinB);
  pinLow(pinA);
}

/* Inputs:  The pin of the most significant bit:    pinC
 *          The pin of the middle significant bit:  pinB
 *          The pin of the least Significant bit:   pinA
 * Result: 3 in binary being set on the three pins
 */
void pinSelect3(int pinC, int pinB, int pinA) {
  pinLow(pinC);
  pinHigh(pinB);
  pinHigh(pinA);
}

/* Inputs:  The pin of the most significant bit:    pinC
 *          The pin of the middle significant bit:  pinB
 *          The pin of the least Significant bit:   pinA
 * Result: 4 in binary being set on the three pins
 */
void pinSelect4(int pinC, int pinB, int pinA) {
  pinHigh(pinC);
  pinLow(pinB);
  pinLow(pinA);
}

/* Inputs:  The pin of the most significant bit:    pinC
 *          The pin of the middle significant bit:  pinB
 *          The pin of the least Significant bit:   pinA
 * Result: 5 in binary being set on the three pins
 */
void pinSelect5(int pinC, int pinB, int pinA) {
  pinHigh(pinC);
  pinLow(pinB);
  pinHigh(pinA);
}

/* Inputs:  The pin of the most significant bit:    pinC
 *          The pin of the middle significant bit:  pinB
 *          The pin of the least Significant bit:   pinA
 * Result: 6 in binary being set on the three pins
 */
void pinSelect6(int pinC, int pinB, int pinA) {
  pinHigh(pinC);
  pinHigh(pinB);
  pinLow(pinA);
}

/* Inputs:  The pin of the most significant bit:    pinC
 *          The pin of the middle significant bit:  pinB
 *          The pin of the least Significant bit:   pinA
 * Result: 7 in binary being set on the three pins
 */
void pinSelect7(int pinC, int pinB, int pinA) {
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
void pinSelect(int num, int pinC, int pinB, int pinA) {
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
  }
}

/* Inputs:  The number between 0 and 3 of the board to be selected:             boardNum
 *          The number between 0 and 7 of the pin to be selected on the demux:  binNum
 *  Result: The desired pin on the desired board being selected as positive for the pulse
 */
void pulsePositiveSelect(int boardNum, int binNum){
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
    }
  }
  else {
  }
}

/* Inputs:  The number between 0 and 3 of the board to be selected:             boardNum
 *          The number between 0 and 7 of the pin to be selected on the mux:    binNum
 *  Result: The desired pin on the desired board being selected as negative for the pulse
 */
void pulseNegativeSelect(int boardNum, int binNum){
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
    }
  }
  else {
  }
}

/* Inputs:  The number between 0 and 3 of the board to have its pulse pin set high: boardNum
 * Result: The board of the desired number having its pulse pin set high.
 */
void pulsePinOn(int boardNum) {
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
  }
}

/* Inputs:  The number between 0 and 3 of the board to have its pulse pin set low: boardNum
 * Result: The board of the desired number having its pulse pin set low.
 */
void pulsePinOff(int boardNum) {
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
  }
}

/* Inputs:  The number between 0 and 3 of the board to be pulsed: boardNum
 * Result: The board of the desired number pulsing.
 */
void pulsePin(int boardNum) {
  if((boardNum <= 3) && (0 <= boardNum)) {
    pulsePinOn(boardNum);
    delayMicroseconds(16000);   //Determines the max time of the pulse
    pulsePinOff(boardNum);
  }
  else {
  }
}

/* Inputs:  The number of the board the pins are to be pulsed on:   boardNum
 *          The pin that is to be pulsed positive:                  posNum
 *          The pin that is to be pulsed negative:                  negNum
 * Result: The desired pins on the desired board are pulsed
 */
void pulse(int boardNum, int posNum, int negNum) {
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
        }
      }
      else {
      }
    }
    else {
    }
  }
  else {
  }
}

void loop() {
  char startbyte = 0x10;
  char endbyte = 0x27;
  byte command[7];
  boolean gotcommand = false;
  
  if((Serial.available() > 0) && !gotcommand){
    if(Serial.read() == startbyte){
      Serial.readBytes(command, 7);
      if(command[6] == endbyte){
        gotcommand = true;
      }
      else {
      }
    }
  }

  if(gotcommand){

    int boardnum = command[1];
    int posnum = command[3];
    int negnum = command[5];

    Serial.println("Pulsing " + (String)boardnum + " " + (String)posnum + " " + (String)negnum);
    pulse(boardnum, posnum, negnum);
    
    gotcommand = false;
  }
}
