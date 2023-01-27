#include <IRremote.h>

const byte IR_RECEIVE_PIN = 7;

void setup()
{
  Serial.begin(9600);
  Serial.println("IR Receive test");
  IrReceiver.begin(IR_RECEIVE_PIN);
}

void loop() {
  if (IrReceiver.decode()) {
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    IrReceiver.printIRResultShort(&Serial); // Print complete received data in one line
    IrReceiver.printIRSendUsage(&Serial);   // Print the statement required to send this data
    IrReceiver.resume();
    
  }
}
