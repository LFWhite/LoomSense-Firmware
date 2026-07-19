#ifndef HALL_SENSOR_H
#define HALL_SENSOR_H

#include <Arduino.h>
#include "TreadleEvent.h"

class HallSensor {
public:
    HallSensor(uint8_t pin, uint8_t treadleNumber);

    void begin();
    bool update(TreadleEvent& event);

private:
    uint8_t pin;
    uint8_t treadleNumber;
    int previousState;
};

#endif