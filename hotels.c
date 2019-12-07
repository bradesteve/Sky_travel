#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hotels.h"
#include <gtk/gtk.h>


enum
{
	ID,
	NOM,
	LIEU,
	DATE_IN,
	DATE_OUT,
	NB_SINGLE,
	NB_DOUBLE,
	NB_TRIPLE,
	NAME,
	PRENOM,
	CIN,
	COLUMNS
};


void afficher_hotelR(GtkWidget *liste)
{
GtkCellRenderer *renderer;

GtkTreeViewColumn *column;

GtkTreeIter  iter;

GtkListStore *store;

GtkWidget *treeview_hotels;

hotelR h;

int id;
char nom[10];
char lieu[30];
Date date_in;
Date date_out;
int nb_single;
int nb_double;
int nb_triple;
char name[30];
char prenom[30];
int cin;
store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);

char d_in[20];
char d_out[20];

if(store==NULL)
{

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" id", renderer, "text",ID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" nom", renderer, "text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" lieu", renderer, "text",LIEU,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" d_in", renderer, "text",DATE_IN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" d_out", renderer, "text",DATE_OUT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" nb_single", renderer, "text",NB_SINGLE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" nb_double", renderer, "text",NB_DOUBLE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" nb_triple", renderer, "text",NB_TRIPLE,NULL);
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

store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

f=fopen("hotels.txt", "r");

if(f==NULL)
{
return;
}
else

 f = fopen("hotels.txt","a+");
	 while(fscanf(f,"%d %s %s %d/%d/%d %d/%d/%d %d %d % d %s %s %d \n",h.id,h.nom,h.lieu,h.date_in.j,h.date_in.m,h.date_in.a,h.date_out.j,h.date_out.m,h.date_out.a,h.nb_single,h.nb_double,h.nb_triple,h.name,h.prenom,h.cin)!=EOF)
{

sprintf(d_in,"%d/%d/%d",h.date_in.j,h.date_in.m,h.date_in.a);
sprintf(d_out,"%d/%d/%d",h.date_out.j,h.date_out.m,h.date_out.a);

gtk_list_store_append (store, &iter);

gtk_list_store_set (store, &iter,ID,h.id,NOM,h.nom,LIEU,h.lieu,DATE_IN,h.d_in,DATE_OUT,h.d_out,NB_SINGLE,h.nb_single,NB_DOUBLE,h.nb_double,NB_TRIPLE,h.nb_triple,NAME,h.name,PRENOM,h.prenom,CIN,h.cin, -1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}
}


	void supprimer_hotelR(int test, hotelR h)
{
		FILE *f,*h;
f=fopen("hotels.txt","r");
if(f!=NULL)
{h=fopen("hoteltest.txt","w+");
while (fscanf(f,"%d %s %s %d/%d/%d %d/%d/%d %d %d % d %s %s %d \n",&h.id,h.nom,h.lieu,&h.date_in.j,&h.date_in.m,&h.date_in.a,&h.date_out.j,&h.date_out.m,&h.date_out.a,&h.nb_single,&h.nb_double,&h.nb_triple,h.name,h.prenom,&h.cin)!=EOF);
if(v.id!=test)
fprintf(h,"%d %s %s %d/%d/%d %d/%d/%d %d %d % d %s %s %d \n",h.id,h.nom,h.lieu,h.date_in.j,h.date_in.m,h.date_in.a,h.date_out.j,h.date_out.m,h.date_out.a,h.nb_single,h.nb_double,h.nb_triple,h.name,h.prenom,h.cin);
}else printf("File Not opened");
fclose(f);
fclose(h);
f=fopen("hotels.txt","w+");
h=fopen("hoteltest.txt","r");
while (fscanf(h,"%d %s %s %d/%d/%d %d/%d/%d %d %d % d %s %s %d \n",&h.id,h.nom,h.lieu,&h.date_in.j,&h.date_in.m,&h.date_in.a,&h.date_out.j,&h.date_out.m,&h.date_out.a,&h.nb_single,&h.nb_double,&h.nb_triple,h.name,h.prenom,&h.cin)!=EOF);

fprintf(f,"%d %s %s %d/%d/%d %d/%d/%d %d %d % d %s %s %d \n",h.id,h.nom,h.lieu,h.date_in.j,h.date_in.m,h.date_in.a,h.date_out.j,h.date_out.m,h.date_out.a,h.nb_single,h.nb_double,h.nb_triple,h.name,h.prenom,h.cin);

fclose(f);fclose(h);}



}



void ajouter_hotelR(hotelR h)
{

FILE *f;
hotelR b;
int i=0;
f=fopen("hotels.txt","r");
strcpy(b.nom,h.nom);
strcpy(b.lieu,h.lieu);
b.date_in.j=h.date_in.j;
b.date_in.m=h.date_in.m;
b.date_in.a=h.date_in.a;
b.date_out.j=h.date_out.j;
b.date_out.m=h.date_out.m;
b.date_out.a=h.date_out.a;
b.nb_single=h.nb_single;
b.nb_double=h.nb_double;
b.nb_triple=h.nb_triple;
strcpy(b.name,h.name);
strcpy(b.prenom,h.prenom);
strcpy(b.cin,h.cin);

while (fscanf(f,"%d %s %s %d/%d/%d %d/%d/%d %d %d %d %s %s %d\n",&h.id,h.nom,h.lieu,&h.date_in.j,&
h.date_in.m,&h.date_in.a,&h.date_out.j,&h.date_out.m,&h.date_out.a,&h.nb_single,&h.nb_double,&h.nb_triple,h.name,h.prenom,&h.cin)!=EOF);
{i=v.id;}
fclose(f);
f=fopen("hotels.txt","a+");
if(f!=NULL)
fprintf(f,"%d %s %s %d/%d/%d %d/%d/%d %d %d %d %s %s %d\n",i+1,b.nom,b.lieu,b.date_in.j,
b.date_in.m,b.date_in.a,b.date_out.j,b.date_out.m,b.date_out.a,b.nb_single,b.nb_double,b.nb_triple,b.name,b.prenom,b.cin);
fclose(f);
}


void modifier_hotelR(hotelR h,int a)
{FILE *f;
hotelR b;
strcpy(b.nom,h.nom);
strcpy(b.lieu,h.lieu);
b.date_in.j=h.date_in.j;
b.date_in.m=h.date_in.m;
b.date_in.a=h.date_in.a;
b.date_out.j=h.date_out.j;
b.date_out.m=h.date_out.m;
b.date_out.a=h.date_out.a;
b.nb_single=h.nb_single;
b.nb_double=h.nb_double;
b.nb_triple=h.nb_triple;
strcpy(b.name,h.name);
strcpy(b.prenom,h.prenom);
strcpy(b.cin,h.cin);
f=fopen("hotels.txt","a+");
if(f!=NULL)
{while (fscanf(f,"%d %s %s %d/%d/%d %d/%d/%d %d %d %d %s %s %d\n",&h.id,h.nom,h.lieu,&h.date_in.j,&
h.date_in.m,&h.date_in.a,&h.date_out.j,&h.date_out.m,&h.date_out.a,&h.nb_single,&h.nb_double,&h.nb_triple,h.name,h.prenom,&h.cin)!=EOF);
if(h.id==a)
{supprimer_hotelR(a,h);
fclose(f);
}
}
f=fopen("hotels.txt","a+");
fprintf(f,"%d %s %s %d/%d/%d %d/%d/%d %d %d %d %s %s %d\n",a,b.nom,b.lieu,b.date_in.j,
b.date_in.m,b.date_in.a,b.date_out.j,b.date_out.m,b.date_out.a,b.nb_single,b.nb_double,b.nb_triple,b.name,b.prenom,b.cin);
fclose(f);
}



int verif(int a,hotelR h)
{
FILE *f;
int e=0;
f=fopen("hotels.txt","r");
if(f!=NULL)
{while (fscanf(f,"%d %s %s %d/%d/%d %d/%d/%d %d %d %d %s %s %d\n",&h.id,h.nom,h.lieu,&h.date_in.j,&
h.date_in.m,&h.date_in.a,&h.date_out.j,&h.date_out.m,&h.date_out.a,&h.nb_single,&h.nb_double,&h.nb_triple,h.name,h.prenom,&h.cin)!=EOF);
{if (a==h.id)
e=1;}
fclose(f);
return e;
}