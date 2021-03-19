#include "../include/conio.h"

int putch(const char c){
    write(1, &c, 1);
    return (int)c;
}

int cputs(const char *str){
    while(*str){
        putch(*str++);
    }
    putch('\n');
    return 0;
}

void clreol(void){
    cprintf("\033[K");
}

void insline(void){
    cprintf( "\x1b[1L");
}

void delline(void){
    cprintf( "\033[1M");
}

void gotoxy(int x, int y){
    cprintf("\033[%d;%df", y, x);
}

void clrscr(void){
    cprintf( "\033[%dm\033[2J\033[1;1f", bgc);
}

void textbackground(int color){
    switch(color % 16){
        case BLACK:          bgc = 40; break;
        case BLUE:           bgc = 44; break;
        case GREEN:          bgc = 42; break;
        case CYAN:           bgc = 46; break;
        case RED:            bgc = 41; break;
        case MAGENTA:        bgc = 45; break;
        case BROWN:          bgc = 43; break;
        case LIGHTGRAY:      bgc = 47; break;
        case DARKGRAY:       bgc = 40; break;
        case LIGHTBLUE:      bgc = 44; break;
        case LIGHTGREEN:     bgc = 42; break;
        case LIGHTCYAN:      bgc = 46; break;
        case LIGHTRED:       bgc = 41; break;
        case LIGHTMAGENTA:   bgc = 45; break;
        case YELLOW:         bgc = 43; break;
        case WHITE:          bgc = 47; break;
    }
}

void textcolor(short color){  
    switch(color % 16){
        case BLACK:          cprintf("\033[0;%d;%dm", 30, bgc); break;
        case BLUE:           cprintf("\033[0;%d;%dm", 34, bgc); break;
        case GREEN:          cprintf("\033[0;%d;%dm", 32 ,bgc); break;
        case CYAN:           cprintf("\033[0;%d;%dm", 36, bgc); break;
        case RED:            cprintf("\033[0;%d;%dm", 31, bgc); break;
        case MAGENTA:        cprintf("\033[0;%d;%dm", 35, bgc); break;
        case BROWN:          cprintf("\033[0;%d;%dm", 33, bgc); break;
        case LIGHTGRAY:      cprintf("\033[0;%d;%dm", 37, bgc); break;
        case DARKGRAY:       cprintf("\033[1;%d;%dm", 30, bgc); break;
        case LIGHTBLUE:      cprintf("\033[1;%d;%dm", 34, bgc); break;
        case LIGHTGREEN:     cprintf("\033[1;%d;%dm", 32, bgc); break;
        case LIGHTCYAN:      cprintf("\033[1;%d;%dm", 36, bgc); break;
        case LIGHTRED:       cprintf("\033[1;%d;%dm", 31, bgc); break;
        case LIGHTMAGENTA:   cprintf("\033[1;%d;%dm", 35, bgc); break;
        case YELLOW:         cprintf("\033[1;%d;%dm", 33, bgc); break;
        case WHITE:          cprintf("\033[1;%d;%dm", 37, bgc); break;
    }
}

int ungetch(int ch){
    return ungetc(ch, stdin);
}

int getch_echo(bool echo){
    struct termios oldt, newt;
    int ch;
    
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~ICANON;
    
    if(echo){
        newt.c_lflag &=  ECHO;
    }
    else{
        newt.c_lflag &= ~ECHO;
    }
    
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

int getch(void){
    getch_echo(false);
}

int getche(void){
    getch_echo(true);
}

int wherexy(int x, int y){
    printf("\033[6n");
    
    if(getch() != '\x1B'){
        return 0;
    }
    if(getch() != '\x5B'){
        return 0;
    }
    
    int in;
    int ly = 0;
    
    while((in = getch()) != ';')
    ly = ly * 10 + in - '0';
    
    int lx = 0;
    
    while((in = getch()) != 'R')
    
    lx = lx * 10 + in - '0';
    x = lx;
    y = ly;
}

int wherex(void){
    int x = 0, y = 0;
    
    wherexy(x, y);
    
    return x;
}

int wherey(void){
    int x = 0, y = 0;
    
    wherexy(x, y);
    
    return y;
} 

int kbhit(void){
    struct termios oldt, newt;
    int ch;
    int oldf;    
    
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);    
    ch = getchar();    
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);    
    
    if(ch != EOF){
        ungetc(ch, stdin);
        return 1;
    }    
    
    return 0;
}


/*
int gettext(int l, int t, int r, int b, void *destination){
    
}
*/
