#include <gtk/gtk.h>
typedef struct{
int j;
int m;
int a;
}DATEH;
typedef struct
{
int id;
char lieu[20];
char nom[20];
DATEH datedb ;
DATEH datefin;
int nbchambersing;
int nbchamberdoubel;
int nbchambertripl;
}conshotel;

void ajouter_hotel(conshotel h);
void afficher_hotel(GtkWidget *liste);
void supprimerhotel(int suphotel,conshotel h);
