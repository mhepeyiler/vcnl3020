#ifndef VCNL3020_INCLUDE_VCNL3020_H
#define VCNL3020_INCLUDE_VCNL3020_H

#ifdef __cplusplus
#include <cstddef>
#include <cstdint>
extern "C" {
#else
#include "stddef.h"
#include "stdint.h"
#include "stdbool.h"
#define bool _Bool
#endif

#define VCNL3020_DEVICE_ADDRESS 0x13

typedef struct VCNL3020
{
	int (*read8)(void*, uint8_t, uint8_t);
	int (*write8)(void*, uint8_t, uint8_t, uint8_t);
	void* i2cDev;
    int sanity;
    uint8_t deviceAddress;
    uint8_t productID;
    uint8_t revisionID;
} VCNL3020_t, *pVCNL3020_t;

typedef enum RateOfMeasurement {
    M1_95    = 0b0000000,
    M3_9     = 0b0000001,
    M7_8     = 0b0000010,
    M16_6    = 0b0000011,
    M31_2    = 0b0000100,
    M62_5    = 0b0000101,
    M125     = 0b0000110,
    M250     = 0b0000111
} RateOfMeasurement_t;

typedef enum IRLedCurrent {
    C1      = 0b0000000,
    C2      = 0b0000001,
    C4      = 0b0000010,
    C8      = 0b0000011,
    C16     = 0b0000100,
    C32     = 0b0000101,
    C64     = 0b0000110,
    C128    = 0b0000111    
} InterruptCount_t;

typedef enum  {
    mA0     = 0,
    mA10    = 1,
    mA20    = 2,
    mA30    = 3,
    mA40    = 4,
    mA50    = 5,
    mA60    = 6,
    mA70    = 7,
    mA80    = 8,
    mA90    = 9,
    mA100   = 10,
    mA110   = 11,
    mA120   = 12,
    mA130   = 13,
    mA140   = 14,
    mA150   = 15,
    mA160   = 16,
    mA170   = 17,
    mA180   = 18,
    mA190   = 19,
    mA200   = 20
} IRLedCurrent_t;


bool isDataReady(const pVCNL3020_t dev);
void startSingleMeasurement(const pVCNL3020_t dev);
void startPeriodicMeasurement(const pVCNL3020_t dev);
void setSelftimedStateMachine(const pVCNL3020_t dev);
uint8_t getProductID(const pVCNL3020_t dev);
uint8_t getRevisionID(const pVCNL3020_t dev);
void setRateOfProxityMeasurement(const pVCNL3020_t dev, RateOfMeasurement_t rate);
uint8_t getFuseProgID(const pVCNL3020_t dev);
void setIRLedCurrent(const pVCNL3020_t dev, IRLedCurrent_t current);
IRLedCurrent_t getIRLedCurrent(const pVCNL3020_t dev);
uint16_t getProxiResult(const pVCNL3020_t dev);
void setInterruptCount(const pVCNL3020_t dev, InterruptCount_t  intCount);
void setIntReady(const pVCNL3020_t dev, bool state);
void setIntExceed(const pVCNL3020_t dev, bool state);
void setIntSel(const pVCNL3020_t dev, bool state);
void setLowThreshold(const pVCNL3020_t dev, uint16_t threshold);
void setHighThreshold(const pVCNL3020_t dev, uint16_t threshold);

#ifdef __cplusplus
}
#endif


#endif //VCNL3020_INCLUDE_VCNL3020_H
