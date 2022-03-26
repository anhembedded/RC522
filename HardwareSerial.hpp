/*
  HardwareSerial.h - Hardware serial library for Wiring
  Copyright (c) 2006 Nicholas Zambetti.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

  Modified 28 September 2010 by Mark Sproul
  Modified 14 August 2012 by Alarus
  Modified 3 December 2013 by Matthijs Kooijman
  Modified 25 March 2022 by Anh.Embedded/   Anh.embedded@gmail.com
*/

#ifndef HardwareSerial_h
#define HardwareSerial_h

#include <inttypes.h>
#include "Print.hpp"




class HardwareSerial : public Print {

  public:
      //todo: write another Constructor
  
    virtual void begin(unsigned long baud) = 0;
    virtual void end() = 0;
    virtual int available(void) = 0;
    virtual int peek(void) = 0;
    virtual int read(void) = 0;
    virtual int availableForWrite(void) = 0;
    virtual void flush(void) = 0;
    virtual size_t write(uint8_t) = 0;
    inline size_t write(unsigned long n)
    {
        return write(static_cast<uint8_t>(n));
    }
    inline size_t write(long n)
    {
      return write((uint8_t)n);
    }
    inline size_t write(unsigned int n)
    {
      return write((uint8_t)n);
    }
    inline size_t write(int n)
    {
      return write((uint8_t)n);
    }

  // size_t write(const uint8_t *buffer, size_t size);
    using Print::write; // pull in write(str) from Print
    operator bool()
    {
      return true;
    }

    // Enable half-duplex mode by setting the Rx pin to NC
    // This needs to be done before the call to begin()
    /*virtual void setHalfDuplex(void);
    virtual bool isHalfDuplex(void) const;
    virtual void enableHalfDuplexRx(void);*/
    // TOdo: write another Declare // Interrupt handlers
   /* virtual void _rx_complete_irq();
    virtual int _tx_complete_irq();*/

    
};


#endif
