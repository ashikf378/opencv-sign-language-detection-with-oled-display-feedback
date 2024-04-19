#include <Wire.h>

#include "U8glib.h"


U8GLIB_SH1106_128X64 u8g(U8G_I2C_OPT_DEV_0|U8G_I2C_OPT_FAST);  // Dev 0, Fast I2C / TWI

// Variable to store received gesture
char receivedGesture;
void setup() {
   u8g.setFont(u8g_font_unifont);
  Serial.begin(9600);
}

void loop() {
  // Check if data is available to read from serial
  if (Serial.available() > 0) {
    // Read the incoming byte
    receivedGesture = Serial.read();

    // Perform actions based on the received gesture
    if (receivedGesture == 'A') {
      u8g.firstPage();
      do {
        u8g.drawStr(0, 10, "Power To");  // Draw "Power To" on the display
      } while ( u8g.nextPage() );
    } else if (receivedGesture == 'B') {

       u8g.firstPage();
      do {
        u8g.drawStr(0, 10, "Hi there ");  // Draw "Hi there" on the display
      } while ( u8g.nextPage() );

    } else if (receivedGesture == 'C') {
       u8g.firstPage();
      do {
        u8g.drawStr(0, 10, "We won");  // Draw "be On time" on the display
      } while ( u8g.nextPage() );
 
    }
  }
}
