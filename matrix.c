#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>
#include "print.h"
#include "util.h"
#include "matrix.h"
#include "debug.h"

// Pin definitions (adjust these based on actual wiring)
#define OUT0_PIN PE6
#define OUT1_PIN PB4
#define OUT2_PIN PB5
#define D1_PIN   PB6
#define D2_PIN   PB2
#define D3_PIN   PB3
#define D4_PIN   PB1

#define OUT0_DDR DDRE
#define OUT1_DDR DDRB
#define OUT2_DDR DDRB
#define D1_DDR   DDRB
#define D2_DDR   DDRB
#define D3_DDR   DDRB
#define D4_DDR   DDRB

#define OUT0_PORT PORTE
#define OUT1_PORT PORTB
#define OUT2_PORT PORTB
#define D1_PIN_REG PINB
#define D2_PIN_REG PINB
#define D3_PIN_REG PINB
#define D4_PIN_REG PINB

static uint8_t matrix[MATRIX_ROWS];

void matrix_init(void)
{
    // Configure output pins
    OUT0_DDR |= (1 << OUT0_PIN);
    OUT1_DDR |= (1 << OUT1_PIN);
    OUT2_DDR |= (1 << OUT2_PIN);

    // Configure input pins with pull-ups
    D1_DDR &= ~(1 << D1_PIN);
    D2_DDR &= ~(1 << D2_PIN);
    D3_DDR &= ~(1 << D3_PIN);
    D4_DDR &= ~(1 << D4_PIN);

    // Enable the keyboard
    OUT0_PORT |= (1 << OUT0_PIN);
    OUT1_PORT |= (1 << OUT1_PIN);
    OUT2_PORT |= (1 << OUT2_PIN);

    _delay_us(90);

    // Initialize matrix state: all keys off
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        matrix[i] = 0x00;
    }
}

static void send_keyboard_data(bool out2, bool out1, bool out0)
{
    if (out2) {
        OUT2_PORT |= (1 << OUT2_PIN);
    } else {
        OUT2_PORT &= ~(1 << OUT2_PIN);
    }

    if (out1) {
        OUT1_PORT |= (1 << OUT1_PIN);
    } else {
        OUT1_PORT &= ~(1 << OUT1_PIN);
    }

    if (out0) {
        OUT0_PORT |= (1 << OUT0_PIN);
    } else {
        OUT0_PORT &= ~(1 << OUT0_PIN);
    }

    _delay_us(90);
}

static uint8_t read_column_data(void)
{
    uint8_t data = 0;

    // Read the 4 data pins
    if (D1_PIN_REG & (1 << D1_PIN)) data |= (1 << 0);
    if (D2_PIN_REG & (1 << D2_PIN)) data |= (1 << 1);
    if (D3_PIN_REG & (1 << D3_PIN)) data |= (1 << 2);
    if (D4_PIN_REG & (1 << D4_PIN)) data |= (1 << 3);

    return data;
}

uint8_t matrix_scan(void)
{
    // Step 1: Write $05 to reset to row 0, column 0
    send_keyboard_data(true, false, true);

    // Poll all 9 rows
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        // Step 2: Write $04 to select column 0
        send_keyboard_data(true, false, false);

        // Step 3: Read column 0 data (4 bits)
        uint8_t col0_data = read_column_data();

        // Step 4: Write $06 to select column 1
        send_keyboard_data(true, true, false);

        // Step 5: Read column 1 data (4 bits)
        uint8_t col1_data = read_column_data();

        matrix[row] = (col1_data << 4) | col0_data;
    }

    return 1;
}

inline
uint8_t matrix_get_row(uint8_t row)
{
    return matrix[row];
}
