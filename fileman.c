#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <ncurses.h>

#define MAX_FILE 40

int main(){

	DIR *dirp;
	struct dirent *dp;

	

	const char PROG_NAME[] = "FileMan";
	const char VER_NO[] = "v0.0.0.1";

	char files[MAX_FILE][FILENAME_MAX];

	if ((dirp = opendir(".")) == NULL){
		perror("Couldn't open .");
		return -1;
	}

	int i = 0;

	do{
		if((dp = readdir(dirp)) != NULL){
			strcpy(files[i++], dp->d_name);
		}
		else {
			perror("couldn't open dir");
		}
	} while (dp != NULL);

	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();

	int row,col;

	col = getmaxx(stdscr);

	attron(A_STANDOUT);

	wprintw(stdscr, "%s", PROG_NAME);

	mvprintw(0, col - strlen(VER_NO), "%s\n", VER_NO);	

	attroff(A_STANDOUT);

	i = 0;

	while(files[i] != NULL && i < MAX_FILE - 1){
		wprintw(stdscr, "%s\n", files[i]);
		i++;
	}

	refresh();

	getch();

	endwin();

	closedir(dirp);

	return 0;
	

}