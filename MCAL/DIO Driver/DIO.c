
#include "../type.h"
#include"../registers.h"
#include "../err.h"

#include "DIO.h"
void DIO_init (uint8_t port_number, uint8_t pin_number , uint8_t direction)
{

  //intialize pin direction

  switch (port_number)
  {
  case 'A':
    
    if (direction == IN)
    {
        DDRA &= ~( 1<< pin_number);

    }
    
   else if (direction == OUT)
   {
      DDRA |= (1<<pin_number);    

   }
    else
   {
    //error handling
   }   
  
    break;

  case 'B':

    if (direction == IN)
    {
        DDRB &= ~( 1<< pin_number);

    }
    
   else if (direction == OUT)
   {
      DDRB |= (1<<pin_number);    

   }
   else
   {
    //error handling
   }   
    break;

  case 'C':

    if (direction == IN)
    {
        DDRC &= ~( 1<< pin_number);

    }
    
   else if (direction == OUT)
   {
      DDRC |= (1<<pin_number);    

   
   }    
   else
   {
    //error handling
   }   
   
    break;   


   case 'D':

    if (direction == IN)
    {
        DDRD &= ~( 1<< pin_number);

    }
    
   else if (direction == OUT)
   {
      DDRD |= (1<<pin_number);    

   }    
  else
   {
    //error handling
   }   
   break;

  }

}



void DIO_write (uint8_t port_number, uint8_t pin_number , uint8_t value)
{

 switch (port_number)
  {
  case 'A':
    
    if (value == LOW)
    {
        PORTA &= ~( 1<< pin_number);

    }
    
   else if (value == HIGH)
   {
      PORTA|= (1<<pin_number);    

   }
    else
   {
    //error handling
   }   
  
    break;

  case 'B':

    if (value == LOW)
    {
        PORTB &= ~( 1<< pin_number);

    }
    
   else if (value == HIGH)
   {
      PORTB |= (1<<pin_number);    

   }
   else
   {
    //error handling
   }   
    break;

  case 'C':

    if (value == LOW)
    {
        PORTC &= ~( 1<< pin_number);

    }
    
   else if (value == HIGH)
   {
      PORTC |= (1<<pin_number);    

   }    
   else
   {
    //error handling
   }   
   break;
   case 'D':

    if ( value == LOW)
    {
        PORTD &= ~( 1<< pin_number);

    }
    
   else if (value == HIGH)
   {
      PORTD |= (1<<pin_number);

   }   
 else
   {
    //error handling
   }   
    break;
  }


}

void DIO_toggle(uint8_t port_number, uint8_t pin_number)
{

   switch (port_number)
   {
   case 'A':
     PORTA ^= 1 << pin_number;

    break;

     case 'B':
     PORTB ^= 1 << pin_number;
      break;
    
     case 'C':
     PORTC ^= 1 << pin_number;
      break;


     case 'D':
     PORTD ^= 1 << pin_number;
    break;
   
   default:
    break;
   }


}

void DIO_read (uint8_t port_number, uint8_t pin_number , uint8_t *value)
{


switch (port_number)
{
case 'A':

  if (((PINA&(1<<pin_number))>>pin_number) == HIGH)
  {
    *value = HIGH;
  }
  else if (((PINA&(1<<pin_number))>>pin_number) == LOW)
  {
    *value = LOW;
  }

  break;

  case 'B':

  if (((PINB&(1<<pin_number))>>pin_number) == HIGH)
  {
    *value = HIGH;
  }
  else if (((PINB&(1<<pin_number))>>pin_number) == LOW)
  {
    *value = LOW;
  }
  else
  {
    //error handling
  }

  break;

  case 'C':

  if (((PINC&(1<<pin_number))>>pin_number) == HIGH)
  {
    *value = HIGH;
  }
  else if (((PINC&(1<<pin_number))>>pin_number) == LOW)
  {
    *value = LOW;
  }
   else
  {
    //error handling
  }


  break;

  case 'D':

  if (((PIND&(1<<pin_number))>>pin_number) == HIGH)
  {
    *value = HIGH;
  }
  else if (((PIND&(1<<pin_number))>>pin_number) == LOW)
  {
    *value = LOW;
  }
   else
  {
    //error handling
  }


  break;




default:
  break;
}




  
}