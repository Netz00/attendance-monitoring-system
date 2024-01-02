#include "light.h"

void setLight(LightState state)
{
    switch (state)
    {
    case RESET:
        analogWrite(RED, 17);
        analogWrite(GREEN, 20);
        analogWrite(BLUE, 22);
        break;
    case POSITIVE:
        analogWrite(RED, 0);
        analogWrite(GREEN, 255);
        analogWrite(BLUE, 40);
        break;
    case NEGATIVE:
        analogWrite(RED, 255);
        analogWrite(GREEN, 0);
        analogWrite(BLUE, 40);
        break;
    }
}