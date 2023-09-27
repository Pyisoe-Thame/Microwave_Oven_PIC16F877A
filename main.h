/*
 * File:   main.h
 * Author: muzan
 *
 * Created on September 21, 2023, 8:55 PM
 */
#ifndef MAIN_H
#define MAIN_H

#include <xc.h>
#include "clcd.h"
#include "digital_keypad.h"

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#define POWER_ON_SCREEN     0x00
#define DISPLAY_MENU_SCREEN 0x01
#define MICRO_MODE          0x02

void power_on_screen(void); 
void menu_display_screen(void);
void set_time(void);

#endif
