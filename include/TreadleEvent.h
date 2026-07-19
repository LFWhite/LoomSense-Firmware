#ifndef TREADLE_EVENT_H
#define TREADLE_EVENT_H

#include <Arduino.h>

enum class TreadleState : uint8_t {
    PRESSED,
    RELEASED
};

struct TreadleEvent {
    uint8_t treadleNumber;
    TreadleState state;
    uint32_t timestampMs;
    uint32_t sequenceNumber;
};

#endif