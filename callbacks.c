#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include"agent.h"
#include"conshotel.h"
#include"compteadmin.h"



void
on_button_ajouteragent_clicked         (GtkButton       *objet,
                                        gpointer         user_data)
{
Agent a;
GtkWidget *input1,*input2,*input31,*input32,*input33,*input4,*input5,*input6,*input7,*input81,*input82,*input83,*input9,*input10,*input11;
GtkWidget *ajouter_agent,*admin_agent,*treeview1;

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
a.naissance.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input31));
a.naissance.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input32));
a.naissance.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input33));
a.cin=atof(gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(a.adresse,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(a.fonction,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(a.telephone,gtk_entry_get_text(GTK_ENTRY(input7)));
a.embauche.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input81));
a.embauche.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input82));
a.embauche.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input83));
strcpy(a.salair,gtk_entry_get_text(GTK_ENTRY(input9)));
strcpy(a.civilite,gtk_entry_get_text(GTK_ENTRY(input10)));


ajouteragent(a);
gtk_widget_hide(ajouter_agent);
admin_agent=lookup_widget(objet,"admin_agent");
admin_agent=create_admin_agent();

gtk_widget_show(admin_agent);

treeview1=lookup_widget(admin_agent,"treeview1");

afficher_agent(treeview1);
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
GtkWidget *ajouter_agent;
GtkWidget *admin_agent;
GtkWidget *treeview1;

ajouter_agent=lookup_widget(button,"ajouter_agent");


gtk_widget_hide(ajouter_agent);
admin_agent=lookup_widget(button,"admin_agent");
admin_agent=create_admin_agent();

gtk_widget_show(admin_agent);
treeview1=lookup_widget(admin_agent,"treeview1");

afficher_agent(treeview1);
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
conshotel h;

GtkWidget *input1, *input2, *input31,*input32,*input33,*input41,*input42,*input43,*input5,*input6,*input7;
GtkWidget *ajouterhotel;

ajouterhotel=lookup_widget(objet,"ajouterhotel");

input1=lookup_widget(objet,"entrylocalisationhotel");
input2=lookup_widget(objet,"entrynomhotel");
input31=lookup_widget(objet,"spinbuttondbj");
input32=lookup_widget(objet,"spinbuttondbm");
input33=lookup_widget(objet,"spinbuttondba");
input41=lookup_widget(objet,"spinbuttonfinj");
input42=lookup_widget(objet,"spinbuttonfinm");
input43=lookup_widget(objet,"spinbuttonfina");
input5=lookup_widget(objet,"entrynbchombersing");
input6=lookup_widget(objet,"entrynbchomberdoubel");
input7=lookup_widget(objet,"entrynbchombertripl");

strcpy(h.lieu,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(h.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
h.datedb.j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input31));
h.datedb.m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input32));
h.datedb.a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input33));
h.datefin.j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input41));
h.datefin.m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input42));
h.datefin.a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input43));
h.nbchambersing=atof(gtk_entry_get_text(GTK_ENTRY(input5)));
h.nbchamberdoubel=atof(gtk_entry_get_text(GTK_ENTRY(input6)));
h.nbchambertripl=atof(gtk_entry_get_text(GTK_ENTRY(input7)));

ajouter_hotel(h);

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
GtkWidget *listehotel,*treeview2;
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
treeview2=lookup_widget(listehotel,"treeview2");

afficher_hotel(treeview2);
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

supagent=atof(gtk_entry_get_text(GTK_ENTRY(input)));
supprimeragent(supagent,a);

suptitionagent=lookup_widget(button,"suptitionagent");


gtk_widget_hide(suptitionagent);
admin_agent=lookup_widget(button,"admin_agent");
admin_agent=create_admin_agent();

gtk_widget_show(admin_agent);
}


void
on_button_compteadmin_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *compte_admin;
GtkWidget *interface_admin;

interface_admin=lookup_widget(button,"interface_admin");


gtk_widget_hide(interface_admin);
compte_admin=lookup_widget(button,"compte_admin");
compte_admin=create_compte_admin();

gtk_widget_show(compte_admin);
}


void
on_button_modifer_admin_clicked        (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *input1,*input2,*input3,*input4,*compte_admin;
char user[30];char apwd[30],npwd[30],cpwd[30];int t=-1;char erreur[]="erreur";
compte_admin=lookup_widget(objet,"compte_admin");
input1=lookup_widget(objet,"entrymodifiernomadmin");
input2=lookup_widget(objet,"entryancienpwd");
input3=lookup_widget(objet,"entrynvpwd");
input4=lookup_widget(objet,"entrycpwd");
strcpy(user,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(apwd,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(npwd,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(cpwd,gtk_entry_get_text(GTK_ENTRY(input4)));
if (strcmp(user,"")!=0)
{
modifnom(user);
}
t=verifpwd(apwd,npwd,cpwd);
if (t==0)
{modifpwd(npwd);}

}
void
on_button_quitte_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *compte_admin;
GtkWidget *interface_admin;

compte_admin=lookup_widget(button,"compte_admin");


gtk_widget_hide(compte_admin);
interface_admin=lookup_widget(button,"interface_admin");
interface_admin=create_interface_admin();

gtk_widget_show(interface_admin);
}


void
on_button_modifier_agent_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *admin_agent;
GtkWidget *modifieragent;

admin_agent=lookup_widget(button,"admin_agent");


gtk_widget_hide(admin_agent);
modifieragent=lookup_widget(button,"modifieragent");
modifieragent=create_modifieragent();
gtk_widget_show(modifieragent);
}


void
on_buttonmodifieragent_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *input;
GtkWidget *pmodifieragent;
GtkWidget *modifieragent,*nomagent,*prenomagent,*cina,*fonctiona,*adresseagent,*telephonea,*datenaissancej,*datenaissancem,*datenaissancea,*dateembauchj,*dateembauchm,*dateembaucha,*salaira,*civiliteagent;
Agent a;
int x;
char cinaux[20];
int id;
FILE *f,*h;
input=lookup_widget(button,"entrymodifagent");
x=atof(gtk_entry_get_text(GTK_ENTRY(input)));

if ((verifagent(x,a)))
{
modifieragent=lookup_widget(button,"modifieragent");
gtk_widget_destroy(modifieragent);

pmodifieragent=create_pmodifieragent();
gtk_widget_show(pmodifieragent);

f=fopen("agent.txt","r");

nomagent=lookup_widget(pmodifieragent,"entrynomagent");
prenomagent=lookup_widget(pmodifieragent,"entryprenomagent");
cina=lookup_widget(pmodifieragent,"entrycina");
fonctiona=lookup_widget(pmodifieragent,"entryfonctiona");
civiliteagent=lookup_widget(pmodifieragent,"entryciviliteagent");
salaira=lookup_widget(pmodifieragent,"entrysalairea");
adresseagent=lookup_widget(pmodifieragent,"entryadresseagent");
telephonea=lookup_widget(pmodifieragent,"entrytelephonea");
datenaissancej=lookup_widget(pmodifieragent,"spinbuttonjoura");
datenaissancem=lookup_widget(pmodifieragent,"spinbuttonmoisa");
datenaissancea=lookup_widget(pmodifieragent,"spinbuttonanneea");
dateembauchj=lookup_widget(pmodifieragent,"spinbuttonembauchj");
dateembauchm=lookup_widget(pmodifieragent,"spinbuttonembauchm");
dateembaucha=lookup_widget(pmodifieragent,"spinbuttonembauchea");

if(f!=NULL)
{while (fscanf(f,"%d %s %s %d/%d/%d %d %s %s %s %d/%d/%d %s %s\n",&a.matricule,a.nom,a.prenom,&a.naissance.jour,&a.naissance.mois,&a.naissance.annee,&a.cin,a.adresse,a.fonction,a.telephone,&a.embauche.jour,&a.embauche.mois,&a.embauche.annee,a.salair,a.civilite)!=EOF)
{if(x==a.matricule)
{
h=fopen("supid.txt","w+");
fprintf(h,"%d",a.matricule);
fclose(h);
gtk_entry_set_text(GTK_ENTRY(nomagent),a.nom);
gtk_entry_set_text(GTK_ENTRY(prenomagent),a.prenom);
gtk_entry_set_text(GTK_ENTRY(civiliteagent),a.civilite);
sprintf(cinaux,"%d\n",a.cin);
gtk_entry_set_text(GTK_ENTRY(cina),cinaux);
gtk_entry_set_text(GTK_ENTRY(fonctiona),a.fonction);
gtk_entry_set_text(GTK_ENTRY(adresseagent),a.adresse);
gtk_entry_set_text(GTK_ENTRY(salaira),a.salair);
gtk_entry_set_text(GTK_ENTRY(telephonea),a.telephone);
gtk_spin_button_set_value (GTK_SPIN_BUTTON(datenaissancej),a.naissance.jour);
gtk_spin_button_set_value (GTK_SPIN_BUTTON(datenaissancem),a.naissance.mois);
gtk_spin_button_set_value (GTK_SPIN_BUTTON(datenaissancea),a.naissance.annee);
gtk_spin_button_set_value (GTK_SPIN_BUTTON(dateembauchj),a.embauche.jour);
gtk_spin_button_set_value (GTK_SPIN_BUTTON(dateembauchm),a.embauche.mois);
gtk_spin_button_set_value (GTK_SPIN_BUTTON(dateembaucha),a.embauche.annee);




}}}}fclose(f);

}


void
on_button_modifragent_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *admin_agent;
GtkWidget *pmodifieragent;
GtkWidget *treeview1, *nomagent,*prenomagent,*cina,*fonctiona,*adresseagent,*telephonea,*datenaissancej,*datenaissancem,*datenaissancea,*dateembauchj,*dateembauchm,*dateembaucha,*salaira,*civiliteagent;
Agent a;
int id,x;
char cinaux[20];
FILE *f,*h;

nomagent=lookup_widget(button,"entrynomagent");
prenomagent=lookup_widget(button,"entryprenomagent");
cina=lookup_widget(button,"entrycina");
fonctiona=lookup_widget(button,"entryfonctiona");
civiliteagent=lookup_widget(button,"entryciviliteagent");
salaira=lookup_widget(button,"entrysalairea");
adresseagent=lookup_widget(button,"entryadresseagent");
telephonea=lookup_widget(button,"entrytelephonea");
datenaissancej=lookup_widget(button,"spinbuttonjoura");
datenaissancem=lookup_widget(button,"spinbuttonmoisa");
datenaissancea=lookup_widget(button,"spinbuttonanneea");
dateembauchj=lookup_widget(button,"spinbuttonembauchj");
dateembauchm=lookup_widget(button,"spinbuttonembauchm");
dateembaucha=lookup_widget(button,"spinbuttonembauchea");

strcpy(a.nom,gtk_entry_get_text(GTK_ENTRY(nomagent)));
strcpy(a.prenom,gtk_entry_get_text(GTK_ENTRY(prenomagent)));
strcpy(a.civilite,gtk_entry_get_text(GTK_ENTRY(civiliteagent)));
strcpy(cinaux,gtk_entry_get_text(GTK_ENTRY(cina)));
a.cin=atof(cinaux);
strcpy(a.fonction,gtk_entry_get_text(GTK_ENTRY(fonctiona)));
strcpy(a.adresse,gtk_entry_get_text(GTK_ENTRY(adresseagent)));
strcpy(a.salair,gtk_entry_get_text(GTK_ENTRY(salaira)));
strcpy(a.telephone,gtk_entry_get_text(GTK_ENTRY(telephonea)));

a.naissance.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(datenaissancej));
a.naissance.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(datenaissancem));
a.naissance.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(datenaissancea));
a.embauche.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(dateembauchj));
a.embauche.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(dateembauchm));
a.embauche.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(dateembaucha));
if (h!=NULL)
{h=fopen("supid.txt","r");
while(fscanf(h,"%d\n",&id)!=EOF){
x=id;}
fclose(h);}
supprimeragent(x,a);
a.matricule=x;
f=fopen("agent.txt","a+");
fprintf(f,"%d %s %s %d/%d/%d %d %s %s %s %d/%d/%d %s %s\n",a.matricule,a.nom,a.prenom,a.naissance.jour,a.naissance.mois,a.naissance.annee,a.cin,a.adresse,a.fonction,a.telephone,a.embauche.jour,a.embauche.mois,a.embauche.annee,a.salair,a.civilite);

fclose(f);
pmodifieragent=lookup_widget(button,"pmodifieragent");
gtk_widget_hide(pmodifieragent);
admin_agent=lookup_widget(button,"admin_agent");
admin_agent=create_admin_agent();
gtk_widget_show(admin_agent);
treeview1=lookup_widget(admin_agent,"treeview1");
afficher_agent(treeview1);
}


void
on_buttonmofierhotel_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonmodifier_hotel_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_retourlisteagent_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *admin_agent;
GtkWidget *interface_admin;

admin_agent=lookup_widget(button,"admin_agent");


gtk_widget_hide(admin_agent);
interface_admin=lookup_widget(button,"interface_admin");
interface_admin=create_interface_admin();
gtk_widget_show(interface_admin);
}


void
on_bouttonretourlisteconv_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *admin_convention;
GtkWidget *interface_admin;

admin_convention=lookup_widget(button,"admin_convention");


gtk_widget_hide(admin_convention);
interface_admin=lookup_widget(button,"interface_admin");
interface_admin=create_interface_admin();
gtk_widget_show(interface_admin);
}


void
on_buttonrelistehotel_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{

}

