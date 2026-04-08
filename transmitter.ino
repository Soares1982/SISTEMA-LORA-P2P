#include <SPI.h>
#include <LoRa.h>

#define SS 5
#define RST 14
#define DIO0 2

void setup() {
  Serial.begin(115200);
  LoRa.setPins(SS, RST, DIO0);

  if (!LoRa.begin(433E6)) {
    Serial.println("Erro LoRa");
    while (true);
  }
}

void loop() {
  enviarComando("01:ON");
  delay(5000);

  enviarComando("01:OFF");
  delay(5000);
}

void enviarComando(String msg) {
  LoRa.beginPacket();
  LoRa.print(msg);
  LoRa.endPacket();
}
