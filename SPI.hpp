/*
 * Copyright (c) 2010 by Cristian Maglie <c.maglie@arduino.cc>
 * Copyright (c) 2014 by Paul Stoffregen <paul@pjrc.com> (Transaction API)
 * SPI Master library for arduino.
 *
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of either the GNU General Public License version 2
 * or the GNU Lesser General Public License version 2.1, both as
 * published by the Free Software Foundation.
 */

#ifndef _SPI_H_INCLUDED
#define _SPI_H_INCLUDED

#include "Arduino.hpp"
#include "Platform.hpp"
#include <stdio.h>


// SPI_HAS_TRANSACTION means SPI has
//   - beginTransaction()
//   - endTransaction()
//   - usingInterrupt()
//   - SPISetting(clock, bitOrder, dataMode)
#define SPI_HAS_TRANSACTION 1

// Compatibility with sketches designed for AVR @ 16 MHz could not
// be ensured as SPI frequency depends of system clock configuration.
// user have to use appropriate divider for the SPI clock
// This function should not be used in new project.
// Use SPISettings with SPI.beginTransaction() to configure SPI parameters.
#define SPI_CLOCK_DIV2   2
#define SPI_CLOCK_DIV4   4
#define SPI_CLOCK_DIV8   8
#define SPI_CLOCK_DIV16  16
#define SPI_CLOCK_DIV32  32
#define SPI_CLOCK_DIV64  64
#define SPI_CLOCK_DIV128 128

// SPI mode parameters for SPISettings
#define SPI_MODE0 0x00
#define SPI_MODE1 0x01
#define SPI_MODE2 0x02
#define SPI_MODE3 0x03

#define SPI_TRANSMITRECEIVE 0x0
#define SPI_TRANSMITONLY 0x1



class SPIClass 
{
public:
    /* Contains various spiSettings for the same spi instance. Each spi spiSettings
    is associated to a CS pin. */
    PF_GPIO_T ThiscsPin;
    virtual void RemovePin(PF_GPIO_T _pin)=0;
    virtual  void RemoveAllPin(void)=0;
    virtual void begin(PF_GPIO_T CSpin)=0;
    virtual void end(void) = 0;

    /* This function should be used to configure the SPI instance in case you
     * don't use default parameters.
     * You can attach another CS pin to the SPI instance and each CS pin can be
     * attach with specific SPI settings.
     */
    virtual void beginTransaction(PF_GPIO_T CSpin, uintmax_t settings) =0;

     void beginTransaction(uintmax_t settings)
    {
      beginTransaction(ThiscsPin, settings);
    }

    virtual void endTransaction(PF_GPIO_T pin) = 0;
    void endTransaction(void)
    {
      endTransaction(ThiscsPin);
    }

    /* Transfer functions: must be called after initialization of the SPI
     * instance with begin() or beginTransaction().
     * You can specify the CS pin to use.
     */
    virtual byte transfer(PF_GPIO_T csPin, uint8_t _data, uintmax_t SPITransferMode) = 0;
    virtual  uint16_t transfer16(PF_GPIO_T pin, uint16_t _data, uintmax_t SPITransferMode ) = 0;
    virtual void transfer(PF_GPIO_T pin, void *_buf, size_t _count, uintmax_t SPITransferMode) =0 ;
    virtual void transfer(PF_GPIO_T _pin, void *_bufout, void *_bufin, size_t _count, uintmax_t SPITransferMode) = 0;

    // Transfer functions when user controls himself the CS pin.
    byte transfer(uint8_t _data, uintmax_t SPITransferMode)
    {
      return transfer(ThiscsPin, _data, SPITransferMode);
    }

    uint16_t transfer16(uint16_t _data, uintmax_t SPITransferMode)
    {
      return transfer16(ThiscsPin, _data, SPITransferMode);
    }

    void transfer(void *_buf, size_t _count, uintmax_t SPITransferMode)
    {
      transfer(ThiscsPin, _buf, _count, SPITransferMode);
    }

    void transfer(void *_bufout, void *_bufin, size_t _count, uintmax_t SPITransferMode)
    {
      transfer(ThiscsPin, _bufout, _bufin, _count, SPITransferMode);
    }

    /* These methods are deprecated and kept for compatibility.
     * Use SPISettings with SPI.beginTransaction() to configure SPI parameters.
     */
    virtual void setBitOrder(PF_GPIO_T csPin, uintmax_t BitOrder) = 0;
    void setBitOrder(uintmax_t BitOrder)
    {
      setBitOrder(ThiscsPin, BitOrder);
    }

    virtual void setDataMode(PF_GPIO_T _pin, uint8_t Mode) = 0;
    void setDataMode(uint8_t _mode)
    {
      setDataMode(ThiscsPin, _mode);
    }

    virtual  void setClockDivider(PF_GPIO_T _pin, uint8_t Mode) = 0;
    void setClockDivider(uint8_t _div)
    {
      setClockDivider(ThiscsPin, _div);
    }

    // Not implemented functions. Kept for backward compatibility.
    void usingInterrupt(uint8_t interruptNumber);
    void attachInterrupt(void);
    void detachInterrupt(void);

 
};

#endif
