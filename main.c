// Establishing serial connection for debugging

#include <avr/io.h>
#include <util/delay.h>

#define F_CPT 16000000UL
#define BAUD 9600
#define MYUBBR F_CPU/16/BAUD-1

void uart_init(void){
    // Set baud rate
    UBRR0H = (MYUBBR >> 8); // High bits of the BaudRateRegiter
    UBRR0L = MYUBBR; // // Low bits of the BaudRateRegiter
    // enable transmitter
    UCSR0B = (1 << TXEN0); 
    // Set frame format: 8 data bits, no parity, 1 stop bit
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); // Set the register for the data format
}

void uart_transmit(char data){
    // Wait for empty transmit buffer
    while (!(UCSR0A & (1 << UDRE0)));
    // Put data into buffer, sends the data
    UDR0 = data;

}

void uart_print(const char *str){
    while(*str){
         uart_transmit(*str++);
    }
}

/*******************************MAIN*******************************/

int main(void){
    uart_init();

    uart_print("Debug Start\n");

    while (1) {
        uart_print("Looping...\n");
        _delay_ms(1000);
    }

}