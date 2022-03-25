/***************************************************************************************************************
 * File Name    : INTERRUPT.c
 * Author       : Rana Mohamed
 * Date Created : 19 Jul 2021
 * Description  : This is the Source File of the Interrupt Driver for Interrupt 0 ,1 ,2.
 **************************************************************************************************************/

/*************************************************** INCLUDES *************************************************/

#include "INTERRUPT.h"




/************************************************ GLOBAL VARIABLES ********************************************/




/******************************************* Interrupt Service Routines ***************************************/



/********************************************* FUNCTIONS DEFINITIONS ******************************************/

#if ( INTERRUPT_ZERO ==1 )

/***************************************************************************************************************
 *  Function Name : SET_interruptzero
 * Description: This Function is responsible for setting Interrupt 0
 * Arguments : None
 * Return: None
 **************************************************************************************************************/
void SET_interruptzero(const set_INT0* data)
{

	  /*
     * INT0  -> 1
     * ISC01 -> 1
     */
	DDRD &= ~(1<<PD2);
	GICR = 1<<INT0;
	MCUCR |= (MCUCR & 0xFC) | (data->setINT0);


}
#endif



#if( INTERRUPT_ONE ==1 )

/***************************************************************************************************************
 * Function Name : SET_interruptone
 * Description: This Function is responsible for setting Interrupt 1
 * Arguments : None
 * Return: None
 **************************************************************************************************************/
void SET_interruptone(const set_INT1* data){


	  /*
      * INT1  -> 1
      * ISC10 -> 0 , ISC11 -> 0
      */
	DDRD &= ~(1<<PD3);
	GICR = 1<<INT1;
	MCUCR |= (MCUCR & 0xF3) | (data->setINT1 << 2);



}

#endif






#if ( INTERRUPT_TWO ==1 )

/***************************************************************************************************************
 * Function Name : SET_interrupttwo
 * Description: This Function is responsible for setting Interrupt 2
 * Arguments : None
 * Return: None
 **************************************************************************************************************/
void SET_interrupttwo(const set_INT1* data){

	  /*
     * INT2  -> 1
     * ISC2  -> 0
     */
	DDRB &= ~(1<<PB2);
	GICR = 1<<INT2;
	MCUCSR |= (MCUCSR & 0xBF )| (data->setINT2 << 6);

}

#endif

