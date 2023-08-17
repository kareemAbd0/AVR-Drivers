//
// Created by kareem on 7/10/23.
//

#ifndef CLIONAVRTEST_UART_H
#define CLIONAVRTEST_UART_H


er_state USART_init();
er_state USART_transmit( uint8_t data );
er_state USART_transmit_9DateBit( uint16_t data );
uint8_t USART_readUSCRC( void );
er_state USART_receive( uint8_t * data );
er_state USART_flush( void );



#endif //CLIONAVRTEST_UART_H
