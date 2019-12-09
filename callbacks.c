#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <stdlib.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include <string.h>
#include "voyorg.h"
#include "exc.h"


void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *menuadmin;
GtkWidget *treevoyorg;
GtkWidget *treeview1;

menuadmin= lookup_widget(button,"menuadmin");
gtk_widget_destroy(menuadmin);

treevoyorg=lookup_widget(button,"treevoyorg");
treevoyorg=create_treevoyorg();
gtk_widget_show(treevoyorg);
treeview1=lookup_widget(treevoyorg,"treeview1");
afficher_voyorg(treeview1);

}


void
on_button2_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *treevoyorg,*ajoutervoyorg;
treevoyorg=lookup_widget(button,"treevoyorg");
gtk_widget_destroy(treevoyorg);
ajoutervoyorg=create_ajoutervoyorg();
gtk_widget_show(ajoutervoyorg);

}


void
on_modifieradmin_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_supprimeradmin_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *treevoyorg;
GtkWidget *choixidsupp;
treevoyorg=lookup_widget(button,"treevoyorg");
gtk_widget_destroy(treevoyorg);
choixidsupp=lookup_widget(button,"choixidsupp");
choixidsupp=create_choixidsupp();
gtk_widget_show(choixidsupp);

}


void
on_retouradmin_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *menuadmin, *treevoyorg;
treevoyorg=lookup_widget(button,"treevoyorg");
gtk_widget_destroy(treevoyorg);
menuadmin= lookup_widget(button,"menuadmin");
menuadmin=create_menuadmin();
gtk_widget_show(menuadmin);
}


void
on_validerajoutervoyorg_clicked        (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*input7;
GtkWidget *ajoutervoyorg;
GtkWidget *treeview1;
GtkWidget *treevoyorg;
vor vo;
ajoutervoyorg=lookup_widget(objet,"ajoutervoyorg");
input1=lookup_widget(objet,"ajoutdestination");
input2=lookup_widget(objet,"joursd");
input3=lookup_widget(objet,"moisd");
input4=lookup_widget(objet,"anneed");
input5=lookup_widget(objet,"joursr");
input6=lookup_widget(objet,"moisr");
input7=lookup_widget(objet,"anneer");
strcpy(vo.destination,gtk_entry_get_text(GTK_ENTRY(input1)));
vo.d_depart.j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input2));
vo.d_depart.m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input3));
vo.d_depart.a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
vo.d_retour.j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));
vo.d_retour.m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
vo.d_retour.a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input7));
ajouter_voyorg(vo);
ajoutervoyorg=lookup_widget(objet,"ajoutervoyorg");
gtk_widget_destroy(ajoutervoyorg);

treevoyorg=create_treevoyorg();
gtk_widget_show(treevoyorg);

treeview1=lookup_widget(treevoyorg,"treeview1");
afficher_voyorg(treeview1);
}


void
on_retourajoutversmenuadmin_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonidmodifvoyorg_clicked         (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *input,*destination,*jd,*md,*ad,*jr,*mr,*ar,*ID;
GtkWidget *modifvoyorg;
GtkWidget *choixidmodif;
vor vo;
int x;
char id[5];
FILE *f;

input=lookup_widget(objet,"entryidvoyorg");
x=atof(gtk_entry_get_text(GTK_ENTRY(input)));

if(verif(x,vo))
{modifvoyorg=lookup_widget(objet,"modifvoyorg");
modifvoyorg=create_modifvoyorg();
gtk_widget_show(modifvoyorg);
f=fopen("voyorg.txt","r");
ID=lookup_widget(modifvoyorg,"ID_Fixx");
destination=lookup_widget(modifvoyorg,"entrymodifdestination");
jd=lookup_widget(modifvoyorg,"modifjoursd");
md=lookup_widget(modifvoyorg,"modifmoisd");
ad=lookup_widget(modifvoyorg,"modifanneed");

jr=lookup_widget(modifvoyorg,"modifjoursr");
mr=lookup_widget(modifvoyorg,"modifmoisr");
ar=lookup_widget(modifvoyorg,"modifanneer");
if(f!=NULL)
{while (fscanf(f,"%d %s  %d/%d/%d %d/%d/%d\n",&vo.id,vo.destination,&vo.d_depart.j,&vo.d_depart.m,&vo.d_depart.a,&vo.d_retour.j,&vo.d_retour.m,&vo.d_retour.a)!=EOF)
{if(x==vo.id)
{sprintf(id,"%d",x);
gtk_entry_set_text(GTK_ENTRY(ID),id);
gtk_entry_set_text(GTK_ENTRY(destination),vo.destination);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(jd),vo.d_depart.j);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(md),vo.d_depart.m);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(ad),vo.d_depart.a);

gtk_spin_button_set_value(GTK_SPIN_BUTTON(jr),vo.d_retour.j);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(mr),vo.d_retour.m);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(ar),vo.d_retour.a);
}}}}fclose(f);
}

void
on_buttonidmodifretourtree_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *idmodif, *treeexc;
idmodif=lookup_widget(button,"idmodif");
gtk_widget_destroy(idmodif);
treeexc= lookup_widget(button,"treeexc");
treeexc=create_treeexc();
gtk_widget_show(treeexc);
}


void
on_buttonchoixidsuppvoyorg_clicked     (GtkButton       *objet,
                                        gpointer         user_data)
{GtkWidget *input;
GtkWidget *treevoyorg;
GtkWidget *treeview1;
GtkWidget *choixidsupp;
vor vo;
int a;
input=lookup_widget(objet,"entryidsupprimer");
a=atof(gtk_entry_get_text(GTK_ENTRY(input)));
choixidsupp=lookup_widget(objet,"choixidsupp");
gtk_widget_destroy(choixidsupp);
supprimer_voyorg(a,vo);


treevoyorg=lookup_widget(objet,"treevoyorg");
treevoyorg=create_treevoyorg();
gtk_widget_show(treevoyorg);
treeview1=lookup_widget(treevoyorg,"treeview1");
afficher_voyorg(treeview1);
}


void
on_buttonidsuppverstree_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *idsupp, *treeexc;
idsupp=lookup_widget(button,"idsupp");
gtk_widget_destroy(idsupp);
treeexc= lookup_widget(button,"treeexc");
treeexc=create_treeexc();
gtk_widget_show(treeexc);
}


void
on_buttonmodifretourverschoixid_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonenregmodifvoyorg_clicked      (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *modifvoyorg,*ID,*destination,*d_d_j,*d_d_m,*d_d_a,*d_r_j,*d_r_m,*d_r_a;
GtkWidget *treevoyorg,*treeview1;
vor vo;
char id[5];

FILE *f;
ID=lookup_widget(objet,"ID_Fixx");
destination=lookup_widget(objet,"entrymodifdestination");

d_d_j=lookup_widget(objet,"modifjoursd");
d_d_m=lookup_widget(objet,"modifmoisd");
d_d_a=lookup_widget(objet,"modifanneed");

d_r_j=lookup_widget(objet,"modifjoursr");
d_r_m=lookup_widget(objet,"modifmoisr");
d_r_a=lookup_widget(objet,"modifanneer");

strcpy(id,gtk_entry_get_text(GTK_ENTRY(ID)));

vo.id=atof(id);

strcpy(vo.destination,gtk_entry_get_text(GTK_ENTRY(destination)));

vo.d_depart.j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(d_d_j));
vo.d_depart.m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(d_d_m));
vo.d_depart.a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(d_d_a));

vo.d_retour.j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(d_r_j));
vo.d_retour.m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(d_r_m));
vo.d_retour.a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(d_r_a));

supprimer_voyorg(atof(id),vo);
f=fopen("voyorg.txt","a+");
fprintf(f,"%d %s  %d/%d/%d %d/%d/%d\n",vo.id,vo.destination,vo.d_depart.j,vo.d_depart.m,vo.d_depart.a,vo.d_retour.j,vo.d_retour.m,vo.d_retour.a);
fclose(f);
modifvoyorg=lookup_widget(objet,"modifvoyorg");
gtk_widget_destroy(modifvoyorg);

treevoyorg=lookup_widget(objet,"treevoyorg");
treevoyorg=create_treevoyorg();
gtk_widget_show(treevoyorg);
treeview1=lookup_widget(treevoyorg,"treeview1");
afficher_voyorg(treeview1);
}



void
on_modifexc_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *idmodif;
GtkWidget *treeexc;

treeexc=lookup_widget(button, "treeexc");
gtk_widget_destroy(treeexc);

idmodif=create_idmodif();
gtk_widget_show(idmodif);
}


void
on_supexc_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeexc;
GtkWidget *idsupp;
treeexc=lookup_widget(button,"treeexc");
gtk_widget_destroy(treeexc);
idsupp=lookup_widget(button,"idsupp");
idsupp=create_idsupp();
gtk_widget_show(idsupp);

}


void
on_ajoutexc_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeexc,*ajouterexc;
treeexc=lookup_widget(button,"treeexc");
gtk_widget_destroy(treeexc);
ajouterexc=create_ajouterexc();
gtk_widget_show(ajouterexc);

}



void
on_choixidsuppexc_clicked              (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *input;
GtkWidget *treeexc;
GtkWidget *treeview2;
GtkWidget *idsupp;
exc vo;
int a;
input=lookup_widget(objet,"entryidsupp");
a=atof(gtk_entry_get_text(GTK_ENTRY(input)));
idsupp=lookup_widget(objet,"idsupp");
gtk_widget_destroy(idsupp);
supprimer_exc(a,vo);


treeexc=lookup_widget(objet,"treeexc");
treeexc=create_treeexc();
gtk_widget_show(treeexc);
treeview2=lookup_widget(treeexc,"treeview2");
afficher_exc(treeview2);
}


void
on_idsuppverstree_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *idsupp, *treeexc, *treeview2;
idsupp=lookup_widget(button,"idsupp");
gtk_widget_destroy(idsupp);
treeexc= lookup_widget(button,"treeexc");
treeexc=create_treeexc();
gtk_widget_show(treeexc);
treeview2=lookup_widget(treeexc,"treeview2");
afficher_exc(treeview2);
}


void
on_choixidmodifexc_clicked             (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *input;
GtkWidget *destination;
GtkWidget *hd,*md,*hr,*mr,*ID;
GtkWidget *modifexc, *idmodif;

exc ex;
int x;
char id[5];
FILE *f;

input=lookup_widget(objet,"entryidmodif");
x=atof(gtk_entry_get_text(GTK_ENTRY(input)));

if((verifexc(x,ex)))
{

idmodif=lookup_widget(objet,"idmodif");
gtk_widget_destroy(idmodif);

modifexc=lookup_widget(objet,"modifexc");
modifexc=create_modifexc();
gtk_widget_show(modifexc);

f=fopen("exc.txt","r");
ID=lookup_widget(modifexc,"ID_Fixe");
destination=lookup_widget(modifexc,"entrymodifdestinationexc");

hd=lookup_widget(modifexc,"heuredmodifier");
md=lookup_widget(modifexc,"mindmodifier");

hr=lookup_widget(modifexc,"heurermodifier");
mr=lookup_widget(modifexc,"heurermodifier");

if(f!=NULL)
{while (fscanf(f,"%d %s %dh%d %dh%d\n" , &ex.id, ex.destination, &ex.h_depart.h, &ex.h_depart.m, &ex.h_retour.h, &ex.h_retour.m)!=EOF)
{if (x==ex.id)
{sprintf(id,"%d",x);
gtk_entry_set_text(GTK_ENTRY(ID),id);
gtk_entry_set_text(GTK_ENTRY(destination),ex.destination);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(hd),ex.h_depart.h);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(md),ex.h_depart.m);

gtk_spin_button_set_value(GTK_SPIN_BUTTON(hr),ex.h_retour.h);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(mr),ex.h_retour.m);

}}
}
}fclose(f);
}


void
on_idmodifverstree_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *idmodif, *treeexc, *treeview2;
idmodif=lookup_widget(button,"idmodif");
gtk_widget_destroy(idmodif);
treeexc= lookup_widget(button,"treeexc");
treeexc=create_treeexc();
gtk_widget_show(treeexc);
treeview2=lookup_widget(treeexc,"treeview2");
afficher_exc(treeview2);
}


void
on_validerajoutexc_clicked             (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *input1,*input2,*input3,*input4,*input5;
GtkWidget *ajouterexc;
GtkWidget *treeview2;
GtkWidget *treeexc;
exc ex;
ajouterexc=lookup_widget(objet,"ajouterexc");
input1=lookup_widget(objet,"destinationexc");
input2=lookup_widget(objet,"heured");
input3=lookup_widget(objet,"mind");
input4=lookup_widget(objet,"heurer");
input5=lookup_widget(objet,"minr");
strcpy(ex.destination,gtk_entry_get_text(GTK_ENTRY(input1)));
ex.h_depart.h=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input2));
ex.h_depart.m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input3));
ex.h_retour.h=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
ex.h_retour.m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));
ajouter_exc(ex);
ajouterexc=lookup_widget(objet,"ajouterexc");
gtk_widget_destroy(ajouterexc);

treeexc=create_treeexc();
gtk_widget_show(treeexc);

treeview2=lookup_widget(treeexc,"treeview2");
afficher_exc(treeview2);

}


void
on_retourajoutexc_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajouterexc, *treeexc, *treeview2;
ajouterexc=lookup_widget(button,"ajouterexc");
gtk_widget_destroy(ajouterexc);
treeexc= lookup_widget(button,"treeexc");
treeexc=create_treeexc();
gtk_widget_show(treeexc);
treeview2=lookup_widget(treeexc,"treeview2");
afficher_exc(treeview2);
}


void
on_manipexc_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_manipuexc_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *menuadmin;
GtkWidget *treeexc;
GtkWidget *treeview2;

menuadmin= lookup_widget(button,"menuadmin");
gtk_widget_destroy(menuadmin);

treeexc=lookup_widget(button,"treeexc");
treeexc=create_treeexc();
gtk_widget_show(treeexc);
treeview2=lookup_widget(treeexc,"treeview2");
afficher_exc(treeview2);

}


void
on_validermodifexc_clicked             (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *modifexc, *ID, *destination, *hdh, *hdm, *hrh, *hrm;
GtkWidget *treeexc, *treeview2;
exc ex;
char id[5];

FILE *f;
ID=lookup_widget(objet,"ID_Fixe");
destination=lookup_widget(objet,"entrymodifdestinationexc");

hdh=lookup_widget(objet,"heuredmodifier");
hdm=lookup_widget(objet,"mindmodifier");

hrh=lookup_widget(objet,"heurermodifier");
hrm=lookup_widget(objet,"minrmodifier");

strcpy(id,gtk_entry_get_text(GTK_ENTRY(ID)));
ex.id=atof(id);

strcpy(ex.destination,gtk_entry_get_text(GTK_ENTRY(destination)));

ex.h_depart.h=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(hdh));
ex.h_depart.m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(hdm));

ex.h_retour.h=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(hrh));
ex.h_retour.m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(hrm));

supprimer_exc(atof(id),ex);
f=fopen("exc.txt","a+");
fprintf(f,"%d %s %dh%d %dh%d\n",ex.id,ex.destination,ex.h_depart.h,ex.h_depart.m,ex.h_retour.h,ex.h_retour.m);
fclose(f);
modifexc=lookup_widget(objet,"modifexc");
gtk_widget_destroy(modifexc);

treeexc=lookup_widget(objet,"treeexc");
treeexc=create_treeexc();
gtk_widget_show(treeexc);
treeview2=lookup_widget(treeexc,"treeview2");
afficher_exc(treeview2);

}


void
on_retourmodifexctree_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *modifexc, *treeexc,*treeview2;
modifexc=lookup_widget(button,"modifexc");
gtk_widget_destroy(modifexc);
treeexc= lookup_widget(button,"treeexc");
treeexc=create_treeexc();
gtk_widget_show(treeexc);
treeview2=lookup_widget(treeexc,"treeview2");
afficher_exc(treeview2);
}


void
on_retourexc_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *menuadmin, *treeexc, *treeview2;
treeexc=lookup_widget(button,"treeexc");
gtk_widget_destroy(treeexc);
menuadmin= lookup_widget(button,"menuadmin");
menuadmin=create_menuadmin();
gtk_widget_show(menuadmin);
treeview2=lookup_widget(treeexc,"treeview2");
afficher_exc(treeview2);
}

