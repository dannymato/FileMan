#ifndef LList
#define LList


struct node {

	char* f_name;

	struct node* next_node;

	char is_selected;

};

struct node* create_list(char*);
struct node* add_item(char*, struct node*);
struct node* create_node(char*);
void clear_list(struct node*);
struct node* sort(struct node*);

#endif