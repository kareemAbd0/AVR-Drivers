#include "../type.h"
#include "../DIO Driver/DIO.h"
#include "interrupt.h"
#include "interrupt_config.h"
#include "interrupt_priv.h"




void (*fp)(void) = NULL ;

void set_interrupt_callback(void (*func_ptr))
{

   fp = func_ptr;

}




void interrupt_init(interrupt * interrupt_object )
{
    //enable global interrupts
    SREG |= (1 << SREG_ENABLE);



    // choose interrupt sense (logic) choice controlled by 2 registers
    interrupt_sense(interrupt_object);

     //enable external interrupt

    if (interrupt_object->status == ENABLED) {
        interrupt_enable(interrupt_object);

    } else if (interrupt_object->status == DISABLED)
    {

        interrupt_disable(interrupt_object);

    }

}




void interrupt_enable(interrupt * interrupt_object)
{
//enable external inturrupt

  GICR |= (1<<interrupt_object->interrupt_number);

}



void interrupt_disable(interrupt * interrupt_object)
{
//enable external inturrupt

    GICR &= ~(1<<interrupt_object->interrupt_number);

}


void interrupt_sense(interrupt * interrupt_object)
{

    if(interrupt_object->interrupt_number == INT0) {

        if (interrupt_object->sense_control == RISING) {

            MCUCR |= (1 << ISC00);
            MCUCR |= (1 << ISC01);
        } else if (interrupt_object->sense_control == FALLING) {
            MCUCR &= ~(1 << ISC00);
            MCUCR |= (1 << ISC01);
        } else if (interrupt_object->sense_control == ANY) {
            MCUCR |= (1 << ISC00);
            MCUCR &= ~(1 << ISC01);
        }
    }else if(interrupt_object->interrupt_number == INT1) {

        if (interrupt_object->sense_control == RISING) {
            MCUCR |= (1 << ISC10);
            MCUCR |= (1 << ISC11);
        } else if (interrupt_object->sense_control == FALLING) {
            MCUCR &= ~(1 << ISC10);
            MCUCR |= (1 << ISC11);
        } else if (interrupt_object->sense_control == ANY) {
            MCUCR |= (1 << ISC10);
            MCUCR &= ~(1 << ISC11);
        }
    } else if(interrupt_object ->interrupt_number == INT2)
    {

        if (interrupt_object->sense_control == RISING)
        {
            MCUCSR |= (1 << ISC2);
        } else if (interrupt_object->sense_control == FALLING)
        {

            MCUCSR &= ~(1 << ISC2);
        }

    }

}

void __vector_1(void)
{
   if(fp != NULL)
   {
       (*fp)();

   }

}



void __vector_2(void)
{
    if(fp != NULL)
    {
        (*fp)();

    }

}


void __vector_3(void)
{
    if(fp != NULL)
    {
        (*fp)();

    }

}











