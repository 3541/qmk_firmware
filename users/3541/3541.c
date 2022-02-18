#include "quantum.h"

// static uint8_t color_scale(uint8_t base, double frac) { return (uint8_t)((double)base / frac); }

uint32_t wpm_cb(uint32_t t, void* p) {
    double wpm_frac = (double)get_current_wpm() / 140.0;
    if (wpm_frac > 1.0) wpm_frac = 1.0;

    HSV color = rgb_matrix_get_hsv();
    color.h   = 170 * (1.0 - wpm_frac);
    rgb_matrix_sethsv_noeeprom(color.h, color.s, color.v);

    return 100;
}

void keyboard_post_init_user(void) { defer_exec(100, wpm_cb, NULL); }
