#include <stdio.h>
#include <string.h>
#include "conshotel.h"
#include <gtk/gtk.h>
#include <stdlib.h>

enum{
ID,
Lieu,
NOM,
DATEDB,
DATEFIN,
NBSING,
NBDOUB,
NBTRIPL,
COLUMNS};

void ajouter_hotel(conshotel h)
{FILE *f;
conshotel b;
b.id=h.id;
strcpy(b.lieu,h.lieu);
strcpy(b.nom,h.nom);
b.datedb.j=h.datedb.j;
b.datedb.m=h.datedb.m;
b.datedb.a=h.datedb.a;
b.datefin.j=h.datefin.j;
b.datefin.m=b.datefin.a;
b.nbchambersing=h.nbchambersing;
b.nbchamberdoubel=h.nbchamberdoubel;
b.nbchambertripl=b.nbchambertripl;
f=fopen("listehotel.txt","a+");
if(f!=NULL)
{
fprintf(f,"%d %s %s %d/%d/%d %d/%d/%d %d %d %d \n",h.id,h.lieu,h.nom,h.datedb.j,h.datedb.m,h.datedb.a,h.datefin.j,h.datefin.m,h.datefin.a,h.nbchambersing,h.nbchamberdoubel,h.nbchambertripl);}
fclose(f);}

void afficher_hotel(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

int id;
char lieu[20];
char nom[20];
DATE datedb ;
DATE datefin ;
int nbchambersing;
int nbchamberdoubel;
int nbchambertripl;
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" id",renderer, "text",ID, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" lieu",renderer, "text",Lieu, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" nom",renderer, "text",NOM, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" datedb", renderer, "text",DATEDB, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" datefin", renderer, "text",DATEFIN, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" nbchambersing", renderer, "text",NBSING, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" nbchamberdoubel", renderer, "text",NBDOUB, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" nbchambertripl", renderer, "text",NBTRIPL, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

store=gtk_list_store_new(COLUMNS, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT,  G_TYPE_INT,  G_TYPE_INT);

f=fopen("listehotel.txt","r");

if(f==NULL)
{
return;
}
else
{f=fopen("listehotel.txt","a+");
while(fscanf(f,"%d %s %s %d/%d/%d %d/%d/%d %s %s %s \n",&h.id,h.lieu,h.nom,&h.datedb.j,&h.datedb.m,&h.datedb.a,&h.datefin.j,&h.datefin.m,&h.datefin.a,&nbchambersing,&nbchamberdoubel,&nbchambertripl)!=EOF)
{sprintf(db,"%d/%d/%d",h.datedb.j,h.datedb.m,h.datedb.a);
sprintf(fin,"%d/%d/%d",h.datefin.j,h.datefin.m,h.datefin.a);
gtk_list_store_append(store, &iter);
gtk_list_store_set (store, &iter, ID, id, LIEU, lieu, NOM, nom, DATEDB, db,DATEFIN,fin,NBSING,nbchambersing,NBDOUB,nbchamberdoubel,NBTRIPL,nbchambertripl, -1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}}
void supprimerhotel(int suph,conshotel h)
{FILE *f,*h;
f=fopen("listehotel.txt","r");
if (f!=NULL)
{h=fopen("listehotels.txt","w+");
while(fscanf(f,"%d %s %s %d/%d/%d %d/%d/%d %d %d %d \n",&h.id,h.lieu,h.nom,&h.datedb.j,&h.datedb.m,&h.datedb.a,&h.datefin.j,&h.datefin.m,&h.datefin.a,&h.nbchambersing,&h.nbchamberdoubel,&h.nbchambertripl)!=EOF)
if(h.nom!=suph)
fprintf(h,"%d %s %s %d/%d/%d %d/%d/%d %d %d %d \n",h.id,h.lieu,h.nom,h.datedb.j,h.datedb.m,h.datedb.a,h.datefin.j,h.datefin.m,h.datefin.a,h.nbchambersing,h.nbchamberdoubel,h.nbchambertripl);
}else printf("File not opened");
fclose(h);
fclose(f);
f=fopen("listehotel.txt","w+");
h=fopen("listehotels.txt","r");
while(fscanf(h,"%d %s %s %d/%d/%d %d/%d/%d %d %d %d \n",&h.id,h.lieu,h.nom,&h.datedb.j,&h.datedb.m,&h.datedb.a,&h.datefin.j,&h.datefin.m,&h.datefin.a,&h.nbchambersing,&h.nbchamberdoubel,&h.nbchambertripl)!=EOF)
fprintf(f,"%d %s %s %d/%d/%d %d/%d/%d %d %d %d \n",h.id,h.lieu,h.nom,h.datedb.j,h.datedb.m,h.datedb.a,h.datefin.j,h.datefin.m,h.datefin.a,h.nbchambersing,h.nbchamberdoubel,h.nbchambertripl);
fclose(h);fclose(f);
}

