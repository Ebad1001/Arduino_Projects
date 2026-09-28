# Seven Segment Display

The Seven Segment Display is an Arduino library designed to simplify the control of a seven-segment display. Its main purpose is to display decimal digits one at a time.

There are two types of seven-segment displays:
 - __Common Anode__: The common pin is connected to a positive voltage.
  - __Common Cathode__: The common pin is connected to ground.

## Usage

An example of displaying digits from 0 to 9 and the decimal point.

```c++
#include "SevenSegmentDisplay.h"

// Set to SEVEN_SEGMENT_DISPLAY_COMMON_ANODE for a common anode configuration
const seven_segment_display_type_t commonPin = SEVEN_SEGMENT_DISPLAY_COMMON_CATHODE;

const uint8_t pinA = 23;
const uint8_t pinB = 22;
const uint8_t pinC = 15;
const uint8_t pinD = 17;
const uint8_t pinE = 4;
const uint8_t pinF = 21;
const uint8_t pinG = 19;

// Use 0xFF if the decimal point is not connected
const uint8_t pinDp = 18;

seven_segment_display_wired_t displayWired = {
  .common_type = commonPin,
  .pin_a = pinA,
  .pin_b = pinB,
  .pin_c = pinC,
  .pin_d = pinD,
  .pin_e = pinE,
  .pin_f = pinF,
  .pin_g = pinG,
  .pin_dp = pinDp,
};
SevenSegmentDisplay myDisplay(displayWired);

void setup() {
  Serial.begin(9600);
}

void loop() {
  /* Turn on the decimal point */
  myDisplay.dp(true);

  delay(1000);

  /* Turn off the decimal point */
  myDisplay.dp(false);

  /* Display each digit from 0 to 9 */
  for(uint8_t digit = 0; digit < 10; digit++) {
    myDisplay.display(digit);
    delay(1000);
  }

  /* Turn off the display */
  myDisplay.off();
}
```

## Types

### seven_segment_display_type_t
```c++
/* Enumeration for seven-segment display types */
typedef enum
{
    SEVEN_SEGMENT_DISPLAY_COMMON_ANODE = 0,
    SEVEN_SEGMENT_DISPLAY_COMMON_CATHODE
} seven_segment_display_type_t;
```

### seven_segment_display_wired_t
```c++
/* Structure for the wiring of the display */
typedef struct
{
    seven_segment_display_type_t common_type; /* Type of common pin */
    uint8_t pin_a;                           /* Pin for segment A */
    uint8_t pin_b;                           /* Pin for segment B */
    uint8_t pin_c;                           /* Pin for segment C */
    uint8_t pin_d;                           /* Pin for segment D */
    uint8_t pin_e;                           /* Pin for segment E */
    uint8_t pin_f;                           /* Pin for segment F */
    uint8_t pin_g;                           /* Pin for segment G */
    uint8_t pin_dp;                          /* Pin for the decimal point (0xFF if not used) */
} seven_segment_display_wired_t;

#endif /* SEVEN_SEGMENT_DISPLAY_T_H */
```

## Methods

### display

```c++
/**
 * @brief               Displays a digit on the Seven Segment Display
 *
 * @param digit         digit to display (0-9).
 */
void display(uint8_t digit);
```

### dp
```c++
/**
 * @brief               Turns the Decimal Point (DP) segment on or off.
 *
 * @param on            `true` to turn on the Decimal Point; `false` to turn it off.
 */
void dp(bool on);
```

### off
```c++
/**
 * @brief              Turns off the display.
 */
void off();
```
# FAQ

### Other libraries display more characters; why doesn’t this one?
> I believe the purpose of a seven-segment display is to show digits only. Other characters may not be displayed clearly enough to be considered.

### Why are there so many comments in the source code?
> Most comments might be seen as 'well, duh' remarks, but they are meant for beginner programmers.
