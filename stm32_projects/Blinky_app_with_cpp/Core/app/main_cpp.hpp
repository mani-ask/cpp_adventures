/*
 * main_cpp.hpp
 *
 *  Created on: Nov 13, 2025
 *      Author: manikanta.m
 */

#ifndef APP_MAIN_CPP_HPP_
#define APP_MAIN_CPP_HPP_

#include "main.h"
#include "stm32f4xx_hal_gpio.h"
#include <cstdint>

void invoke_cpp_func();

class led {

public :
	typedef GPIO_TypeDef * port_t;
	typedef std::uint32_t pin_t;

	/* Constructor with no parameter list */
	led();

	/* Constructor with parameter list */
	led(port_t port, pin_t pin);

	/* default : tells the compiler to generate a default, empty destructor*/
	~led() = default;

	/* Class methods */
	void on () const;
	void off() const;
	void toggle() const;

private :
	const port_t port;
	const pin_t pin;

};

#endif /* APP_MAIN_CPP_HPP_ */
