

#define F_CPU 3333333UL
#include <xc.h>
#include <avr/interrupt.h>
# define led PIN0_bm
volatile int xx = 0;

void main(void) {
    PORTB.DIRSET = led;
    
TCB0.CTRLB   = TCB_CNTMODE_INT_gc;
TCB0.CCMP = 16500;                  // can adjust time          
TCB0.INTCTRL = TCB_CAPT_bm;
TCB0.CTRLA   = 0x3 | TCB_ENABLE_bm;
sei();
while(1){
    
}

    return;
}

           
ISR(TCB0_INT_vect)
{
    TCB0.INTFLAGS = TCB_CAPT_bm;
    xx ++;
    if(xx>100){
        xx = 0;
        PORTB.OUTTGL = led;// blinks every one second
    }
    
}
