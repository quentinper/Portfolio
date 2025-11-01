#include <Arduino.h>
/*
// Communication UART entre ESP32-S3 et Arduino Mega 2560
// Exemple utilisant UART1 sur les GPIO 16 (RX) et 17 (TX)
#define RXD1 16
#define TXD1 17
const uint8_t IN_PIN_3_C5 = 3;
const uint8_t IN_PIN_4_D5 = 4;
const uint8_t IN_PIN_5_E5 = 5;
const uint8_t OUT_PIN_6_C5 = 6;
const uint8_t OUT_PIN_7_D5 = 7;
const uint8_t OUT_PIN_8_E5 = 8;
const uint8_t IN_PIN_10_SENSOR = 10;

bool STATE;

uint8_t tabNotes[24];
uint8_t sol;

void sendReceivedMessage();
void touchState();
void piloteSolC5();
void piloteSolD5();
void piloteSolE5();

void piloteSolC5()
{
  digitalWrite(OUT_PIN_6_C5, HIGH);
  delayMicroseconds(10000);
  digitalWrite(OUT_PIN_6_C5, LOW);
}

void piloteSolD5()
{
  digitalWrite(OUT_PIN_7_D5, HIGH);
}

void piloteSolE5()
{
  digitalWrite(OUT_PIN_8_E5, HIGH);
}

void touchState()
{
  sol = 3;
  for (uint8_t idx1 = 0; idx1 <= 2; idx1++)
  {
    tabNotes[idx1] = digitalRead(sol);
    Serial.print(tabNotes[idx1]);
    sol += 1;
  }
}

void sendReceivedMessage()
{
  sol = 0;
  for (uint8_t idx0 = 3; idx0 <= 5; idx0++)
  {
    idx0 = idx0 + 3;
    digitalWrite(idx0, 0);
  }
  Serial.println();
}

void setup()
{
  Serial.begin(115200);
  Serial1.begin(115200);
  // Pour la communication UART avec l’ESP32-S3
  Serial.println("Mega 2560 prêt !");
  pinMode(IN_PIN_3_C5, INPUT);
  attachInterrupt(digitalPinToInterrupt(IN_PIN_3_C5), piloteSolC5, RISING);
  pinMode(IN_PIN_4_D5, INPUT);
  pinMode(IN_PIN_5_E5, INPUT);
  pinMode(OUT_PIN_6_C5, OUTPUT);
  pinMode(OUT_PIN_7_D5, OUTPUT);
  pinMode(OUT_PIN_8_E5, OUTPUT);
  pinMode(IN_PIN_10_SENSOR, INPUT);
  digitalWrite(6, 0);
  digitalWrite(7, 0);
  digitalWrite(8, 0);
}
void loop()
{ // Si on reçoit des données de l’ESP32-S3
  digitalWrite(OUT_PIN_6_C5, LOW);
  digitalWrite(OUT_PIN_7_D5, LOW);
  digitalWrite(OUT_PIN_8_E5, LOW);

  sendReceivedMessage();
  touchState();
}
*/

#define BUT_IN 3
#define BUT1_IN 4
#define BUT2_IN 5
#define BUT_OUT 6
#define BUT1_OUT 7
#define BUT2_OUT 8
void piloteC5();
int tempo = 10000;

bool last_state_but = false;
bool last_state_but1 = false;
bool last_state_but2 = false;
bool state_but = false;
bool state_but1 = false;
bool state_but2 = false;

void piloteC5()
{
  state_but = 1;
  digitalWrite(BUT_OUT, 1);
  delayMicroseconds(500);
  digitalWrite(BUT_OUT, 0);
  if (state_but)
  {
    Serial.println("/C5");
    Serial1.println("/C5");
    state_but = 0;
  }
}

void setup()
{
  Serial.begin(115200);
  Serial1.begin(115200);
  pinMode(BUT_IN, INPUT);
  pinMode(BUT1_IN, INPUT);
  pinMode(BUT2_IN, INPUT);
  pinMode(BUT_OUT, OUTPUT);
  pinMode(BUT1_OUT, OUTPUT);
  pinMode(BUT2_OUT, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(BUT_IN), piloteC5, RISING);
  Serial.println("READY");
}
void loop()
{

  if (digitalRead(BUT_IN) == 1 && last_state_but == 0)
  {
    piloteC5();
  }

  else if (digitalRead(BUT1_IN) == 1 && last_state_but1 == 0)
  {
    state_but1 = 1;
    digitalWrite(BUT1_OUT, 1);
    delayMicroseconds(500);
    digitalWrite(BUT1_OUT, 0);
    if (state_but1)
    {
      Serial.println("/D5");
      Serial1.println("/D5");
      state_but1 = 0;
      last_state_but1 = 0;
    }
  }
  else if (digitalRead(BUT2_IN) == 1 && last_state_but2 == 0)
  {
    state_but2 = 1;
    digitalWrite(BUT2_OUT, 1);
    delayMicroseconds(500);
    digitalWrite(BUT2_OUT, 0);
    if (state_but2)
    {
      Serial.println("/E5");
      Serial1.println("/E5");
      state_but2 = 0;
    }
  }
}