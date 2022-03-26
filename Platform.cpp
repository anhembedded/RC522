//
// Created by pcx on 3/23/2022.
//

#include "Platform.hpp"
#include "HardwareSerial.hpp"

// HARDWARE SERIAL




PF_GPIO_T PF_GPIO_T::operator=(const PF_GPIO_T &var) {

    PF_GPIO_T temp{};
    temp.pin = var.pin;
    temp.port = var.port;
            return temp;
}

bool PF_GPIO_T::operator==(const PF_GPIO_T &var)
{
    if ((this->pin == var.pin) && (this->port == var.port))
    {
        return true;
    } else
    {
        return false;
    }
}

bool PF_GPIO_T::operator!=(const PF_GPIO_T &var) {
    if ((this->pin == var.pin) || (this->port == var.port))
    {
        return true;
    }else
    {
        return false;
    }
}



 