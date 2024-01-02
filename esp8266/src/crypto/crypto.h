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

#ifndef CRYPTO_H
#define CRYPTO_H

#include <Crypto.h>

void getKey(uint8_t *, int, uint8_t *);

#endif