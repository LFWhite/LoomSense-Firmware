#include <Arduino.h>

#include "SensorManager.h"
#include "LoomController.h"
#include "TreadleEvent.h"

SensorManager sensors;
LoomController loom;

uint32_t nextEventId = 1;

void printTreadleEvent(const TreadleEvent& event)
{
    Serial.print("{\"treadle\":");
    Serial.print(event.treadleNumber);

    Serial.print(",\"state\":\"");

    if (event.state == TreadleState::PRESSED)
    {
        Serial.print("PRESSED");
    }
    else
    {
        Serial.print("RELEASED");
    }

    Serial.print("\",\"timestampMs\":");
    Serial.print(event.timestampMs);

    Serial.print(",\"eventId\":");
    Serial.print(event.eventId);

    Serial.println("}");
}

void setup()
{
    Serial.begin(115200);

    delay(1000);

    sensors.begin();
    loom.begin();

    Serial.println();
    Serial.println("LoomSense Firmware");
    Serial.println("Sensor Manager initialized");
}

void loop()
{
    TreadleEvent event;

    if (sensors.update(event))
    {
        event.eventId = nextEventId++;

        printTreadleEvent(event);

        loom.process(event);
    }
}