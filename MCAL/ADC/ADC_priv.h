//
// Created by kareem on 3/17/23.
//

#ifndef CLIONAVRTEST_ADC_PRIV_H
#define CLIONAVRTEST_ADC_PRIV_H




#define ADMUX  *((volatile uint8_t*) 0x27) // ADC Multiplexer Selection Register
#define ADCSRA *((volatile uint8_t*) 0x26) // ADC Control and Status Register A
#define ADC   *((volatile uint16_t*) 0x24) // ADC Data Register  (includes ADCH and ADCL)
#define ADCH  *((volatile uint8_t*) 0x25) // ADC Data Register High
#define SFIOR  *((volatile uint8_t*) 0x50) // Special Function IO Register


// ADMUX
#define REFS0  6
#define REFS1  7
#define ADLAR  5
#define MUX0   0
#define MUX1   1
#define MUX2   2
#define MUX3   3
#define MUX4   4

// ADCSRA
#define ADEN   7
#define ADSC   6
#define ADATE  5
#define ADIF   4
#define ADIE   3
#define ADPS0  0
#define ADPS1  1
#define ADPS2  2
// SFIOR
#define ADTS0  5
#define ADTS1  6
#define ADTS2  7



#endif //CLIONAVRTEST_ADC_PRIV_H
