#ifndef _TODO_LIST_H_
#define _TODO_LIST_H_

#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

struct todo_list{

  struct todo_item * head;

};

typedef struct todo_list * todo_list_p;

//initializes a todo list
todo_list_p todo_list_init();

//frees/destroys a todo list
void todo_list_free( todo_list_p );

//serializes a todo list
char* todo_list_serialize( todo_list_p );

//reads a todo list
todo_list_p todo_list_read( todo_list_p );

//adds a new item to the head of the todo list
void todo_list_add( todo_list_p , char * desc );

//removes an item from the todo list
void todo_list_remove( todo_list_p tl, todo_item_p ti);

#endif
