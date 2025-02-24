#ifndef SERIAL_H
#define SERIAL_H

// Serial configuration structure
typedef struct {
    char *port_name;     // e.g., "/dev/ttyUSB0"
    int baud_rate;       // e.g., 115200
    int data_bits;       // Typically 8
    int stop_bits;       // 1 or 2
    char parity;         // 'N' (None), 'E' (Even), 'O' (Odd)
    int flow_control;    // 0 = None, 1 = Hardware, 2 = Software
    int timeout_ms;      // Read timeout in milliseconds
} SerialConfig;

