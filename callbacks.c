#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include"agent.h"
#include"conshotel.h"



void
on_button_ajouteragent_clicked         (GtkButton       *objet,
                                        gpointer         user_data)
{
Agent a;
GtkWidget *input1,*input2,*input31,*input32,*input33,*input4,*input5,*input6,*input7,*input81,*input82,*input83,*input9,*input10,*input11;
GtkWidget *ajouter_agent;
int joure,moise,anneee,journ,moisn,anneen;
ajouter_agent=lookup_widget(objet,"ajouter_agent");

input1=lookup_widget(objet,"entrynomagent");
input2=lookup_widget(objet,"entryprenomagent");
input31=lookup_widget(objet,"spinbuttonjournai");
input32=lookup_widget(objet,"spinbuttonmoisnai");
input33=lookup_widget(objet,"spinbuttonanneenai");
input4=lookup_widget(objet,"entrycin");
input5=lookup_widget(objet,"entryadresse");
input6=lookup_widget(objet,"entryfonction");
input7=lookup_widget(objet,"entrytelephone");
input81=lookup_widget(objet,"spinbuttonjourem");
input82=lookup_widget(objet,"spinbuttonmoisem");
input83=lookup_widget(objet,"spinbuttonanneeem");
input9=lookup_widget(objet,"entrysalaire");
input10=lookup_widget(objet,"entrycivilite");


strcpy(a.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(a.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
journ=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input31));
moisn=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input32));
anneen=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input33));
a.cin=gtk_entry_get_text(GTK_ENTRY(input4));
strcpy(a.adresse,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(a.fonction,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(a.telephone,gtk_entry_get_text(GTK_ENTRY(input7)));
joure=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input81));
moise=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input82));
anneee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input83));
strcpy(a.salair,gtk_entry_get_text(GTK_ENTRY(input9)));
strcpy(a.civilite,gtk_entry_get_text(GTK_ENTRY(input10)));
a.naissance.jour=journ;
a.naissance.mois=moisn;
a.naissance.jour=anneen;
a.embauche.jour=joure;
a.embauche.mois=moise;
a.embauche.annee=anneee;

ajouteragent(a);
}


void
on_button_gestionagent_clicked         (GtkButton       *objet,
                                        gpointer         user_data)


{GtkWidget *admin_agent;
GtkWidget *interface_admin;
GtkWidget *treeview1;

admin_agent=lookup_widget(objet,"admin_agent");


gtk_widget_hide(interface_admin);
admin_agent=lookup_widget(objet,"admin_agent");
admin_agent=create_admin_agent();

gtk_widget_show(admin_agent);

treeview1=lookup_widget(admin_agent,"treeview1");

afficher_agent(treeview1);
}






void
on_button_Quitter_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_conshotel_clicked                   (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *listehotel;
GtkWidget *admin_convention;
GtkWidget *treeview2;

admin_convention=lookup_widget(objet,"admin_convention");


gtk_widget_hide(admin_convention);
listehotel=lookup_widget(objet,"listehotel");
listehotel=create_listehotel();

gtk_widget_show(listehotel);

treeview2=lookup_widget(listehotel,"treeview2");

afficher_hotel(treeview2);
}


void
on_consavion_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_consvoiture_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_conseorgan_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_consbus_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_consexcursions_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonajouterhotel_clicked          (GtkButton       *objet,
                                        gpointer         user_data)
{
conshotel hotel;

GtkWidget *input1, *input2, *input3,*input4,*input5,*input6,*input7;
GtkWidget *ajouterhotel;

ajouterhotel=lookup_widget(objet,"ajouterhotel");

input1=lookup_widget(objet,"entrylocalisationhotel");
input2=lookup_widget(objet,"entrynomhotel");
input3=lookup_widget(objet,"entrydatedb");
input4=lookup_widget(objet,"entrydatefin");
input5=lookup_widget(objet,"entrynbchombersing");
input6=lookup_widget(objet,"entrynbchomberdoubel");
input7=lookup_widget(objet,"entrynbchombertripl");

strcpy(hotel.localisation,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(hotel.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(hotel.datedb,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(hotel.datefin,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(hotel.nbchambersing,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(hotel.nbchamberdoubel,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(hotel.nbchambertripl,gtk_entry_get_text(GTK_ENTRY(input7)));

ajouter_hotel(hotel);

}
void
on_buttonajouterunhotel_clicked          (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *listehotel;
GtkWidget *ajouterhotel;

ajouterhotel=lookup_widget(objet,"ajouterhotel");


gtk_widget_hide(listehotel);
listehotel=lookup_widget(objet,"listehotel");
ajouterhotel=create_ajouterhotel();

gtk_widget_show(ajouterhotel);

}


void
on_button_ajoute_agent_clicked         (GtkButton       *objet,
                                        gpointer         user_data)

{
GtkWidget *admin_agent;
GtkWidget *ajouter_agent;

admin_agent=lookup_widget(objet,"admin_agent");


gtk_widget_hide(admin_agent);
ajouter_agent=lookup_widget(objet,"ajouter_agent");
ajouter_agent=create_ajouter_agent();

gtk_widget_show(ajouter_agent);
}


void
on_button_convention_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *admin_convention;
GtkWidget *interface_admin;

interface_admin=lookup_widget(button,"interface_admin");


gtk_widget_hide(interface_admin);
admin_convention=lookup_widget(button,"admin_convention");
admin_convention=create_admin_convention();

gtk_widget_show(admin_convention);
}


void
on_buttonrretour_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *admin_convention;
GtkWidget *listehotel;

listehotel=lookup_widget(button,"listehotel");


gtk_widget_hide(listehotel);
admin_convention=lookup_widget(button,"admin_convention");
admin_convention=create_admin_convention();

gtk_widget_show(admin_convention);
}


void
on_suprimerhotel_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *suprimhotel;
GtkWidget *listehotel;

listehotel=lookup_widget(button,"listehotel");


gtk_widget_hide(listehotel);
suprimhotel=lookup_widget(button,"suprimhotel");
suprimhotel=create_suprimhotel();

gtk_widget_show(suprimhotel);
}


void
on_supritionhotel_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *suprimhotel;
GtkWidget *listehotel;
GtkWidget *input;
conshotel hotel;
char nomhotel[20];
input=lookup_widget(button,"entry17");
strcpy(nomhotel,gtk_entry_get_text(GTK_ENTRY(input)));
supprimerhotel(nomhotel,hotel);

suprimhotel=lookup_widget(button,"suprimhotel");


gtk_widget_hide(suprimhotel);
listehotel=lookup_widget(button,"listehotel");
listehotel=create_listehotel();

gtk_widget_show(listehotel);
}


void
on_button_supprime_agent_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *admin_agent;
GtkWidget *suptitionagent;

admin_agent=lookup_widget(button,"admin_agent");


gtk_widget_hide(admin_agent);
suptitionagent=lookup_widget(button,"suptitionagent");
suptitionagent=create_supritionagent();

gtk_widget_show(suptitionagent);
}


void
on_supritionaget_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *admin_agent;
GtkWidget *suptitionagent;
GtkWidget *input;
Agent a;
int supagent;
input=lookup_widget(button,"entrynomagentsupri");
supagent=gtk_entry_get_text(GTK_ENTRY(input));
supprimeragent(supagent,a);

suptitionagent=lookup_widget(button,"suptitionagent");


gtk_widget_hide(suptitionagent);
admin_agent=lookup_widget(button,"admin_agent");
admin_agent=create_admin_agent();

gtk_widget_show(admin_agent);
}

