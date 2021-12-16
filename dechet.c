#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h> 
#include "dechet.h"

enum{
JOUR,
TEMPS,
VALEUR,
COLUMNS
};

void afficher_meilleure_menu(GtkWidget * liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

int jour;
char temps[20];
float valeur;
int jour_max;
char temps_max[20];
float valeur_max=47.00;
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("jour",renderer,"text",JOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("temps",renderer,"text",TEMPS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("valeur",renderer,"text",VALEUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



store=gtk_list_store_new(COLUMNS,G_TYPE_INT,G_TYPE_STRING,G_TYPE_FLOAT,G_TYPE_STRING);

f=fopen("dechets.txt","r");
if(f==NULL)
{return;}
else
{
f=fopen("dechets.txt","a+");
fscanf(f,"%d %s %f\n",&jour_max,temps_max,&valeur_max);
while(fscanf(f,"%d %s %f\n",&jour,temps,&valeur)!=EOF)
{
if(valeur_max>valeur)
{
jour_max=jour;
strcmp(temps_max,temps);
valeur_max=valeur;
}
}
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,JOUR,jour_max,TEMPS,temps_max,VALEUR,valeur_max,-1);
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);

}
}
}
/*void meilleur_menu_de_la_semaine_nutrition()
{

    int jour;
    char temps[1000];
  
    float valeur;
dechet D;
int min_valeur=100;
int aux;
FILE *f, *g;
f=fopen("dechets.txt","r");
g=fopen("best_menu.txt","w");
if(f==NULL || g==NULL)
{
return;
}
else
{
    while(fscanf(f,"%d %s %f\n",&jour,temps,&valeur)!=EOF)
{    
aux=valeur;
if(aux< min_valeur){
min_valeur=aux;

D.jour=jour;

D.valeur=valeur;
strcpy(D.temps,temps);
}
}
fprintf(g,"%d %s %f\n",&jour,temps,&valeur);
fclose(f);
fclose(g);
}
}*/
