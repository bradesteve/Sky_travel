#include <stdio.h>
#include <string.h>
#include "conshotel.h"
#include <gtk/gtk.h>
#include <stdlib.h>

enum{
LOCALISATION,
NOM,
DATEDB,
DATEFIN,
NBSING,
NBDOUB,
NBTRIPL,
COLUMNS};

void ajouter_hotel(conshotel hotel)
{FILE *f;
f=fopen("listehotel.txt","a+");
if(f!=NULL)
{
fprintf(f,"%s %s %s %s %s %s %s \n",hotel.localisation,hotel.nom,hotel.datedb,hotel.datefin,hotel.nbchambersing,hotel.nbchamberdoubel,hotel.nbchambertripl);}
fclose(f);}

void afficher_hotel(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char localisation[20];
char nom[20];
char datedb [20];
char datefin [20] ;
char nbchambersing[20];
char nbchamberdoubel[20];
char nbchambertripl[20];
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" localisation",renderer, "text",LOCALISATION, NULL);
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

store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

f=fopen("listehotel.txt","r");

if(f==NULL)
{
return;
}
else
{f=fopen("listehotel.txt","a+");
while(fscanf(f,"%s %s %s %s %s %s %s \n",localisation,nom,datedb,datefin,nbchambersing,nbchamberdoubel,nbchambertripl)!=EOF)
{
gtk_list_store_append(store, &iter);
gtk_list_store_set (store, &iter, LOCALISATION, localisation, NOM, nom, DATEDB, datedb,DATEFIN,datefin,NBSING,nbchambersing,NBDOUB,nbchamberdoubel,NBTRIPL,nbchambertripl, -1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}}
void supprimerhotel(char suphotel[20],conshotel hotel)
{FILE *f,*h;
f=fopen("listehotel.txt","r");
if (f!=NULL)
{h=fopen("listehotels.txt","w+");
while(fscanf(f,"%s %s %s %s %s %s %s\n",hotel.localisation,hotel.nom,hotel.datedb,hotel.datefin,hotel.nbchambersing,hotel.nbchamberdoubel,hotel.nbchambertripl)!=EOF)
if(strcmp(hotel.nom,suphotel)!=0)
fprintf(h,"%s %s %s %s %s %s  %s\n",hotel.localisation,hotel.nom,hotel.datedb,hotel.datefin,hotel.nbchambersing,hotel.nbchamberdoubel,hotel.nbchambertripl);
}else printf("File not opened");
fclose(h);
fclose(f);
f=fopen("listehotel.txt","w+");
h=fopen("listehotels.txt","r");
while(fscanf(h,"%s %s %s %s %s %s  %s\n",hotel.localisation,hotel.nom,hotel.datedb,hotel.datefin,hotel.nbchambersing,hotel.nbchamberdoubel,hotel.nbchambertripl)!=EOF)
fprintf(f,"%s %s %s %s %s %s  %s\n",hotel.localisation,hotel.nom,hotel.datedb,hotel.datefin,hotel.nbchambersing,hotel.nbchamberdoubel,hotel.nbchambertripl);
fclose(h);fclose(f);
}

