#include <stdio.h>
#include<string.h>
#include"voyorg.h"
#include<gtk/gtk.h>
#include<stdlib.h>
#include<wctype.h>
#include "exc.h"
enum {
ID,
DESTINATION,
HEUREDEPART,
HEURERETOUR,
COLUMNS
};
void afficher_exc(GtkWidget *liste)
{GtkWidget *treeexc;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
char heure_depart[20];
char heure_retour[20];
int id;
char destination[50];
HEURE h_depart;
HEURE h_retour;
exc ex;
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" id",renderer,"text",ID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" destination",renderer,"text", DESTINATION,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" heure_depart",renderer,"text", HEUREDEPART,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" heure_retour",renderer,"text", HEURERETOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

store=gtk_list_store_new(COLUMNS, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

f=fopen("exc.txt","r");
if(f==NULL)
{
return;
}
else 
{f=fopen("exc.txt","a+");
while(fscanf(f,"%d %s %dh%d %dh%d\n",&ex.id,ex.destination,&ex.h_depart.h,&ex.h_depart.m,&ex.h_retour.h,&ex.h_retour.m)!=EOF)
{
sprintf(heure_depart,"%dh%d",ex.h_depart.h, ex.h_depart.m);
sprintf(heure_retour,"%dh%d",ex.h_retour.h, ex.h_retour.m);
gtk_list_store_append(store, &iter);
gtk_list_store_set(store, &iter, ID, ex.id, DESTINATION, ex.destination , HEUREDEPART,heure_depart, HEURERETOUR,heure_retour,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}}
}
void ajouter_exc(exc ex)
{FILE *f;
exc e;
int i=0;
f=fopen("exc.txt","r");
strcpy(e.destination,ex.destination);
e.h_depart.h=ex.h_depart.h;
e.h_depart.m=ex.h_depart.m;
e.h_retour.h=ex.h_retour.h;
e.h_retour.m=ex.h_retour.m;
while(fscanf(f,"%d %s %dh%d %dh%d\n",&ex.id,ex.destination,&ex.h_depart.h,&ex.h_depart.m,&ex.h_retour.h,&ex.h_retour.m)!=EOF)
{if(ex.id>=i)
i=ex.id;}
fclose(f);


f=fopen("exc.txt","a+");
if(f!=NULL)
fprintf(f,"%d %s %dh%d %dh%d\n",i+1,e.destination,e.h_depart.h,e.h_depart.m,e.h_retour.h,e.h_retour.m);
fclose(f);}


void supprimer_exc(int test,exc ex)
{FILE *f,*h;
f=fopen("exc.txt","r");
if (f!=NULL)
{h=fopen("exctest.txt","w+");
while(fscanf(f,"%d %s %dh%d %dh%d\n",&ex.id,ex.destination,&ex.h_depart.h,&ex.h_depart.m,&ex.h_retour.h,&ex.h_retour.m)!=EOF)
if(ex.id!=test)
fprintf(h,"%d %s %dh%d %dh%d\n",ex.id,ex.destination,ex.h_depart.h,ex.h_depart.m,ex.h_retour.h,ex.h_retour.m);
}else printf("File not opened");
fclose(f);
fclose(h);
f=fopen("exc.txt","w+");
h=fopen("exctest.txt","r");
while(fscanf(h,"%d %s %dh%d %dh%d\n",&ex.id,ex.destination,&ex.h_depart.h,&ex.h_depart.m,&ex.h_retour.h,&ex.h_retour.m)!=EOF)
fprintf(f,"%d %s %dh%d %dh%d\n",ex.id,ex.destination,ex.h_depart.h,ex.h_depart.m,ex.h_retour.h,ex.h_retour.m);
fclose(f);fclose(h);
}

void modifier_exc(exc ex,int a)
{FILE *f;
exc copie;
strcpy(copie.destination,ex.destination);

copie.h_depart.h=ex.h_depart.h;
copie.h_depart.m=ex.h_depart.m;

copie.h_retour.h=ex.h_retour.h;
copie.h_retour.m=ex.h_retour.m;


f=fopen("exc.txt","r");
if(f!=NULL)
{while (fscanf(f,"%d %s %dh%d %dh%d\n",&ex.id,ex.destination,&ex.h_depart.h,&ex.h_depart.m,&ex.h_retour.h,&ex.h_retour.m)!=EOF)
if(a==ex.id)
{supprimer_exc(a,ex);
fclose(f);
}
}
f=fopen("exc.txt","a+");
fprintf(f,"%d %s %dh%d %dh%d\n",a,copie.destination,copie.h_depart.h,copie.h_depart.m,copie.h_retour.h,copie.h_retour.m);
fclose(f);
}

int verifexc(int a,exc ex)
{
FILE *f;
int e=0;
f=fopen("exc.txt","r");
if(f!=NULL)
while (fscanf(f,"%d %s %dh%d %dh%d\n",&ex.id,ex.destination,&ex.h_depart.h,&ex.h_depart.m,&ex.h_retour.h,&ex.h_retour.m)!=EOF)
{if (a==ex.id)
e=1;}
fclose(f);
return e;
}




