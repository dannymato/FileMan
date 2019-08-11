#include <dirent.h>
#include <stdio.h>
#include <string.h>

int main(){

	DIR *dirp;
	struct dirent *dp;

	if ((dirp = opendir(".")) == NULL){
		perror("Couldn't open ~");
		return -1;
	}

	do{
		if((dp = readdir(dirp)) != NULL){
			printf ("Found %s\n", dp->d_name);
		}
		else {
			perror("couldn't open dir");
			return;
		}
	} while (dp != NULL);


	closedir(dirp);

	return 0;
	

}