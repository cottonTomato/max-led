#include <Arduino.h>
#include "LedController.hpp"

#define DATA_PIN 14
#define CS_PIN 12
#define CLK_PIN 27
#define NUM_SEG 3
#define LED_INTENSITY 10

auto lc = LedController(DATA_PIN, CLK_PIN, CS_PIN);

void setup()
{
    lc.shutdownAllSegments();
    lc.setIntensity(LED_INTENSITY);
    lc.clearMatrix();
}

void loop()
{
    for (int j = 0; j < 8; j++)
    {
        for (int i = 0; i < 8; i++)
        {
            lc.setLed(0, j, i, true);
            delay(1000);
            lc.setLed(0, j, i, false);
            delay(1000);
        }
    }
}
