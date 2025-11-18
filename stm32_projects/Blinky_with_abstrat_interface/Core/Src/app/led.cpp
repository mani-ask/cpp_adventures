/*
 * led.cpp
 *
 *  Created on: Nov 17, 2025
 *      Author: manikanta.m
 */

#include "led.hpp"

/* Base class Led Constructors */
Led::Led(): port(GPIOA), pin ((std::uint32_t)0x0020), state (OFF) { };

Led::Led(port_t port, port_pin_t pin): port(port), pin(pin) { state = OFF; };


/* Class methods */

void Led::on()
{
	port->BSRR = pin;
	state = ON;

}

void Led::off()
{
	port->BSRR = (pin << 16U);
	state = OFF;
}

void Led::toggle()
{
	std::uint32_t odr = port->ODR;

	port->ODR = ((odr & pin) << 16U) | (~odr & pin);

	state = (state == OFF)? ON : OFF;
}


Led::Led_State_t Led::get_state() const
{
	return state;
}
