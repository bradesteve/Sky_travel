#include<stdio.h>
#include<string.h>
#include "agent.h"
#include<gtk/gtk.h>

enum
{
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
	MATRIQULE,
	COLUMNS};
void ajouteragent(Agent a)
{
char bnom[30],bprenom[30],badresse[30],bfonction[30],btelephone[15],bsalair[15],bcivilite[15],naissance[10],bnaissance[10],embauche[10],bembauche[10];
int bcin,bmatriqule;
FILE *f ;FILE *f1;
int x=2;int i;
sprintf(naissance,"%d/%d/%d",a.naissance.jour,a.naissance.mois,a.naissance.annee);
sprintf(embauche,"%d/%d/%d",a.embauche.jour,a.embauche.mois,a.embauche.annee);
strcpy(bnaissance,naissance);
strcpy(bembauche,embauche);
strcpy(bnom,a.nom);
strcpy(bprenom,a.prenom);
bcin=a.cin;
strcpy(badresse,a.adresse);
strcpy(bfonction,a.fonction);
strcpy(btelephone,a.telephone);
strcpy(bsalair,a.salair);
strcpy(bcivilite,a.civilite);

if(f!=NULL){
f1=fopen("/home/smir/Projects/project3/src/agent.txt","r");
while (fscanf(f1,"%s %s %s %d %s %s %s %s %s %s %d  \n",bnom,bprenom,bnaissance,&bcin,badresse,bfonction,btelephone,bembauche,bsalair,bcivilite,&bmatriqule)!=EOF){
i=bmatriqule;}
fclose(f);}
i++;
a.matriqule=i;
f=fopen("/home/smir/Projects/project3/src/agent.txt","a+");
f1=fopen("/home/smir/Projects/project3/src/utlisateur.txt","a+");
if(f!=NULL)
{fprintf(f,"%s %s %s %d %s %s %s %s %s %s %d  \n",a.nom,a.prenom,naissance,a.cin,a.adresse,a.fonction,a.telephone,embauche,a.salair,a.civilite,a.matriqule);
fprintf(f1,"%s %d %d \n",a.nom,a.cin,x);
}
fclose(f);
fclose(f1);
}
void afficher_agent(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

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
int matriqule;
store=NULL;
Agent a;
char naisance[12],ambauche[12];
FILE *f;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer= gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes(" matriqule",renderer,"text",MATRIQULE,NULL);
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
column=gtk_tree_view_column_new_with_attributes(" naissance",renderer,"text",NAISSANCE,NULL);
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
column=gtk_tree_view_column_new_with_attributes(" embauche",renderer,"text",EMBAUCHE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer= gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes(" salair",renderer,"text",SALAIRE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer= gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes(" civilite",renderer,"text",CIVILITE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT);
f=fopen("/home/smir/Projects/project3/src/agent.txt","r");
if(f==NULL)
{return ;
}
else
{fclose(f);f=fopen("/home/smir/Projects/project3/src/agent.txt","a+");
while(fscanf(f,"%s %s %d/%d/%d %d %s %s %s %d/%d/%d %s %s %d \n",a.nom,a.prenom,&a.naissance.jour,&a.naissance.mois,&a.naissance.annee,&a.cin,a.adresse,a.fonction,a.telephone,&a.embauche.jour,&a.embauche.mois,&a.embauche.annee,a.salair,a.civilite,&a.matriqule)!=EOF)
{
sprintf(naisance,"%d/%d/%d",a.naissance.jour,a.naissance.mois,a.naissance.annee);
sprintf(ambauche,"%d/%d/%d",a.embauche.jour,a.embauche.mois,a.embauche.annee);
gtk_list_store_append (store,&iter);
gtk_list_store_set(store,&iter,NOM,a.nom,PRENOM,a.prenom,NAISSANCE,naisance,CIN,a.cin,ADRESSE,a.adresse,FONCTION,a.fonction,TELEPHONE,a.telephone,EMBAUCHE,ambauche,SALAIRE,a.salair,CIVILITE,a.civilite,MATRIQULE,a.matriqule,  -1);}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);}
}}
void supprimeragent(int supagent,Agent a)
{FILE *f,*h;
char naisance[10],ambauche[10];
sprintf(naisance,"%d/%d/%d",a.naissance.jour,a.naissance.mois,a.naissance.annee);
sprintf(ambauche,"%d/%d/%d",a.embauche.jour,a.embauche.mois,a.embauche.annee);
f=fopen("/home/smir/Projects/project3/src/agent.txt","r");
if (f!=NULL)
{h=fopen("/home/smir/Projects/project3/src/agents.txt","w+");
while(fscanf(f,"%s %s %d/%d/%d %d %s %s %s %d/%d/%d %s %s %d \n",a.nom,a.prenom,&a.naissance.jour,&a.naissance.mois,&a.naissance.annee,&a.cin,a.adresse,a.fonction,a.telephone,&a.embauche.jour,&a.embauche.mois,&a.embauche.annee,a.salair,a.civilite,&a.matriqule)!=EOF)
if(a.matriqule!=supagent)
fprintf(h,"%s %s %d/%d/%d %d %s %s %s %d/%d/%d %s %s %d \n",a.nom,a.prenom,a.naissance.jour,a.naissance.mois,a.naissance.annee,a.cin,a.adresse,a.fonction,a.telephone,a.embauche.jour,a.embauche.mois,a.embauche.annee,a.salair,a.civilite,a.matriqule);
}else printf("File not opened");
fclose(h);
fclose(f);
f=fopen("/home/smir/Projects/project3/src/agent.txt","w+");
h=fopen("/home/smir/Projects/project3/src/agents.txt","r");
while(fscanf(h,"%s %s %d/%d/%d %d %s %s %s %d/%d/%d %s %s %d \n",a.nom,a.prenom,&a.naissance.jour,&a.naissance.mois,&a.naissance.annee,&a.cin,a.adresse,a.fonction,a.telephone,&a.embauche.jour,&a.embauche.mois,&a.embauche.annee,a.salair,a.civilite,&a.matriqule)!=EOF)

fprintf(f,"%s %s %d/%d/%d %d %s %s %s %d/%d/%d %s %s %d \n",a.nom,a.prenom,a.naissance.jour,a.naissance.mois,a.naissance.annee,a.cin,a.adresse,a.fonction,a.telephone,a.embauche.jour,a.embauche.mois,a.embauche.annee,a.salair,a.civilite,a.matriqule);
fclose(h);fclose(f);
}

