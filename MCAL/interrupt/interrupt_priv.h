//
// Created by kareem on 3/14/23.
//

#ifndef CLIONAVRTEST_INTERRUPT_PRIV_H
#define CLIONAVRTEST_INTERRUPT_PRIV_H

#define SREG_ENABLE 7

#define ISC00 0

#define ISC01 1
#define ISC10 2
#define ISC11 3
#define ISC2 6

//  interrupt registers
#define MCUCR *(( volatile uint8_t *) 0x55) //edge config
#define GICR  *(( volatile uint8_t *) 0x5B) // DIO inturrupt enable
#define MCUCSR *(( volatile uint8_t *) 0x54)
#define SREG  *(( volatile uint8_t *) 0x5F) //general inturrupt enable

void __vector_1(void) __attribute__((signal,used));
void __vector_2(void) __attribute__((signal,used));
void __vector_3(void) __attribute__((signal,used));
#endif //CLIONAVRTEST_INTERRUPT_PRIV_H
