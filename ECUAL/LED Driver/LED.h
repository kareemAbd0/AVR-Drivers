#ifndef LED_H
#define LED_H
#include"../../MCAL/type.h"
#include"../../MCAL/DIO Driver/DIO.h"


void LED_innit(uint8_t port_number,uint8_t pin_number);
void LED_on (uint8_t port_number,uint8_t pin_number);
void LED_off (uint8_t port_number,uint8_t pin_number);
void LED_toggle (uint8_t port_number,uint8_t pin_number);



#endif