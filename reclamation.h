#ifndef CAPTEUR_H_INCLUDED
#define CAPTEUR_H_INCLUDED
#include <gtk/gtk.h>

typedef struct
{
	char id[20];
	char reff[20];
	char prec[20];
        char texte[200];
         int  Jour;
         int Mois;
         int Annee;
	 

}reclamation;


int ajouter_reclamation(reclamation r);
void supprimer_reclamation(char ids[]);
int modifier_reclamation(reclamation r);
int service_plus();
void rechercher_reclamation(GtkWidget *liste, char idr[]);
void afficher_reclamation(GtkWidget *liste);



#endif 
