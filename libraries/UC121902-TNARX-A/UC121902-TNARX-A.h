
#ifndef UC121902_TNARX_A_hpp
#define UC121902_TNARX_A_hpp

#include "Arduino.h"

namespace UC121902_TNARX_A {

  uint8_t DP = 4;
  uint8_t DQ = 2;
  uint8_t DR = 1;

  class State {
    private:
      int m_CE_pin;
      int m_CK_pin;
      int m_DI_pin;

    public:
      /*  uint8_t data[14]
          ================
        data = {a, b, c, d, e, f, g, h, i, j, k, l, m, n}
                0  1  2  3  4  5  6  7  8  9 10 11 12 13
                x  x  x  x  x  x     x  x  x  x  x  x
        
        Definition: byte b = data[...]; b[x] means (b & (1 << x)) >> x 
        
        7 Segment Display:
        
            x[2]  -               
            x[0] | | x[4]   
            x[3]  -          
            x[1] | | x[7]
            x[5]  -   

            bits used for x: 1011 1111
                             7 54 3210
                             bit 6 is not in use
        
        Special elements:
         
            g[0] = ?         n[0] = ?
            g[1] = ?         n[1] = ?
            g[2] = ?         n[2] = ?
            g[3] = ?         n[3] = ?
            g[4] = CHAN      n[4] = BATTERY_SECOND_HALF
            g[5] = MEM       n[5] = BATTERY_FIRST_HALF
            g[6] = /CLOCK    n[6] = PROG
            g[7] = CLOCK     n[7] = SEC
      */
      uint8_t m_data[14]; /* 2 * 56bits */
      boolean writeOnChange;

      State(int CE_pin = 2, int CK_pin = 3, int DI_pin = 4) {
        m_CE_pin = CE_pin;
        m_CK_pin = CK_pin;
        m_DI_pin = DI_pin;
        for (int i = 0; i < 14; i++) {
          m_data[i] = 0;
        }
      }
      
      void begin() {
        pinMode(m_CE_pin, OUTPUT);
        pinMode(m_CK_pin, OUTPUT);
        pinMode(m_DI_pin, OUTPUT);
      }
      
      void end() {
        
      }

      void write_bits(uint8_t data[7]) {
        /* assuming length 7 */
        digitalWrite(m_CK_pin, LOW);
        digitalWrite(m_DI_pin, LOW);
        delayMicroseconds(1); // t1, at least 1 microsecond
        digitalWrite(m_CE_pin, HIGH); // t3 must be at least 4 microseconds HIGH
        delayMicroseconds(1); // t1, at least 1 microsecond
        for(int data_index = 0; data_index < 7; data_index++) {
          uint8_t data_byte = data[data_index];
          for (uint8_t bit_mask = 128; bit_mask > 0; bit_mask >>= 1) {
            delayMicroseconds(1); // tSU, at least 1 microseconds and tSU
            digitalWrite(m_DI_pin, data_byte & bit_mask ? HIGH : LOW);
            digitalWrite(m_CK_pin, HIGH);
            delayMicroseconds(1); // tDH, at least 0.25 microseconds
            digitalWrite(m_CK_pin, LOW);
          }
        }
        delayMicroseconds(1);
        digitalWrite(m_DI_pin, LOW);
        delayMicroseconds(1); // t2 - tDH; t2 at least 1.25 microseconds
        digitalWrite(m_CE_pin, LOW); 
      }

      void flush() {
        uint8_t data1[7];
        uint8_t data2[7];
        for (int i = 0; i < 7; i++) data1[i] = m_data[i];
        for (int i = 0; i < 7; i++) data2[i] = m_data[7 + i];
        data1[6] &= 248;
        data1[6] |= DP;
        data2[6] &= 248;
        data2[6] |= DR;
        write_bits(data1);
        delayMicroseconds(4); // t4 at least 4 microseconds
        digitalWrite(13, HIGH);
        write_bits(data2);
        digitalWrite(13, LOW);
      }
      
      uint8_t* data() {
        return m_data;
      }
      
      void changed() {
        if (writeOnChange) {
          flush();
        }
      }
      
  };

  class Switch {
    private: 
      State* state;
      int byte_index;
      int bit_index;
    public: 
      Switch(State* state = NULL, int byte_index = 0, int bit_index = 0) : 
        state(state), byte_index(byte_index), bit_index(bit_index) {
      }
      ~Switch () {
        
      }
      
      void turnOn() {
        state->data()[byte_index] |= 1 << bit_index;
        state->changed();
      }
      
      void turnOff() {
        state->data()[byte_index] &= 255 - (1 << bit_index);
        state->changed();
      }
      
      boolean isOn() {
        return state->data()[byte_index] & (1 << bit_index);
      }
      
      boolean isOff() {
        !isOn();
      }
      
      void toggle() {
        if (isOn()) {
          turnOff();
        } else {
          turnOn();
        }
      }
      
  };

  class Display {
    private:
      State* state;
      /*
            g[4] = CHAN      n[4] = BATTERY_SECOND_HALF
            g[5] = MEM       n[5] = BATTERY_FIRST_HALF
            g[6] = /CLOCK    n[6] = PROG
            g[7] = CLOCK     n[7] = SEC
      */
      Switch CHAN;
      Switch MEM;
      Switch PROG;
      Switch SEC;
      
    public: 
      
      Display(int CE_pin = 2, int CK_pin = 3, int DI_pin = 4) {
        state = new State(CE_pin, CK_pin, DI_pin);
        CHAN = Switch(state, 6, 4);
        MEM = Switch(state, 6, 5);
        PROG = Switch(state, 13, 6);
        SEC = Switch(state, 13, 7);
      }
      ~Display() {
        delete(state);
      }
      
      boolean writeOnChange() {
        return state->writeOnChange;
      }
      void writeOnChange(boolean value) {
        state->writeOnChange = value;
      }
      
      void begin() {
        state->begin();
      }
      
      void end() {
        state->end();
      }
      
      void flush() {
        state->flush();
      }
      
  };
};






#endif