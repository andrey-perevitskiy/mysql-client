#ifndef DATA_H
#define DATA_H

#include <gtk/gtk.h>
#include <mysql.h>

/* data which will passed everywhere auxiliary object is needed */
struct wrapped_data {
	GObject *object;
	gpointer data;
};

struct server_data {
	GtkWidget *host;
	GtkWidget *username;
	GtkWidget *password;
	GList *servers_list; /* keep array of the server structures */
	MYSQL *con;

	/* extra */
	GtkTreeView *servers_view;
	GtkListStore *servers_store;
};

/* Server structure. It needs for appending data on the list.
 * It's data will used for create connection when user
 * want connect to the server from servers list. */
struct server {
	gchar *host;
	gchar *username;
	gchar *password;
	gchar *name;
};

struct selection_data {
	GtkTreeSelection *selection;
	MYSQL *con;
};

struct args_data {
	const gchar *host;
	const gchar *username;
	const gchar *password;
};

#endif /* DATA_H */
