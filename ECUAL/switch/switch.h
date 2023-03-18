//
// Created by kareem on 2/12/23.
//

#ifndef CLIONAVRTEST_SWITCH_H
#define CLIONAVRTEST_SWITCH_H
#include"../../MCAL/type.h"
#include"../../MCAL/DIO Driver/DIO.h"
#include "switch_config.h"
#include "../../MCAL/err.h"
#include <stddef.h>
#define SW_N 3


// pass the array of switches in the config file
er_state switch_innit (sw_t * copy_switches);

//pass one switch
er_state switch_get_status (sw_t * copy_switches , uint8_t *pin_value);




#endif //CLIONAVRTEST_SWITCH_H
