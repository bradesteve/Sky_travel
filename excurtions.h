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
Date d_excurtion;
Heure h_depart;
Heure h_arrivee;
char name[30];
char prenom[30];
int cin;


}excurtionR;


void afficher_excurtionR(GtkWidget *liste);
void supprimer_excurtionR(int test,excurtionR ex);
void ajouter_excurtionR(excurtionR ex);
void modifier_excurtionR(excurtionR ex,int a);
int verif(int a,excurtionR ex);
