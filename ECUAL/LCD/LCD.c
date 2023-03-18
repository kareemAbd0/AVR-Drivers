//
// Created by kareem on 2/22/23.
//

#include "../../MCAL/err.h"
#include "../../MCAL/type.h"
#include "../../MCAL/DIO Driver/DIO.h"
#include "../../MCAL/Timer Driver/timer.h"
#include "LCD.h"
#include "LCD_config.h"
#include "LCD_priv.h"
er_state LCD_init()
{
    er_state local_error = ER_GOOD;
    DIO_init(RS_PORT,RS_PIN,OUT);
    DIO_init(RW_PORT,RW_PIN,OUT);
    DIO_init(EN_PORT,EN_PIN,OUT);

    DIO_init(D7_PORT,D7_PIN,OUT);
    DIO_init(D6_PORT,D6_PIN,OUT);
    DIO_init(D5_PORT,D5_PIN,OUT);
    DIO_init(D4_PORT,D4_PIN,OUT);
    timer_delay_ms(100);
#if LCD_MODE == EIGHT_BIT

    DIO_init(D3_PORT,D3_PIN,OUT);
    DIO_init(D2_PORT,D2_PIN,OUT);
    DIO_init(D1_PORT,D1_PIN,OUT);
    DIO_init(D0_PORT,D0_PIN,OUT);
    LCD_send_command(0x38);
#elif LCD_MODE == FOUR_BIT
      LCD_send_command(0x28);
#endif
    timer_delay_ms(1);
    LCD_send_command(0x0f);
    timer_delay_ms(1);
    LCD_send_command(0x01);
    timer_delay_ms(2);
    LCD_send_command(0x06);
    return local_error;
}

er_state LCD_send_command(uint8_t u8_command)
{
    er_state local_error = ER_GOOD;

    //temp

    DIO_write(RS_PORT,RS_PIN,LOW);
    LCD_latch(u8_command);
    return local_error;
}

er_state LCD_display_char(uint8_t u8_command)
{
    er_state local_error = ER_GOOD;
    DIO_write(RS_PORT,RS_PIN,HIGH);
    LCD_latch(u8_command);
    return local_error;
}
static void LCD_latch(uint8_t copy)
{
    DIO_write(RW_PORT,RW_PIN,LOW);
    DIO_write(EN_PORT,EN_PIN,LOW);

    DIO_write(D7_PORT,D7_PIN,((copy>>7)&1));
    DIO_write(D6_PORT,D6_PIN,((copy>>6)&1));
    DIO_write(D5_PORT,D5_PIN,((copy>>5)&1));
    DIO_write(D4_PORT,D4_PIN,((copy>>4)&1));
#if LCD_MODE == EIGHT_BIT

    DIO_write(D3_PORT,D3_PIN,((copy>>3)&1));
    DIO_write(D2_PORT,D2_PIN,((copy>>2)&1));
    DIO_write(D1_PORT,D1_PIN,((copy>>1)&1));
    DIO_write(D0_PORT,D0_PIN,((copy>>0)&1));
#elif LCD_MODE == FOUR_BIT
#endif

    //latch
    DIO_write(EN_PORT,EN_PIN,HIGH);
    timer_delay_ms(10);
    DIO_write(EN_PORT,EN_PIN,LOW);
}
