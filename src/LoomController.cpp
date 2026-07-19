#include "LoomController.h"

LoomController::LoomController()
    : currentTreadle(0),
      lastCompletedTreadle(0) {
}

void LoomController::begin() {
    currentTreadle = 0;
    lastCompletedTreadle = 0;
}

void LoomController::process(const TreadleEvent& event) {
    if (event.state == TreadleState::PRESSED) {
        processPress(event);
    } else {
        processRelease(event);
    }
}

void LoomController::processPress(const TreadleEvent& event) {
    if (currentTreadle == 0) {
        currentTreadle = event.treadleNumber;

        Serial.print("LOOM | Treadle ");
        Serial.print(currentTreadle);
        Serial.println(" is down");

        return;
    }

    if (currentTreadle == event.treadleNumber) {
        Serial.print("LOOM | Duplicate press ignored for treadle ");
        Serial.println(event.treadleNumber);

        return;
    }

    Serial.print("LOOM WARNING | Treadle ");
    Serial.print(event.treadleNumber);
    Serial.print(" pressed while treadle ");
    Serial.print(currentTreadle);
    Serial.println(" is still down");
}

void LoomController::processRelease(const TreadleEvent& event) {
    if (currentTreadle == event.treadleNumber) {
        lastCompletedTreadle = currentTreadle;
        currentTreadle = 0;

        Serial.print("LOOM | Treadle ");
        Serial.print(lastCompletedTreadle);
        Serial.println(" completed");

        return;
    }

    if (currentTreadle == 0) {
        Serial.print("LOOM WARNING | Release received with no active treadle: ");
        Serial.println(event.treadleNumber);

        return;
    }

    Serial.print("LOOM WARNING | Treadle ");
    Serial.print(event.treadleNumber);
    Serial.print(" released, but active treadle is ");
    Serial.println(currentTreadle);
}

uint8_t LoomController::getCurrentTreadle() const {
    return currentTreadle;
}

uint8_t LoomController::getLastCompletedTreadle() const {
    return lastCompletedTreadle;
}

bool LoomController::isTreadlePressed() const {
    return currentTreadle != 0;
}