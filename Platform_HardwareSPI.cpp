#include "Platform_HardwareSPI.h"





void Platform_HardwareSPI::beginTransaction(PF_GPIO_T CSpin, uintmax_t settings) {

    std::cout << "END!!! " << std::endl;

}

void Platform_HardwareSPI::endTransaction(PF_GPIO_T pin) {
    std::cout << "END!!! " << std::endl;

}

byte Platform_HardwareSPI::transfer(PF_GPIO_T csPin, uint8_t _data, uintmax_t SPITransferMode) {
    std::cout << "END!!! " << std::endl;
    return 1;
}

uint16_t Platform_HardwareSPI::transfer16(PF_GPIO_T pin, uint16_t _data, uintmax_t SPITransferMode) {
    std::cout << "END!!! " << std::endl;
    return 1;
}

void Platform_HardwareSPI::transfer(PF_GPIO_T pin, void *_buf, size_t _count, uintmax_t SPITransferMode) {
    std::cout << "END!!! " << std::endl;

}

void
Platform_HardwareSPI::transfer(PF_GPIO_T _pin, void *_bufout, void *_bufin, size_t _count, uintmax_t SPITransferMode) {
    std::cout << "END!!! " << std::endl;

}

void Platform_HardwareSPI::setBitOrder(PF_GPIO_T csPin, uintmax_t BitOrder) {
    std::cout << "END!!! " << std::endl;

}

// todo: I'm not sure with that code
void Platform_HardwareSPI::setDataMode(PF_GPIO_T _pin, uint8_t Mode) {
    std::cout << "END!!! " << std::endl;

}
    

void Platform_HardwareSPI::setClockDivider(PF_GPIO_T _pin, uint8_t Mode) {
    std::cout << "END!!! " << std::endl;

}

void Platform_HardwareSPI::end(void) {
    std::cout << "END!!! " << std::endl;

}

void Platform_HardwareSPI::begin(PF_GPIO_T CSpin) {
    std::cout << "END!!! " << std::endl;
   
}

void Platform_HardwareSPI::RemovePin(PF_GPIO_T _pin) {
    std::cout << "END!!! " << std::endl;
}

void Platform_HardwareSPI::RemoveAllPin(void) {
    std::cout << "END!!! " << std::endl;
}


Platform_HardwareSPI SPI;