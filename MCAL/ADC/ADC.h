//
// Created by kareem on 3/17/23.
//

#ifndef CLIONAVRTEST_ADC_H
#define CLIONAVRTEST_ADC_H


void ADC_init(uint8_t channel);


uint16_t ADC_read(uint8_t channel);

void change_channel(uint8_t channel);


#endif //CLIONAVRTEST_ADC_H
