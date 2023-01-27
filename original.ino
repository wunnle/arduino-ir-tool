#include <IRremote.hpp>
#include <Keyboard.h>


int IR_RECEIVE_PIN = 7;

void setup()
{
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK); // Start the receiver
  Serial.println("hello world");
  Keyboard.begin();
}

void loop() {
  if (IrReceiver.decode()) {
      Serial.println("decoded");
      int receivedValue = IrReceiver.decodedIRData.decodedRawData;
      if(receivedValue == 56) {
        // wake up the pc
        Serial.println("hello!");
        // monitor switch
        Keyboard.press(KEY_LEFT_ALT);
        delay(500);
        Keyboard.press(KEY_LEFT_SHIFT);
        delay(500);
        Keyboard.press('1'); 
        Keyboard.releaseAll();
        delay(1000);
        // steam
        Keyboard.press(KEY_LEFT_ALT);
        delay(500);
        Keyboard.press(KEY_LEFT_SHIFT);
        delay(500);
        Keyboard.press('2'); 
        Keyboard.releaseAll();
        Keyboard.releaseAll();
      }

      IrReceiver.resume();
  }
}
