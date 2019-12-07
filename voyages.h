#include <gtk/gtk.h>

typedef struct
{

int h;
int m;

}Heure;

typedef struct
{

int j;
int m;
int a;

}Date;



typedef struct
{

int id;
char nom[30];
char description[255];
Date d_voyage;
Heure h_depart;
Heure h_arrivee;
char name[30];
char prenom[30];
int cin;


}voyageR;


void afficher_voyageR(GtkWidget *liste);
void supprimer_voyageR(int test,voyageR vo);
void ajouter_voyageR(voyageR vo);
void modifier_voyageR(voyageR vo,int a);
int verif(int a,voyageR vo);
