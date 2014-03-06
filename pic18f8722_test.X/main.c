/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#if defined(__XC)
#include <xc.h>        /* XC8 General Include File */
#elif defined(HI_TECH_C)
#include <htc.h>       /* HiTech General Include File */
#elif defined(__18CXX)
#include <p18cxxx.h>   /* C18 General Include File */
#endif

#if defined(__XC) || defined(HI_TECH_C)

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */

#endif

#include <delays.h>
#include <usart.h>

#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h"          /* User funct/params, such as InitApp */

#include "UARTIntC.h"

/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/

/* i.e. uint8_t <variable_name>; */

/******************************************************************************/
/* Main Program                                                               */

/******************************************************************************/

void main(void) {
    char packet[] = {'T', 'e', 's', 't'};

    unsigned char i = 0;
    unsigned char packet_size = sizeof (packet) / sizeof (packet[0]);
    unsigned char cArray[10]
            = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    // temporary local array
    unsigned char writtenArray[10];

    // local variables for all test cases and their initialisation
    unsigned char chData;
    unsigned char *pReadArray;
    unsigned char *pWriteArray;
    unsigned char j = 0;
    unsigned char i = 0;
    unsigned char l = 0;
    unsigned char k = 0;
    pReadArray = pWriteArray = writtenArray;

    /* Configure the oscillator for the device */
    ConfigureOscillator();

    /* Initialize I/O and Peripherals for application */
    InitApp();

    /* TODO <INSERT USER APPLICATION CODE HERE> */
    /*
    while(1)
    {
        i = 0;
        
        do {
            UARTIntPutChar(packet[i++]);
        } while (i < packet_size);

        while (!vUARTIntStatus.UARTIntTxBufferEmpty);

        Delay10KTCYx(1000);
    }
     */
    TRISD = 0;
    PORTD = 0;
    k = 0;

    while (k < 100) {
        for (j = 0; j < 100; j++) {
            i = 0;
            do {
                if (vUARTIntStatus.UARTIntTxBufferEmpty)
                    UARTIntPutChar(cArray[i++]);
            } while (i < 10);
        }

        if (!(vUARTIntStatus.UARTIntRxError) &&
            !(vUARTIntStatus.UARTIntRxOverFlow) &&
            !(vUARTIntStatus.UARTIntRxBufferEmpty)) {
                if (UARTIntGetChar(&chData))
                    PORTD = chData;
        }

        k++;
    }

    while (1);
}

