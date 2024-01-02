/***
 *
 * Responsible for buzzer control
 *
 * OUTPUT - GPIO pin 5
 *
 * */

#ifndef BUZZER_H
#define BUZZER_H

#include <Arduino.h>
#include "pitches.h"

#define BUZZER 5

void play(int);

#endif