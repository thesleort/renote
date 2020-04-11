#include <string.h>
#include <gtk/gtk.h>

int main(int argc, char **argv) {

  GtkBuilder *ribbon_builder;
  GError *error;

  GtkWindow *window;
  GtkWidget *widget_ribbon;

  gtk_init(&argc, &argv);

  ribbon_builder = gtk_builder_new();

  if (gtk_builder_add_from_file(ribbon_builder, "gui/ribbon.glade", &error) == 0) {
    g_printerr("Error loading file: %s\n", error->message);
    g_clear_error(&error);
    return 1;
  }

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);


  widget_ribbon = gtk_builder_get_object(ribbon_builder, "ribbon");

  gtk_container_add(window, widget_ribbon);

  gtk_main();

  return 0;
}