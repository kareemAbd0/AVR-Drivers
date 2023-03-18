#ifndef DIO_H

#define DIO_H



#define IN 0
#define OUT 1

#define LOW 0
#define HIGH 1

#define DIO_u8FLOAT		0
#define DIO_u8PULL_UP	1




void DIO_init (uint8_t port_number, uint8_t pin_number , uint8_t direction);
void  DIO_write (uint8_t port_number, uint8_t pin_number , uint8_t value);

void DIO_toggle(uint8_t port_number, uint8_t pin_number);

void DIO_read (uint8_t port_number, uint8_t pin_number , uint8_t *value);




#endif