#include <gtk/gtk.h>

typedef struct{
int j;
int m;
int a;
}DATE;
typedef struct
{
int id;
char nom[20];
char prenom[20];
int cin;
char email [80];
char adresse[20];
int telephone;
DATE datenaissance;
char username[20];
char password[20]; 
}adherent;

void afficher_adherent(GtkWidget *liste);
void ajouter_adherent(adherent ad);

void supprimer_adherent(int test,adherent ad);
void modifier_adherent(adherent ad, int a);
int verif(int a,adherent ad);
