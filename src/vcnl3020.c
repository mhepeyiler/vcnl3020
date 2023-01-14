#include "vcnl3020.h"
#include "registers.h"

#define GET_BIT_FLAG(data, bit_number) ((data & (1 << bit_number)) != 0)

static void getRegister1Value(const pVCNL3020_t dev) {
    if (dev->productID != 0 && dev->revisionID != 0) {
        return;
    }
    uint8_t data = 0;
    data = dev->read8(dev->i2cDev, dev->deviceAddress, rIDRevision);
    dev->productID = (data & 0b11110000);
    dev->revisionID = (data & 0b00001111);
}

bool isDataReady(const pVCNL3020_t dev) {
    uint8_t data = 0;
    data = dev->read8(dev->i2cDev, dev->deviceAddress, rCommand);
    return GET_BIT_FLAG(data, 5);
}

void startSingleMeasurement(const pVCNL3020_t dev) {
    uint8_t data = 0;
    data = dev->read8(dev->i2cDev, dev->deviceAddress, rCommand);
    data |= 0b00001000;
    dev->write8(dev->i2cDev, dev->deviceAddress, rCommand, data);
}

void startPeriodicMeasurement(const pVCNL3020_t dev) {
    uint8_t data = 0;
    data = dev->read8(dev->i2cDev, dev->deviceAddress, rCommand);
    data |= 0b00000010;
    dev->write8(dev->i2cDev, dev->deviceAddress, rCommand, data);
}

void setSelftimedStateMachine(const pVCNL3020_t dev) {
    uint8_t data = 0;
    data = dev->read8(dev->i2cDev, dev->deviceAddress, rCommand);
    data |= 0b00000001;
    dev->write8(dev->i2cDev, dev->deviceAddress, rCommand, data);
}

uint8_t getProductID(const pVCNL3020_t dev) {
    getRegister1Value(dev);
    return dev->productID;
}

uint8_t getRevisionID(const pVCNL3020_t dev) {
    getRegister1Value(dev);
    return dev->revisionID;
}

void setRateOfProxityMeasurement(const pVCNL3020_t dev, RateOfMeasurement_t rate) { 
    dev->write8(dev->i2cDev, dev->deviceAddress, rRateProximityMeasurement, rate);
}

uint8_t getFuseProgID(const pVCNL3020_t dev) {
	return 0;
}

void setIRLedCurrent(const pVCNL3020_t dev, IRLedCurrent_t current) {
    dev->write8(dev->i2cDev, dev->deviceAddress, rLEDCurrentSettingProxMode, current);
}

IRLedCurrent_t getIRLedCurrent(const pVCNL3020_t dev) {
    uint8_t data = 0;
    data = dev->read8(dev->i2cDev, dev->deviceAddress, rLEDCurrentSettingProxMode);
    return data;
}

uint16_t getProxiResult(const pVCNL3020_t dev) {
	// TODO double check!!
    uint8_t data[2] = {0, 0};
    data[0] = dev->read8(dev->i2cDev, dev->deviceAddress, rProxMeasurementResult1);
    data[1] = dev->read8(dev->i2cDev, dev->deviceAddress, rProxMeasurementResult2);
    return (data[1] << 8 | data[0]);
}

void setInterruptCount(const pVCNL3020_t dev, InterruptCount_t  intCount) {

}

void setIntReady(const pVCNL3020_t dev, bool state) {

}

void setIntExceed(const pVCNL3020_t dev, bool state) {

}

void setIntSel(const pVCNL3020_t dev, bool state) {

}

void setLowThreshold(const pVCNL3020_t dev, uint16_t threshold) {
	// TODO double check!!
    uint8_t data[2] = {threshold | 0xFF, threshold >> 8};
    dev->write8(dev->i2cDev, dev->deviceAddress, rLowThreshold1, data[0]);
    dev->write8(dev->i2cDev, dev->deviceAddress, rLowThreshold2, data[1]);
}

void setHighThreshold(const pVCNL3020_t dev, uint16_t threshold) {
	// TODO double check!!
    uint8_t data[2] = {threshold | 0xFF, threshold >> 8};
    dev->write8(dev->i2cDev, dev->deviceAddress, rHighThreshold1, data[0]);
    dev->write8(dev->i2cDev, dev->deviceAddress, rHighThreshold2, data[1]);
}
