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
char lieu[30];
Date date_in;
Date date_out;
int nb_single;
int nb_double;
int nb_triple;
char name[30];
char prenom[30];
int cin;

}hotelR;


void afficher_hotelR(GtkWidget *liste);
void supprimer_hotelR(int test,hotelR h);
void ajouter_hotelR(hotelR h);
void modifier_hotelR(hotelR h,int a);
int verif(int a,hotelR h);