//
// Created by kareem on 2/22/23.
//

#include <stddef.h>
#include "../../MCAL/type.h"
#include "../../MCAL/err.h"
#include "../../MCAL/DIO Driver/DIO.h"
#include "../../MCAL/Timer Driver/timer.h"
#include "keypad.h"
#include "keypad_config.h"
#include "keypad_private.h"

er_state  key_pad_init()
{
    er_state local_error = ER_BAD;
    DIO_init(C1_PORT,C1_PIN,OUT);
    DIO_init(C2_PORT,C2_PIN,OUT);
    DIO_init(C3_PORT,C3_PIN,OUT);
    DIO_init(C4_PORT,C4_PIN,OUT);

    DIO_init(R1_PORT,R1_PIN,IN);
    DIO_init(R2_PORT,R2_PIN,IN);
    DIO_init(R3_PORT,R3_PIN,IN);
    DIO_init(R4_PORT,R4_PIN,IN);

    DIO_write(C1_PORT,C1_PIN,HIGH);
    DIO_write(C2_PORT,C2_PIN,HIGH);
    DIO_write(C3_PORT,C3_PIN,HIGH);
    DIO_write(C4_PORT,C4_PIN,HIGH);

    DIO_write(R1_PORT,R1_PIN,DIO_u8PULL_UP);
    DIO_write(R2_PORT,R2_PIN,DIO_u8PULL_UP);
    DIO_write(R3_PORT,R3_PIN,DIO_u8PULL_UP);
    DIO_write(R4_PORT,R4_PIN,DIO_u8PULL_UP);

    local_error =ER_GOOD;
    return local_error;

}

er_state key_pad_pressed_key(uint8_t *pressed_key)
{
    er_state local_error = ER_BAD;
    if(pressed_key != NULL)
    {
        uint8_t row_pins [ROWS_NUMBER] = { R1_PIN , R2_PIN , R3_PIN , R4_PIN };
        uint8_t col_pins [COLOMS_NUMBER] = { C1_PIN , C2_PIN , C3_PIN , C4_PIN };
        uint8_t row_ports[ROWS_NUMBER] = { R1_PORT , R2_PORT , R3_PORT , R4_PORT };
        uint8_t col_ports[COLOMS_NUMBER] = { C1_PORT , C2_PORT , C3_PORT , C4_PORT };
        uint8_t local_value = KEY_NOT_PRESSED;
        for (int i = 0; i < COLOMS_NUMBER ; i++)
        {
            DIO_write(col_ports[i],col_pins[i],LOW);
            for (int j = 0; j <ROWS_NUMBER ; j++)
            {
                DIO_read(row_ports[j],row_pins[j],&local_value);
                if(LOW == local_value)
                {

                    //indicator

                    do{

                        DIO_read(row_ports[j],row_pins[j],&local_value);

                    } while (LOW == local_value);

                    *pressed_key = key_values[j][i];
                    local_error = ER_GOOD;
                    return local_error;
                }
            }

            DIO_write(col_ports[i],col_pins[i], HIGH);
        }

    } else
    {
        local_error = NULL_POINTER;
        return local_error;
    }

    return local_error;

}
