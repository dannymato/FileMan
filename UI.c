#include <ncurses.h>
#include "UI.h"


int init_screen(){

	initscr();
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();

	wborder(stdscr, 0,0,0,0,0,0,0,0);

}