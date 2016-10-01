include <msp430.h>

volatile char received_ch = 0;
int main(void)
{
    WDTCTL = WDTPW + WDTHOLD;

    P1OUT |= BIT5;
    P1DIR |= BIT5;
    P1SEL = BIT1 | BIT2 | BIT4;
    P1SEL2 = BIT1 | BIT2 | BIT4;

    UCA0CTL1 = UCSWRST
    UCA0CTL0 |= UCCKPH + UCMSB + UCMST + UCSYNC; 
    UCA0CTL1 |= UCSSEL_2; 
    UCA0BR0 |= 0x02; 
    UCA0BR1 = 0; 
    UCA0MCTL = 0; 
    UCA0CTL1 &= ~UCSWRST; 

    P1OUT &= (~BIT5);

    while (!(IFG2 & UCA0TXIFG)); 
    UCA0TXBUF = 0xAA; 
    while (!(IFG2 & UCA0RXIFG)); 
    received_ch = UCA0RXBUF; 

    P1OUT |= (BIT5); 
}