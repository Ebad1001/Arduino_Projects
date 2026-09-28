#ifndef SEVEN_SEGMENT_DISPLAY_T_H
#define SEVEN_SEGMENT_DISPLAY_T_H

#include <stdint.h>

/* Enumeration for seven-segment display types */
typedef enum
{
    SEVEN_SEGMENT_DISPLAY_COMMON_ANODE = 0,
    SEVEN_SEGMENT_DISPLAY_COMMON_CATHODE
} seven_segment_display_type_t;

/* Structure for the wiring of the display */
typedef struct
{
    seven_segment_display_type_t common_type; /* Type of common pin */
    uint8_t pin_a;                            /* Pin for segment A */
    uint8_t pin_b;                            /* Pin for segment B */
    uint8_t pin_c;                            /* Pin for segment C */
    uint8_t pin_d;                            /* Pin for segment D */
    uint8_t pin_e;                            /* Pin for segment E */
    uint8_t pin_f;                            /* Pin for segment F */
    uint8_t pin_g;                            /* Pin for segment G */
    uint8_t pin_dp;                           /* Pin for the decimal point (0xFF if not used) */
} seven_segment_display_wired_t;

#endif /* SEVEN_SEGMENT_DISPLAY_T_H */
