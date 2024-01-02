/*
Board: Croduino NOVA2

 * Signal      Pin
 * ---------------
 * RST/Reset   16
 * SPI SS      15
 * SPI MOSI    13
 * SPI MISO    12
 * SPI SCK     14

 * RED         4
 * GREEN       2
 * BLUE        5

 * BUZZ        0

 */

#ifndef MAIN_H
#define MAIN_H

#include <SPI.h>
#include <MFRC522.h>


#define RST_PIN 16
#define SS_PIN 15

#include "./buzzer/buzzer.h"
#include "./light/light.h"
#include "./crypto/crypto.h"
#include "./client/client.h"

#endif