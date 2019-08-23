/*
 * File:   main.c
 * Author: ?????
 *
 * Created on August 19, 2019, 6:53 PM
 */


#include <xc.h>
#include <stdio.h>
#include <stdlib.h> 
// FICD

#define FCY 10000000
#define BAUDRATE 9600
#define BRGVAL ((FCY/BAUDRATE)/16)-1
#include <libpic30.h>
// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.
void main(void) {
    TRISBbits.TRISB12=0;
    TRISBbits.TRISB10=0;
    TRISBbits.TRISB11=0;
    _U2TXIF = 0;
    _U2TXIE = 0;
    _U2RXIF = 0;
    _U2RXIE = 0;
    RPINR19bits.U2RXR = 42;
    RPOR4bits.RP43R = 3;
    U2MODEbits.STSEL = 0; 
    U2MODEbits.PDSEL = 0; 
    U2MODEbits.BRGH = 0;
    U2MODE = 0; //clear mode register
    U2BRG = BRGVAL;
    U2MODEbits.UARTEN = 1;
    U2STAbits.UTXEN = 1;
    __delay_ms(100);
    U2TXREG = '1';
    char a;
     //__delay_ms(100);
    while (1)
    {     
        
        a = U2RXREG;
        U2TXREG = a;
    }
}
//!U1STAbits.UTXBF