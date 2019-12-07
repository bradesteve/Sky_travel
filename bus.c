#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "voitures.h"
#include <gtk/gtk.h>




enum
{
	ID,
	TAILLE,
	DATE_PRISE,
	DATE_RETOUR,
	H_PRISE,
	H_RETOUR,
	NAME,
	PRENOM,
	CIN,
	COLUMNS
};


void afficher_busR(GtkWidget *liste)
{
GtkCellRenderer *renderer;

GtkTreeViewColumn *column;

GtkTreeIter  iter;

GtkListStore *store;

GtkWidget *treeview_bus;

busR bu;

int id;
char taille[20];
Date date_prise;
Date date_retour;
Heure h_prise;
Heure h_retour;
char name[30];
char prenom[30];
int cin;
store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" id", renderer, "text",ID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" taille", renderer, "text",LIEU,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" d_Prise", renderer, "text",DATE_PRISE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" d_retour", renderer, "text",DATE_RETOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" heure_prise", renderer, "text",H_PRISE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" heure_retour", renderer, "text",H_RETOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" name", renderer, "text",NAME,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" prenom", renderer, "text",PRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" cin", renderer, "text",CIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

f=fopen("bus.txt", "r");

if(f==NULL)
{
return;
}
else

 f = fopen("bus.txt","a+");
	 while(fscanf(f,"%d %s %d/%d/%d %d/%d/%d %d:%d %d:%d %s %s %d \n",&bu.id,bu.taille,&bu.date_prise.j,&bu.date_prise.m,&bu.date_prise.a,&bu.date_retour.j,&bu.date_retour.m,&bu.date_retour.a,&bu.h_prise.h,&bu.h_prise.m,&bu.h_retour.h,&bu.h_retour.m,bu.name,bu.prenom,&bu.cin)!=EOF);
{

sprintf(d_prise,"%d/%d/%d",bu.date_prise.j,bu.date_prise.m,bu.date_prise.a);
sprintf(d_retour,"%d/%d/%d",bu.date_retour.j,bu.date_retour.m,bu.date_retour.a);
sprintf(heure_prise,"%d:%d",bu.h_prise.h,bu.h_prise.m);
sprintf(heure_retour,"%d:%d",bu.h_retour.h,bu.h_retour.m);{
gtk_list_store_append (store, &iter);

gtk_list_store_set (store, &iter,ID,bu.id,TAILLE,bu.taille,DATE_PRISE,bu.d_prise,DATE_RETOUR,bu.d_retour,H_PRISE,bu.heure_prise,H_RETOUR,bu.heure_retour,NAME,bu.name,PRENOM,bu.prenom,CIN,bu.cin, -1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}
}



void supprimer_busR(int test,busR vi)
{
	FILE *f,*h;
f=fopen("bus.txt","r");
if(f!=NULL)
{h=fopen("bustest.txt","w+");
while (fscanf(f,"%d %s %d/%d/%d %d/%d/%d %d:%d %d:%d %s %s %d \n",&bu.id,bu.taille,&bu.date_prise.j,&bu.date_prise.m,&bu.date_prise.a,&bu.date_retour.j,&bu.date_retour.m,&bu.date_retour.a,&bu.h_prise.h,&bu.h_prise.m,&bu.h_retour.h,&bu.h_retour.m,bu.name,bu.prenom,&bu.cin)!=EOF);
if(bu.id!=test)
fprintf(h,"%d %s %d/%d/%d %d/%d/%d %d:%d %d:%d %s %s %d \n",bu.id,bu.taille,bu.date_prise.j,bu.date_prise.m,bu.date_prise.a,bu.date_retour.j,bu.date_retour.m,bu.date_retour.a,bu.h_prise.h,bu.h_prise.m,bu.h_retour.h,bu.h_retour.m,bu.name,bu.prenom,bu.cin);
}else printf("File Not opened");
fclose(f);
fclose(h);
f=fopen("bus.txt","w+");
h=fopen("bustest.txt","r");
while (fscanf(h,"%d %s %d/%d/%d %d/%d/%d %d:%d %d:%d %s %s %d \n",&bu.id,bu.taille,&bu.date_prise.j,&bu.date_prise.m,&bu.date_prise.a,&bu.date_retour.j,&bu.date_retour.m,&bu.date_retour.a,&bu.h_prise.h,&bu.h_prise.m,&bu.h_retour.h,&bu.h_retour.m,bu.name,bu.prenom,&bu.cin)!=EOF);
fprintf(f,"%d %s %d/%d/%d %d/%d/%d %d:%d %d:%d %s %s %d \n",bu.id,bu.taille,bu.date_prise.j,bu.date_prise.m,bu.date_prise.a,bu.date_retour.j,bu.date_retour.m,bu.date_retour.a,bu.h_prise.h,bu.h_prise.m,bu.h_retour.h,bu.h_retour.m,bu.name,bu.prenom,bu.cin);

fclose(f);fclose(h);
}


void ajouter_busR(busR bu)
{

FILE *f;
bus g;
int i=0;
f=fopen("buss.txt","r");
strcpy(g.taille,bu.taille);
g.date_prise.j=bu.date_prise.j;
g.date_prise.m=bu.date_prise.m;
g.date_prise.a=bu.date_prise.a;
g.date_retour.j=bu.date_retour.j;
g.date_retour.m=bu.date_retour.m;
g.date_retour.a=bu.date_retour.a;
g.h_prise.h=bu.h_prise.h;
g.h_prise.m=bu.h_prise.m;
g.h_retour.h=bu.h_retour.h;
g.h_retour.m=bu.h_retour.m;
strcpy(g.name,bu.name);
strcpy(g.prenom,bu.prenom);
strcpy(g.cin,bu.cin);

while (fscanf(f,"%d %s %d/%d/%d %d/%d/%d %d:%d %d:%d %s %s %d \n",&bu.id,bu.taille,&bu.date_prise.j,&bu.date_prise.m,&bu.date_prise.a,&bu.date_retour.j,&bu.date_retour.m,&bu.date_retour.a,&bu.h_prise.h,&bu.h_prise.m,&bu.h_retour.h,&bu.h_retour.m,bu.name,bu.prenom,&bu.cin)!=EOF);
{i=bu.id;}
fclose(f);
f=fopen("bus.txt","a+");
if(f!=NULL)
fprintf(f,"%d %s %d/%d/%d %d/%d/%d %d:%d %d:%d %s %s %d \n",bu.id,bu.taille,bu.date_prise.j,bu.date_prise.m,bu.date_prise.a,bu.date_retour.j,bu.date_retour.m,bu.date_retour.a,bu.h_prise.h,bu.h_prise.m,bu.h_retour.h,bu.h_retour.m,bu.name,bu.prenom,bu.cin);

fclose(f);
}


void modifier_busR(busR bu,int a)
{FILE *f;busR g;
strcpy(g.taille,bu.taille);
g.date_prise.j=bu.date_prise.j;
g.date_prise.m=bu.date_prise.m;
g.date_prise.a=bu.date_prise.a;
g.date_retour.j=bu.date_retour.j;
g.date_retour.m=bu.date_retour.m;
g.date_retour.a=bu.date_retour.a;
g.h_prise.h=bu.h_prise.h;
g.h_prise.m=bu.h_prise.m;
g.h_retour.h=bu.h_retour.h;
g.h_retour.m=bu.h_retour.m;
strcpy(g.name,bu.name);
strcpy(g.prenom,bu.prenom);
strcpy(g.cin,bu.cin);
f=fopen("bus.txt","r");
if(f!=NULL)
{while (fscanf(f,"%d %s %d/%d/%d %d/%d/%d %d:%d %d:%d %s %s %d \n",&bu.id,bu.taille,&bu.date_prise.j,&bu.date_prise.m,&bu.date_prise.a,&bu.date_retour.j,&bu.date_retour.m,&bu.date_retour.a,&bu.h_prise.h,&bu.h_prise.m,&bu.h_retour.h,&bu.h_retour.m,bu.name,bu.prenom,&bu.cin)!=EOF);
if(bu.id==a)
{supprimer_busR(a,bu);
fclose(f);
}
}
f=fopen("buss.txt","a+");
fprintf(f,"%d %s %d/%d/%d %d/%d/%d %d:%d %d:%d %s %s %d \n",bu.id,bu.taille,bu.date_prise.j,bu.date_prise.m,bu.date_prise.a,bu.date_retour.j,bu.date_retour.m,bu.date_retour.a,bu.h_prise.h,bu.h_prise.m,bu.h_retour.h,bu.h_retour.m,bu.name,bu.prenom,bu.cin);
fclose(f);
}



int verif(int a,busR bu)
{
FILE *f;
int e=0;
f=fopen("bus.txt","r");
if(f!=NULL)
while (fscanf(f,"%d %s %d/%d/%d %d/%d/%d %d:%d %d:%d %s %s %d \n",&bu.id,bu.taille,&bu.date_prise.j,&bu.date_prise.m,&bu.date_prise.a,&bu.date_retour.j,&bu.date_retour.m,&bu.date_retour.a,&bu.h_prise.h,&bu.h_prise.m,&bu.h_retour.h,&bu.h_retour.m,bu.name,bu.prenom,&bu.cin)!=EOF);

{if (a==bu.id)
e=1;}
fclose(f);
return e;
}