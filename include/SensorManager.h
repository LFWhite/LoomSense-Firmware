#ifndef SENSOR_MANAGER_H
#define SENSOR_MANAGER_H

#include <Arduino.h>
#include "HallSensor.h"
#include "TreadleEvent.h"

class SensorManager
{
public:
    SensorManager();

    void begin();

    bool update(TreadleEvent& event);

private:
    static constexpr uint8_t SENSOR_COUNT = 1;

    HallSensor sensors[SENSOR_COUNT] = {
        HallSensor(4, 1)
    };
};

#endif