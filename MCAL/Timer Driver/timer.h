

#ifndef TIMER_H
#define TIMER_H

#include "../type.h"
#define F_CPU 1000000U
#include "../registers.h"
#include "math.h"

void timer_delay_ms(int delay);

#endif