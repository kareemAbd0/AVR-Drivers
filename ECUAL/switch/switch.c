//
// Created by kareem on 2/12/23.
//

#include "switch.h"
er_state switch_innit (sw_t * copy_switches)
{
    er_state local_error_state = ER_GOOD;

    if(copy_switches != NULL)
    {
        for (int i = 0; i < SW_NUM ; ++i)
        {
            DIO_init(copy_switches[i].sw_port,copy_switches[i].sw_pin,IN);
            DIO_write(copy_switches[i].sw_port,copy_switches[i].sw_pin,copy_switches[i].sw_state);

        }
    }
    else
    {
        local_error_state = NULL_POINTER;
    }
    return local_error_state;
}


er_state switch_get_status (sw_t * copy_switches , uint8_t *pin_value)
{
    er_state local_error_state = ER_GOOD;

    if(copy_switches != NULL && pin_value != NULL)
    {

        DIO_read(copy_switches->sw_port,copy_switches->sw_pin,pin_value);

    } else
    {
        local_error_state = NULL_POINTER;
    }
    return local_error_state;


}
