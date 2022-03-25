/***************************************************************************************************************
 * File Name    : INTERRUPT.h
 * Author       : Rana Mohamed
 * Date Created : 19 Jul 2021
 * Description  : This is the Header File of the Interrupt Driver for Interrupt 0 ,1 ,2.
 **************************************************************************************************************/

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

/****************************************************INCLUDES***************************************************/

#include <avr/io.h>


/****************************************** DEFINITIONS and CONFIGURATIONS **************************************/


/****************************************************************************************************************
 * Set the following to one if you want to activate interrupt
 ***************************************************************************************************************/
#define INTERRUPT_ZERO 1

#define INTERRUPT_ONE 0

#define INTERRUPT_TWO 0



/************************************************ ENUMERATIONS *************************************************/

/***************************************************************************************************************
 *  Enumeration Name: interupptzero
 *  Enumeration Description:
 *  0- lowLevel0         : Triggers Interrupt 0 request at low level.
 *  1- AnyLogicalChange0 : Triggers Interrupt 0 request at any logical change.
 *  2- fallingEdge0      : Triggers Interrupt 0 request at falling edge
 *  3- risingEdge0       : Triggers Interrupt 0 request at rising edge
 *
 **************************************************************************************************************/
typedef enum {
	lowLevel0, AnyLogicalChange0 , fallingEdge0 , risingEdge0
}interupptzero;


/***************************************************************************************************************
 *  Enumeration Name: interupptone
 *  Enumeration Description:
 *  0- lowLevel1         : Triggers Interrupt 1 request at low level.
 *  1- AnyLogicalChange1 : Triggers Interrupt 1 request at any logical change.
 *  2- fallingEdge1      : Triggers Interrupt 1 request at falling edge
 *  3- risingEdge1       : Triggers Interrupt 1  request at rising edge
 *
 **************************************************************************************************************/
typedef enum {
	lowLevel1, AnyLogicalChange1 , fallingEdge1 , risingEdge1
}interupptone;



/**************************************************************************************************************
 *  Enumeration Name: interuppttwo
 *  Enumeration Description:
 *  0- fallingEdge0      : Triggers Interrupt 2 at falling edge
 *  1- risingEdge0       : Triggers Interrupt 2 at rising edge
 *
 **************************************************************************************************************/
typedef enum {
	 fallingEdge2 , risingEdge2
}interuppttwo;




typedef struct{
	interupptzero setINT0;
}set_INT0;



typedef struct{
	interupptone setINT1;
}set_INT1;

typedef struct{
	interuppttwo setINT2;
}set_INT2;



/***************************************************************************************************************
 *  Function Name : SET_interruptzero
 * Description: This Function is responsible for setting Interrupt 0
 * Arguments : None
 * Return: None
 **************************************************************************************************************/
void SET_interruptzero(const set_INT0* data);



/***************************************************************************************************************
 *  Function Name : SET_interruptone
 * Description: This Function is responsible for setting Interrupt 1
 * Arguments : None
 * Return: None
 **************************************************************************************************************/
void SET_interruptone(const set_INT1* data);



/***************************************************************************************************************
 * Function Name : SET_interrupttwo
 * Description: This Function is responsible for setting Interrupt 2
 * Arguments : None
 * Return: None
 **************************************************************************************************************/
void SET_interrupttwo(const set_INT2* data);




#endif /* INTERRUPT_H_ */
