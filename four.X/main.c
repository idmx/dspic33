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
#define FOSC    7370000ULL
#define FCY     (FOSC / 2)
#define BAUDRATE 9600
#define BRGVAL 23 //((FCY/BAUDRATE)/16)-1
#include <libpic30.h>
// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.
void main(void) {
    TRISBbits.TRISB12=0;
    TRISBbits.TRISB10=0;
    TRISBbits.TRISB11=0;
    LATBbits.LATB12 = 1;
//    _U2TXIF = 0;
//    _U2TXIE = 0;
//    _U2RXIF = 0;
//    _U2RXIE = 0;
    RPINR19bits.U2RXR = 54;
    RPOR4bits.RP43R = 3;
    U2MODEbits.STSEL = 0; 
    U2MODEbits.PDSEL = 0; 
    U2MODEbits.BRGH = 0;
    U2MODE = 0; //clear mode register
    U2BRG = BRGVAL;
    U2MODEbits.UARTEN = 1;
    U2STAbits.UTXEN = 1;
    __delay_ms(100);
    U2TXREG = '7';
    char y=NULL;
    LATBbits.LATB10 = 1;
     //__delay_ms(100);
    while (1)
    {     
        LATBbits.LATB12 = !LATBbits.LATB12;
        __delay_ms(1000);
        
        while(U2STAbits.UTXBF == 1);// check buuffer tx
        if(U2STAbits.URXDA == 1)
        y = U2RXREG;
        
        if(y!=NULL)
        U2TXREG = y++;
    }
}
//!U1STAbits.UTXBF