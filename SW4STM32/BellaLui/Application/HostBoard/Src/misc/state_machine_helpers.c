#include "misc/state_machine_helpers.h"

#include "misc/rocket_constants.h"

namespace state_machine_helpers {

    bool handleLiftoffState(const uint32_t currentTime, const uint32_t previousTime) {
		// determine motor burn-out based on lift-off detection
		if ((currentTime - previousTime) > ROCKET_CST_MOTOR_BURNTIME) {
		    //return STATE_COAST; // switch to coast state
            return true;
        }
        //return STATE_LIFTOFF;
        return false;
    }

    uint8_t newImuDataIsAvailable(const uint32_t currentImuSeqNumber, const uint32_t lastImuSeqNumber) {
        return currentImuSeqNumber > lastImuSeqNumber;
    }

    uint8_t newBarometerDataIsAvailable(const uint32_t currentBaroSeqNumber, const uint32_t lastBaroSeqNumber){
        return currentBaroSeqNumber > lastBaroSeqNumber;
    }

    bool touchdownStateIsReached(const uint32_t currentTime, const uint32_t liftoff_time){
        const bool timeExceedsFiveMinutes = ((int32_t) currentTime - (int32_t) liftoff_time) > 5 * 60 * 1000;
        return liftoff_time != 0 && timeExceedsFiveMinutes;
    }

}