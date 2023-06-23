#include "common.h"

#ifndef _GAME_TIGER_COLOR_H
#define _GAME_TIGER_COLOR_H

typedef struct Color {
    union {
        uint16_t value;
        struct {
            uint16_t red:5;
            uint16_t green:6;
            uint16_t blue:5;
        } Colors;
    };

    Color() {
        Colors.red = 0; Colors.green = 0; Colors.blue = 0;
    }

    Color(uint8_t r, uint8_t g, uint8_t b) {
        Colors.red = r >> 3; Colors.green = g >> 2; Colors.blue = b >> 3;
    }

    Color(uint16_t v) {
        value = v;
    }

    Color(uint32_t v) {
        uint8_t r = (v & 0xFF0000) >> 16;
        uint8_t g = (v & 0x00FF00) >> 8;
        uint8_t b = (v & 0x0000FF) >> 0;
        Colors.red = r >> 3; 
        Colors.green = g >> 2; 
        Colors.blue = b >> 3;
    }

    Color& operator=(const uint16_t &v) {
        value = v;
        return *this;
    }

} Color;

#endif