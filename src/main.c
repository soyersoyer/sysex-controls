#include "config.h"

#include <glib/gi18n.h>

#include "ks37-application.h"

int
main (int   argc,
      char *argv[])
{
	g_autoptr(Ks37Application) app = NULL;
	int ret;

	bindtextdomain (GETTEXT_PACKAGE, LOCALEDIR);
	bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
	textdomain (GETTEXT_PACKAGE);

	app = ks37_application_new ("hu.irl.keystep37-settings", G_APPLICATION_DEFAULT_FLAGS);
	ret = g_application_run (G_APPLICATION (app), argc, argv);

	return ret;
}

