/*
    File name. interface.h
    Date: 2024.10.06
    Author: Stephan Scholz
    Description: Pool Control
*/

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#define POOL_LED     13  // D2
#define WATERING_LED 15  // D3

#define POOL_SWT     12  // D5
#define WATERING_SWT 14  // D6


extern char msg[50];
extern PubSubClient client;

void pool_pump(bool option)
{
    if (option)
    {
        Serial.println("Pump ON");
        digitalWrite(POOL_SWT, LOW);
        digitalWrite(POOL_LED, HIGH);
    }
    else
    {
        Serial.println("Pump OFF");
        digitalWrite(POOL_SWT, LOW);
        digitalWrite(POOL_LED, HIGH);
    }
    msg[0] = (option ? '1' : '0');
    msg[1] = 0;
    client.publish("outGarden/pool/pump", msg);
}/*--------------------------------------------------------------------------*/

void watering(bool option)
{
    if (option)
    {
        Serial.println("Watering ON");
        digitalWrite(WATERING_SWT, HIGH);
        digitalWrite(WATERING_LED, HIGH);
    }
    else
    {
        Serial.println("Watering OFF");
        digitalWrite(WATERING_SWT, LOW);
        digitalWrite(WATERING_LED, LOW);
    }
    msg[0] = (option ? '1' : '0');
    msg[1] = 0; // String end
    client.publish("outGarden/watering/state", msg);
}/*--------------------------------------------------------------------------*/
