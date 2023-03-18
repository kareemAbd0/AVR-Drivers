//
// Created by kareem on 3/17/23.
//
#include "../type.h"
#include "../bits.h"
#include "../DIO Driver/DIO.h"
#include "ADC_config.h"
#include"ADC_priv.h"
#include "ADC.h"


void ADC_init(uint8_t channel)
{


    //set voltage reference
    if(ADC_VREF_TYPE == ADC_VREF_AVCC)
    {
        set_bit(ADMUX,REFS0);
        clear_bit(ADMUX,REFS1);
    }
    else if(ADC_VREF_TYPE == ADC_VREF_AREF)
    {
        clear_bit(ADMUX,REFS0);
        clear_bit(ADMUX,REFS1);
    }
    else if(ADC_VREF_TYPE == ADC_VREF_INTERNAL)
    {
        set_bit(ADMUX,REFS0);
        set_bit(ADMUX,REFS1);
    }

    //set adjustment
    if(ADJUSMENT == RIGHT_ADJUSMENT)
    {
        clear_bit(ADMUX,ADLAR);
    }
    else if(ADJUSMENT == LEFT_ADJUSMENT)
    {
        set_bit(ADMUX,ADLAR);
    }

    //set prescaler to 8
    set_bit(ADCSRA,ADPS0);
    set_bit(ADCSRA,ADPS1);
    clear_bit(ADCSRA,ADPS2);

    //select channel
    change_channel(channel);

    //set auto trigger to free running mode (configurability yet implemented)
    clear_bit(SFIOR,ADTS0);
    clear_bit(SFIOR,ADTS1);
    clear_bit(SFIOR,ADTS2);


    //enable ADC
    set_bit(ADCSRA,ADEN);



}

uint16_t ADC_read(uint8_t channel)
{


    change_channel(channel);
    set_bit(ADCSRA,ADSC);

    // start conversion
    //wait for conversion to finish
    while(get_bit(ADCSRA,ADIF ) == 0);

    //return result
    return ADC;
}

void change_channel(uint8_t channel)
{
    //select channel
    if(channel == ADC_CHANNEL0)
    {
        clear_bit(ADMUX,MUX0);
        clear_bit(ADMUX,MUX1);
        clear_bit(ADMUX,MUX2);
        clear_bit(ADMUX,MUX3);
        clear_bit(ADMUX,MUX4);
    } else if(channel == ADC_CHANNEL1)
    {
        set_bit(ADMUX,MUX0);
        clear_bit(ADMUX,MUX1);
        clear_bit(ADMUX,MUX2);
        clear_bit(ADMUX,MUX3);
        clear_bit(ADMUX,MUX4);
    } else if(channel == ADC_CHANNEL2)
    {
        clear_bit(ADMUX,MUX0);
        set_bit(ADMUX,MUX1);
        clear_bit(ADMUX,MUX2);
        clear_bit(ADMUX,MUX3);
        clear_bit(ADMUX,MUX4);
    } else if(channel == ADC_CHANNEL3)
    {
        set_bit(ADMUX,MUX0);
        set_bit(ADMUX,MUX1);
        clear_bit(ADMUX,MUX2);
        clear_bit(ADMUX,MUX3);
        clear_bit(ADMUX,MUX4);
    } else if(channel == ADC_CHANNEL4)
    {
        clear_bit(ADMUX,MUX0);
        clear_bit(ADMUX,MUX1);
        set_bit(ADMUX,MUX2);
        clear_bit(ADMUX,MUX3);
        clear_bit(ADMUX,MUX4);
    } else if(channel == ADC_CHANNEL5)
    {
        set_bit(ADMUX,MUX0);
        clear_bit(ADMUX,MUX1);
        set_bit(ADMUX,MUX2);
        clear_bit(ADMUX,MUX3);
        clear_bit(ADMUX,MUX4);
    } else if(channel == ADC_CHANNEL6)
    {
        clear_bit(ADMUX,MUX0);
        set_bit(ADMUX,MUX1);
        set_bit(ADMUX,MUX2);
        clear_bit(ADMUX,MUX3);
        clear_bit(ADMUX,MUX4);
    } else if(channel == ADC_CHANNEL7)
    {
        set_bit(ADMUX,MUX0);
        set_bit(ADMUX,MUX1);
        set_bit(ADMUX,MUX2);
        clear_bit(ADMUX,MUX3);
        clear_bit(ADMUX,MUX4);

    }

}
