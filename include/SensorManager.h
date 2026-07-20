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
    private:
    static constexpr uint8_t SENSOR_COUNT = 2;

    HallSensor sensors[SENSOR_COUNT] = {
        HallSensor(4, 1),
        HallSensor(5, 2)
    };
};

#endif