#include <gtk/gtk.h>

typedef struct
{
char localisation[20];
char nom[20];
char datedb [20];
char datefin [20];
char nbchambersing[20];
char nbchamberdoubel[20];
char nbchambertripl[20];
}conshotel;

void ajouter_hotel(conshotel hotel);
void afficher_hotel(GtkWidget *liste);
void supprimerhotel(char suphotel[20],conshotel hotel);
