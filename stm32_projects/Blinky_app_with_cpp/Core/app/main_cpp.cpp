/*
 * main_cpp.cpp
 *
 *  Created on: Nov 13, 2025
 *      Author: manikanta.m
 */

/* This is my fist embedded CPP project
 * Goal #1 : To configure and verify the C++ development environment with STm32cube IDE
 * Goal #2 : Blink a LED, make use of class */

#include "main_cpp.hpp"


class led_class
{
	public:

	led_class();

	/* method to blink LED */
	void blink_led ()
	{
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
	}
};

/* led_class constructor, which does nothing in this example */
/* It could be used to initialize the object attributes */
led_class::led_class()
{

}


void invoke_cpp_func()
{

	/* led_class object instantiation */
	led_class led_green;

	while(1)
	{
		/* led_class public method access using object */
		led_green.blink_led();

		/* Delay of 500 ms */
		HAL_Delay(500);
	}

}
