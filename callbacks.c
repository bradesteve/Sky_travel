#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "vols.h"
#include "hotels.h"
#include "excurtions.h"
#include "voyages.h"
#include "voitures.h"
#include "bus.h"

void
on_hotels_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *AGENT;
GtkWidget *HOTELS;
GtkWidget *treeview_hotels;

AGENT=lookup_widget(button,"AGENT");


gtk_widget_destroy(AGENT);
HOTELS=lookup_widget(button,"HOTELS");
HOTELS=create_HOTELS();

gtk_widget_show(HOTELS);

treeview_hotels=lookup_widget(HOTELS,"treeview_hotels");

afficher_hotelR(treeview_hotels);


}


void
on_excurtions_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *AGENT;
GtkWidget *EXCURTIONS;
GtkWidget *treeview_excurtions;

AGENT=lookup_widget(button,"AGENT");


gtk_widget_destroy(AGENT);
EXCURTIONS=lookup_widget(button,"EXCURTIONS");
EXCURTIONS=create_EXCURTIONS();

gtk_widget_show(EXCURTIONS);

treeview_excurtions=lookup_widget(EXCURTIONS,"treeview_excurtions");

afficher_excurtionR(treeview_excurtions);


}


void
on_voyages_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *AGENT;
GtkWidget *VOYAGES;
GtkWidget *treeview_voyages;

AGENT=lookup_widget(button,"AGENT");


gtk_widget_destroy(AGENT);
VOYAGES=lookup_widget(button,"VOYAGES");
VOYAGES=create_VOYAGES();

gtk_widget_show(VOYAGES);

treeview_voyages=lookup_widget(VOYAGES,"treeview_voyages");

afficher_voyageR(treeview_voyages);

}


void
on_location_voiture_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *AGENT;
GtkWidget *LOCATION_VOITURES;
GtkWidget *treeview_voitures;

AGENT=lookup_widget(button,"AGENT");


gtk_widget_destroy(AGENT);
LOCATION_VOITURES=lookup_widget(button,"LOCATION_VOITURES");
LOCATION_VOITURES=create_LOCATION_VOITURES();

gtk_widget_show(LOCATION_VOITURES);

treeview_voitures=lookup_widget(LOCATION_VOITURES,"treeview_voitures");

afficher_voitureR(treeview_voitures);
}


void
on_location_bus_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *AGENT;
GtkWidget *LOCATION_BUS;
GtkWidget *treeview_bus;

AGENT=lookup_widget(button,"AGENT");


gtk_widget_destroy(AGENT);
LOCATION_BUS=lookup_widget(button,"LOCATION_BUS");
LOCATION_BUS=create_LOCATIONS_BUS();

gtk_widget_show(LOCATION_BUS);

treeview_bus=lookup_widget(LOCATION_BUS,"treeview_bus");

afficher_busR(treeview_bus);

}


void
on_vols_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *AGENT;
GtkWidget *VOLS;
GtkWidget *treeview_vols;

AGENT=lookup_widget(button,"AGENT");


gtk_widget_destroy(AGENT);
VOLS=lookup_widget(button,"VOLS");
VOLS=create_VOLS();

gtk_widget_show(VOLS);

treeview_vols=lookup_widget(VOLS,"treeview_vols");

afficher_volR(treeview_vols);
}


void
on_compte_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *AGENT;
GtkWidget *COMPTE;


AGENT=lookup_widget(button,"AGENT");


gtk_widget_destroy(AGENT);
COMPTE=lookup_widget(button,"COMPTE");
COMPTE=create_COMPTE();

gtk_widget_show(COMPTE);

}


void
on_valider_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_retour_vols_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *AGENT, *VOLS;

VOLS=lookup_widget(button,"VOLS");

gtk_widget_destroy(VOLS);
AGENT=create_AGENT();
gtk_widget_show(AGENT);


}

void
on_retour_hotels_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *AGENT, *HOTELS;

HOTELS=lookup_widget(button,"HOTELS");

gtk_widget_destroy(HOTELS);
AGENT=create_AGENT();
gtk_widget_show(AGENT);


}

void
on_retour_excurtions_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *AGENT, *EXCURTIONS;

EXCURTIONS=lookup_widget(button,"EXCURTIONS");

gtk_widget_destroy(EXCURTIONS);
AGENT=create_AGENT();
gtk_widget_show(AGENT);


}

void
on_retour_voyages_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *AGENT, *VOYAGES;

VOYAGES=lookup_widget(button,"VOYAGES");

gtk_widget_destroy(VOYAGES);
AGENT=create_AGENT();
gtk_widget_show(AGENT);


}

void
on_retour_voiture_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *AGENT, *LOCATION_VOITURES;

LOCATION_VOITURES=lookup_widget(button,"LOCATION_VOITURES");

gtk_widget_destroy(LOCATION_VOITURES);
AGENT=create_AGENT();
gtk_widget_show(AGENT);


}

void
on_retour_bus_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *AGENT, *LOCATION_BUS;

LOCATION_BUS=lookup_widget(button,"LOCATION_BUS");

gtk_widget_destroy(LOCATION_BUS);
AGENT=create_AGENT();
gtk_widget_show(AGENT);


}


void
on_ajouter_vols_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
volR v;

GtkWidget *input1, *input2, *input3, *input4, *input5, *input6, *input7, *input8, *input9, *input10;*input11, *input12, *input13;
GtkWidget *VOLS;

VOLS=lookup_widget(button,"VOLS");

input1=lookup_widget(button,"id");
input2=lookup_widget(button,"nom");
input3=lookup_widget(button,"depart");
input4=lookup_widget(button,"retour");
input5=lookup_widget(button,"date_depart.jour");
input6=lookup_widget(button,"date_depart.mois");
input7=lookup_widget(button,"date_depart.annee");
input8=lookup_widget(button,"date_retour.jour");
input9=lookup_widget(button,"date_retour.mois");
input10=lookup_widget(button,"date_retourt.annee");
input11=lookup_widget(button,"name");
input12=lookup_widget(button,"prenom");
input13=lookup_widget(button,"cin");


v.id=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input1));
strcpy(v.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(v.depart,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(v.retour,gtk_entry_get_text(GTK_ENTRY(input4)));
v.d_depart.j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Jour));
v.d_depart.j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Jour));
strcpy(v.date_depart.annee,gtk_entry_get_text(GTK_ENTRY(input7)));
strcpy(v.date_retour.jour,gtk_entry_get_text(GTK_ENTRY(input8)));
strcpy(v.date_retour.mois,gtk_entry_get_text(GTK_ENTRY(input9)));
strcpy(v.date_retour.annee,gtk_entry_get_text(GTK_ENTRY(input10)));
strcpy(v.name,gtk_entry_get_text(GTK_ENTRY(input11)));
strcpy(v.prenom,gtk_entry_get_text(GTK_ENTRY(input12)));
strcpy(v.cin,gtk_entry_get_text(GTK_ENTRY(input13)));

ajouter_volR(v);

}

}


void
on_modifier_vols_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_supprimer_vols_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ajouter_hotels_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
hotelR h;

GtkWidget *input1, *input2, *input3, *input4, *input5, *input6, *input7, *input8, *input9, *input10;*input11, *input12, *input13, *input14, *input15;
GtkWidget *HOTELS;

HOTELS=lookup_widget(button,"HOTELS");

input1=lookup_widget(button,"id");
input2=lookup_widget(button,"nom");
input3=lookup_widget(button,"lieu");
input4=lookup_widget(button,"date_in.jour");
input5=lookup_widget(button,"date_in.mois");
input6=lookup_widget(button,"date_in.annee");
input7=lookup_widget(button,"date_out.jour");
input8=lookup_widget(button,"date_out.mois");
input9=lookup_widget(button,"date_out.annee");
input10=lookup_widget(button,"nb_single");
input11=lookup_widget(button,"nb_double");
input12=lookup_widget(button,"nb_triple");
input13=lookup_widget(button,"name");
input14=lookup_widget(button,"prenom");
input15=lookup_widget(button,"cin");



strcpy(h.id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(h.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(h.lieu,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(h.date_in.jour,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(h.date_in.mois,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(h.date_in.annee,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(h.date_out.jour,gtk_entry_get_text(GTK_ENTRY(input7)));
strcpy(h.date_out.mois,gtk_entry_get_text(GTK_ENTRY(input8)));
strcpy(h.date_out.annee,gtk_entry_get_text(GTK_ENTRY(input9)));
strcpy(h.nb_single,gtk_entry_get_text(GTK_ENTRY(input10)));
strcpy(h.nb_double,gtk_entry_get_text(GTK_ENTRY(input11)));
strcpy(h.nb_triple,gtk_entry_get_text(GTK_ENTRY(input12)));
strcpy(h.name,gtk_entry_get_text(GTK_ENTRY(input13)));
strcpy(h.prenom,gtk_entry_get_text(GTK_ENTRY(input14)));
strcpy(h.cin,gtk_entry_get_text(GTK_ENTRY(input15)));

ajouter_hotelR(h);

}


void
on_modifier_hotels_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_supprimer_hotels_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_supprimer_excurtions_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_modifier_excurtions_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ajouter_excurtions_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
excurtionR ex;

GtkWidget *input1, *input2, *input3, *input4, *input5, *input6, *input7, *input8, *input9, *input10;*input11, *input12, *input13;
GtkWidget *EXCURTIONS;

EXCURTIONS=lookup_widget(button,"EXCRTIONS");

input1=lookup_widget(button,"id");
input2=lookup_widget(button,"nom");
input3=lookup_widget(button,"description");
input4=lookup_widget(button,"d_excurtion.jour");
input5=lookup_widget(button,"d_excurtion.mois");
input6=lookup_widget(button,"d_excurtion.annee");
input7=lookup_widget(button,"H_depart.heure");
input8=lookup_widget(button,"H_depart.minute");
input9=lookup_widget(button,"H_arrivee.heure");
input10=lookup_widget(button,"H_arrivee.minute");
input11=lookup_widget(button,"name");
input12=lookup_widget(button,"prenom");
input13=lookup_widget(button,"cin");


strcpy(ex.id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(ex.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(ex.description,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(ex.d_excurtion.jour,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(ex.d_excurtion.mois,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(ex.d_excurtion.annee,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(ex.h_depart.heure,gtk_entry_get_text(GTK_ENTRY(input7)));
strcpy(ex.h_depart.minute,gtk_entry_get_text(GTK_ENTRY(input8)));
strcpy(ex.h_arrivee.heure,gtk_entry_get_text(GTK_ENTRY(input9)));
strcpy(ex.h_arrivee.minute,gtk_entry_get_text(GTK_ENTRY(input10)));
strcpy(ex.name,gtk_entry_get_text(GTK_ENTRY(input11)));
strcpy(ex.prenom,gtk_entry_get_text(GTK_ENTRY(input12)));
strcpy(ex.cin,gtk_entry_get_text(GTK_ENTRY(input13)));

ajouter_excurtionR(ex);


}


void
on_ajouter_voyages_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
voyageR vo;

GtkWidget *input1, *input2, *input3, *input4, *input5, *input6, *input7, *input8, *input9, *input10;*input11, *input12, *input13;
GtkWidget *VOYAGES;

VOYAGES=lookup_widget(button,"VOYAGES");

input1=lookup_widget(button,"id");
input2=lookup_widget(button,"nom");
input3=lookup_widget(button,"description");
input4=lookup_widget(button,"d_voyage.jour");
input5=lookup_widget(button,"d_voyage.mois");
input6=lookup_widget(button,"d_voyage.annee");
input7=lookup_widget(button,"H_depart.heure");
input8=lookup_widget(button,"H_depart.minute");
input9=lookup_widget(button,"H_arrivee.heure");
input10=lookup_widget(button,"H_arrivee.minute");
input11=lookup_widget(button,"name");
input12=lookup_widget(button,"prenom");
input13=lookup_widget(button,"cin");


strcpy(vo.id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(vo.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(vo.description,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(vo.d_voyage.jour,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(vo.d_voyage.mois,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(vo.d_voyage.annee,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(vo.h_depart.heure,gtk_entry_get_text(GTK_ENTRY(input7)));
strcpy(vo.h_depart.minute,gtk_entry_get_text(GTK_ENTRY(input8)));
strcpy(vo.h_arrivee.heure,gtk_entry_get_text(GTK_ENTRY(input9)));
strcpy(vo.h_arrivee.minute,gtk_entry_get_text(GTK_ENTRY(input10)));
strcpy(vo.name,gtk_entry_get_text(GTK_ENTRY(input11)));
strcpy(vo.prenom,gtk_entry_get_text(GTK_ENTRY(input12)));
strcpy(vo.cin,gtk_entry_get_text(GTK_ENTRY(input13)));

ajouter_voyageR(vo);

}


void
on_modifier_voyages_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_supprimer_voyages_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_supprimer_voitures_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_modifier_voitures_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ajouter_voitures_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
voitureR vi;

GtkWidget *input1, *input2, *input3, *input4, *input5, *input6, *input7, *input8, *input9, *input10;*input11, *input12, *input13, *input14, *input15;
GtkWidget *VOITURES;

VOITURES=lookup_widget(button,"VOITURES");

input1=lookup_widget(button,"id");
input2=lookup_widget(button,"lieu");
input3=lookup_widget(button,"date_prise.jour");
input4=lookup_widget(button,"date_prise.mois");
input5=lookup_widget(button,"date_prise.annee");
input6=lookup_widget(button,"date_retour.jour");
input7=lookup_widget(button,"date_retour.mois");
input8=lookup_widget(button,"date_retour.annee");
input9=lookup_widget(button,"h_depart.heure");
input10=lookup_widget(button,"h_depart.minute");
input11=lookup_widget(button,"h_arrivee.heure");
input12=lookup_widget(button,"h_arrivee.minute");
input13=lookup_widget(button,"name");
input14=lookup_widget(button,"prenom");
input15=lookup_widget(button,"cin");


strcpy(vi.id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(vi.lieu,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(vi.date_prise.jour,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(vi.date_prise.mois,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(vi.date_prise.annee,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(vi.date_retour.jour,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(vi.date_retour.mois,gtk_entry_get_text(GTK_ENTRY(input7)));
strcpy(vi.date_retour.annee,gtk_entry_get_text(GTK_ENTRY(input8)));
strcpy(vi.h_depart.heure,gtk_entry_get_text(GTK_ENTRY(input9)));
strcpy(vi.h_depart.minute,gtk_entry_get_text(GTK_ENTRY(input10)));
strcpy(vi.h_arrivee.heure,gtk_entry_get_text(GTK_ENTRY(input11)));
strcpy(vi.h_arrivee.minute,gtk_entry_get_text(GTK_ENTRY(input12)));
strcpy(vi.name,gtk_entry_get_text(GTK_ENTRY(input13)));
strcpy(vi.prenom,gtk_entry_get_text(GTK_ENTRY(input14)));
strcpy(vi.cin,gtk_entry_get_text(GTK_ENTRY(input15
)));

ajouter_voitureR(vi);


}


void
on_supprimer_bus_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_modifier_bus_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ajouter_bus_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
busR bu;

GtkWidget *input1, *input2, *input3, *input4, *input5, *input6, *input7, *input8, *input9, *input10;*input11, *input12, *input13, *input14, *input15;
GtkWidget *BUS;

BUS=lookup_widget(button,"BUS");

input1=lookup_widget(button,"id");
input2=lookup_widget(button,"lieu");
input3=lookup_widget(button,"date_prise.jour");
input4=lookup_widget(button,"date_prise.mois");
input5=lookup_widget(button,"date_prise.annee");
input6=lookup_widget(button,"date_retour.jour");
input7=lookup_widget(button,"date_retour.mois");
input8=lookup_widget(button,"date_retour.annee");
input9=lookup_widget(button,"h_depart.heure");
input10=lookup_widget(button,"h_depart.minute");
input11=lookup_widget(button,"h_arrivee.heure");
input12=lookup_widget(button,"h_arrivee.minute");
input13=lookup_widget(button,"name");
input14=lookup_widget(button,"prenom");
input15=lookup_widget(button,"cin");


strcpy(bu.id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(bu.lieu,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(bu.date_prise.jour,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(bu.date_prise.mois,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(bu.date_prise.annee,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(bu.date_retour.jour,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(bu.date_retour.mois,gtk_entry_get_text(GTK_ENTRY(input7)));
strcpy(bu.date_retour.annee,gtk_entry_get_text(GTK_ENTRY(input8)));
strcpy(bu.h_depart.heure,gtk_entry_get_text(GTK_ENTRY(input9)));
strcpy(bu.h_depart.minute,gtk_entry_get_text(GTK_ENTRY(input10)));
strcpy(bu.h_arrivee.heure,gtk_entry_get_text(GTK_ENTRY(input11)));
strcpy(bu.h_arrivee.minute,gtk_entry_get_text(GTK_ENTRY(input12)));
strcpy(bu.name,gtk_entry_get_text(GTK_ENTRY(input13)));
strcpy(bu.prenom,gtk_entry_get_text(GTK_ENTRY(input14)));
strcpy(bu.cin,gtk_entry_get_text(GTK_ENTRY(input15
)));

ajouter_busR(bu);


}







void
on_reservol_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_rvol_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_reserhotel_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_rhotel_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_reserexcurtion_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_rexcurtion_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_reservoyage_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_rvoyage_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_reservoiture_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_rvoiture_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_reserbus_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_rbus_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{

}

