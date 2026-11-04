// RootBoot BIOS
// Copyleft (C) 2026 @RootBootAuthor (Telegram)
// 
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, see <https://www.gnu.org/licenses/>.

#include "printf.h"

void _putchar(char character) {
    volatile uint16_t *video = (volatile uint16_t*) 0xB8000;
    static int cursor = 0;

    if (character == '\n') {
        cursor += 80 - (cursor % 80);
    } 
    else if (character == '\r') {
        cursor -= (cursor % 80);
    }
    else if (character == '\b') {
        if (cursor > 0) {
            cursor--;
            video[cursor] = (0x07 << 8) | ' ';
        }
    }
    else {
        video[cursor] = (0x07 << 8) | character;
        cursor++;
    }

    if (cursor >= 80 * 25) {
        for (int i = 0; i < 80 * 24; i++) {
            video[i] = video[i + 80];
        }
        for (int i = 80 * 24; i < 80 * 25; i++) {
            video[i] = (0x07 << 8) | ' ';
        }
        cursor = 80 * 24;
    }
}
void c_main() {
    printf("Hello from RootBoot BIOS!\n");
    printf("Version RootBoot 0.1\n");
    printf(":))))");
    
    while (1) {}
}
