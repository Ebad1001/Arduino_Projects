#include "SevenSegmentDisplay.h"

#define PIN_NOT_CONNECTED 0xFF

SevenSegmentDisplay::SevenSegmentDisplay(seven_segment_display_wired_t displayWired)
{
    commonType = displayWired.common_type;

    digitsMap = (commonType) ? digitsMapCathode : digitsMapAnode;    

    /* Assign pins to segments A through G */
    segmentPins[0] = displayWired.pin_a;
    segmentPins[1] = displayWired.pin_b;
    segmentPins[2] = displayWired.pin_c;
    segmentPins[3] = displayWired.pin_d;
    segmentPins[4] = displayWired.pin_e;
    segmentPins[5] = displayWired.pin_f;
    segmentPins[6] = displayWired.pin_g;

    /* Initialize the decimal point pin here to prevent evaluating the condition twice in the init method. */
    pinDpConnected = (displayWired.pin_dp != PIN_NOT_CONNECTED);
    if (pinDpConnected)
    {
        pinDp = displayWired.pin_dp;
        pinMode(pinDp, OUTPUT);
    }

    init();
    off();
}

void SevenSegmentDisplay::init()
{
    for (uint8_t segment = 0; segment < 7; segment++)
    {
        pinMode(segmentPins[segment], OUTPUT);
    }
}

void SevenSegmentDisplay::display(uint8_t digit)
{
    if (digit > 9)
        return;

    for (uint8_t segment = 0; segment < 7; segment++)
        digitalWrite(segmentPins[segment], digitsMap[digit][segment]);
}

void SevenSegmentDisplay::off()
{
    uint8_t pinOff = getOffLevel();

    for (uint8_t segment = 0; segment < 7; segment++)
        digitalWrite(segmentPins[segment], pinOff);

    if (pinDpConnected)
        digitalWrite(pinDp, pinOff);
}

void SevenSegmentDisplay::dp(bool on)
{    
    if (!pinDpConnected) 
        return;

    digitalWrite(pinDp, on ? getOnLevel() : getOffLevel());
}
