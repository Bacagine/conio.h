/* Compilation: gcc -o pause.out pause.c -lconio
 * Test program: ./pause.out
 */

#include <conio.h>

#define stay() cprintf("Press any key to continue. . ."); getch();

int main(void){
    clrscr();
    
    cprintf("Test!\n");
    
    stay();
    
    return 0;
}
