#include <gtk/gtk.h>


void
on_hotels_clicked                      (GtkButton       *button,
                                        gpointer         user_data);

void
on_excurtions_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_voyages_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_location_voiture_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_location_bus_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_vols_clicked                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_compte_clicked                      (GtkButton       *button,
                                        gpointer         user_data);

void
on_valider_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_vols_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_hotels_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_excurtions_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_voyages_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_voiture_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_bus_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_ajouter_vols_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_modifier_vols_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_supprimer_vols_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_ajouter_hotels_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_modifier_hotels_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_supprimer_hotels_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_supprimer_excurtions_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_modifier_excurtions_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_ajouter_excurtions_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_ajouter_voyages_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_modifier_voyages_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_supprimer_voyages_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_supprimer_voitures_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_modifier_voitures_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_ajouter_voitures_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_supprimer_bus_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_modifier_bus_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_ajouter_bus_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview_vols_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_treeview_hotels_row_activated       (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_treeview_excurtions_row_activated   (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_treeview_voyages_row_activated      (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_treeview_voitures_row_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_treeview_bus_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_idchoose_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_idreturn_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_reservol_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_rvol_clicked                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_reserhotel_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_rhotel_clicked                      (GtkButton       *button,
                                        gpointer         user_data);

void
on_reserexcurtion_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_rexcurtion_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_reservoyage_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_rvoyage_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_reservoiture_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_rvoiture_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_reserbus_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_rbus_clicked                        (GtkButton       *button,
                                        gpointer         user_data);
