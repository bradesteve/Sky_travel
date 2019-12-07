#include <gtk/gtk.h>

typedef struct
{

int j;
int m;
int a;

}Date;

typedef struct
{

int h;
int m;

}Heure;



typedef struct
{

int id;
char taille[20];
Date date_prise;
Date date_retour;
Heure h_prise;
Heure h_retour;
char name[30];
char prenom[30];
int cin;

}busR;


void afficher_busR(GtkWidget *liste);
void supprimer_busR(int test,busR vi);
void ajouter_busR(busR bu);
void modifier_busR(busR bu,int a);
int verif(int a,busR bu);
