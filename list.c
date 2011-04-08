#include "list.h"

//initializes a todo list
todo_list_p todo_list_init(){

  todo_list_p tl = (todo_list_p ) malloc( sizeof(struct todo_list));
  memset(tl, 0, sizeof(struct todo_list));
  return tl;

}

//frees/destroys a todo list
void todo_list_free( todo_list_p tl){

}

//serializes a todo list
char* todo_list_serialize( todo_list_p tl){

}

//reads a todo list
todo_list_p todo_list_read( todo_list_p tl){

}

//adds a new item to the todo list
void todo_list_add( todo_list_p tl, char * desc ){

  todo_item_p ti = todo_item_init( desc );

  //add to the head of the list
  todo_item_set_next(ti, tl->head);
  tl->head = ti;
  return;

}


//removes an item from the todo list
void todo_list_remove( todo_list_p tl, todo_item_p ti){

}


