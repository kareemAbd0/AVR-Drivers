#include"LED.h"



void LED_innit(uint8_t port_number,uint8_t pin_number)
{

    DIO_init(port_number,pin_number,OUT);

}


void LED_on (uint8_t port_number,uint8_t pin_number)
{

    DIO_write(port_number,pin_number,HIGH);

}

void LED_off (uint8_t port_number,uint8_t pin_number)
{

    DIO_write(port_number,pin_number,LOW);


}

void LED_toggle (uint8_t port_number,uint8_t pin_number)
{

    DIO_toggle(port_number,pin_number);

}





