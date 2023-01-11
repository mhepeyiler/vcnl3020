#ifndef VCNL3020_INCLUDE_REGISTERS_H
#define VCNL3020_INCLUDE_REGISTERS_H

#ifdef __cplusplus
#include <cstdint>
extern "C" {
#else 
#include "stdint.h"
#endif

enum Registers {

    /**
     * @brief Register #1 Product ID Revision Register
     */
    rCommand                    = (uint8_t)0x80,

    /**
     * @brief Register #2 Rate of Proximity Measurement
     */
    rIDRevision                 = (uint8_t)0x81,
    
    /**
     * @brief Register #3 LED Current Setting for Proximity Mode
     */
    rRateProximityMeasurement   = (uint8_t)0x82,
    
    /**
     * @brief Register #7 Proximity Measurement Result Register
     */
    rLEDCurrentSettingProxMode  = (uint8_t)0x83,
    
    /**
     * @brief Register #8 Proximity Measurement Result Register
     */
    rProxMeasurementResult1     = (uint8_t)0x87,
    
    /**
     * @brief Register #9 Interrupt Control Register
     */
    rProxMeasurementResult2     = (uint8_t)0x88,
    
    /**
     * @brief Register #10 Low Threshold
     */
    rInterruptControl           = (uint8_t)0x89,
    
    /**
     * @brief Register #11 Low Threshold
     */
    rLowThreshold1              = (uint8_t)0x8A,
    
    /**
     * @brief Register #12 High Threshold
     */
    rHighThreshold2             = (uint8_t)0x8C,
    
    /**
     * @brief Register #13 High Threshold
     */
    rHighThreshold2             = (uint8_t)0x8D,
    
    /**
     * @brief Register #14 Interrupt Status Register
     */
    rInterruptStatus            = (uint8_t)0x8E,
    
    /**
     * @brief Register #15 Proximity Modulator Timing Adjustment
     */
    rProxModulatorTimingAdj     = (uint8_t)0x8F,
}


#ifdef __cplusplus
}
#endif


#endif //VCNL3020_INCLUDE_REGISTERS_H
