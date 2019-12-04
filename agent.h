#include <gtk/gtk.h>
typedef struct {
int jour;
int mois;
int annee;
}DATE;
typedef struct
{
char nom[30];
char prenom[30];
DATE naissance;
int cin;
char adresse[30];
char fonction[30];
char telephone[15];
DATE embauche ;
char salair[15];
char civilite [15];
int matriqule;
}Agent;
void ajouteragent(Agent a);
void afficher_agent(GtkWidget *liste);
void supprimeragent(int supagent,Agent a);

