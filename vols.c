6
+#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vols.h"
#include <gtk/gtk.h>


enum
{
	ID,
	NOM,
	DEPART,
	RETOUR,
	DATE_DEPART,
	DATE_RETOUR,
	NAME,
	PRENOM,
	CIN,
	COLUMNS
};


void afficher_volR(GtkWidget *liste)
{
GtkCellRenderer *renderer;

GtkTreeViewColumn *column;

GtkTreeIter  iter;

GtkListStore *store;

GtkWidget *treeview_vols;

volR v;

int id;
char nom[10];
char depart[20];
char retour[20];
Date d_depart;
Date d_retour;
char name[30];
char prenom[30];
int cin;
store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);

char d_depart[20];
char d_retour[20];
if(store==NULL)
{

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" id", renderer, "text",ID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" nom", renderer, "text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" depart", renderer, "text",DEPART,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" retour", renderer, "text",RETOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" date_depart", renderer, "text",DATE_DEPART,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" date_retour", renderer, "text",DATE_RETOUR,NULL);
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

f=fopen("vols.txt", "r");

if(f==NULL)
{
return;
}
else

 f = fopen("vols.txt","a+");
	 while(fscanf(f,"%d %s %s %s %d/%d/%d %d/%d/%d %s %s %d \n",&v.id,v.nom,v.depart,v.retour,&v.d_depart.j,&v.d_depart.m,&v.d_depart.a,&v.d_retour.j,&v.d_retour.m,&v.d_retou.a,v.name,v.prenom,&v.cin)!=EOF)
{

sprintf(date_depart,"%d/%d/%d",v.d_depart.j,v.d_depart.m,v.d_depart.a);
sprintf(date_retour,"%d/%d/%d",v.d_retour.j,v.d_retour.m,v.d_retour.a);

gtk_list_store_append (store, &iter);

gtk_list_store_set (store, &iter,ID,v.id,NOM,v.nom,DEPART,v.depart,RETOUR,v.retour,DATE_DEPART,v.date_depart,DATE_RETOUR,date_retour,NAME,name,PRENOM,prenom,CIN,cin, -1);

}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}
}


	void supprimer_volR(int test,volR v)
{
	FILE *f,*h;
f=fopen("vols.txt","r");
if(f!=NULL)
{h=fopen("voltest.txt","w+");
while (fscanf(f,"%d %s %s %s %d/%d/%d %d/%d/%d %s %s %d\n",&v.id,v.nom,v.depart,v.retour,&v.d_depart.j,&
v.d_depart.m,&v.d_depart.a,&v.d_retour.j,&v.d_retour.m,&v.d_retour.a, v.name,v.prenom,&v.cin)!=EOF);
if(v.id!=test)
fprintf(h,"%d %s %s %s %d/%d/%d %d/%d/%d %s %s %d\n",v.id,v.nom,v.depart,v.retour,v.d_depart.j,
v.d_depart.m,v.d_depart.a,v.d_retour.j,v.d_retour.m,v.d_retour.a,v.name,v.prenom,v.cin);
}else printf("File Not opened");
fclose(f);
fclose(h);
f=fopen("vols.txt","w+");
h=fopen("voltest.txt","r");
while (fscanf(h,"%d %s %s %s %d/%d/%d %d/%d/%d %s %s %d\n",&v.id,v.nom,v.depart,v.retour,&v.d_depart.j,&
v.d_depart.m,&v.d_depart.a,&v.d_retour.j,&v.d_retour.m,&v.d_retour.a,v.name,v.prenom,&v.cin)!=EOF);
fprintf(f,"%d %s %s %s %d/%d/%d %d/%d/%d %s %s %d\n",v.id,v.nom,v.depart,v.retour,v.d_depart.j,
v.d_depart.m,v.d_depart.a,v.d_retour.j,v.d_retour.m,v.d_retour.a,v.name,v.prenom,v.cin);
fclose(f);fclose(h);}



}



void ajouter_volR(volR v)
{

FILE *f;
volR h;
int i=0;
f=fopen("vols.txt","r");
strcpy(h.nom,v.nom);
strcpy(h.depart,v.depart);
strcpy(h.retour,v.retour);
h.d_depart.j=v.d_depart.j;
h.d_depart.m=v.d_depart.m;
h.d_depart.a=v.d_depart.a;
h.d_retour.j=v.d_retour.j;
h.d_retour.m=v.d_retour.m;
h.d_retour.a=v.d_retour.a;
strcpy(h.name,v.name);
strcpy(h.prenom,v.prenom);
strcpy(h.cin,v.cin);

while (fscanf(f,"%d %s %s %s %d/%d/%d %d/%d/%d %s %s %d\n",&v.id,v.nom,v.depart,v.retour,&v.d_depart.j,&
v.d_depart.m,&v.d_depart.a,&v.d_retour.j,&v.d_retour.m,&v.d_retour.a,v.name,v.prenom,&v.cin)!=EOF)
{i=v.id;}
fclose(f);
f=fopen("vols.txt","a+");
if(f!=NULL)
fprintf(f,"%d %s %s %s %d/%d/%d %d/%d/%d %s %s %d\n",i+1,h.nom,h.depart,h.retour,h.d_depart.j,
h.d_depart.m,h.d_depart.a,h.d_retour.j,h.d_retour.m,h.d_retour.a,h.name,h.prenom,h.cin);
fclose(f);}

void modifier_volR(volR v,int a)
{FILE *f;volR h;
strcpy(h.nom,v.nom);
strcpy(h.depart,v.depart);
strcpy(h.retour,v.retour);
h.d_depart.j=v.d_depart.j;
h.d_depart.m=v.d_depart.m;
h.d_depart.a=v.d_depart.a;
h.d_retour.j=v.d_retour.j;
h.d_retour.m=v.d_retour.m;
h.d_retour.a=v.d_retour.a;
strcpy(h.name,v.name);
strcpy(h.prenom,v.prenom);
strcpy(h.cin,v.cin);
f=fopen("vols.txt","r");
if(f!=NULL)
{while (fscanf(f,"%d %s %s %s %d/%d/%d %d/%d/%d %s %s %d\n",&v.id,v.nom,v.depart,v.retour,&v.d_depart.j,&
v.d_depart.m,&v.d_depart.a,&v.d_retour.j,&v.d_retour.m,&v.d_retour.a,v.name,v.prenom,&v.cin)!=EOF)
if(v.id==a)
{supprimer_volR(a,v);
fclose(f);
}
}
f=fopen("vols.txt","a+");
fprintf(f,"%d %s %s %s %d/%d/%d %d/%d/%d %s %s %d\n",a,h.nom,h.depart,h.retour,h.d_depart.j,
h.d_depart.m,h.d_depart.a,h.d_retour.j,h.d_retour.m,h.d_retour.a,h.name,h.prenom,h.cin);
fclose(f);
}

int verif(int a,volR v)
{
FILE *f;
int e=0;
f=fopen("vols.txt","r");
if(f!=NULL)
while (fscanf(f,"%d %s %s %s %d/%d/%d %d/%d/%d %s %s %d\n",&v.id,v.nom,v.depart,v.retour,&v.d_depart.j,&
v.d_depart.m,&v.d_depart.a,&v.d_retour.j,&v.d_retour.m,&v.d_retour.a,v.name,v.prenom,&v.cin)!=EOF)
{if (a==v.id)
e=1;}
fclose(f);
return e;
}




