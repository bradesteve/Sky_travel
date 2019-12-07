#include<stdio.h>
#include<string.h>
#include"compteadmin.h"
#include<gtk/gtk.h>

void modifnom(char nomadmin[30])
{FILE *f,*f1;
char user[20];char pwd[30];int role;char passwd[30];
f=fopen("/home/smir/Projects/project3/src/users.txt","r");
f1=fopen("/home/smir/Projects/project3/src/userss.txt","w+");
while (fscanf(f,"%s %s %d\n",user,pwd,&role)!=EOF)
{
if (role!=1) fprintf(f1,"%s %s %d \n",user,pwd,role);
if (role==1)strcpy(passwd,pwd);}
fclose(f1);
fclose(f);
f=fopen("/home/smir/Projects/project3/src/users.txt","w+");
f1=fopen("/home/smir/Projects/project3/src/userss.txt","r");
while(fscanf(f1,"%s %s %d\n",user,pwd,&role)!=EOF)
{fprintf(f,"%s %s %d\n",user,pwd,role);}
fprintf(f,"%s %s %d\n",nomadmin,passwd,1);
fclose(f);
fclose(f1);
}


int verifpwd(char apwd[20],char npwd[20],char cpwd[20])
{char user[30];char pwd[30];int role,t1=-1,t2=-1,t=-1;
FILE *f;
f=fopen("/home/smir/Projects/project3/src/users.txt","r");

t2=strcmp(npwd,cpwd);
while (fscanf(f,"%s %s %d\n",user,pwd,&role)!=EOF)
{t1=strcmp(apwd,pwd);
if ((role==1)&&(t1==0)&&(t2==0)) t=0;}
fclose(f);
return(t);}


void modifpwd(char npwd[20])
{char user[30];char pwd[30];int role;char nomadmin[30];
FILE *f,*f1;
f=fopen("/home/smir/Projects/project3/src/users.txt","r");
f1=fopen("/home/smir/Projects/project3/src/userss.txt","w+");
while (fscanf(f,"%s %s %d \n",user,pwd,&role)!=EOF)
{if (role==1) strcpy(nomadmin,user);
if (role!=1) fprintf(f1,"%s %s %d \n",user,pwd,role);}
fclose(f);
fclose(f1);
f=fopen("/home/smir/Projects/project3/src/users.txt","w+");
f1=fopen("/home/smir/Projects/project3/src/userss.txt","r");
while(fscanf(f1,"%s %s %d",user,pwd,&role)!=EOF)
{fprintf(f,"%s %s %d\n",user,pwd,role);}
fprintf(f,"%s %s %d\n",nomadmin,npwd,1);
fclose(f);
fclose(f1);

}


