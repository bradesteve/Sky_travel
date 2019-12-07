#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "voyages.h"
#include <gtk/gtk.h>



enum
{
	ID,
	NOM,
	DESCRIPTION,
	D_VOYAGE,
	H_DEPART,
	H_ARRIVEE,
	NAME,
	PRENOM,
	CIN,
	COLUMNS
};


void afficher_voyageR(GtkWidget *liste)
{
GtkCellRenderer *renderer;

GtkTreeViewColumn *column;

GtkTreeIter  iter;

GtkListStore *store;

GtkWidget *treeview_voyages;

voyageR vo;

int id;
char nom[30];
char description[255];
Date d_voyage;
Heure h_depart;
Heure h_arrivee;
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
column = gtk_tree_view_column_new_with_attributes(" nom", renderer, "text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" description", renderer, "text",DESCRIPTION,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" date_voyage", renderer, "text",D_VOYAGE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" heure_depart", renderer, "text",H_DEPART,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" heure_arrivee", renderer, "text",H_ARRIVEE,NULL);
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

f=fopen("voyages.txt", "r");

if(f==NULL)
{
return;
}
else

 f = fopen("voyages.txt","a+");
	 while(fscanf(f,"%d %s %s %d/%d/%d %d:%d %d:%d %s %s %d \n",&vo.id,vo.nom,vo.description,&vo.d_voyage.j,&vo.d_voyage.m,&vo.d_voyage.a,&vo.h_depart.h,&vo.h_depart.m,&vo.h_arrivee.h,&vo.h_arrivee.m,vo.name,vo.prenom,&vo.cin)!=EOF);

{

sprintf(date_voyage,"%d/%d/%d",vo.d_voyage.j,vo.d_voyage.m,vo.d_voyage.a);
sprintf(heure_depart,"%d:%d",vo.h_depart.h,vo.h_depart.m);
sprintf(heure_arrivee,"%d:%d",vo.h_arrivee.h,vo.h_arrivee.m);

gtk_list_store_append (store, &iter);

gtk_list_store_set (store, &iter,ID,vo.id,NOM,vo.nom,DESCRIPTION,vo.description,D_VOYAGE,vo.date_voyage,H_DEPART,vo.heure_depart,H_ARRIVEE,vo.heure_arrivee,NAME,vo.name,PRENOM,vo.prenom,CIN,vo.cin, -1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}
}


void supprimer_voyageR(int test,voyageR vo)
{
		FILE *f,*h;
f=fopen("voyages.txt","r");
if(f!=NULL)
{h=fopen("voyagetest.txt","w+");
while (fscanf(f,"%d %s %s %d/%d/%d %d:%d %d:%d %s %s %d \n",&vo.id,vo.nom,vo.description,&vo.d_voyage.j,&vo.d_voyage.m,&vo.d_voyage.a,&vo.h_depart.h,&vo.h_depart.m,&vo.h_arrivee.h,&vo.h_arrivee.m,vo.name,vo.prenom,&vo.cin)!=EOF);
if(vo.id!=test)
fprintf(h,"%d %s %s %d/%d/%d %d:%d %d:%d %s %s %d \n",vo.id,vo.nom,vo.description,vo.d_voyage.j,vo.d_voyage.m,vo.d_voyage.a,vo.h_depart.h,vo.h_depart.m,vo.h_arrivee.h,vo.h_arrivee.m,vo.name,vo.prenom,vo.cin);
}else printf("File Not opened");
fclose(f);
fclose(h);
f=fopen("voyages.txt","w+");
h=fopen("voyagetest.txt","r");
while (fscanf(h,"%d %s %s %d/%d/%d %d:%d %d:%d %s %s %d \n",&vo.id,vo.nom,vo.description,&vo.d_voyage.j,&vo.d_voyage.m,&vo.d_voyage.a,&vo.h_depart.h,&vo.h_depart.m,&vo.h_arrivee.h,&vo.h_arrivee.m,vo.name,vo.prenom,&vo.cin)!=EOF);
fprintf(f,"%d %s %s %d/%d/%d %d:%d %d:%d %s %s %d \n",vo.id,vo.nom,vo.description,vo.d_voyage.j,vo.d_voyage.m,vo.d_voyage.a,vo.h_depart.h,vo.h_depart.m,vo.h_arrivee.h,vo.h_arrivee.m,vo.name,vo.prenom,vo.cin);

fclose(f);fclose(h);
}



void ajouter_voyageR(voyageR vo)
{

FILE *f;
voyageR c;
int i=0;
f=fopen("voyages.txt","r");
strcpy(c.nom,vo.nom);
strcpy(c.description,vo.description);
c.d_voyage.j=vo.d_voyage.j;
c.d_voyage.m=vo.d_voyage.m;
c.d_voyage.a=vo.d_voyage.a;
c.h_depart.h=vo.h_depart.h;
c.h_depart.m=vo.h_depart.m;
c.h_arrivee.h=vo.h_arrivee.h;
c.h_arrivee.m=vo.h_arrivee.m;
strcpy(c.name,vo.name);
strcpy(c.prenom,vo.prenom);
strcpy(c.cin,vo.cin);

while (fscanf(f,"%d %s %s %d/%d/%d %d:%d %d:%d %s %s %d \n",&vo.id,vo.nom,vo.description,&vo.d_voyage.j,&vo.d_voyage.m,&vo.d_voyage.a,&vo.h_depart.h,&vo.h_depart.m,&vo.h_arrivee.h,&vo.h_arrivee.m,vo.name,vo.prenom,&vo.cin)!=EOF);
{i=vo.id;}
fclose(f);
f=fopen("voyages.txt","a+");
if(f!=NULL)
fprintf(f,"%d %s %s %d/%d/%d %d:%d %d:%d %s %s %d \n",vo.id,vo.nom,vo.description,vo.d_voyage.j,vo.d_voyage.m,vo.d_voyage.a,vo.h_depart.h,vo.h_depart.m,vo.h_arrivee.h,vo.h_arrivee.m,vo.name,vo.prenom,vo.cin);

fclose(f);
}


void modifier_voyageR(voyageR vo,int a)
{FILE *f;voyageR c;
strcpy(c.nom,vo.nom);
strcpy(c.description,vo.description);
c.d_voyage.j=vo.d_voyage.j;
c.d_voyage.m=vo.d_voyage.m;
c.d_voyage.a=vo.d_voyage.a;
c.h_depart.h=vo.h_depart.h;
c.h_depart.m=vo.h_depart.m;
c.h_arrivee.h=vo.h_arrivee.h;
c.h_arrivee.m=vo.h_arrivee.m;
strcpy(c.name,vo.name);
strcpy(c.prenom,vo.prenom);
strcpy(c.cin,vo.cin);
f=fopen("voyages.txt","r");
if(f!=NULL)
{while (fscanf(f,"%d %s %s %d/%d/%d %d:%d %d:%d %s %s %d \n",&vo.id,vo.nom,vo.description,&vo.d_voyage.j,&vo.d_voyage.m,&vo.d_voyage.a,&vo.h_depart.h,&vo.h_depart.m,&vo.h_arrivee.h,&vo.h_arrivee.m,vo.name,vo.prenom,&vo.cin)!=EOF);
if(vo.id==a)
{supprimer_voyageR(a,vo);
fclose(f);
}
}
f=fopen("voyages.txt","a+");
fprintf(f,"%d %s %s %d/%d/%d %d:%d %d:%d %s %s %d \n",vo.id,vo.nom,vo.description,vo.d_voyage.j,vo.d_voyage.m,vo.d_voyage.a,vo.h_depart.h,vo.h_depart.m,vo.h_arrivee.h,vo.h_arrivee.m,vo.name,vo.prenom,vo.cin);
fclose(f);
}



int verif(int a,voyageR vo)
{
FILE *f;
int e=0;
f=fopen("voyages.txt","r");
if(f!=NULL)
while (fscanf(f,"%d %s %s %d/%d/%d %d:%d %d:%d %s %s %d \n",&vo.id,vo.nom,vo.description,&vo.d_voyage.j,&vo.d_voyage.m,&vo.d_voyage.a,&vo.h_depart.h,&vo.h_depart.m,&vo.h_arrivee.h,&vo.h_arrivee.m,vo.name,vo.prenom,&vo.cin)!=EOF);

{if (a==vo.id)
e=1;}
fclose(f);
return e;
}
