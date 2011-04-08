//code by Robert Grider
//Mar 11, 2010

#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "list.h"

void on_add_item( GtkWidget * addbutton, gpointer data);
void on_item_complete( GtkWidget * checkbutton, gpointer data);
void add_new_task( struct todo_state * ts, char * description);
struct todo_state* init_todo_state();

gint QuitProg(GtkWidget *widget, gpointer gdata){

    gtk_main_quit();
    return (FALSE);

}

int main( int argc, char ** argv){

  GtkBuilder * builder;
  GtkWidget * window;
  GtkWidget * button;
  GtkWidget * vbox;
  GtkTextBuffer * buf;

  GError * error = NULL;
  
  //initializations
  gtk_init( &argc, &argv);
  builder = gtk_builder_new();

  if( ! gtk_builder_add_from_file(builder, "todo2.glade", &error) ){
    g_warning( "%s", error->message);
    g_free( error );
    return(1);
  }

  //get objects here and put them in the todo structure
  window = GTK_WIDGET ( gtk_builder_get_object(builder, "window1" ) );
  vbox = GTK_WIDGET ( gtk_builder_get_object(builder, "vbox3") );
  
  //connect the signals here
  

  gtk_signal_connect (GTK_OBJECT (window), "delete_event", GTK_SIGNAL_FUNC(QuitProg), NULL);

  //after signals connected
  gtk_builder_connect_signals( builder, NULL );

  //destroy builder
  g_object_unref( G_OBJECT( builder ) );

  //show and run
  gtk_widget_show( window );

  gtk_main();

  return( 0 );
}

//the gpointer needs to point to the todo_state
void on_add_item( GtkWidget * addbutton, gpointer data){
  
}

void add_new_task( struct todo_state * ts, char * description);
struct todo_state* init_todo_state();



