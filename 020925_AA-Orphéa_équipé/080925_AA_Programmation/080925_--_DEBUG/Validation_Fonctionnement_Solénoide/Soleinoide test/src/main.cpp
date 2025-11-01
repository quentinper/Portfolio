// librairies
#include <Arduino.h>
#include <Ticker.h>
// define
// notes
#define noteDo 5
#define noteRe 6
#define noteMi 7
#define noteFa 8
#define noteSol 9
#define LED 10
// Periode
#define PERIOD 2000

// const

// Var
int tab[5] = {noteDo, noteRe, noteMi, noteFa, noteSol};
bool partition = 1;
// fonctions
void Play();

Ticker ticker(Play, PERIOD, 0, MILLIS);

// fonctions jouer une partition
void Play()
{
  partition = !partition;
  digitalWrite(LED, partition);
  switch (partition)
  {
  case 0:
    for (uint8_t idx = 0; idx < 4; idx++)
    {
      digitalWrite(tab[idx], 1);
      Serial.print("\t");
      Serial.print(idx);
      delay(100);
      digitalWrite(tab[idx], 0);
    }
    break;
  case 1:
    for (uint8_t idx1 = 0; idx1 < 4; idx1++)
    {
      digitalWrite(tab[idx1], 1);
      digitalWrite(tab[idx1 + 1], 1);
      Serial.print("\t");
      Serial.print(idx1);
      Serial.print(idx1 + 1);
      delay(100);
      digitalWrite(tab[idx1], 0);
      digitalWrite(tab[idx1 + 1], 0);
    }
    break;
  }
}

void setup()
{
  Serial.begin(115200);
  Serial.print("Debut de l'orchestre");
  ticker.start();
}

void loop()
{
  // put your main code here, to run repeatedly:
  ticker.update();
}
