/*
 * main_cpp.cpp
 *
 *  Created on: Nov 17, 2025
 *      Author: manikanta.m
 */

#include "main.h"
#include "led.hpp"
#include <stdio.h>
#include <utility>

/* Anonymous namespace */
namespace{

	LedBlue led_blue {LD2_GPIO_Port, LD2_Pin};

	void delay(int ms)
	{
		for (volatile int i = 0; i < ms * 10000; ++i);
	}
}


void invoke_main_cpp ()
{

	while(1)
	{
		led_blue.toggle();
		delay(100);
	}

}

