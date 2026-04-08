#include <SPI.h>
#include <LoRa.h>

#define SS 5
#define RST 14
#define DIO0 2
#define RELE 4

String deviceID = "01";

void setup() {
  Serial.begin(115200);
  pinMode(RELE, OUTPUT);
  digitalWrite(RELE, LOW);

  LoRa.setPins(SS, RST, DIO0);
  if (!LoRa.begin(433E6)) {
    Serial.println("Erro LoRa");
    while (true);
  }
}

void loop() {
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    String msg = "";

    while (LoRa.available()) {
      msg += (char)LoRa.read();
    }

    int separator = msg.indexOf(':');
    String id = msg.substring(0, separator);
    String command = msg.substring(separator + 1);

    if (id == deviceID) {
      if (command == "ON") digitalWrite(RELE, HIGH);
      else if (command == "OFF") digitalWrite(RELE, LOW);
    }
  }
}
