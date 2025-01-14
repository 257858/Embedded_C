#include <avr/io.h>
#include<util/delay.h>
/** \brief init3(): initializing all ports for pwm
 * \return void
 *
 */
void init3()
{
    TCCR1A|=(1<<COM1A1)|(1<<WGM11)|(1<<WGM10);
    TCCR1B|=(1<<WGM12)|(1<<CS11);
    DDRB|=(1<<PB1);
}
/** \brief pwm(uint16_t temp): based on ADC values temperatures are displayed by pwm
 * \return void
 *
 */ 
char pwm(uint16_t temp)
{       char deg='0';
        if(temp<200)
        {
            OCR1A=205;//20% duty cycle
            deg='20';
            _delay_ms(20);
        }
        else if(temp<500)
        {
            OCR1A=409;//40% duty cycle
            deg='25';
            _delay_ms(20);
        }
        else if(temp<700)
        {
            OCR1A=717;//70% duty cycle
            deg='29';
            _delay_ms(20);
        }
        else if(temp<=1024)
        {
            OCR1A=973;//95% duty cycle
            deg='33';
            _delay_ms(33);
        }
        return deg;
}
