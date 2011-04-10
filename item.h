#ifndef _ITEM_H_
#define _ITEM_H_

#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>

struct todo_item{

  GtkCheckButton * button;
  gint callback_id;
  struct todo_item * next;
  int completed;

};

typedef struct todo_item * todo_item_p;

//initializes (allocates) a todo item with the description 
todo_item_p todo_item_init(const char * desc );

//frees a todo_item, returning the item in the list after it
todo_item_p todo_item_free(todo_item_p);

//gets the checkbox from a todo_item
GtkCheckButton * todo_item_get_checkbutton( todo_item_p );

//adds the checkbox to the end of a GtkBox
void todo_item_pack_end( todo_item_p , GtkBox * );

//serializes a todo_item
char * todo_item_serialize( todo_item_p );

//reads a todo item from serialized form
void todo_item_read( char * );

//set the next item
void todo_item_set_next( todo_item_p , todo_item_p );

#endif
