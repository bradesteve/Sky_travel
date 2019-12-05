#include <stdio.h>
#include <string.h>
#include "adherent.h"
#include <gtk/gtk.h>
#include <stdlib.h>
#include <wctype.h>

enum{
ID,
NOM,
PRENOM,
CIN,
EMAIL,
ADRESSE,
TELEPHONE,
DATENAISSANCE,
USERNAME,
PASSWORD,
COLUMNS};

void afficher_adherent(GtkWidget *liste)
{
GtkWidget *treeview1;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
adherent ad;
int id;
char nom[20];
char prenom[20];
int cin;
char email [80];
char adresse[20];
int telephone;
DATE datenaissance;
char username[20];
char password[20]; 

store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);

char date_naissance[20];
if (store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("id",renderer, "text",ID, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("nom",renderer, "text",NOM, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("prenom", renderer, "text",PRENOM, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("cin", renderer, "text",CIN, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("email", renderer, "text",EMAIL, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("adresse", renderer, "text",ADRESSE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("telephone", renderer, "text",TELEPHONE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("date_naissance", renderer, "text",DATENAISSANCE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("username", renderer, "text",USERNAME, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("password", renderer, "text",PASSWORD, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

store=gtk_list_store_new(COLUMNS, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

f=fopen("adherent.txt","r");

if(f==NULL)
{
return;
}
else
{f=fopen("adherent.txt","a+");
while(fscanf(f,"%d %s %s %d %s %s %d %d/%d/%d %s %s\n",&ad.id,ad.nom,ad.prenom,&ad.cin,ad.email,ad.adresse,&ad.telephone,&ad.datenaissance.j,&ad.datenaissance.m,&ad.datenaissance.a,ad.username,ad.password)!=EOF)
{
sprintf(date_naissance,"%d/%d/%d",ad.datenaissance.j,ad.datenaissance.m,ad.datenaissance.a);
gtk_list_store_append(store, &iter);
gtk_list_store_set (store, &iter, ID, ad.id, NOM, ad.nom, PRENOM, ad.prenom, CIN, ad.cin, EMAIL, ad.email, ADRESSE,  ad.adresse, TELEPHONE, ad.telephone, DATENAISSANCE, date_naissance, USERNAME, ad.username, PASSWORD, ad.password, -1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}}
}

void ajouter_adherent(adherent ad)
{FILE *f;
int i=0;
adherent h;
f=fopen("adherent.txt","r");
strcpy(h.nom,ad.nom);
strcpy(h.prenom,ad.prenom);
h.cin=ad.cin;
strcpy(h.email,ad.email);
strcpy(h.adresse,ad.adresse);
h.telephone=ad.telephone;
h.datenaissance.j=ad.datenaissance.j;
h.datenaissance.m=ad.datenaissance.m;
h.datenaissance.a=ad.datenaissance.a;
strcpy(h.username,ad.username);
strcpy(h.password,ad.password);

while (fscanf(f,"%d %s %s %d %s %s %d %d/%d/%d %s %s\n",&ad.id,ad.nom,ad.prenom,&ad.cin,ad.email,ad.adresse,&ad.telephone,&ad.datenaissance.j,&ad.datenaissance.m,&ad.datenaissance.a,ad.username,ad.password)!=EOF)
{i=ad.id;}
fclose(f);
f=fopen("adherent.txt","a+");
if(f!=NULL)
fprintf(f,"%d %s %s %d %s %s %d %d/%d/%d %s %s\n",i+1,h.nom,h.prenom,h.cin,h.email,h.adresse,h.telephone,h.datenaissance.j,h.datenaissance.m,h.datenaissance.a,h.username,h.password);
fclose(f);}



void supprimer_adherent(int test,adherent ad)
{FILE *f,*h;
f=fopen("adherent.txt","r");
if (f!=NULL)
{h=fopen("adherents.txt","w+");
while(fscanf(f,"%d %s %s %d %s %s %d %d/%d/%d %s %s\n",&ad.id,ad.nom,ad.prenom,&ad.cin,ad.email,ad.adresse,&ad.telephone,&ad.datenaissance.j,&ad.datenaissance.m,&ad.datenaissance.a,ad.username,ad.password)!=EOF)
if(ad.id!=test)
fprintf(h,"%d %s %s %d %s %s %d %d/%d/%d %s %s\n",ad.id,ad.nom,ad.prenom,ad.cin,ad.email,ad.adresse,ad.telephone,ad.datenaissance.j,ad.datenaissance.m,ad.datenaissance.a,ad.username,ad.password);
}else printf("File not opened");
fclose(f);
fclose(h);
f=fopen("adherent.txt","w+");
h=fopen("adherents.txt","r");
while(fscanf(h,"%d %s %s %d %s %s %d %d/%d/%d %s %s\n",&ad.id,ad.nom,ad.prenom,&ad.cin,ad.email,ad.adresse,&ad.telephone,&ad.datenaissance.j,&ad.datenaissance.m,&ad.datenaissance.a,ad.username,ad.password)!=EOF)
fprintf(f,"%d %s %s %d %s %s %d %d/%d/%d %s %s\n",ad.id,ad.nom,ad.prenom,ad.cin,ad.email,ad.adresse,ad.telephone,ad.datenaissance.j,ad.datenaissance.m,ad.datenaissance.a,ad.username,ad.password);
fclose(f);fclose(h);
}

void modifier_adherent(adherent ad, int a)
{
FILE *f;
adherent copie;
strcpy(copie.nom,ad.nom);
strcpy(copie.prenom,ad.prenom);
copie.cin=ad.cin;
strcpy(copie.email,ad.email);
strcpy(copie.adresse,ad.adresse);
copie.telephone=ad.telephone;
copie.datenaissance.j=ad.datenaissance.j;
copie.datenaissance.m=ad.datenaissance.m;
copie.datenaissance.a=ad.datenaissance.a;
strcpy(copie.username,ad.username);
strcpy(copie.password,ad.password);

f=fopen("adherent.txt","r");
if(f!=NULL)
{while (fscanf(f,"%d %s %s %d %s %s %d %d/%d/%d %s %s\n",&ad.id,ad.nom,ad.prenom,&ad.cin,ad.email,ad.adresse,&ad.telephone,&ad.datenaissance.j,&ad.datenaissance.m,&ad.datenaissance.a,ad.username,ad.password)!=EOF)
if(a==ad.id)
{supprimer_adherent(a,ad);
fclose(f);
}
}
f=fopen("adherent.txt","a+");
fprintf(f,"%d %s %s %d %s %s %d %d/%d/%d %s %s\n",a,copie.nom,copie.prenom,copie.cin,copie.email,copie.adresse,copie.telephone,copie.datenaissance.j,copie.datenaissance.m,copie.datenaissance.a,copie.username,copie.password);
fclose(f);
}

int verif(int a,adherent ad)
{
FILE *f;
int e=0;
f=fopen("adherent.txt","r");
if(f!=NULL)
while (fscanf(f,"%d %s %s %d %s %s %d %d/%d/%d %s %s\n",&ad.id,ad.nom,ad.prenom,&ad.cin,ad.email,ad.adresse,&ad.telephone,&ad.datenaissance.j,&ad.datenaissance.m,&ad.datenaissance.a,ad.username,ad.password)!=EOF)
{if (a==ad.id)
e=1;}
fclose(f);
return e;
}
