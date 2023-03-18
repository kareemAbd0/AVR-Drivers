//
// Created by kareem on 3/17/23.
//

#ifndef CLIONAVRTEST_BITS_H
#define CLIONAVRTEST_BITS_H

#define set_bit(reg, bit) (reg |= (1 << bit))
#define clear_bit(reg, bit) (reg &= ~(1 << bit))
#define toggle_bit(reg, bit) (reg ^= (1 << bit))
#define get_bit(reg, bit) ((reg >> bit) & 1)



#endif //CLIONAVRTEST_BITS_H
