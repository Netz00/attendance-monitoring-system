/***
 *
 * Responsible for RGB LED control
 *
 * OUTPUT - GPIO pins
 *
 * RED         4
 * GREEN       2
 * BLUE        5
 *
 * */

#ifndef LIGHT_H
#define LIGHT_H

#include <Arduino.h>

#define RED 4
#define GREEN 0
#define BLUE 2

enum LightState
{
    RESET,
    POSITIVE,
    NEGATIVE
};

void setLight(LightState);

#endif