#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "adherent.h"


void
on_buttonconsulteradherent_clicked     (GtkButton       *objet,
                                        gpointer         user_data)
{GtkWidget *consulteradherent;
GtkWidget *menuadmin;
GtkWidget *treeview1;

menuadmin=lookup_widget(objet,"menuadmin");
gtk_widget_destroy(menuadmin);

consulteradherent=lookup_widget(objet,"consulteradherent");

consulteradherent=create_consulteradherent();
gtk_widget_show(consulteradherent);

treeview1=lookup_widget(consulteradherent,"treeview1");
afficher_adherent(treeview1);
}


void
on_buttonajouteradherent_clicked       (GtkButton       *objet,
                                        gpointer         user_data)
{GtkWidget *ajouteradherent;
GtkWidget *consulteradherent;


consulteradherent=lookup_widget(objet,"consulteradherent");
gtk_widget_destroy(consulteradherent);

ajouteradherent=create_ajouteradherent();
gtk_widget_show(ajouteradherent);



}


void
on_buttonmodifieradherent_clicked      (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *consulteradherent;
GtkWidget *choixadherentamodifier;

consulteradherent=lookup_widget(objet,"consulteradherent");
gtk_widget_destroy(consulteradherent);

choixadherentamodifier=create_choixadherentamodifier();
gtk_widget_show(choixadherentamodifier);
}


void
on_buttonsupprimeradherent_clicked     (GtkButton       *objet,
                                        gpointer         user_data)
{GtkWidget *supprimeradherent;
GtkWidget *consulteradherent;

consulteradherent=lookup_widget(objet,"consulteradherent");
gtk_widget_destroy(consulteradherent);

supprimeradherent=lookup_widget(objet,"supprimeradherent");
supprimeradherent=create_supprimeradherent();
gtk_widget_show(supprimeradherent);

}


void
on_buttonretourversmenuadmin_clicked   (GtkButton       *objet,
                                        gpointer         user_data)
{GtkWidget *consulteradherent;
GtkWidget *menuadmin;
consulteradherent=lookup_widget(objet,"consulteradherent");
gtk_widget_destroy(consulteradherent);

menuadmin=lookup_widget(objet,"menuadmin");
menuadmin=create_menuadmin();
gtk_widget_show(menuadmin);

}


void
on_buttonenregistreradherent_clicked   (GtkButton       *objet,
                                        gpointer         user_data)
{GtkWidget *input1, *input2, *input3, *input4, *input5, *input6, *input7, *input8, *input9, *input10,*input11;
GtkWidget *ajouteradherent;
GtkWidget *consulteradherent;
GtkWidget *treeview1;
adherent ad;
char cin[20];
char tel[20];
ajouteradherent=lookup_widget(objet,"ajouteradherent");

input1=lookup_widget(objet,"entrynom");
input2=lookup_widget(objet,"entryprenom");
input3=lookup_widget(objet,"entrycin");
input4=lookup_widget(objet,"entrymail");
input5=lookup_widget(objet,"entryadresse");
input6=lookup_widget(objet,"entrytelephone");
input7=lookup_widget(objet,"jours");
input8=lookup_widget(objet,"mois");
input9=lookup_widget(objet,"annee");
input10=lookup_widget(objet,"entryusername");
input11=lookup_widget(objet,"entrypassword");

strcpy(ad.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(ad.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input3)));
ad.cin=atof(cin);
strcpy(ad.email,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(ad.adresse,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(tel,gtk_entry_get_text(GTK_ENTRY(input6)));
ad.telephone=atof(tel);
ad.datenaissance.j=gtk_spin_button_get_value(GTK_SPIN_BUTTON(input7));
ad.datenaissance.m=gtk_spin_button_get_value(GTK_SPIN_BUTTON(input8));
ad.datenaissance.a=gtk_spin_button_get_value(GTK_SPIN_BUTTON(input9));
strcpy(ad.username,gtk_entry_get_text(GTK_ENTRY(input10)));
strcpy(ad.password,gtk_entry_get_text(GTK_ENTRY(input11)));

ajouter_adherent(ad);

ajouteradherent=lookup_widget(objet,"ajouteradherent");
gtk_widget_destroy(ajouteradherent);


consulteradherent=create_consulteradherent();
gtk_widget_show(consulteradherent);

treeview1=lookup_widget(consulteradherent,"treeview1");
afficher_adherent(treeview1);
}



void
on_buttonretourversconsulteradherent_clicked
                                        (GtkButton       *objet,
                                        gpointer         user_data)
{GtkWidget *consulteradherent;
GtkWidget *ajouteradherent;
GtkWidget *treeview1;

ajouteradherent=lookup_widget(objet,"ajouteradherent");
gtk_widget_destroy(ajouteradherent);


consulteradherent=create_consulteradherent();
gtk_widget_show(consulteradherent);
treeview1=lookup_widget(consulteradherent,"treeview1");
afficher_adherent(treeview1);
}


void
on_buttonvalidersupressionadherent_clicked
                                        (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *input;
GtkWidget *supprimeradherent;
GtkWidget *consulteradherent;
GtkWidget *treeview1;
adherent ad;
int a;
input=lookup_widget(objet,"entryid");
a=atof(gtk_entry_get_text(GTK_ENTRY(input)));
supprimer_adherent(a,ad);
supprimeradherent=lookup_widget(objet,"supprimeradherent");
gtk_widget_destroy(supprimeradherent);

consulteradherent=lookup_widget(objet,"consulteradherent");
consulteradherent=create_consulteradherent();
gtk_widget_show(consulteradherent);
treeview1=lookup_widget(consulteradherent,"treeview1");
afficher_adherent(treeview1);
}




void
on_buttonenregistermodif_clicked       (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *modifadherent,*ID,*nom,*prenom,*cin,*email,*adresse,*telephone,*datenaissancej,*datenaissancem,*datenaissancea,*username,*password;
GtkWidget *consulteradherent,*treeview1;
adherent ad;
char id[5];
char cinaux[20],telaux[20];
FILE *f;
ID=lookup_widget(objet,"ID_fix");
nom=lookup_widget(objet,"entrymodifnom");
prenom=lookup_widget(objet,"entrymodifprenom");
cin=lookup_widget(objet,"entrymodifcin");
email=lookup_widget(objet,"entrymodifmail");
adresse=lookup_widget(objet,"entrymodifadresse");
telephone=lookup_widget(objet,"entrymodiftelephone");
datenaissancej=lookup_widget(objet,"modifjours");
datenaissancem=lookup_widget(objet,"modifmois");
datenaissancea=lookup_widget(objet,"modifannee");
username=lookup_widget(objet,"entrymodifusername");
password=lookup_widget(objet,"entrymodifpassword");

strcpy(id,gtk_entry_get_text(GTK_ENTRY(ID)));

ad.id=atof(id);

strcpy(ad.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(ad.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));


strcpy(cinaux,gtk_entry_get_text(GTK_ENTRY(cin)));
ad.cin=atof(cinaux);

strcpy(ad.email,gtk_entry_get_text(GTK_ENTRY(email)));
strcpy(ad.adresse,gtk_entry_get_text(GTK_ENTRY(adresse)));


strcpy(telaux,gtk_entry_get_text(GTK_ENTRY(telephone)));
ad.telephone=atof(telaux);

ad.datenaissance.j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(datenaissancej));
ad.datenaissance.m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(datenaissancem));
ad.datenaissance.a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(datenaissancea));
strcpy(ad.username,gtk_entry_get_text(GTK_ENTRY(username)));
strcpy(ad.password,gtk_entry_get_text(GTK_ENTRY(password)));

supprimer_adherent(atof(id),ad);
f=fopen("adherent.txt","a+");
fprintf(f,"%d %s %s %d %s %s %d %d/%d/%d %s %s\n",ad.id,ad.nom,ad.prenom,ad.cin,ad.email,ad.adresse,ad.telephone,ad.datenaissance.j,ad.datenaissance.m,ad.datenaissance.a,ad.username,ad.password);

fclose(f);
modifadherent=lookup_widget(objet,"modifadherent");
gtk_widget_destroy(modifadherent);
consulteradherent=lookup_widget(objet,"consulteradherent");
consulteradherent=create_consulteradherent();
gtk_widget_show(consulteradherent);
treeview1=lookup_widget(consulteradherent,"treeview1");
afficher_adherent(treeview1);
}



void
on_buttonretourmodifversconsulteradherent_clicked
                                        (GtkButton       *objet,
                                        gpointer         user_data)
{
}


void
on_buttonretoursupprimerversconsulteradherent_clicked
                                        (GtkButton       *objet,
                                        gpointer         user_data)
{GtkWidget *consulteradherent;
GtkWidget *supprimeradherent;
GtkWidget *treeview1;
supprimeradherent=lookup_widget(objet,"supprimeradherent");
gtk_widget_destroy(supprimeradherent);

consulteradherent=lookup_widget(objet,"consulteradherent");
consulteradherent=create_consulteradherent();
gtk_widget_show(consulteradherent);
treeview1=lookup_widget(consulteradherent,"treeview1");
afficher_adherent(treeview1);

}


void
on_buttonstatistique_clicked           (GtkButton       *objet,
                                        gpointer         user_data)
{GtkWidget *consulteradherent;
GtkWidget *menuadmin;
GtkWidget *treeview1;

menuadmin=lookup_widget(objet,"menuadmin");
gtk_widget_destroy(menuadmin);

consulteradherent=lookup_widget(objet,"consulteradherent");

consulteradherent=create_consulteradherent();
gtk_widget_show(consulteradherent);

treeview1=lookup_widget(consulteradherent,"treeview1");
afficher_adherent(treeview1);
}





void
on_buttonretourduchoixusernameversconsulteradherent_clicked
                                        (GtkButton       *objet,
                                        gpointer         user_data)
{GtkWidget *choixadherentamodifier;
GtkWidget *consulteradherent;
GtkWidget *treeview1;
choixadherentamodifier=lookup_widget(objet,"choixadherentamodifier");
gtk_widget_destroy(choixadherentamodifier);
consulteradherent=lookup_widget(objet,"consulteradherent");
consulteradherent=create_consulteradherent();
gtk_widget_show(consulteradherent);
treeview1=lookup_widget(consulteradherent,"treeview1");
afficher_adherent(treeview1);

}





void
on_buttonchoixid_clicked               (GtkButton       *objet,
                                        gpointer         user_data)
{GtkWidget *input;
GtkWidget *choixadherentamodifier;
GtkWidget *modifadherent,*nom,*prenom,*cin,*email,*adresse,*telephone,*datenaissancej,*datenaissancem,*datenaissancea,*username,*password,*ID;
adherent ad;
int x;
char cinaux[20],telaux[20];
char id[5];
FILE *f;
input=lookup_widget(objet,"entrychoixid");
x=atof(gtk_entry_get_text(GTK_ENTRY(input)));

if ((verif(x,ad)))
{
choixadherentamodifier=lookup_widget(objet,"choixadherentamodifier");
gtk_widget_destroy(choixadherentamodifier);

modifadherent=lookup_widget(objet,"modifadherent");
modifadherent=create_modifadherent();
gtk_widget_show(modifadherent);

f=fopen("adherent.txt","r");
ID=lookup_widget(modifadherent,"ID_fix");
nom=lookup_widget(modifadherent,"entrymodifnom");
prenom=lookup_widget(modifadherent,"entrymodifprenom");
cin=lookup_widget(modifadherent,"entrymodifcin");
email=lookup_widget(modifadherent,"entrymodifmail");
adresse=lookup_widget(modifadherent,"entrymodifadresse");
telephone=lookup_widget(modifadherent,"entrymodiftelephone");
datenaissancej=lookup_widget(modifadherent,"modifjours");
datenaissancem=lookup_widget(modifadherent,"modifmois");
datenaissancea=lookup_widget(modifadherent,"modifannee");
username=lookup_widget(modifadherent,"entrymodifusername");
password=lookup_widget(modifadherent,"entrymodifpassword");
if(f!=NULL)
{while (fscanf(f,"%d %s %s %d %s %s %d %d/%d/%d %s %s\n",&ad.id,ad.nom,ad.prenom,&ad.cin,ad.email,ad.adresse,&ad.telephone,&ad.datenaissance.j,&ad.datenaissance.m,&ad.datenaissance.a,ad.username,ad.password)!=EOF)
{if(x==ad.id)
{
sprintf(id,"%d",ad.id);
gtk_entry_set_text(GTK_ENTRY(ID),id);
gtk_entry_set_text(GTK_ENTRY(nom),ad.nom);
gtk_entry_set_text(GTK_ENTRY(prenom),ad.prenom);
sprintf(cinaux,"%d",ad.cin);
gtk_entry_set_text(GTK_ENTRY(cin),cinaux);
gtk_entry_set_text(GTK_ENTRY(email),ad.email);
gtk_entry_set_text(GTK_ENTRY(adresse),ad.adresse);
sprintf(telaux,"%d",ad.telephone);
gtk_entry_set_text(GTK_ENTRY(telephone),telaux);
gtk_spin_button_set_value (GTK_SPIN_BUTTON(datenaissancej),ad.datenaissance.j);
gtk_spin_button_set_value (GTK_SPIN_BUTTON(datenaissancem),ad.datenaissance.m);
gtk_spin_button_set_value (GTK_SPIN_BUTTON(datenaissancea),ad.datenaissance.a);
gtk_entry_set_text(GTK_ENTRY(username),ad.username);
gtk_entry_set_text(GTK_ENTRY(password),ad.password);

}}}}fclose(f);

}


void
on_buttonretourmodifverschoixadherentamodifier_clicked
                                        (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *modifadherent;
GtkWidget *choixadherentamodifier;

modifadherent=lookup_widget(objet,"modifadherent");
gtk_widget_destroy(modifadherent);
choixadherentamodifier=lookup_widget(objet,"choixadherentamodifier");
choixadherentamodifier=create_choixadherentamodifier();
gtk_widget_show(choixadherentamodifier);
}

