#ifndef __PLATFORM_HARDWARESPI_H__
#define __PLATFORM_HARDWARESPI_H__

#include "Platform.hpp"
#include "SPI.hpp"

class Platform_HardwareSPI : public SPIClass
{
public:
     void RemovePin(PF_GPIO_T _pin) override;
     void RemoveAllPin(void) override;
    void begin(PF_GPIO_T CSpin) override;
    void end(void) override;
    void beginTransaction(PF_GPIO_T CSpin, uintmax_t settings) override;
    void endTransaction(PF_GPIO_T pin) override;
    byte transfer(PF_GPIO_T csPin, uint8_t _data, uintmax_t SPITransferMode) override;
    uint16_t transfer16(PF_GPIO_T pin, uint16_t _data, uintmax_t SPITransferMode) override;
    void transfer(PF_GPIO_T pin, void *_buf, size_t _count, uintmax_t SPITransferMode) override;
    void transfer(PF_GPIO_T _pin, void *_bufout, void *_bufin, size_t _count, uintmax_t SPITransferMode) override;
    void setBitOrder(PF_GPIO_T csPin, uintmax_t BitOrder) override;
    void setDataMode(PF_GPIO_T _pin, uint8_t Mode) override;
    void setClockDivider(PF_GPIO_T _pin, uint8_t Mode) override;
    
};

extern Platform_HardwareSPI SPI;

#endif // __PLATFORM_HARDWARESPI_H__