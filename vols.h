#include <gtk/gtk.h>

typedef struct
{

int j;
int m;
int a;

}Date;


typedef struct
{

int id;
char nom[10];
char depart[20];
char retour[20];
Date d_depart;
Date d_retour;
char name[30];
char prenom[30];
int cin;

}volR;


void afficher_volR(GtkWidget *liste);
void supprimer_volR(int test,volR v);
void ajouter_volR(volR v);
void modifier_volR(volR v,int a);
int verif(int a,volR v);
