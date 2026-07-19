#include "HallSensor.h"

HallSensor::HallSensor(uint8_t pin, uint8_t treadleNumber)
    : pin(pin),
      treadleNumber(treadleNumber),
      previousState(HIGH) {
}

void HallSensor::begin() {
    pinMode(pin, INPUT_PULLUP);

    // Capture the starting state without creating a false event.
    previousState = digitalRead(pin);
}

bool HallSensor::update(TreadleEvent& event) {
    const int currentState = digitalRead(pin);

    if (currentState == previousState) {
        return false;
    }

    event.treadleNumber = treadleNumber;
    event.timestampMs = millis();

    if (currentState == LOW) {
        event.state = TreadleState::PRESSED;
    } else {
        event.state = TreadleState::RELEASED;
    }

    previousState = currentState;

    return true;
}