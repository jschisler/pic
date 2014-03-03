/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#elif defined(__18CXX)
    #include <p18cxxx.h>    /* C18 General Include File */
#endif

#if defined(__XC) || defined(HI_TECH_C)

#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */

#endif

#include "user.h"
#include "UARTIntC.h"
#include <plib.h>

#define USE_OR_MASKS

/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/

/* <Initialize variables in user.h and insert code for user algorithms.> */

void InitApp(void)
{
    /* TODO Initialize User Ports/Peripherals/Project here */

    /* Setup analog functionality and port direction */

    /* Initialize peripherals */
    UARTIntInit();
    
    /*
    Open1USART( USART_TX_INT_ON |
                USART_RX_INT_ON |
                USART_ASYNCH_MODE |
                USART_EIGHT_BIT |
                USART_CONT_RX |
                USART_BRGH_HIGH |
                TX_PRIORITY_ON |
                RX_PRIORITY_ON,
                SPBRG_VAL);
                */
}

