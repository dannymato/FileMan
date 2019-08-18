#include <stdio.h>
#include <stdlib.h>
#include "LList.h"
#include <string.h>
#include <ctype.h>



struct node* create_list(char* fName){

	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	new_node->f_name = fName;
	new_node->next_node = NULL;
	
	return new_node;
}

struct node* add_item(char* fName, struct node* root){

	if(root == NULL){

		return create_node(fName);

	}

	else if(root->next_node == NULL){

		
		root->next_node = create_node(fName);

		return root;		

	}

	else if(is_before(fName, root->f_name) > 0 && is_before(fName, root->next_node->f_name) < 0){


		struct node* temp = root->next_node;

		root->next_node = create_node(fName);
		root->next_node->next_node = temp;

		return root;
		
	}

	


	else{

		add_item(fName, root->next_node);
		return root;

	}

}

struct node* create_node(char* fName){

	struct node* new_node = (struct node*)malloc(sizeof(struct node));

	new_node->f_name = fName;
	new_node->next_node = NULL;
	new_node->is_selected = 0;

	return new_node;

}

void clear_list(struct node* root){

	if (root->next_node){
		clear_list(root->next_node);
	}
	else{
		free(root);
	}

}


int is_before(char* this, char* that){

	return strcmp(this, that);

}

char* lower(char* elem){

	char* temp = elem;

	int i = 0;

	while(temp[i] != '\0'){

		if(isalpha(temp[i])){
			tolower(temp[i]);
		}

		i++;
	
	}

	return temp;

}