#include <gtk/gtk.h>

static GtkWidget *_g_window;

static void _button_callback(GtkWidget *midget, gpointer data)
{
    GtkWidget *dialog;

    dialog = gtk_message_dialog_new(GTK_WINDOW(_g_window), GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "Hello this is a dialog!");
    g_signal_connect_swapped(dialog, "response", G_CALLBACK(gtk_widget_destroy), dialog);
    gtk_widget_show(dialog);
}

static void _activate(GtkApplication *app, gpointer user_date)
{
    _g_window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(_g_window), "hi this is a window");
    gtk_window_set_default_size(GTK_WINDOW(_g_window), 800, 600);

    GtkWidget *button_box;
    
    button_box = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
    gtk_container_add(GTK_CONTAINER(_g_window), button_box);

    GtkWidget *button;

    button = gtk_button_new_with_label("button");
    g_signal_connect(button, "clicked", G_CALLBACK(_button_callback), NULL);
    gtk_container_add(GTK_CONTAINER(button_box), button);

    gtk_widget_show_all(_g_window);
}

int main(int argc, char **argv)
{
    GtkApplication *app;
    int status;

    app = gtk_application_new("com.moltony.gtkapp", G_APPLICATION_FLAGS_NONE); // Create the app
    g_signal_connect(app, "activate", G_CALLBACK(_activate), NULL); // Run _activate on activate
    status = g_application_run(G_APPLICATION(app), argc, argv); // Run the app
    g_object_unref(app); // Unref (destroy) the app

    return status;
}
