#include <stdio.h>
#include <stdlib.h>

struct node {

	char* f_name;

	struct node* next_node;

};


struct node* create_list(char* fName){

	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	new_node->f_name = fName;
	new_node->next_node = NULL;
	
	return new_node;
}

struct node* add_item(char* fName, struct node* root){

	if(root == NULL){

		root->f_name = fName;
		root->next_node = NULL;

		return root;

	}

	else if(root->next_node == NULL){

		struct node* douglas;
		douglas->f_name = fName;
		douglas->next_node = NULL;
		root->next_node = douglas;

		return root;		

	}

	else{

		add_item(fName, root->next_node);
		return root;

	}


}