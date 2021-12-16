#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "menu.h"
#include "dechet.h"



void
on_buttonModifMenu_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ModifierMenu;
GtkWidget *windowMenu;
windowMenu = lookup_widget(button, "windowGestionMenu");
gtk_widget_destroy(windowMenu);
ModifierMenu = create_ModifierMenu();
gtk_widget_show(ModifierMenu);

}


void
on_buttonSupprimeMenu_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowSupprimer;
GtkWidget *windowMenu;
GtkWidget *treeview;
windowMenu = lookup_widget(button, "windowGestionMenu");
gtk_widget_destroy(windowMenu);
windowSupprimer = create_windowSupprimeMenu();
gtk_widget_show(windowSupprimer);
treeview = lookup_widget (windowSupprimer, "treeview");
afficher_menu(treeview);
}


void
on_buttonAjoutMenu_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowAjout;
GtkWidget *windowMenu;
windowMenu = lookup_widget(button,"windowGestionMenu");
gtk_widget_destroy(windowMenu);

windowAjout = lookup_widget(button,"windowAjoutMenu");
windowAjout = create_windowAjoutMenu();
gtk_widget_show(windowAjout);
}


void
on_buttonAcceuil_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowSupprimer;
GtkWidget *windowMenu;
GtkWidget *windowAjoutMenu;
GtkWidget *windowModifier;
GtkWidget *ListeMenus;

windowSupprimer = lookup_widget(button, "windowSupprimeMenu");
gtk_widget_destroy(windowSupprimer);

windowModifier = lookup_widget(button, "windowModifierMenu");
gtk_widget_destroy(windowModifier);

windowAjoutMenu = lookup_widget(button, "windowAjoutMenu");
gtk_widget_destroy(windowAjoutMenu);
ListeMenus = lookup_widget(button, "ListeMenus");
gtk_widget_destroy(ListeMenus);

windowMenu = create_windowGestionMenu();
gtk_widget_show(windowMenu);

}


void
on_buttonDeconnexin_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

}


gboolean
on_treeview_start_interactive_search   (GtkTreeView     *treeview,
                                        gpointer         user_data)
{

  return FALSE;
}


void
on_buttonDeconnexion_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}

char tmps[30];
void
on_buttonModif_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
Menu m;
GtkWidget *input1;
GtkWidget *windowModification;
FILE *fp;
fp = fopen("temp1.txt", "r");
input1 = lookup_widget(button, "entryID");
strcpy(tmps,gtk_entry_get_text(GTK_ENTRY(input1)));
windowModification = create_ModifierMenu();
gtk_widget_show(windowModification);

GtkWidget *output1, *output2, *output3, *output4, *output5, *output6;
if(fp!=NULL)
{
while (fread(&m, sizeof(m), 1, fp))
{
	output1 = lookup_widget(windowModification, "entryMOdifierId");
	gtk_entry_set_text(GTK_ENTRY(output1), m.id);

	output2 = lookup_widget(windowModification, "entryModifierRepas");
	gtk_entry_set_text(GTK_ENTRY(output2), m.repas);

	output3 = lookup_widget(windowModification, "entryModifierQD");
	gtk_entry_set_text(GTK_ENTRY(output3), m.qd);

	/*output4 = lookup_widget(windowModification, "spinbuttonJour");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(output4), m.date_creation.jour);


	output5 = lookup_widget(windowModification, "spinbuttonMois");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(output5), m.date_creation.mois);


	output6 = lookup_widget(windowModification, "spinbuttonMAnnee");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(output6), m.date_creation.annee);*/

}
}

fclose(fp);
}


void
on_buttonSupprimer_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowConfirmation;
char id[30];
char type[30];
Menu m;
GtkWidget *input1;
input1= lookup_widget(button, "entryID");
strcpy(id, gtk_entry_get_text(GTK_ENTRY(input1)));
supprimer_menu(m,id,type);
windowConfirmation = create_dialog3();
gtk_widget_show(windowConfirmation);
}

int c1=0;
void
on_buttonConfirmerModif_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
Menu m;
FILE *fp1;
fp1 = fopen("menu.txt", "r");
char j[30];
char q[30];
char a[30];

GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *Jour;
GtkWidget *Mois;
GtkWidget *Annee;
GtkWidget *windowErreur;
GtkWidget *windowSuccees;
GtkWidget *ModifierMenu;


input1 = lookup_widget(button, "entryMOdifierId");
input2 = lookup_widget(button, "entryModifierRepas");
input3 = lookup_widget(button, "entryModifierQD");
Jour = lookup_widget(button, "spinbuttonJours");
Mois = lookup_widget(button, "spinbuttonMois");
Annee = lookup_widget(button, "spinbuttonAnnees");


strcpy(m.id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(m.repas,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(m.qd,gtk_entry_get_text(GTK_ENTRY(input3)));

if (c1==1)
strcpy(m.type,"Dejuner");
else if (c1==2)
strcpy(m.type,"Diner");


sprintf(m.date_creation.jour,"%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Jour)));
sprintf(m.date_creation.mois,"%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Mois)));
sprintf(m.date_creation.annee,"%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Annee)));

if( (c1==0) && (strcmp(m.id,"")==0) && (strcmp(m.repas,"")==0) && (strcmp(m.qd,"")==0))
{
windowErreur = create_windowRemplir();
gtk_widget_show(windowErreur);
}
else
{
modifier_menu(m,tmps);
windowSuccees = create_dialog2();
gtk_widget_show(windowSuccees);
ModifierMenu = lookup_widget(button, "ModifierMenu");

}

}


void
on_checkbuttonDejeuner_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
c1=1;

}


void
on_checkbuttonDiner_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
c1=2;

}


void
on_okbutton1_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window = lookup_widget(button, "dialog1");
gtk_widget_destroy(window);
}


void
on_okbutton2_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window = lookup_widget(button, "dialog2");
gtk_widget_destroy(window);

}


void
on_okbutton3_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window = lookup_widget(button, "dialog3");
gtk_widget_destroy(window);

}


void
on_okbutton4_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window = lookup_widget(button, "windowRemplir");
gtk_widget_destroy(window);

}



int c=0;

void
on_buttonAjouter_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
Menu m;
Menu r;
FILE *fp1;
char j[30];
char q[30];
char a[30];

fp1 = fopen("menu.txt", "r");

GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *Jour;
GtkWidget *Mois;
GtkWidget *Annee;
GtkWidget *windowRemplir;
GtkWidget *windowConfirmation;


input1 = lookup_widget(button, "entryId_ajout");
input3 = lookup_widget(button, "entryQD_ajout");
input4 = lookup_widget(button, "entryRepas_ajout");
Jour = lookup_widget(button, "spinbuttonJours_ajout");
Mois = lookup_widget(button, "spinbuttonMois_ajout");
Annee = lookup_widget(button, "spinbuttonAnnees_ajout");
strcpy(m.id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(m.qd,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(m.repas,gtk_entry_get_text(GTK_ENTRY(input4)));


sprintf(j,"%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Jour)));
sprintf(q,"%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Mois)));
sprintf(a,"%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Annee)));



if (c==1)
{
strcpy(m.type,"Dejeuner");
}
else if (c==2)
{
strcpy(m.type,"Diner");
}

sprintf(m.date_creation.jour,"%d", gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Jour)));
sprintf(m.date_creation.mois,"%d", gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Mois)));
sprintf(m.date_creation.annee,"%d", gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Annee)));


ajouter_menu(m);
fclose(fp1);
windowConfirmation = create_dialog1();
gtk_widget_show(windowConfirmation);



}





void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
c=2;

}


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
c=1;

}








void
on_treeview4_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_Actualiser_clicked                  (GtkButton       *button,
                                        gpointer         user_data)

{

}


void
on_button16_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview;
GtkWidget *listeMenus;
GtkWidget *window;
listeMenus = create_ListeMenus();
gtk_widget_show(listeMenus);
treeview = lookup_widget(listeMenus, "treeview");
afficher_menu(treeview);
window = lookup_widget(button,"windowGestionMenu");
gtk_widget_destroy(window);
}


void
on_treeview_row_activated              (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_buttonRetouur_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowSupprimer;
GtkWidget *windowMenu;
GtkWidget *windowAjoutMenu;
GtkWidget *windowModifier;
GtkWidget *ListeMenus;

windowSupprimer = lookup_widget(button, "windowSupprimeMenu");
gtk_widget_destroy(windowSupprimer);

windowModifier = lookup_widget(button, "windowModifierMenu");
gtk_widget_destroy(windowModifier);

windowAjoutMenu = lookup_widget(button, "windowAjoutMenu");
gtk_widget_destroy(windowAjoutMenu);
ListeMenus = lookup_widget(button, "ListeMenus");
gtk_widget_destroy(ListeMenus);

windowMenu = create_windowGestionMenu();
gtk_widget_show(windowMenu);

}


void
on_buttonRetour_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowSupprimer;
GtkWidget *windowMenu;
GtkWidget *windowAjoutMenu;
GtkWidget *windowModifier;
GtkWidget *ListeMenus;

windowSupprimer = lookup_widget(button, "windowSupprimeMenu");
gtk_widget_destroy(windowSupprimer);

windowModifier = lookup_widget(button, "windowModifierMenu");
gtk_widget_destroy(windowModifier);

windowAjoutMenu = lookup_widget(button, "windowAjoutMenu");
gtk_widget_destroy(windowAjoutMenu);
ListeMenus = lookup_widget(button, "ListeMenus");
gtk_widget_destroy(ListeMenus);

windowMenu = create_windowGestionMenu();
gtk_widget_show(windowMenu);

}


void
on_button17modifier_clicked            (GtkButton       *button,
                                        gpointer         user_data)

{
Menu m;
GtkWidget *input1;
GtkWidget *windowModification;
FILE *fp;
fp = fopen("temp1.txt", "r");
input1 = lookup_widget(button, "entryID");
strcpy(tmps,gtk_entry_get_text(GTK_ENTRY(input1)));
windowModification = create_ModifierMenu();
gtk_widget_show(windowModification);

GtkWidget *output1, *output2, *output3, *output4, *output5, *output6;
if(fp!=NULL)
{
while (fread(&m, sizeof(m), 1, fp))
{
	output1 = lookup_widget(windowModification, "entryMOdifierId");
	gtk_entry_set_text(GTK_ENTRY(output1), m.id);

	output2 = lookup_widget(windowModification, "entryModifierRepas");
	gtk_entry_set_text(GTK_ENTRY(output2), m.repas);

	output3 = lookup_widget(windowModification, "entryModifierQD");
	gtk_entry_set_text(GTK_ENTRY(output3), m.qd);

	/*output4 = lookup_widget(windowModification, "spinbuttonJour");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(output4), m.date_creation.jour);


	output5 = lookup_widget(windowModification, "spinbuttonMois");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(output5), m.date_creation.mois);


	output6 = lookup_widget(windowModification, "spinbuttonMAnnee");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(output6), m.date_creation.annee);*/

}
}

fclose(fp);
}


void
on_button18retouuuur_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowSupprimer;
GtkWidget *windowMenu;
GtkWidget *windowAjoutMenu;
GtkWidget *ModifierMenu;
GtkWidget *ListeMenus;

windowSupprimer = lookup_widget(button, "windowSupprimeMenu");
gtk_widget_destroy(windowSupprimer);

ModifierMenu = lookup_widget(button, "ModifierMenu");
gtk_widget_destroy(ModifierMenu);

windowAjoutMenu = lookup_widget(button, "windowAjoutMenu");
gtk_widget_destroy(windowAjoutMenu);
ListeMenus = lookup_widget(button, "ListeMenus");
gtk_widget_destroy(ListeMenus);

windowMenu = create_windowGestionMenu();
gtk_widget_show(windowMenu);

}


void
on_buttonReeeeeeeeetour_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowSupprimer;
GtkWidget *windowMenu;
GtkWidget *windowAjoutMenu;
GtkWidget *windowModifier;
GtkWidget *ListeMenus;

windowSupprimer = lookup_widget(button, "windowSupprimeMenu");
gtk_widget_destroy(windowSupprimer);

windowModifier = lookup_widget(button, "windowModifierMenu");
gtk_widget_destroy(windowModifier);

windowAjoutMenu = lookup_widget(button, "windowAjoutMenu");
gtk_widget_destroy(windowAjoutMenu);
ListeMenus = lookup_widget(button, "ListeMenus");
gtk_widget_destroy(ListeMenus);

windowMenu = create_windowGestionMenu();
gtk_widget_show(windowMenu);

}




void
on_afficher_meuilleur_m_clicked        (GtkButton       *objet,
                                        gpointer         user_data)
{


GtkWidget *windowMenu ;
GtkWidget *meilleur;
windowMenu=lookup_widget(objet,"windowMenu");
gtk_widget_destroy(windowMenu);
meilleur=lookup_widget(objet,"meilleur");
meilleur=create_meilleur();
gtk_widget_show(meilleur);


}







void
on_treeview2_nutrition_row_activated   (GtkTreeView     *treeview2_nutrition,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{



GtkTreeIter iter;
gchar *jour;
gchar *temps;
gfloat *valeur;
dechet D;
 GtkTreeModel *model=gtk_tree_view_get_model(treeview2_nutrition);
if (gtk_tree_model_get_iter(model,&iter ,path))
{
gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0,&jour,1,&temps,3,&valeur,-1);

afficher_meilleure_menu(treeview2_nutrition);
}


}


void
on_button_afficher_meilleur_M_clicked  (GtkButton       *objet,
                                        gpointer         user_data)
{


GtkWidget *meilleur;
GtkWidget *treeview2_nutrition;
meilleur=lookup_widget(objet,"meilleur");
gtk_widget_show(meilleur);
treeview2_nutrition=lookup_widget(meilleur,"treeview2_nutrition");
afficher_meilleure_menu(treeview2_nutrition);





}

