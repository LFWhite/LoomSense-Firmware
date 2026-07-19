#include "SensorManager.h"

SensorManager::SensorManager()
{
}

void SensorManager::begin()
{
    for (uint8_t i = 0; i < SENSOR_COUNT; i++)
    {
        sensors[i].begin();
    }
}

bool SensorManager::update(TreadleEvent& event)
{
    for (uint8_t i = 0; i < SENSOR_COUNT; i++)
    {
        if (sensors[i].update(event))
        {
            return true;
        }
    }

    return false;
}