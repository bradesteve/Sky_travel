#include <gtk/gtk.h>

typedef struct{
int h;
int m;
}HEURE;
typedef struct{
int id;
char destination[50];
HEURE h_depart;
HEURE h_retour;
}exc;
void ajouter_exc(exc ex);
void afficher_exc(GtkWidget *liste);
void supprimer_exc(int test,exc ex);
void modifier_exc(exc ex,int a);
int verifexc(int a,exc ex);
