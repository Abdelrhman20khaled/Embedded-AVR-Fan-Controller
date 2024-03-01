/*
 * dc_motor.c
 *
 *  Created on: 11 Oct 2023
 *      Author: AbdoS
 */

#include "dc_motor.h"
// include the pwm.h file for used the function from it in DcMotor_Rotate function
#include "pwm.h"
#include "gpio.h"


void DcMotor_Init(void){

	/*
	 * setup the two pins in the motor as output pins.
	 */
	GPIO_setupPinDirection(DC_MOTOR_PORT,DC_MOTOR_PIN1,PIN_OUTPUT);
	GPIO_setupPinDirection(DC_MOTOR_PORT,DC_MOTOR_PIN2,PIN_OUTPUT);

	/*
	 * put the output of two pins is 0 to make a DC motor stop in the first.
	 */
	GPIO_writePin(DC_MOTOR_PORT,DC_MOTOR_PIN1,LOGIC_LOW);
	GPIO_writePin(DC_MOTOR_PORT,DC_MOTOR_PIN2,LOGIC_LOW);

}

/*
 * this function takes 2 argument:
 * 1- first argument is state that represent that state of the motor stop or move.
 * 2- the second argument is
 * 3- check on the state of the motor that take it in main function and due to it
 * 	  will make a motor move in specific direction
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed){

	// check the state of the motor to make it move in specific direction.
	if(state == Motor_Stop){
		GPIO_writePin(DC_MOTOR_PORT,DC_MOTOR_PIN1,LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_PORT,DC_MOTOR_PIN2,LOGIC_LOW);
	}
	else if(state == Motor_CW){
		GPIO_writePin(DC_MOTOR_PORT,DC_MOTOR_PIN1,LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_PORT,DC_MOTOR_PIN2,LOGIC_HIGH);
	}
	else if(state == Motor_A_CW){
		GPIO_writePin(DC_MOTOR_PORT,DC_MOTOR_PIN1,LOGIC_HIGH);
		GPIO_writePin(DC_MOTOR_PORT,DC_MOTOR_PIN2,LOGIC_LOW);
	}

	// send the speed argument to PWM to make a motor move with the speed from PWM pin
	PWM_Timer0_Start(speed);
}
