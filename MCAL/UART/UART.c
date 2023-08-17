//
// Created by kareem on 7/10/23.
//

#include "../type.h"
#include "../DIO Driver/DIO.h"
#include "../bits.h"
#include"../err.h"
#include "UART.h"
#include "UART_config.h"
#include "UART_priv.h"
#define UBR(baud) ((freq / (16 * BAUDRATE)) -1)
er_state USART_init() //8N1
{

     uint16_t UBRR_16bit = (uint16_t)UBR(BAUDRATE);

    er_state state = ER_BAD;

    if(UBRR_16bit > 4500)
    {
        state = OUT_OF_RANGE;
    }
    else {
        state = ER_GOOD;

/* Set baud rate */
         //select UBRRH
         UBRRL =  UBRR_16bit;
        UBRRH = (uint8_t) (UBRR_16bit >> 8);
/* Enable receiver and transmitter */
        UCSRB = (1 << RXEN) | (1 << TXEN);

        uint8_t local_UCSRC1 = 0;
        uint8_t local_UCSRC2 = 0;
        uint8_t local_UCSRC3 = 0;

        //write on UCSRC
        set_bit(UCSRC,URSEL);
#if STOP_BITS == ONE_STOP_BIT
        local_UCSRC1= (1 << URSEL) | (0 << USBS) ; //bug here 2 wont work
#elif STOP_BITS == TWO_STOP_BITS
        local_UCSRC1 = (1 << URSEL) | (0 << USBS) | (3 << UCSZ0) ;
#endif


#if PARITY_BITS == NO_PARITY_BITS
        local_UCSRC2 = (1 << URSEL) | (0 << UPM1) | (0 << UPM0)  ;
#elif PARITY_BITS == EVEN_PARITY
        local_UCSRC2 = (1 << URSEL) | (1 << UPM1) | (0 << UPM0) ;
#elif PARITY_BITS == ODD_PARITY
        local_UCSRC2 = (1 << URSEL) | (1 << UPM1) | (1 << UPM0) ;
#endif

#if DATA_BITS == FIVE_BITS
        local_UCSRC3 = (1 << URSEL) | (0 << UCSZ2) | (0 << UCSZ1) | (0 << UCSZ0) ;
#elif DATA_BITS == SIX_BITS
        local_UCSRC3 = (1 << URSEL) | (0 << UCSZ2) | (0 << UCSZ1) | (1 << UCSZ0) ;
#elif DATA_BITS == SEVEN_BITS
        local_UCSRC3 = (1 << URSEL) | (0 << UCSZ2) | (1 << UCSZ1) | (0 << UCSZ0) ;
#elif DATA_BITS == EIGHT_BITS
        local_UCSRC3 = (1 << URSEL) | (0 << UCSZ2) | (1 << UCSZ1) | (1 << UCSZ0) ;
#elif DATA_BITS == NINE_BITS
        local_UCSRC3 = (1 << URSEL) | (1 << UCSZ2) | (1 << UCSZ1) | (1 << UCSZ0) ;

#endif
UCSRC = local_UCSRC1 | local_UCSRC2 | local_UCSRC3;

    }
    return state;
}

er_state USART_transmit( uint8_t data ) //e i
{
    er_state state = ER_BAD;
    /* Wait for empty transmit buffer */
    while ( !(get_bit(UCSRA,UDRE)) );
    /* Put data into buffer, sends the data */

    UDR = data;
    state = ER_GOOD;
    return state;
}

er_state USART_transmit_9DateBit( uint16_t data )
{
    er_state state = ER_BAD;

    /* Wait for empty transmit buffer */
    while ( !(get_bit(UCSRA,UDRE)) );
    /* Copy 9th bit to TXB8 */
    clear_bit(UCSRB,TXB8);
    if ( data & 0x0100 )
    set_bit(UCSRB,TXB8);
    /* Put data into buffer, sends the data */
    UDR = data;
    state = ER_GOOD;
    return state;
}

er_state USART_receive( uint8_t * data )
{
    er_state state = ER_BAD;
    if(data == NULL)
    {
        state = NULL_POINTER;
    }
    else {
        /* Wait for data to be received */
        while ( !(get_bit(UCSRA,RXC)) );
        /* Get and return received data from buffer */
        *data = UDR;
        state = ER_GOOD;
   }
    return state;
}


er_state USART_flush( void )
{
    er_state state = ER_GOOD;
    unsigned char dummy;
    while ( get_bit(UCSRC,RXC) ) dummy = UDR;
    return state;
}


uint8_t USART_readUSCRC( void )
{
    uint8_t ucsrc;
/* Read UCSRC */
    ucsrc = UBRRH;
    ucsrc = UCSRC;
    return ucsrc;
}
