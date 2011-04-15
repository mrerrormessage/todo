#include "item.h"

void todo_item_callback( GtkWidget * checkbutton, gpointer data){
  
  todo_item_p ti = (todo_item_p) data;
  ti->completed = gtk_toggle_button_get_mode((GtkToggleButton *) checkbutton);

}

//initializes (allocates) a todo item with the description 
todo_item_p todo_item_init(const char * desc ){

  todo_item_p ti = (todo_item_p ) malloc( sizeof(struct todo_item) );
  //zero the struct
  memset(ti, 0, sizeof(struct todo_item));
  
  //malloc the string

  //get the checkbox struct
  GtkCheckButton * checkbox = (GtkCheckButton *) gtk_check_button_new_with_label( (gchar *) desc ); 

  ti->button = checkbox;
  
  //the completed field should be set to zero
  ti->completed = 0;

  gtk_signal_connect( GTK_OBJECT( checkbox ), "toggled", GTK_SIGNAL_FUNC( todo_item_callback) , ti);

  return ti;

}

//gets the checkbox from a todo_item
GtkCheckButton * todo_item_get_checkbutton( todo_item_p ti ){
  return ti->button;
}

//adds the checkbox to the end of a GtkBox
void todo_item_pack_end( todo_item_p ti, GtkBox * gb){
  GtkCheckButton * cb = ti->button;
  gtk_box_pack_end( gb, 
		    GTK_WIDGET( cb ), 
		    FALSE, 
		    FALSE, 
		    5 );
  gtk_widget_show( GTK_WIDGET( cb ) );
  return;
}

//frees a todo_item, returns the pointer to the next todo_item
todo_item_p todo_item_free(todo_item_p ti){
  
  gtk_widget_destroy( GTK_WIDGET( ti ) );
  todo_item_p next_ti = ti->next;
  free(ti);
  return next_ti;

}

//serializes a todo_item
char * todo_item_serialize( todo_item_p ti ){
  //gtk_button_get_label will be used here
  return NULL;
}

//reads a todo item from serialized form
void todo_item_read( char * s_ti){

}

void todo_item_set_next( todo_item_p ti, todo_item_p nti){
  ti->next = nti;
}


