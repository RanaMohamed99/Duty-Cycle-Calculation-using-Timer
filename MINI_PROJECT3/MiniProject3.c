/***************************************************************************************************************
 * File Name    : MiniProject3.c
 * Author       : Rana Mohamed
 * Date Created : 19 Jul 2021
 * Description  : This is the Source File of the Main Function.
 **************************************************************************************************************/


#include "timers.h"
#include "INTERRUPT.h"
#include "lcd.h"
#include <util/delay.h>
#include "common_macros.h"


uint8  g_edgeCount = 0;
uint16 g_timeHigh = 0;
uint16 g_timePeriod = 0;
uint16 g_timePeriodPlusHigh = 0;
uint16 g_timeValue=0;


int main(void)
{
	uint32 duty_Cycle = 0;
	SREG |= (1<<7);
	LCD_init();
	Timer1_setup timer1={normal1,Normal_NonPWMT1,No_Prescaler};
	SET_timer1(&timer1);
	set_INT0 int00={risingEdge0};
	SET_interruptzero(&int00);
	while(1)
	{
		if(g_edgeCount == 4)
	{
		TCCR1A = 0;
		TCCR1B = 0;
		TCNT1 = 0;
		SREG  &= ~(1<<7);
		g_edgeCount = 0;
		LCD_displayString("Duty Cycle = ");
		duty_Cycle = (((float)(g_timePeriodPlusHigh-g_timePeriod) / (g_timePeriodPlusHigh - g_timeHigh)) * 100);
		LCD_intgerToString(duty_Cycle);
		LCD_displayCharacter('%');
	}

 }
		}










ISR(INT0_vect){

	g_timeValue=TCNT1;
	g_edgeCount++;
		if(g_edgeCount == 1)
		{
			/*Start to count from first rising edge*/
			TCNT1=0;
			/*configure INT0 to detect falling edge*/
			CLEAR_BIT(MCUCR,ISC00);

		}
		else if(g_edgeCount == 2)
		{
			g_timeHigh= g_timeValue;
			SET_BIT(MCUCR,ISC00);
		}
		else if(g_edgeCount==3)
		{
			g_timePeriod= g_timeValue;
			CLEAR_BIT(MCUCR,ISC00);
		}
		else if(g_edgeCount == 4)
		{
			g_timePeriodPlusHigh =g_timeValue;
			SET_BIT(MCUCR,ISC00);

		}
}

