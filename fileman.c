#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include "LList.h"

#define MAX_FILE 40

int main(){

	DIR *dirp;
	struct dirent *dp;

	

	const char PROG_NAME[] = "FileMan";
	const char VER_NO[] = "v0.0.0.1";

	char files[MAX_FILE][FILENAME_MAX];

	if ((dirp = opendir("/")) == NULL){
		perror("Couldn't open .");
		return -1;
	}

	int i = 0;
	struct node* root;
	
	if((dp = readdir(dirp)) != NULL){

		root = create_node(dp->d_name);
		
	}
	else {
		perror("couldn't open dir");
	}

	while (dp != NULL){
		if((dp = readdir(dirp)) != NULL){
			root = add_item(dp->d_name, root);
		}
		else {
			perror("couldn't open dir");
		}
	} 

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

	show_files(root);

	refresh();

	getch();

	endwin();

	clear_list(root);

	closedir(dirp);

	return 0;
	

}

void show_files(struct node* root){

	wprintw(stdscr,"%s\n", root->f_name);

	if(root->next_node){
		show_files(root->next_node);
	}
	else{
		refresh();
	}

}