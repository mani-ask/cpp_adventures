/*
 * led.hpp
 *
 *  Created on: Nov 17, 2025
 *      Author: manikanta.m
 */

#ifndef SRC_APP_LED_HPP_
#define SRC_APP_LED_HPP_

#include "stm32f4xx.h"
#include <cstdint>
#include <utility>

class Led {

public :
	typedef GPIO_TypeDef * port_t;
	typedef std::uint32_t port_pin_t;

	typedef enum
	{
		ON  = 0,
		OFF = 1
	}Led_State_t;

	Led();

	Led(port_t port, port_pin_t pin);

	/* tells the compiler to generate a default, empty destructor */
	~Led() = default;

	void on();
	void off();
	void toggle();
	Led_State_t get_state() const;

	/* Deletion of default copy constructor */
	Led(const Led &other) = delete;

	/* Deletion of copy assignment operator */
	Led& operator=(const Led&)= delete;

	/* Move constructor */
	//Led(Led &&other) noexcept: port(other.port), pin(other.pin) { };

	/* Move constructor : Using std::move( ) method*/
//	Led(Led &&other) noexcept {
//		port = std::move(other.port);
//		pin = std::move(other.pin);
//	}

	Led(Led &&other) = delete;

//	Led& operator=(Led&& other){
//	port = other.port;
//	pin = other.pin;
//	return *this;
//	};

	Led &operator=(Led &&other) = delete;

private :

	port_t port;
	port_pin_t pin;
	Led_State_t state;
};




#endif /* SRC_APP_LED_HPP_ */
