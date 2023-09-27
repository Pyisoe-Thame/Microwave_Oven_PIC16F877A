/*
 * File:   main.c
 * Author: muzan
 *
 * Created on September 20, 2023, 9:46 PM
 */

#include "main.h"

unsigned char min = 0, sec = 0; 

void init_config(void) 
{
    init_clcd();
}

void main(void) 
{
    init_config();
    int operation_flag = POWER_ON_SCREEN;
    
    while(1)
    {
        switch(operation_flag)
        {
            case POWER_ON_SCREEN:
                power_on_screen();
                operation_flag = DISPLAY_MENU_SCREEN;
                clear_clcd();
                break;
            case DISPLAY_MENU_SCREEN:
                menu_display_screen();
                break;
        }
    }
}

void power_on_screen(void)
{
    for( unsigned char i=0; i<16; i++)
    {
        clcd_putch( 0xFF , LINE1(i));
        __delay_ms(100);
    }
    clcd_print(" Powering On  ", LINE2(1));
    clcd_print("Microwave Oven", LINE3(1));
    for( unsigned char i=0; i<16; i++)
    {
        clcd_putch( 0xFF , LINE4(i));
        __delay_ms(100);
    }
    __delay_ms(2500);
}

void menu_display_screen()
{
    clcd_print("1.Micro", LINE1(0));
    clcd_print("2.Grill", LINE2(0));
    clcd_print("3.Convection", LINE3(0));
    clcd_print("4.Start", LINE4(0));
}

void set_time(void)
{
    clcd_print("SET TIME (MM:SS)", LINE1(0));
    clcd_print("TIME-", LINE2(0));
    clcd_print("*:Clear  #:Enter", LINE4(0));
    
    // minute
    clcd_putch( min/10 + '0', LINE2(5)); 
    clcd_putch( min%10 + '0', LINE2(6)); 
    
    clcd_putch( ':', LINE2(7));  // the separator
    
    // second
    clcd_putch( sec/10 + '0', LINE2(8));  // change sec to char to put
    clcd_putch( sec%10 + '0', LINE2(9)); 
}

