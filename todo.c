//code by Robert Grider
//Mar 11, 2010

#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "list.h"

gint QuitProg(GtkWidget *widget, gpointer gdata){

    gtk_main_quit();
    return (FALSE);

}

struct add_item{

  todo_list_p list;
  GtkEntryBuffer * tb; 
  GtkBox * box;

};

void build_add_item( struct add_item * ai , todo_list_p l , GtkEntryBuffer * tb, GtkBox * b){
  ai->list = l;
  ai->tb = tb;
  ai->box = b;
  return;
}

/* the struct in data (above) is the GtkTextBuffer *, the vbox *, and the list * */
void AddRealNewItem( GtkWidget * addbutton, gpointer data){

  struct add_item * ai = (struct add_item *) data;
 
  const char * description = gtk_entry_buffer_get_text( ai->tb );
  todo_item_p ti = todo_item_init( description );
  todo_item_pack_end( ti, ai->box );
  //probably need to free description
  //then clear the entry_buffer
}

/* Data is the vbox that the new item needs to be created in 
void AddNewItem( GtkWidget *addbutton, gpointer data){
  
  GtkBox * gb = (GtkBox *) data;
  todo_item_p ti = todo_item_init( "hello world!");
  todo_item_pack_end( ti, gb );

  } */

int main( int argc, char ** argv){

  GtkBuilder * builder;
  GtkWidget * window;
  GtkWidget * button;
  GtkWidget * vbox;
  GtkWidget * textentry;
  struct add_item a;

  GError * error = NULL;
  
  //initializations
  gtk_init( &argc, &argv);
  builder = gtk_builder_new();

  if( ! gtk_builder_add_from_file(builder, "todo.gtkb", &error) ){
    g_warning( "%s", error->message);
    g_free( error );
    return(1);
  }

  //get objects here and put them in the todo structure
  window = GTK_WIDGET ( gtk_builder_get_object(builder, "window1" ) );
  vbox = GTK_WIDGET ( gtk_builder_get_object(builder, "vbox3") );
  button = GTK_WIDGET ( gtk_builder_get_object( builder, "button1") );
  textentry = GTK_WIDGET ( gtk_builder_get_object( builder, "entry1") );
  //this must be AFTER gtk_init
  GtkEntryBuffer * buf = gtk_entry_buffer_new( "type" , 4 );
  
  gtk_entry_set_buffer( (GtkEntry *) textentry, buf );
  build_add_item( &a, NULL, (GtkEntryBuffer *) buf, (GtkBox *) vbox );

  //connect the signals here
  gtk_signal_connect (GTK_OBJECT (window), "delete_event", GTK_SIGNAL_FUNC(QuitProg), NULL);
  gtk_signal_connect( GTK_OBJECT (button), "clicked", GTK_SIGNAL_FUNC(AddRealNewItem), &a );

  //after signals connected
  gtk_builder_connect_signals( builder, NULL );

  //destroy builder
  g_object_unref( G_OBJECT( builder ) );

  //show and run
  gtk_widget_show( GTK_WIDGET( window ) );

  gtk_main();

  return( 0 );
}







