#include "menu.h"

#include "callbacks.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>

enum{
ID,
REPAS,
DATE_CREATION,
TYPE,
QD,
COLUMNS
};

void ajouter_menu(Menu m)
{

FILE *f=NULL;
f=fopen("menu.txt","a+");
fprintf(f,"%s %s %s %s %s %s %s \n",m.id,m.date_creation.jour,m.date_creation.mois,m.date_creation.annee,m.type,m.repas,m.qd);
fclose(f);

}
void afficher_menu(GtkWidget *liste)
{
Menu m;
char DATE[30];
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
store = NULL;
FILE *fp;
char ch1[30];

store = gtk_tree_view_get_model(liste);
if (store == NULL)
{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Id",renderer,"text",ID,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Repas",renderer,"text",REPAS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Date de Menu",renderer,"text",DATE_CREATION,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Type",renderer,"text",TYPE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" QD",renderer,"text",QD,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
	store = gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	fp = fopen("menu.txt", "r");

	

	
		fp = fopen("menu.txt", "a+");	
		while(fscanf(fp,"%s %s %s %s %s %s %s \n",m.id,m.date_creation.jour,m.date_creation.mois,m.date_creation.annee,m.type,m.repas,m.qd)!=EOF)
		{
		sprintf(ch1,"%s/%s/%s",m.date_creation.jour,m.date_creation.mois,m.date_creation.annee);
	       gtk_list_store_append(store, &iter);
		gtk_list_store_set(store, &iter, ID, m.id, REPAS, m.repas,DATE_CREATION,ch1, TYPE, m.type,  QD, m.qd,-1);
		}
		fclose(fp);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref(store);


}
void supprimer_menu(Menu m, char id[], char type[])
{
Menu m1;
FILE *f;
FILE *ftemp;
f=fopen("menu.txt","r");
ftemp=fopen("menutmp.txt","a+");
while(fscanf(f,"%s %s %s %s %s %s %s ",m1.id,m1.date_creation.jour,m1.date_creation.mois,m1.date_creation.annee,m1.type,m1.repas,m1.qd)!=EOF)
{if (strcmp(id,m1.id)!=0)
fprintf(ftemp,"%s %s %s %s %s %s %s \n",m1.id,m1.date_creation.jour,m1.date_creation.mois,m1.date_creation.annee,m1.type,m1.repas,m1.qd);
}
fclose(f);
fclose(ftemp);
remove("menu.txt");
rename("menutmp.txt","menu.txt");
}




void afficher_menuModif(GtkWidget *liste)
{
Menu m;
char DATE[30];
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

store = NULL;

FILE *fp;



store = gtk_tree_view_get_model(liste);

if (store == NULL)
{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Id",renderer,"text",ID,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Repas",renderer,"text",REPAS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("DatedeMenu",renderer,"text",DATE_CREATION,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Type",renderer,"text",TYPE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("QD",renderer,"text",QD,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
	store = gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	fp = fopen("temp1.txt", "r+");

	
	
		fp = fopen("temp1.txt", "a+");	
		while(fscanf(fp,"%s %s %s %s %s %s %s \n",m.id,m.date_creation.jour,m.date_creation.mois,m.date_creation.annee,m.type,m.repas,m.qd)!=EOF)
	{
		
		gtk_list_store_append(store, &iter);
		gtk_list_store_set(store, &iter, ID, m.id, REPAS, m.repas, TYPE, m.type, DATE_CREATION, DATE, QD, m.qd,-1);
		}
		fclose(fp);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref(store);
	}


void modifier_menu(Menu m1, char id[])
{

Menu m;
FILE*f;
FILE*ftemp;
f=fopen("menu.txt","r");
ftemp=fopen("menutmp.txt","a+");
while(fscanf(f,"%s %s %s %s %s %s %s ",m.id,m.date_creation.jour,m.date_creation.mois,m.date_creation.annee,m.type,m.repas,m.qd)!=EOF)
{if (strcmp(m1.id,m.id)==0)
fprintf(ftemp,"%s %s %s %s %s %s %s \n",m1.id,m1.date_creation.jour,m1.date_creation.mois,m1.date_creation.annee,m1.type,m1.repas,m1.qd);
else
fprintf(ftemp,"%s %s %s %s %s %s %s \n",m.id,m.date_creation.jour,m.date_creation.mois,m.date_creation.annee,m.type,m.repas,m.qd);
}

fclose(f);
fclose(ftemp);
remove("menu.txt");
rename("menutmp.txt","menu.txt");

}

void meilleur_menu_de_la_semaine_nutrition()
{

    char id[50];
    char nom_repas[1000];
    int nbr_dechets;
    int jour;
    int mois;
    int annee;
    char type[50];
Menu best;
int min_nbr_dechets=100;
int aux;
FILE *f, *g;
f=fopen("menu.txt","r");
g=fopen("best_menu.txt","w");
if(f==NULL || g==NULL)
{
return;
}
else
{
    while(fscanf(f,"%s %s %d %d %d %d %s \n",id,nom_repas,&jour,&mois,&annee,&nbr_dechets,type)!=EOF)
{    
aux=nbr_dechets;
if(aux< min_nbr_dechets){
min_nbr_dechets=aux;
strcpy(best.id,id);
strcpy(best.repas,nom_repas);
best.date_creation.jour==jour;
best.date_creation.mois==mois;
best.date_creation.annee==annee;
best.qd==nbr_dechets;
strcpy(best.type,type);
}
}
fprintf(g,"%s %s %s %s %s %s %s \n",best.id,best.repas,best.date_creation.jour,best.date_creation.mois,best.date_creation.annee,best.qd,best.type);
fclose(f);
fclose(g);
}
}












