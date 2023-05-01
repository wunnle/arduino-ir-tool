#include <IRremote.h>
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
      int receivedValue = IrReceiver.decodedIRData.decodedRawData;
      if(receivedValue == 56) {
        // wake up the pc
        Serial.println("hello!");
        // monitor switch
        Keyboard.press(KEY_F13);
        Keyboard.release(KEY_F13);
      }
      IrReceiver.resume();
  }
}
