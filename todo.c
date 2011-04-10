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
  GtkTextBuffer * tb; 
  GtkBox * box;

};

void build_add_item( struct add_item * ai , todo_list_p l , GtkTextBuffer * tb, GtkBox * b){
  ai->list = l;
  ai->tb = tb;
  ai->box = b;
  return;
}

/* the struct in data (above) is the GtkTextBuffer *, the vbox *, and the list * */
void AddRealNewItem( GtkWidget * addbutton, gpointer data){

  struct add_item * ai = (struct add_item *) data;
  
  GtkTextIter * text_beg;
  GtkTextIter * text_end;
  gtk_text_buffer_get_iter_at_offset( ai->tb,
				      text_beg,
				      0 );
  gtk_text_buffer_get_iter_at_offset( ai->tb,
				      text_end,
				      0 );
  gtk_text_iter_forward_to_end( text_end );
  gchar * description = gtk_text_buffer_get_text( ai->tb, text_beg, text_end, FALSE );

  todo_item_p ti = todo_item_init( description );
  todo_item_pack_end( ti, ai->box );

}

/* Data is the vbox that the new item needs to be created in */
void AddNewItem( GtkWidget *addbutton, gpointer data){
  
  GtkBox * gb = (GtkBox *) data;
  todo_item_p ti = todo_item_init( "hello world!");
  todo_item_pack_end( ti, gb );

}

int main( int argc, char ** argv){

  GtkBuilder * builder;
  GtkWidget * window;
  GtkWidget * button;
  GtkWidget * vbox;
  GtkTextBuffer * buf;
  struct add_item a;

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
  button = GTK_WIDGET ( gtk_builder_get_object( builder, "button1") );
  GtkTextBuffer * buffer = (GtkTextBuffer *) gtk_builder_get_object( builder, "textbuffer1") ;
  build_add_item( &a, NULL, (GtkTextBuffer *) buffer, (GtkBox *) vbox );

  //connect the signals here
  

  gtk_signal_connect (GTK_OBJECT (window), "delete_event", GTK_SIGNAL_FUNC(QuitProg), NULL);
  gtk_signal_connect( GTK_OBJECT (button), "clicked", GTK_SIGNAL_FUNC(AddRealNewItem), &a );

  //after signals connected
  gtk_builder_connect_signals( builder, NULL );

  //destroy builder
  g_object_unref( G_OBJECT( builder ) );

  //show and run
  gtk_widget_show( window );

  gtk_main();

  return( 0 );
}







