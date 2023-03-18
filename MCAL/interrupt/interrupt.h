

#ifndef INTERRUPT_H

#define INTERRUPT_H





#define INT0 6
#define INT1 7
#define INT2 5


enum sense {RISING,FALLING,ANY};
enum stat{ENABLED,DISABLED};

typedef struct interrupt
{

    int interrupt_number;
    enum sense sense_control;
    enum stat status;

}interrupt;

void set_interrupt_callback(void (*func_ptr));
void interrupt_init( interrupt *);
void interrupt_enable(interrupt *);

void interrupt_disable(interrupt *);
void interrupt_sense(interrupt *);






#endif

