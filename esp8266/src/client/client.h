#ifndef CLIENT_H
#define CLIENT_H

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

#ifndef STASSID

#define STASSID "chmod"
#define STAPSK "AvTrx321"
#endif

#define SERVER_IP "192.168.150.3:8080"

int initWifiConnection();
bool sendMessage(byte *, int);

#endif