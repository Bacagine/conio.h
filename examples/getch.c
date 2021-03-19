/* Compilation: gcc -o getch.out getch.c -lconio
 * Test program: ./getch.out
 */

#include <conio.h>

int main(void){
    unsigned char ch;
    
    ch = getch();
    
    cprintf("Voce precionou a tecla %c\n", ch);
    
    return 0;
}
