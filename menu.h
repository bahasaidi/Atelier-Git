#include <gtk/gtk.h>
typedef struct
{
    char jour[20];
    char mois[20];
    char annee[20];
}Creation;

typedef struct
{
    char id[20];
    Creation date_creation;
    char type[20];
    char repas[20];
    char qd[20];
}Menu;


void  ajouter_menu(Menu m);
void afficher_menu(GtkWidget *liste);
void afficher_menuModif(GtkWidget *liste);
void supprimer_menu(Menu c, char id[],char type[]);
void modifier_menu(Menu m1, char id[]);
void chercher_menu_supp(Menu m, char id[20],char type[20],int *ok);
void meilleur_menu_de_la_semaine_nutrition();

