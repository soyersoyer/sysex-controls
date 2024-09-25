#include "config.h"

#include "ks37-application.h"
#include "ks37-window.h"
#include "ks37-midi.h"

struct _Ks37Application
{
	AdwApplication parent_instance;
};

G_DEFINE_FINAL_TYPE (Ks37Application, ks37_application, ADW_TYPE_APPLICATION)

Ks37Application *
ks37_application_new (const char        *application_id,
                      GApplicationFlags  flags)
{
	g_return_val_if_fail (application_id != NULL, NULL);

	return g_object_new (KS37_TYPE_APPLICATION,
	                     "application-id", application_id,
	                     "flags", flags,
	                     NULL);
}

static void
ks37_application_activate (GApplication *app)
{
	GtkWindow *window;

	g_assert (KS37_IS_APPLICATION (app));

	window = gtk_application_get_active_window (GTK_APPLICATION (app));

	if (window == NULL)
		window = g_object_new (KS37_TYPE_WINDOW,
		                       "application", app,
		                       NULL);

	gtk_window_present (window);
}

static void
ks37_application_class_init (Ks37ApplicationClass *klass)
{
	GApplicationClass *app_class = G_APPLICATION_CLASS (klass);

	app_class->activate = ks37_application_activate;
}

static void
ks37_application_about_action (GSimpleAction *action,
                               GVariant      *parameter,
                               gpointer       user_data)
{
	static const char *developers[] = {"Gergo Koteles <soyer@irl.hu>", NULL};
	Ks37Application *self = user_data;
	GtkWindow *window = NULL;

	g_assert (KS37_IS_APPLICATION (self));

	window = gtk_application_get_active_window (GTK_APPLICATION (self));

	adw_show_about_dialog (GTK_WIDGET (window),
	                       "application-name", "KeyStep37 Settings",
	                       "application-icon", "hu.irl.keystep37-settings",
	                       "version", "0.1.0",
	                       "website", "https://github.com/soyersoyer/keystep37-settings",
	                       "issue-url", "https://github.com/soyersoyer/keystep37-settings/issues",
	                       "license-type", GTK_LICENSE_GPL_3_0,
	                       "developer-name", "Gergo Koteles",
	                       "developers", developers,
	                       "copyright", "© 2024 Gergo Koteles",
	                       NULL);
}

static void
ks37_application_quit_action (GSimpleAction *action,
                              GVariant      *parameter,
                              gpointer       user_data)
{
	Ks37Application *self = user_data;

	g_assert (KS37_IS_APPLICATION (self));

	g_application_quit (G_APPLICATION (self));
}

static const GActionEntry app_actions[] = {
	{ "quit", ks37_application_quit_action },
	{ "about", ks37_application_about_action },
};

static void
ks37_application_init (Ks37Application *self)
{
	g_action_map_add_action_entries (G_ACTION_MAP (self),
	                                 app_actions,
	                                 G_N_ELEMENTS (app_actions),
	                                 self);
	gtk_application_set_accels_for_action (GTK_APPLICATION (self),
	                                       "app.quit",
	                                       (const char *[]) { "<primary>q", NULL });
}

