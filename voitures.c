#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "voitures.h"
#include <gtk/gtk.h>


enum
{
	ID,
	DATE_PRISE,
	DATE_RETOUR,
	H_PRISE,
	H_RETOUR,
	NAME,
	PRENOM,
	CIN,
	COLUMNS
};


void afficher_voitureR(GtkWidget *liste)
{
GtkCellRenderer *renderer;

GtkTreeViewColumn *column;

GtkTreeIter  iter;

GtkListStore *store;

GtkWidget *treeview_voitures;

voitureR vi;


int id;
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

f=fopen("voitures.txt", "r");

if(f==NULL)
{
return;
}
else

 f = fopen("voitures.txt","a+");
	 while(fscanf(f,"%d %s %d/%d/%d %d/%d/%d %d:%d %d:%d %s %s %d \n",&vi.id,&vi.date_prise.j,&vi.date_prise.m,&vi.date_prise.a,&vi.date_retour.j,&vi.date_retour.m,&vi.date_retour.a,&vi.h_prise.h,&vi.h_prise.m,&vi.h_retour.h,&vi.h_retour.m,vi.name,vi.prenom,&vi.cin)!=EOF)
{

sprintf(d_prise,"%d/%d/%d",vi.date_prise.j,vi.date_prise.m,vi.date_prise.a);
sprintf(d_retour,"%d/%d/%d",vi.date_retour.j,vi.date_retour.m,vi.date_retour.a);
sprintf(heure_prise,"%d:%d",vi.h_prise.h,vi.h_prise.m);
sprintf(heure_retour,"%d:%d",vi.h_retour.h,vi.h_retour.m);

gtk_list_store_append (store, &iter);

gtk_list_store_set (store, &iter,ID,vi.id,,DATE_PRISE,vi.d_prise,DATE_RETOUR,vi.d_retour,H_PRISE,vi.heure_prise,H_RETOUR,vi.heure_retour,NAME,vi.name,PRENOM,vi.prenom,CIN,vi.cin, -1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}
}



void supprimer_voitureR(int test,voitureR vi)
{
	FILE *f,*h;
f=fopen("voitures.txt","r");
if(f!=NULL)
{h=fopen("voituretest.txt","w+");
while (fscanf(f,"%d %s %d/%d/%d %d/%d/%d %d:%d %d:%d %s %s %d \n",&vi.id,&vi.date_prise.j,&vi.date_prise.m,&vi.date_prise.a,&vi.date_retour.j,&vi.date_retour.m,&vi.date_retour.a,&vi.h_prise.h,&vi.h_prise.m,&vi.h_retour.h,&vi.h_retour.m,vi.name,vi.prenom,&vi.cin)!=EOF);
if(vi.id!=test)
fprintf(h,"%d %s %d/%d/%d %d/%d/%d %d:%d %d:%d %s %s %d \n",vi.id,vi.date_prise.j,vi.date_prise.m,vi.date_prise.a,vi.date_retour.j,vi.date_retour.m,vi.date_retour.a,vi.h_prise.h,vi.h_prise.m,vi.h_retour.h,vi.h_retour.m,vi.name,vi.prenom,vi.cin);
}else printf("File Not opened");
fclose(f);
fclose(h);
f=fopen("voitures.txt","w+");
h=fopen("voituretest.txt","r");
while (fscanf(h,"%d %s %d/%d/%d %d/%d/%d %d:%d %d:%d %s %s %d \n",&vi.id,&vi.date_prise.j,&vi.date_prise.m,&vi.date_prise.a,&vi.date_retour.j,&vi.date_retour.m,&vi.date_retour.a,&vi.h_prise.h,&vi.h_prise.m,&vi.h_retour.h,&vi.h_retour.m,vi.name,vi.prenom,&vi.cin)!=EOF);
fprintf(f,"%d %s %d/%d/%d %d/%d/%d %d:%d %d:%d %s %s %d \n",vi.id,vi.date_prise.j,vi.date_prise.m,vi.date_prise.a,vi.date_retour.j,vi.date_retour.m,vi.date_retour.a,vi.h_prise.h,vi.h_prise.m,vi.h_retour.h,vi.h_retour.m,vi.name,vi.prenom,vi.cin);

fclose(f);fclose(h);
}


void ajouter_voitureR(voitureR vi)
{

FILE *f;
voitureR e;
int i=0;
f=fopen("voitures.txt","r");
e.date_prise.j=vi.date_prise.j;
e.date_prise.m=vi.date_prise.m;
e.date_prise.a=vi.date_prise.a;
e.date_retour.j=vi.date_retour.j;
e.date_retour.m=vi.date_retour.m;
e.date_retour.a=vi.date_retour.a;
e.h_prise.h=vi.h_prise.h;
e.h_prise.m=vi.h_prise.m;
e.h_retour.h=vi.h_retour.h;
e.h_retour.m=vi.h_retour.m;
strcpy(e.name,vi.name);
strcpy(e.prenom,vi.prenom);
strcpy(e.cin,vi.cin);

while (fscanf(f,"%d %s %d/%d/%d %d/%d/%d %d:%d %d:%d %s %s %d \n",&vi.id,&vi.date_prise.j,&vi.date_prise.m,&vi.date_prise.a,&vi.date_retour.j,&vi.date_retour.m,&vi.date_retour.a,&vi.h_prise.h,&vi.h_prise.m,&vi.h_retour.h,&vi.h_retour.m,vi.name,vi.prenom,&vi.cin)!=EOF);
{i=vi.id;}
fclose(f);
f=fopen("voitures.txt","a+");
if(f!=NULL)
fprintf(f,"%d %s %d/%d/%d %d/%d/%d %d:%d %d:%d %s %s %d \n",vi.id,vi.date_prise.j,vi.date_prise.m,vi.date_prise.a,vi.date_retour.j,vi.date_retour.m,vi.date_retour.a,vi.h_prise.h,vi.h_prise.m,vi.h_retour.h,vi.h_retour.m,vi.name,vi.prenom,vi.cin);

fclose(f);
}


void modifier_voitureR(voitureR vi,int a)
{FILE *f;voitureR e;
e.date_prise.j=vi.date_prise.j;
e.date_prise.m=vi.date_prise.m;
e.date_prise.a=vi.date_prise.a;
e.date_retour.j=vi.date_retour.j;
e.date_retour.m=vi.date_retour.m;
e.date_retour.a=vi.date_retour.a;
e.h_prise.h=vi.h_prise.h;
e.h_prise.m=vi.h_prise.m;
e.h_retour.h=vi.h_retour.h;
e.h_retour.m=vi.h_retour.m;
strcpy(e.name,vi.name);
strcpy(e.prenom,vi.prenom);
strcpy(e.cin,vi.cin);
f=fopen("voitures.txt","r");
if(f!=NULL)
{while (fscanf(f,"%d %s %d/%d/%d %d/%d/%d %d:%d %d:%d %s %s %d \n",&vi.id,&vi.date_prise.j,&vi.date_prise.m,&vi.date_prise.a,&vi.date_retour.j,&vi.date_retour.m,&vi.date_retour.a,&vi.h_prise.h,&vi.h_prise.m,&vi.h_retour.h,&vi.h_retour.m,vi.name,vi.prenom,&vi.cin)!=EOF);
if(vi.id==a)
{supprimer_voitureR(a,vi);
fclose(f);
}
}
f=fopen("voitures.txt","a+");
fprintf(f,"%d %s %d/%d/%d %d/%d/%d %d:%d %d:%d %s %s %d \n",vi.id,vi.date_prise.j,vi.date_prise.m,vi.date_prise.a,vi.date_retour.j,vi.date_retour.m,vi.date_retour.a,vi.h_prise.h,vi.h_prise.m,vi.h_retour.h,vi.h_retour.m,vi.name,vi.prenom,vi.cin);
fclose(f);
}



int verif(int a,voitureR vi)
{
FILE *f;
int e=0;
f=fopen("voitures.txt","r");
if(f!=NULL)
while (fscanf(f,"%d %s %d/%d/%d %d/%d/%d %d:%d %d:%d %s %s %d \n",&vi.id,&vi.date_prise.j,&vi.date_prise.m,&vi.date_prise.a,&vi.date_retour.j,&vi.date_retour.m,&vi.date_retour.a,&vi.h_prise.h,&vi.h_prise.m,&vi.h_retour.h,&vi.h_retour.m,vi.name,vi.prenom,&vi.cin)!=EOF);

{if (a==vi.id)
e=1;}
fclose(f);
return e;
}