#include <Arduino.h>
#include <Ticker.h>
// Communication UART entre ESP32-S3 et Arduino Mega 2560
// Exemple utilisant UART1 sur les GPIO 16 (RX) et 17 (TX)
#define PERIOD 100
#define RXD1 16
#define TXD1 17
const uint8_t IN_PIN_3 = 3;
const uint8_t IN_PIN_4 = 4;
const uint8_t IN_PIN_5 = 5;
const uint8_t OUT_PIN_6 = 6;
const uint8_t OUT_PIN_7 = 7;
const uint8_t OUT_PIN_8 = 8;

bool STATE;

uint8_t tabNotes[24];
uint8_t addSol = 0;

void sendReceivedMessage();
void touchState();
void piloteSol(uint8_t tabNotes[]);

Ticker ticker(sendReceivedMessage, PERIOD, 0, MILLIS);

void piloteSol(uint8_t sol)
{
  sol = sol + 3;
  digitalWrite(sol, HIGH);
}

void touchState()
{
  for (uint8_t idx1 = 3; idx1 <= 5; idx1++)
  {
    tabNotes[idx1] = digitalRead(idx1);
    Serial.print(tabNotes[idx1]);
  }
}

void sendReceivedMessage()
{
  for (uint8_t idx0 = 3; idx0 <= 5; idx0++)
  {
    idx0 = idx0 + 3;
    digitalWrite(idx0, 0);
  }
  touchState();
  for (uint8_t idx2 = 3; idx2 <= 5; idx2++)
  {
    if (tabNotes[idx2] == 1)
    {
      switch (idx2)
      {
      case 3:
        Serial1.print("/C5");
        piloteSol(idx2);
        break;
      case 4:
        Serial1.print("/D5");
        piloteSol(idx2);
        break;
      case 5:
        Serial1.print("/E5");
        piloteSol(idx2);
        break;
      default:
        break;
      }
    }
  }
  Serial.println();
}

void setup()
{
   
  Serial.begin(115200);
  Serial1.begin(115200);
  // Pour la communication UART avec l’ESP32-S3
  Serial.println("Mega 2560 prêt !");
  pinMode(IN_PIN_3, INPUT);
  pinMode(IN_PIN_4, INPUT);
  pinMode(IN_PIN_5, INPUT);
  pinMode(OUT_PIN_6, OUTPUT);
  pinMode(OUT_PIN_7, OUTPUT);
  pinMode(OUT_PIN_8, OUTPUT);
   digitalWrite(6, 0);
    digitalWrite(7, 0);
     digitalWrite(8, 0);
  ticker.start();
}
void loop()
{ // Si on reçoit des données de l’ESP32-S3
  ticker.update();
}