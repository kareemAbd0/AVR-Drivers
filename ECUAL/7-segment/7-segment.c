//
// Created by kareem on 12/14/22.
//

#include "7-segment.h"

void Seven_Seg_Cathode_Innit(uint8_t port_pin_0_to_6)
{
    DIO_init(port_pin_0_to_6,0,OUT);
    DIO_init(port_pin_0_to_6,1,OUT);
    DIO_init(port_pin_0_to_6,2,OUT);
    DIO_init(port_pin_0_to_6,3,OUT);
    DIO_init(port_pin_0_to_6,4,OUT);
    DIO_init(port_pin_0_to_6,5,OUT);
    DIO_init(port_pin_0_to_6,6,OUT);

}
void Seven_Seg_Cathode_Display_Num(uint8_t num,uint8_t port_pin_0_to_6)
{

    switch (num)
    {
        case 0:
            DIO_write(port_pin_0_to_6,0,HIGH);
            DIO_write(port_pin_0_to_6,1,HIGH);
            DIO_write(port_pin_0_to_6,2,HIGH);
            DIO_write(port_pin_0_to_6,3,HIGH);
            DIO_write(port_pin_0_to_6,4,HIGH);
            DIO_write(port_pin_0_to_6,5,HIGH);
            DIO_write(port_pin_0_to_6,6,LOW);
            break;
        case 1:

            DIO_write(port_pin_0_to_6,0,LOW);
            DIO_write(port_pin_0_to_6,1,HIGH);
            DIO_write(port_pin_0_to_6,2,HIGH);
            DIO_write(port_pin_0_to_6,3,LOW);
            DIO_write(port_pin_0_to_6,4,LOW);
            DIO_write(port_pin_0_to_6,5,LOW);
            DIO_write(port_pin_0_to_6,6,LOW);
            break;

        case 2:
            DIO_write(port_pin_0_to_6,0,HIGH);
            DIO_write(port_pin_0_to_6,1,HIGH);
            DIO_write(port_pin_0_to_6,2,LOW);
            DIO_write(port_pin_0_to_6,3,HIGH);
            DIO_write(port_pin_0_to_6,4,HIGH);
            DIO_write(port_pin_0_to_6,5,LOW);
            DIO_write(port_pin_0_to_6,6,HIGH);
            break;
        case 3:
            DIO_write(port_pin_0_to_6,0,HIGH);
            DIO_write(port_pin_0_to_6,1,HIGH);
            DIO_write(port_pin_0_to_6,2,HIGH);
            DIO_write(port_pin_0_to_6,3,HIGH);
            DIO_write(port_pin_0_to_6,4,LOW);
            DIO_write(port_pin_0_to_6,5,LOW);
            DIO_write(port_pin_0_to_6,6,HIGH);
            break;
        case 4:
            DIO_write(port_pin_0_to_6,0,LOW);
            DIO_write(port_pin_0_to_6,1,HIGH);
            DIO_write(port_pin_0_to_6,2,HIGH);
            DIO_write(port_pin_0_to_6,3,LOW);
            DIO_write(port_pin_0_to_6,4,LOW);
            DIO_write(port_pin_0_to_6,5,HIGH);
            DIO_write(port_pin_0_to_6,6,HIGH);
            break;
        case 5:
            DIO_write(port_pin_0_to_6,0,HIGH);
            DIO_write(port_pin_0_to_6,1,LOW);
            DIO_write(port_pin_0_to_6,2,HIGH);
            DIO_write(port_pin_0_to_6,3,HIGH);
            DIO_write(port_pin_0_to_6,4,LOW);
            DIO_write(port_pin_0_to_6,5,HIGH);
            DIO_write(port_pin_0_to_6,6,HIGH);
            break;
        case 6:
            DIO_write(port_pin_0_to_6,0,HIGH);
            DIO_write(port_pin_0_to_6,1,LOW);
            DIO_write(port_pin_0_to_6,2,HIGH);
            DIO_write(port_pin_0_to_6,3,HIGH);
            DIO_write(port_pin_0_to_6,4,HIGH);
            DIO_write(port_pin_0_to_6,5,HIGH);
            DIO_write(port_pin_0_to_6,6,HIGH);
            break;
        case 7:
            DIO_write(port_pin_0_to_6,0,HIGH);
            DIO_write(port_pin_0_to_6,1,HIGH);
            DIO_write(port_pin_0_to_6,2,HIGH);
            DIO_write(port_pin_0_to_6,3,LOW);
            DIO_write(port_pin_0_to_6,4,LOW);
            DIO_write(port_pin_0_to_6,5,LOW);
            DIO_write(port_pin_0_to_6,6,LOW);
            break;
        case 8:
            DIO_write(port_pin_0_to_6,0,HIGH);
            DIO_write(port_pin_0_to_6,1,HIGH);
            DIO_write(port_pin_0_to_6,2,HIGH);
            DIO_write(port_pin_0_to_6,3,HIGH);
            DIO_write(port_pin_0_to_6,4,HIGH);
            DIO_write(port_pin_0_to_6,5,HIGH);
            DIO_write(port_pin_0_to_6,6,HIGH);
            break;
        case 9:
            DIO_write(port_pin_0_to_6,0,HIGH);
            DIO_write(port_pin_0_to_6,1,HIGH);
            DIO_write(port_pin_0_to_6,2,HIGH);
            DIO_write(port_pin_0_to_6,3,HIGH);
            DIO_write(port_pin_0_to_6,4,LOW);
            DIO_write(port_pin_0_to_6,5,HIGH);
            DIO_write(port_pin_0_to_6,6,HIGH);
            break;
            
    }

}

