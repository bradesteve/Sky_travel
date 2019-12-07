#include <gtk/gtk.h>
typedef struct{
int j;
int m;
int a;
}DATE
typedef struct
{
int id;
char lieu[20];
char nom[20];
DATE datedb ;
DATE datefin;
int nbchambersing;
int nbchamberdoubel;
int nbchambertripl;
}conshotel;

void ajouter_hotel(conshotel hotel);
void afficher_hotel(GtkWidget *liste);
void supprimerhotel(char suphotel[20],conshotel hotel);
