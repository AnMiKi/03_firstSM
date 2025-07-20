// Establishing serial connection for debugging

#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"

/*******************************MAIN*******************************/

int main(void){
    uart_init();

    uart_print("Debug Start\n");

    while (1) {
        uart_print("Looping...\n");
        _delay_ms(1000);
    }

}