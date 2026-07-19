#ifndef LOOM_CONTROLLER_H
#define LOOM_CONTROLLER_H

#include <Arduino.h>
#include "TreadleEvent.h"

class LoomController {
public:
    LoomController();

    void begin();
    void process(const TreadleEvent& event);

    uint8_t getCurrentTreadle() const;
    uint8_t getLastCompletedTreadle() const;
    bool isTreadlePressed() const;

private:
    uint8_t currentTreadle;
    uint8_t lastCompletedTreadle;

    void processPress(const TreadleEvent& event);
    void processRelease(const TreadleEvent& event);
};

#endif