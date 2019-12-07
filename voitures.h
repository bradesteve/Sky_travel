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
Date date_prise;
Date date_retour;
Heure h_prise;
Heure h_retour;
char name[30];
char prenom[30];
int cin;

}voitureR;


void afficher_voitureR(GtkWidget *liste);
void supprimer_voitureR(int test,voitureR vi);
void ajouter_voitureR(voitureR vi);
void modifier_voitureR(voitureR vi,int a);
int verif(int a,voitureR vi);

