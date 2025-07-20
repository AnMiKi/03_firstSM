MCU = atmega328p
F_CPU = 16000000UL
CC = avr-gcc
OBJCOPY = avr-objcopy
CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os

TARGET = main
PORT = COM3       # ⚠️ Change this to match your Arduino COM port
BAUD = 115200

all: $(TARGET).hex

%.hex: %.elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

%.elf: %.c
	$(CC) $(CFLAGS) $< -o $@

flash: $(TARGET).hex
	avrdude -v -p $(MCU) -c arduino -P $(PORT) -b $(BAUD) -U flash:w:$<:i

clean:
	del /Q *.hex *.elf 2>NUL