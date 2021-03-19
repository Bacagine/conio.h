/* conio4linux (conio.h for linux)
 * Copyright (C) 2013 - 2021 by Carlos J. Pinto B.
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Developed by Carlos J. Pinto B. <pintocar83@gmail.com>
 * Modified by Gustavo Bacagine <gustavo.bacagine@protonmail.com>
 * 
 * Version: 0.3-1
 * 
 * Begin's date: 2013-11-05
 * Date of last modification: 2021-03-18
 */

#ifndef __CONIO4LINUX_H
#define __CONIO4LINUX_H

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

#define cprintf printf
#define cscanf  scanf
#define cgets   gets

//DEV C++ only have the next funtions (version: 4.9.9.2)
#define _cprintf        cprintf
#define _cscanf         cscanf
#define _cputs          cputs
#define _getche         getche
#define _kbhit          kbhit
#define _putch          putch
#define _ungetch        ungetch

#ifdef __cplusplus
extern "C"{
#endif

typedef enum c_colors{
    BLACK, BLUE, GREEN, CYAN,
    RED, MAGENTA, BROWN, LIGHTGRAY,
    DARKGRAY, LIGHTBLUE, LIGHTGREEN, LIGHTCYAN,
    LIGHTRED, LIGHTMAGENTA, YELLOW, WHITE,
    BLINK
} c_colors;

/* Used in funciton 
 * _setcursortype */
typedef enum c_cursors{
    _NOCURSOR, _SOLIDCURSOR, _NORMALCURSOR
} c_cursors;

/* Background color */
static int bgc = 40;

/* Similar putchar */
int putch(const char c);

/*  Similar puts*/
int cputs(const char *str);

/*  */
void clreol(void);

/*  */
void insline(void);

/*  */
void delline(void);

/*  */
void gotoxy(int x, int y);

/* Clear screen */
void clrscr(void);

/* Set a background color */
void textbackground(int color);

/* Set a text color */
void textcolor(short color);

/* Push a character
 * back onto the input
 * buffer of stdin */
int ungetch(int ch);

/* Get character and 
 * display or no in screen
 * according the boolean
 * passed with argument. 
 * 
 * If true, display
 * character in screen,
 * else, don't display the
 * character */
int getch_echo(bool echo);

/* Get a character */
int getch(void);

/* Get a character
 * and display in
 * screen */
int getche(void);

/*  */
int wherexy(int x, int y);

/*  */
int wherex(void);

/*  */
int wherey(void);

/*  */
int kbhit(void);


/* Implemented in unistd.h */
//char *getpass(const char *prompt);

/*  */
//int gettext(int l, int t, int r, int b, void *destination);

#ifdef __cplusplus
}
#endif

#endif
