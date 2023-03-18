//
// Created by kareem on 2/22/23.
//



#ifndef CLIONAVRTEST_LCD_H
#define CLIONAVRTEST_LCD_H

er_state LCD_init();
er_state LCD_send_command(uint8_t u8_command);
er_state LCD_display_char(uint8_t u8_data);

#endif //CLIONAVRTEST_LCD_H
