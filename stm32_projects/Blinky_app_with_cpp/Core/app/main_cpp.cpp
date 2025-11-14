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


led::led( ) : port(GPIOA), pin ((std::uint32_t)0x0020) { };

led::led(port_t port, pin_t pin) : port(port), pin (pin) { };


void led::on() const
{
	port->BSRR = pin;
}


void led::off() const
{
	port->BSRR = (uint32_t)(pin  <<  16U);
}

void led::toggle() const
{
	uint32_t odr;

	/* get current Output Data Register value */
	odr = port->ODR;

	/* Set selected pins that were at low level, and reset ones that were high */
	port->ODR = ((odr & pin) << 16U) | (~odr & pin);
}

void invoke_cpp_func()
{

	/* led_class object instantiation */
	led led_green;

	while(1)
	{
		/* led_class public method access using object */
		led_green.toggle();

		/* Delay of 500 ms */
		HAL_Delay(500);
	}

}
