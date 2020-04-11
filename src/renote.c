#include <string.h>
#include <gtk/gtk.h>

int main(int argc, char **argv) {

  GtkBuilder *ribbon_builder;
  GError *error = NULL;

  GtkApplication *app;
  GtkWidget *window;
  GtkWidget *widget_ribbon;

  gtk_init(&argc, &argv);


  app = gtk_application_new ("thesleort.renote", G_APPLICATION_FLAGS_NONE);
  ribbon_builder = gtk_builder_new();

  if (gtk_builder_add_from_file(ribbon_builder, "ribbon.ui", &error) == 0) {
    g_printerr("Error loading file: %s\n", error->message);
    g_clear_error(&error);
    return 1;
  }

  window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "Renote");
  gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);


  widget_ribbon = GTK_WIDGET(gtk_builder_get_object(ribbon_builder, "ribbon"));

  gtk_container_add(GTK_CONTAINER(window), widget_ribbon);

  gtk_widget_show_all(window);
  gtk_main();

  return 0;
}