/*
 * led.hpp
 *
 *  Created on: Nov 17, 2025
 *      Author: manikanta.m
 */

#ifndef SRC_APP_LED_HPP_
#define SRC_APP_LED_HPP_

#include "stm32f4xx.h"
#include "main.h"
#include <cstdint>
#include <utility>

class Led {

public :

	/* Type definitions */
	typedef enum
	{
		ON  = 0,
		OFF = 1
	}Led_State_t;

	typedef GPIO_TypeDef * port_t;
	typedef std::uint32_t port_pin_t;

	/* Standard class constructor functions */
	Led();
	Led(port_t port, const port_pin_t pin);

	/* tells the compiler to generate a default, empty destructor */
	~Led() = default;

	/* Class methods */
	virtual void on();
	virtual void off();
	virtual void toggle();
	Led_State_t get_state() const;

	/* Deletion of default copy constructor */
	Led(const Led &other) = delete;

	/* Deletion of copy assignment operator */
	Led& operator=(const Led&)= delete;

	/* Deletion of default move constructor */
	Led(Led &&other) = delete;

	/* Deletion of default move assignment operator */
	Led &operator=(Led &&other) = delete;

protected :
	port_t port;
	port_pin_t pin;
	Led_State_t state;

private :

};

/* Derived class created from Led base class */
/* TODO : brightness parameter is not initialized by the constructor */
class LedBlue : protected Led {

public :

	/* Standard class constructors */
	~LedBlue() = default;
	LedBlue(port_t port, const port_pin_t pin) : Led(port, pin) {state = OFF;};

	/* Class method */
	void set_brightness (const std::uint32_t brightness)
	{
		Led::toggle();

		this->brightness = brightness;
	};

	/* Function override example */
	void toggle () override
	{
		HAL_GPIO_TogglePin(port, pin);
	}

private :
	std::uint32_t brightness;
};




#endif /* SRC_APP_LED_HPP_ */
