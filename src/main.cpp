#include <Arduino.h>
#include "HallSensor.h"
#include "TreadleEvent.h"
#include "LoomController.h"

// Treadle 1 is connected to GPIO 4.
HallSensor treadle1(4, 1);

// Loom controller
LoomController loom;

// Global event sequence counter
uint32_t nextSequenceNumber = 1;

//------------------------------------------------------------
// Print a treadle event
//------------------------------------------------------------
void printTreadleEvent(const TreadleEvent& event)
{
    Serial.print("EVENT ");
    Serial.print(event.sequenceNumber);

    Serial.print(" | ");
    Serial.print(event.timestampMs);
    Serial.print(" ms");

    Serial.print(" | Treadle ");
    Serial.print(event.treadleNumber);

    Serial.print(" | ");

    if (event.state == TreadleState::PRESSED)
        Serial.println("PRESSED");
    else
        Serial.println("RELEASED");
}

void setup()
{
    Serial.begin(115200);

    treadle1.begin();
    loom.begin();

    Serial.println();
    Serial.println("==================================");
    Serial.println("LoomSense v0.2.0");
    Serial.println("Loom Controller");
    Serial.println("==================================");
    Serial.println("Ready");
}

void loop()
{
    TreadleEvent event;

    if (treadle1.update(event))
    {
        event.sequenceNumber = nextSequenceNumber++;

        printTreadleEvent(event);

        loom.process(event);
    }

    delay(10);
}