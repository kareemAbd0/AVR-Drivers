//
// Created by kareem on 2/22/23.
//

#ifndef CLIONAVRTEST_KEYPAD_CONFIG_H
#define CLIONAVRTEST_KEYPAD_CONFIG_H

#define C1_PORT    'C'
#define C1_PIN      0
#define C2_PORT    'C'
#define C2_PIN      1
#define C3_PORT    'C'
#define C3_PIN      2
#define C4_PORT    'C'
#define C4_PIN      3

#define R1_PORT    'C'
#define R1_PIN      4
#define R2_PORT    'C'
#define R2_PIN      5
#define R3_PORT    'C'
#define R3_PIN      6
#define R4_PORT    'C'
#define R4_PIN      7

#define COLOMS_NUMBER 4

#define ROWS_NUMBER 4

uint8_t key_values[ROWS_NUMBER][COLOMS_NUMBER] = {{'7', '8', '9', '/'},
									{'4', '5', '6', 'X'},
									{'1', '2', '3', '-'},
									{'c', '0', '=', '+'}};






#endif //CLIONAVRTEST_KEYPAD_CONFIG_H
