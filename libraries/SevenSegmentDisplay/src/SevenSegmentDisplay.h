#ifndef SEVEN_SEGMENT_DISPLAY_H
#define SEVEN_SEGMENT_DISPLAY_H

#include "Arduino.h"
#include "seven_segment_display_t.h"

class SevenSegmentDisplay
{
public:
    /**
     * @param displayWired  Configuration of the seven-segment display wiring
     */
    SevenSegmentDisplay(seven_segment_display_wired_t displayWired);

    /**
     * @brief               Displays a digit on the Seven Segment Display
     *
     * @param digit         digit to display (0-9).
     */
    void display(uint8_t digit);

    /**
     * @brief               Turns the Decimal Point (DP) segment on or off.
     *
     * @param on            `true` to turn on the Decimal Point; `false` to turn it off.
     */
    void dp(bool on);

    /**
     * @brief               Turns off the display.
     */
    void off();

private:
    seven_segment_display_type_t commonType;    /* `false`: Common Anode; `true`: Common Cathode */

    uint8_t segmentPins[7];                     /* Storage for the the pins from A to G */

    bool pinDpConnected;                        /* If the DP segment pin is set or not. */

    uint8_t pinDp;                              /* Pin for the decimal point (0xFF if not used) */

    const bool (*digitsMap)[7];                 /* digitsMapCathode when commonType is true; digitsMapAnode otherwise */

    /**
     * @brief               Represents the digits for a Cathode Seven Segment Display
     *                      (when commonType is SEVEN_SEGMENT_DISPLAY_COMMON_CATHODE).
     */
    bool digitsMapCathode[10][7] = {
        {0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x0}, /* 0 */
        {0x0, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0}, /* 1 */
        {0x1, 0x1, 0x0, 0x1, 0x1, 0x0, 0x1}, /* 2 */
        {0x1, 0x1, 0x1, 0x1, 0x0, 0x0, 0x1}, /* 3 */
        {0x0, 0x1, 0x1, 0x0, 0x0, 0x1, 0x1}, /* 4 */
        {0x1, 0x0, 0x1, 0x1, 0x0, 0x1, 0x1}, /* 5 */
        {0x1, 0x0, 0x1, 0x1, 0x1, 0x1, 0x1}, /* 6 */
        {0x1, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0}, /* 7 */
        {0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1}, /* 8 */
        {0x1, 0x1, 0x1, 0x0, 0x0, 0x1, 0x1}  /* 9 */
    };


    /**
     * @brief               Represents the digits for a Anode Seven Segment Display
     *                      (when commonType is SEVEN_SEGMENT_DISPLAY_COMMON_ANODE).
     */
    bool digitsMapAnode[10][7] = {
        {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1}, /* 0 */
        {0x1, 0x0, 0x0, 0x1, 0x1, 0x1, 0x1}, /* 1 */
        {0x0, 0x0, 0x1, 0x0, 0x0, 0x1, 0x0}, /* 2 */
        {0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x0}, /* 3 */
        {0x1, 0x0, 0x0, 0x1, 0x1, 0x0, 0x0}, /* 4 */
        {0x0, 0x1, 0x0, 0x0, 0x1, 0x0, 0x0}, /* 5 */
        {0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0}, /* 6 */
        {0x0, 0x0, 0x0, 0x1, 0x1, 0x1, 0x1}, /* 7 */
        {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, /* 8 */
        {0x0, 0x0, 0x0, 0x1, 0x1, 0x0, 0x0}  /* 9 */
    };

    /**
     * @brief               Sets the pins (A-G) to OUTPUT mode.
     */
    void init();

    inline uint8_t getOnLevel()  const { return commonType ? HIGH : LOW; }
    inline uint8_t getOffLevel() const { return commonType ? LOW  : HIGH; }
};

#endif /* SEVEN_SEGMENT_DISPLAY_H */
