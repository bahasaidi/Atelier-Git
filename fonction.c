#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"
#include <gtk/gtk.h>

enum
{
    EID,
    EP_N,
    EROLE,
    EN_U,
    EMDP,
    EETAT,
    ECONFIRMER,
    EJOUR_FCT,
    EMOIS_FCT,
    EANNEE_FCT,
    ESEXE,
    COLUMNS,
};

    
void ajouter(user n)
{

 FILE *f;
 f=fopen("user.txt","a+");
 if(f!=NULL)
 {
 fprintf(f,"%s %s %s %s %s %s %s %s %d %d %d\n",n.id,n.p_n,n.role,n.n_u,n.mdp,n.etat,n.confirmer,n.sexe,n.date_mise_fct.jour,n.date_mise_fct.mois,n.date_mise_fct.annee);

 fclose(f);
 }
////****************************///////////////////********///////////////**********///////////***********////////******////
}

void afficher(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char id[20];
char p_n[20];
char role[20];
char n_u[20];
char mdp[20];
char etat[20];
char confirmer[20];
char jour_fct[20];
char mois_fct[20];
char annee_fct[20];
char sexe[20];


store =NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);

if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("id",renderer,"text",EID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("P_N",renderer,"text",EP_N,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("role",renderer,"text",EROLE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("Nom_U",renderer,"text",EN_U,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("mdp",renderer,"text",EMDP,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("etat_civil",renderer,"text",EETAT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("confirmer",renderer,"text",ECONFIRMER,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",ESEXE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	
	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("jour",renderer,"text",EJOUR_FCT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("mois",renderer,"text",EMOIS_FCT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("annee",renderer,"text",EANNEE_FCT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	


	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("user.txt","r");

	if(f==NULL)
	{
		return;
	}
	else
	
	{ 
	f=fopen("user.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s \n",id,p_n,role,n_u,mdp,etat,confirmer,sexe,jour_fct,mois_fct,annee_fct)!=EOF)
		{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,EID,id,EP_N,p_n,EROLE,role,EN_U,n_u,EMDP,mdp,EETAT,etat,ECONFIRMER,confirmer,EJOUR_FCT,jour_fct,EMOIS_FCT,mois_fct,EANNEE_FCT,annee_fct,ESEXE,sexe,-1);
		}
	   fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);
	}
}
}

void chercher(GtkWidget *liste, char ref[])
{
    
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char id[20];
char p_n[20];
char role[20];
char n_u[20];
char mdp[20];
char etat[20];
char confirmer[20];
char jour_fct[20];
char mois_fct[20];
char annee_fct[20];
char sexe[20];


store =NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);

if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("id",renderer,"text",EID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("p_n",renderer,"text",EP_N,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("role",renderer,"text",EROLE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("n_u",renderer,"text",EN_U,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("mdp",renderer,"text",EMDP,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("etat",renderer,"text",EETAT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("confirmer",renderer,"text",ECONFIRMER,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",ESEXE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	
	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("jour",renderer,"text",EJOUR_FCT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("mois",renderer,"text",EMOIS_FCT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("annee",renderer,"text",EANNEE_FCT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	


	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("user.txt","r");

	if(f==NULL)
	{
		return;
	}
	else
	
	{ 
	f=fopen("user.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s \n",id,p_n,role,n_u,mdp,etat,confirmer,sexe,jour_fct,mois_fct,annee_fct)!=EOF)
		{
            if(strcmp(id,ref)==0)
{
			gtk_list_store_append(store,&iter);
/*******/////////////////////////////////*************////////////////***************//////////////////**************////////////////////***************//////
			gtk_list_store_set(store,&iter,EID,id,EP_N,p_n,EROLE,role,EN_U,n_u,EMDP,mdp,EETAT,etat,ECONFIRMER,confirmer,EJOUR_FCT,jour_fct,EMOIS_FCT,mois_fct,EANNEE_FCT,annee_fct,ESEXE,sexe,-1);
}
		}
	   fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);
	}
}
}

void modifier(user n)
{
    char id1[20];	
    char p_n1[20];
    char role1[20];
    char n_u1[20];
    char mdp1[20];
    char confirmer1[20];
    char sexe1[20];
    char etat1[20];
    int jdf;
    int mdf;
    int adf;
	

FILE *f;
FILE *f1;

f=fopen("user.txt","r");
f1=fopen("modif.txt","a+");
while (fscanf(f,"%s %s %s %s %s %s %s %s %d %d %d \n",id1,p_n1,role1,n_u1,mdp1,etat1,confirmer1,sexe1,&jdf,&mdf,&adf)!=EOF)
{
if (strcmp(n.id,id1)==0)
	fprintf(f1,"%s %s %s %s %s %s %s %s %d %d %d\n",n.id,n.p_n,n.role,n.n_u,n.mdp,n.etat,n.confirmer,n.sexe,n.date_mise_fct.jour,n.date_mise_fct.mois,n.date_mise_fct.annee);

else
	fprintf(f1,"%s %s %s %s %s %s %s %s %d %d %d\n",id1,p_n1,role1,n_u1,mdp1,etat1,confirmer1,sexe1,jdf,mdf,adf);

}
fclose(f);
fclose(f1);
remove("user.txt");
rename("modif.txt","user.txt");
}
/////////*****************//////////////////////**********************//////////////////********************//////////////**********
void supprimer(char refsp[])
{
FILE *f;
FILE *f1;
user n;
f=fopen("user.txt","r");
f1=fopen("doc.txt","a+");
while (fscanf(f,"%s %s %s %s %s %s %s %s %d %d %d \n",n.id,n.p_n,n.role,n.n_u,n.mdp,n.etat,n.confirmer,n.sexe,&n.date_mise_fct.jour,&n.date_mise_fct.mois,&n.date_mise_fct.annee)!=EOF)
{
	if (strcmp(n.id,refsp)!=0)	
	fprintf(f1,"%s %s %s %s %s %s %s %s %d %d %d\n",n.id,n.p_n,n.role,n.n_u,n.mdp,n.etat,n.confirmer,n.sexe,n.date_mise_fct.jour,n.date_mise_fct.mois,n.date_mise_fct.annee);

}
fclose(f);
fclose(f1);
remove("user.txt");
rename("doc.txt","user.txt");
}


int verif(char ref[])
{
    
    FILE *f=NULL;
    user n;
    int test;
    f=fopen("user.txt","r");
    test=0;
    if(f!=NULL)
    {
       while(fscanf(f,"%s %s %s %s %s %s %s %s %d %d %d \n",n.id,n.p_n,n.role,n.n_u,n.mdp,n.etat,n.confirmer,n.sexe,&n.date_mise_fct.jour,&n.date_mise_fct.mois,&n.date_mise_fct.annee)!=EOF)
       {
         if(strcmp(n.id,ref)==0)
        {
          test=1;
          break;
        }

       }
     fclose(f);
     }
return(test);
}

