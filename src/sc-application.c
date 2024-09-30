#include "config.h"

#include "sc-application.h"
#include "sc-window.h"
#include "sc-midi.h"

struct _ScApplication
{
  AdwApplication parent_instance;
};

G_DEFINE_FINAL_TYPE (ScApplication, sc_application, ADW_TYPE_APPLICATION)

ScApplication *
sc_application_new (const char        *application_id,
                    GApplicationFlags  flags)
{
  g_return_val_if_fail (application_id != NULL, NULL);

  return g_object_new (SC_TYPE_APPLICATION,
                       "application-id", application_id,
                       "flags", flags,
                       NULL);
}

static void
sc_application_activate (GApplication *app)
{
  GtkWindow *window;

  g_assert (SC_IS_APPLICATION (app));

  window = gtk_application_get_active_window (GTK_APPLICATION (app));

  if (window == NULL)
    window = g_object_new (SC_TYPE_WINDOW,
                           "application", app,
                           NULL);

  gtk_window_present (window);
}

static void
sc_application_class_init (ScApplicationClass *klass)
{
  GApplicationClass *app_class = G_APPLICATION_CLASS (klass);

  app_class->activate = sc_application_activate;
}

static void
sc_application_about_action (GSimpleAction *action,
                             GVariant      *parameter,
                             gpointer       user_data)
{
  static const char *developers[] = {"Gergo Koteles <soyer@irl.hu>", NULL};
  ScApplication *self = user_data;
  GtkWindow *window = NULL;

  g_assert (SC_IS_APPLICATION (self));

  window = gtk_application_get_active_window (GTK_APPLICATION (self));

  adw_show_about_dialog (GTK_WIDGET (window),
                         "application-name", "SysEx Controls",
                         "application-icon", "hu.irl.sysex-controls",
                         "version", PACKAGE_VERSION,
                         "website", "https://github.com/soyersoyer/sysex-controls",
                         "issue-url", "https://github.com/soyersoyer/sysex-controls/issues",
                         "license-type", GTK_LICENSE_GPL_3_0,
                         "developer-name", "Gergo Koteles",
                         "developers", developers,
                         "copyright", "© 2024 Gergo Koteles",
                         NULL);
}

static void
sc_application_quit_action (GSimpleAction *action,
                            GVariant      *parameter,
                            gpointer       user_data)
{
  ScApplication *self = user_data;

  g_assert (SC_IS_APPLICATION (self));

  g_application_quit (G_APPLICATION (self));
}

static const GActionEntry app_actions[] = {
  { "quit", sc_application_quit_action },
  { "about", sc_application_about_action },
};

static void
sc_application_init (ScApplication *self)
{
  g_action_map_add_action_entries (G_ACTION_MAP (self),
                                   app_actions,
                                   G_N_ELEMENTS (app_actions),
                                   self);
  gtk_application_set_accels_for_action (GTK_APPLICATION (self),
                                         "app.quit",
                                         (const char *[]) { "<primary>q", NULL });
}

