#include <Arduino.h>

#include "SensorManager.h"
#include "LoomController.h"
#include "TreadleEvent.h"

SensorManager sensors;
LoomController loom;

uint32_t nextSequenceNumber = 1;

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
    {
        Serial.println("PRESSED");
    }
    else
    {
        Serial.println("RELEASED");
    }
}

void setup()
{
    Serial.begin(115200);

    delay(1000);

    sensors.begin();

    Serial.println();
    Serial.println("LoomSense Firmware");
    Serial.println("Sensor Manager initialized");
}

void loop()
{
    TreadleEvent event;

    if (sensors.update(event))
    {
        event.sequenceNumber = nextSequenceNumber++;

        printTreadleEvent(event);

        loom.process(event);
    }
}