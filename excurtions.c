#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "excurtions.h"
#include <gtk/gtk.h>




enum
{
	ID,
	NOM,
	DESCRIPTION,
	D_EXCURTION,
	H_DEPART,
	H_ARRIVEE,
	NAME,
	PRENOM,
	CIN,
	COLUMNS
};


void afficher_excurtionR(GtkWidget *liste)
{
GtkCellRenderer *renderer;

GtkTreeViewColumn *column;

GtkTreeIter  iter;

GtkListStore *store;

GtkWidget *treeview_excurtions;

excurtionR ex;

int id;
char nom[30];
char description[255];
Date d_excurtion;
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
column = gtk_tree_view_column_new_with_attributes(" date_excurtion", renderer, "text",D_EXCURTION,NULL);
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

f=fopen("excurtions.txt", "r");

if(f==NULL)
{
return;
}
else

 f = fopen("excurtions.txt","a+");
	 while(fscanf(f,""%d %s %s %d/%d/%d %d:%d %d:%d %s %s %d \n",&ex.id,ex.nom,ex.description,&ex.d_excurtion.j,&ex.d_excurtion.m,&ex.d_excurtion.a,&ex.h_depart.h,&ex.h_depart.m,&ex.h_arrivee.h,&ex.h_arrivee.m,ex.name,ex.prenom,&ex.cin)!=EOF);

{

sprintf(date_excurtion,"%d/%d/%d",ex.d_excurtion.j,ex.d_excurtion.m,ex.d_excurtion.a);
sprintf(heure_depart,"%d:%d",ex.h_depart.h,ex.h_depart.m);
sprintf(heure_arrivee,"%d:%d",ex.h_arrivee.h,ex.h_arrivee.m);{
gtk_list_store_append (store, &iter);

gtk_list_store_set (store, &iter,ID,id,NOM,nom,DESCRIPTION,description,D_EXCURTION,date_excurtion,H_DEPART,heure_depart,H_ARRIVEE,heure_arrivee,NAME,name,PRENOM,prenom,CIN,cin, -1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}
}



void supprimer_excurtionR(int test,excurtionR ex)
{
		FILE *f,*h;
f=fopen("excurtions.txt","r");
if(f!=NULL)
{h=fopen("excurtiontest.txt","w+");
while (fscanf(f,"%d %s %s %d/%d/%d %d:%d %d:%d %s %s %d \n",&ex.id,ex.nom,ex.description,&ex.d_excurtion.j,&ex.d_excurtion.m,&ex.d_excurtion.a,&ex.h_depart.h,&ex.h_depart.m,&ex.h_arrivee.h,&ex.h_arrivee.m,ex.name,ex.prenom,&ex.cin)!=EOF);
if(ex.id!=test)
fprintf(h,"%d %s %s %d/%d/%d %d:%d %d:%d %s %s %d \n",ex.id,ex.nom,ex.description,ex.d_excurtion.j,ex.d_excurtion.m,ex.d_excurtion.a,ex.h_depart.h,ex.h_depart.m,ex.h_arrivee.h,ex.h_arrivee.m,ex.name,ex.prenom,ex.cin);
}else printf("File Not opened");
fclose(f);
fclose(h);
f=fopen("excurtions.txt","w+");
h=fopen("excurtiontest.txt","r");
while (fscanf(h,"%d %s %s %d/%d/%d %d:%d %d:%d %s %s %d \n",&ex.id,ex.nom,ex.description,&ex.d_excurtion.j,&ex.d_excurtion.m,&ex.d_excurtion.a,&ex.h_depart.h,&ex.h_depart.m,&ex.h_arrivee.h,&ex.h_arrivee.m,ex.name,ex.prenom,&ex.cin)!=EOF);
fprintf(f,"%d %s %s %d/%d/%d %d:%d %d:%d %s %s %d \n",ex.id,ex.nom,ex.description,ex.d_excurtion.j,ex.d_excurtion.m,ex.d_excurtion.a,ex.h_depart.h,ex.h_depart.m,ex.h_arrivee.h,ex.h_arrivee.m,ex.name,ex.prenom,ex.cin);

fclose(f);fclose(h);
}



void ajouter_excurtionR(excurtionR ex)
{

FILE *f;
excurtionR d;
int i=0;
f=fopen("excurtions.txt","r");
strcpy(d.nom,ex.nom);
strcpy(d.description,ex.description);
d.d_excurtion.j=ex.d_excurtion.j;
d.d_excurtion.m=ex.d_excurtion.m;
d.d_excurtion.a=ex.d_excurtion.a;
d.h_depart.h=ex.h_depart.h;
d.h_depart.m=ex.h_depart.m;
d.h_arrivee.h=ex.h_arrivee.h;
d.h_arrivee.m=ex.h_arrivee.m;
strcpy(d.name,ex.name);
strcpy(d.prenom,ex.prenom);
strcpy(d.cin,ex.cin);

while (fscanf(f,"%d %s %s %d/%d/%d %d:%d %d:%d %s %s %d \n",&ex.id,ex.nom,ex.description,&ex.d_excurtion.j,&ex.d_excurtion.m,&ex.d_excurtion.a,&ex.h_depart.h,&ex.h_depart.m,&ex.h_arrivee.h,&ex.h_arrivee.m,ex.name,ex.prenom,&ex.cin)!=EOF);
{i=ex.id;}
fclose(f);
f=fopen("excurtions.txt","a+");
if(f!=NULL)
fprintf(f,"%d %s %s %d/%d/%d %d:%d %d:%d %s %s %d \n",ex.id,ex.nom,ex.description,ex.d_excurtion.j,ex.d_excurtion.m,ex.d_excurtion.a,ex.h_depart.h,ex.h_depart.m,ex.h_arrivee.h,ex.h_arrivee.m,ex.name,ex.prenom,ex.cin);

fclose(f);

}


void modifier_excurtionR(excurtionR ex,int a)
{FILE *f;excurtionR d;
strcpy(d.nom,ex.nom);
strcpy(d.description,ex.description);
d.d_excurtion.j=ex.d_excurtion.j;
d.d_excurtion.m=ex.d_excurtion.m;
d.d_excurtion.a=ex.d_excurtion.a;
d.h_depart.h=ex.h_depart.h;
d.h_depart.m=ex.h_depart.m;
d.h_arrivee.h=ex.h_arrivee.h;
d.h_arrivee.m=ex.h_arrivee.m;
strcpy(d.name,ex.name);
strcpy(d.prenom,ex.prenom);
strcpy(d.cin,ex.cin);
f=fopen("excurtions.txt","r");
if(f!=NULL)
{while (fscanf(f,"%d %s %s %d/%d/%d %d:%d %d:%d %s %s %d \n",&ex.id,ex.nom,ex.description,&ex.d_excurtion.j,&ex.d_excurtion.m,&ex.d_excurtion.a,&ex.h_depart.h,&ex.h_depart.m,&ex.h_arrivee.h,&ex.h_arrivee.m,ex.name,ex.prenom,&ex.cin)!=EOF);
if(ex.id==a)
{supprimer_excurtionR(a,ex);
fclose(f);
}
}
f=fopen("excurtions.txt","a+");
fprintf(f,"%d %s %s %d/%d/%d %d:%d %d:%d %s %s %d \n",ex.id,ex.nom,ex.description,ex.d_excurtion.j,ex.d_excurtion.m,ex.d_excurtion.a,ex.h_depart.h,ex.h_depart.m,ex.h_arrivee.h,ex.h_arrivee.m,ex.name,ex.prenom,ex.cin);
fclose(f);
}



int verif(int a,excurtionR ex)
{
FILE *f;
int e=0;
f=fopen("excurtions.txt","r");
if(f!=NULL)
while (fscanf(f,"%d %s %s %d/%d/%d %d:%d %d:%d %s %s %d \n",&ex.id,ex.nom,ex.description,&ex.d_excurtion.j,&ex.d_excurtion.m,&ex.d_excurtion.a,&ex.h_depart.h,&ex.h_depart.m,&ex.h_arrivee.h,&ex.h_arrivee.m,ex.name,ex.prenom,&ex.cin)!=EOF);

{if (a==ex.id)
e=1;}
fclose(f);
return e;
}

