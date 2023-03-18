//
// Created by kareem on 2/12/23.
//

#ifndef CLIONAVRTEST_SWITCH_CONFIG_H
#define CLIONAVRTEST_SWITCH_CONFIG_H
#include "../../MCAL/type.h"
#include "../../MCAL/DIO Driver/DIO.h"
#include "../../MCAL/registers.h"
#define SW_NUM		3
typedef struct
{
    uint8_t sw_port;
    uint8_t sw_pin;
    uint8_t sw_state;

} sw_t;


#endif //CLIONAVRTEST_SWITCH_CONFIG_H
