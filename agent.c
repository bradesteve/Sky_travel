#include<stdio.h>
#include<string.h>
#include "agent.h"
#include<gtk/gtk.h>

enum
{
	MATRICULE,
	NOM,
	PRENOM,
	NAISSANCE,
	CIN,
	ADRESSE,
	FONCTION,
	TELEPHONE,
	EMBAUCHE,
	SALAIRE,
	CIVILITE,
	COLUMNS};
void ajouteragent(Agent a)
{
Agent h;
FILE *f ;FILE *f1;
int x=2;int i=0;

h.naissance.jour=a.naissance.jour;
h.naissance.mois=a.naissance.mois;
h.naissance.annee=a.naissance.annee;
h.embauche.jour=a.embauche.jour;
h.embauche.mois=a.embauche.mois;
h.embauche.annee=a.embauche.annee;
strcpy(h.nom,a.nom);
strcpy(h.prenom,a.prenom);
h.cin=a.cin;
strcpy(h.adresse,a.adresse);
strcpy(h.fonction,a.fonction);
strcpy(h.telephone,a.telephone);
strcpy(h.salair,a.salair);
strcpy(h.civilite,a.civilite);
f1=fopen("/home/smir/Projects/project3/src/agent.txt","r");
while (fscanf(f1,"%d %s %s %d/%d/%d %d %s %s %s %d/%d/%d %s %s\n",&a.matricule,a.nom,a.prenom,&a.naissance.jour,&a.naissance.mois,&a.naissance.annee,&a.cin,a.adresse,a.fonction,a.telephone,&a.embauche.jour,&a.embauche.mois,&a.embauche.annee,a.salair,a.civilite)!=EOF){
if(i<=a.matricule)
i=a.matricule;}
fclose(f1);
f=fopen("/home/smir/Projects/project3/src/agent.txt","a+");
f1=fopen("/home/smir/Projects/project3/src/utlisateur.txt","a+");
if(f!=NULL)
{fprintf(f,"%d %s %s %d/%d/%d %d %s %s %s %d/%d/%d %s %s\n",i+1,h.nom,h.prenom,h.naissance.jour,h.naissance.mois,h.naissance.annee,h.cin,h.adresse,h.fonction,h.telephone,h.embauche.jour,h.embauche.mois,h.embauche.annee,h.salair,h.civilite);
fprintf(f1,"%s %s %d \n",a.nom,a.prenom,x);
}
fclose(f);
fclose(f1);
}
void afficher_agent(GtkWidget *liste)
{
GtkWidget *treeview1;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
Agent a;

int matricule;
char nom [30];
char prenom[30];
DATE naissance;
int cin;
char adresse[30];
char fonction[30];
char telephone[15];
DATE embauche ;
char salair[15];
char civilite [15];

store=NULL;

char naisance[30],ambauche[30];
FILE *f;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer= gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes(" matricule",renderer,"text",MATRICULE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer= gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes(" nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer= gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes(" prenom",renderer,"text",PRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer= gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes(" cin",renderer,"text",CIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer= gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes(" naisance",renderer,"text",NAISSANCE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer= gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes(" adresse",renderer,"text",ADRESSE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer= gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes(" fonction",renderer,"text",FONCTION,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer= gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes(" telephone",renderer,"text",TELEPHONE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer= gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes(" ambauche",renderer,"text",EMBAUCHE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer= gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes(" salair",renderer,"text",SALAIRE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer= gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes(" civilite",renderer,"text",CIVILITE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

store=gtk_list_store_new(COLUMNS, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f=fopen("/home/smir/Projects/project3/src/agent.txt","r");
if(f==NULL)
{return ;
}
else
{fclose(f);f=fopen("/home/smir/Projects/project3/src/agent.txt","a+");
while(fscanf(f,"%d %s %s %d/%d/%d %d %s %s %s %d/%d/%d %s %s\n",&a.matricule,a.nom,a.prenom,&a.naissance.jour,&a.naissance.mois,&a.naissance.annee,&a.cin,a.adresse,a.fonction,a.telephone,&a.embauche.jour,&a.embauche.mois,&a.embauche.annee,a.salair,a.civilite)!=EOF)
{sprintf(naisance,"%d/%d/%d",a.naissance.jour,a.naissance.mois,a.naissance.annee);
sprintf(ambauche,"%d/%d/%d",a.embauche.jour,a.embauche.mois,a.embauche.annee);

gtk_list_store_append (store,&iter);
gtk_list_store_set(store,&iter,MATRICULE,a.matricule,NOM,a.nom,PRENOM,a.prenom,NAISSANCE,naisance,CIN,a.cin,ADRESSE,a.adresse,FONCTION,a.fonction,TELEPHONE,a.telephone,EMBAUCHE,ambauche,SALAIRE,a.salair,CIVILITE,a.civilite,  -1);}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);}
}}
void supprimeragent(int supagent,Agent a)
{FILE *f,*h;

f=fopen("/home/smir/Projects/project3/src/agent.txt","r");
if (f!=NULL)
{h=fopen("/home/smir/Projects/project3/src/agents.txt","w+");
while(fscanf(f,"%d %s %s %d/%d/%d %d %s %s %s %d/%d/%d %s %s\n",&a.matricule,a.nom,a.prenom,&a.naissance.jour,&a.naissance.mois,&a.naissance.annee,&a.cin,a.adresse,a.fonction,a.telephone,&a.embauche.jour,&a.embauche.mois,&a.embauche.annee,a.salair,a.civilite)!=EOF)
if(a.matricule!=supagent)
fprintf(h,"%d %s %s %d/%d/%d %d %s %s %s %d/%d/%d %s %s\n",a.matricule,a.nom,a.prenom,a.naissance.jour,a.naissance.mois,a.naissance.annee,a.cin,a.adresse,a.fonction,a.telephone,a.embauche.jour,a.embauche.mois,a.embauche.annee,a.salair,a.civilite);
}else printf("File not opened");
fclose(h);
fclose(f);
f=fopen("/home/smir/Projects/project3/src/agent.txt","w+");
h=fopen("/home/smir/Projects/project3/src/agents.txt","r");
while(fscanf(h,"%d %s %s %d/%d/%d %d %s %s %s %d/%d/%d %s %s\n",&a.matricule,a.nom,a.prenom,&a.naissance.jour,&a.naissance.mois,&a.naissance.annee,&a.cin,a.adresse,a.fonction,a.telephone,&a.embauche.jour,&a.embauche.mois,&a.embauche.annee,a.salair,a.civilite)!=EOF)

fprintf(f,"%d %s %s %d/%d/%d %d %s %s %s %d/%d/%d %s %s\n",a.matricule,a.nom,a.prenom,a.naissance.jour,a.naissance.mois,a.naissance.annee,a.cin,a.adresse,a.fonction,a.telephone,a.embauche.jour,a.embauche.mois,a.embauche.annee,a.salair,a.civilite);
fclose(h);fclose(f);
}
void modifagent(int i,Agent a)
{
Agent h;
FILE *f,l ;
h.matricule=a.matricule;
h.naissance.jour=a.naissance.jour;
h.naissance.mois=a.naissance.mois;h.naissance.annee=a.naissance.annee;
h.embauche.jour=a.embauche.jour;h.embauche.mois=a.embauche.mois;h.embauche.annee=a.embauche.annee;
strcpy(h.nom,a.nom);
strcpy(h.prenom,a.prenom);
h.cin=a.cin;
strcpy(h.adresse,a.adresse);
strcpy(h.fonction,a.fonction);
strcpy(h.telephone,a.telephone);
strcpy(h.salair,a.salair);
strcpy(h.civilite,a.civilite);

if(f!=NULL){
f=fopen("/home/smir/Projects/project3/src/agent.txt","r");
while (fscanf(f,"%d %s %s %d/%d/%d %d %s %s %s %d/%d/%d %s %s\n",&a.matricule,a.nom,a.prenom,&a.naissance.jour,&a.naissance.mois,&a.naissance.annee,&a.cin,a.adresse,a.fonction,a.telephone,&a.embauche.jour,&a.embauche.mois,&a.embauche.annee,a.salair,a.civilite)!=EOF){if (i==a.matricule) supprimeragent(i,a);}
fclose(f);}
f=fopen("/home/smir/Projects/project3/src/agent.txt","a+");
fprintf(f,"%d %s %s %d/%d/%d %d %s %s %s %d/%d/%d %s %s\n",h.matricule,h.nom,h.prenom,h.naissance.jour,h.naissance.mois,h.naissance.annee,h.cin,h.adresse,h.fonction,h.telephone,h.embauche.jour,h.embauche.mois,h.embauche.annee,h.salair,h.civilite);
fclose(f);}



int verifagent(int x,Agent a)
{
FILE *f;
int e=0;
f=fopen("/home/smir/Projects/project3/src/agent.txt","r");
if(f!=NULL){
while (fscanf(f,"%d %s %s %d/%d/%d %d %s %s %s %d/%d/%d %s %s \n",&a.matricule,a.nom,a.prenom,&a.naissance.jour,&a.naissance.mois,&a.naissance.annee,&a.cin,a.adresse,a.fonction,a.telephone,&a.embauche.jour,&a.embauche.mois,&a.embauche.annee,a.salair,a.civilite)!=EOF)
{if (x==a.matricule)
e=1;}}
fclose(f);
return e;
}

