#include <Arduino.h>
#include <Ticker.h>
// Communication UART entre ESP32-S3 et Arduino Mega 2560
// Exemple utilisant UART1 sur les GPIO 16 (RX) et 17 (TX)
#define PERIOD 2000
#define RXD1 16
#define TXD1 17

const uint8_t LED_PIN = 12;
bool STATE;

void sendReceivedMessage();

Ticker ticker(sendReceivedMessage, PERIOD, 0, MILLIS);

void sendReceivedMessage()
{
  digitalWrite(LED_PIN, LOW);
  Serial1.print("OK_ESP32");
  if (Serial1.available())
  {
    String recu = Serial1.readStringUntil('\n');
    if (recu == "OK_ARDUINO")
    {
      STATE = 1;
      Serial.print(recu);
      digitalWrite(LED_PIN, STATE);
    }
  }
}

void setup()
{
  Serial.begin(115200);                          // Pour le moniteur série
  Serial1.begin(115200, SERIAL_8N1, RXD1, TXD1); // Pour la communication UART
  Serial.println("ESP32-S3 prêt !");
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);
  ticker.start();
}

void loop()
{
  ticker.update();
}