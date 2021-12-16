#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "reclamation.h"
#include <stdlib.h>
#include <string.h>

int x = 1;
int supp =0;
int ajout;
int service;
void
on_button_deconnexion_gestion_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_retour_liste_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* window2_liste;
GtkWidget* windowmenu;

window2_liste=lookup_widget(button,"window2_liste");
gtk_widget_destroy(window2_liste);
windowmenu=create_windowmenu();
gtk_widget_show(windowmenu);
}


void
on_button_rechercher_liste_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *window2_liste;
	GtkWidget *treeview3;
	GtkWidget *entry1;


	window2_liste = lookup_widget(button,"window2_liste");
	treeview3 = lookup_widget(window2_liste,"treeview3");
	entry1 = lookup_widget(window2_liste,"entry1");

	rechercher_reclamation(treeview3, gtk_entry_get_text(GTK_ENTRY(entry1)));
}


void
on_button_supprimer_supprission_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *window3_supp;
	GtkWidget *entry2;
	GtkWidget *label_supp_message;

	window3_supp = lookup_widget(button,"window3_supp");
	entry2 = lookup_widget(window3_supp,"entry2");
	label_supp_message = lookup_widget(window3_supp,"label_supp_message");

	if(supp == 1)
	{
		supprimer_reclamation(gtk_entry_get_text(GTK_ENTRY(entry2)));
		gtk_label_set_text(GTK_LABEL(label_supp_message),"reclamation supprimée avec succès!");
		gtk_widget_show(label_supp_message);
	}
	else if(supp == 0)
	{
		gtk_label_set_text(GTK_LABEL(label_supp_message),"Confirmer la suppression !");
		gtk_widget_show(label_supp_message);
	}
}


void
on_button_retour_suppression_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* window3_supp;
GtkWidget* windowmenu;

window3_supp=lookup_widget(button,"window3_supp");
gtk_widget_destroy(window3_supp);

windowmenu=create_windowmenu();
gtk_widget_show(windowmenu);
}


void
on_button_Affichier_supprission_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowsupp;
GtkWidget *windowgestion;
GtkWidget *treeview1;

windowsupp=lookup_widget(button,"window3_supp");
gtk_widget_destroy(windowsupp);

windowgestion=lookup_widget(button,"window1_gestion");
windowgestion=create_window1_gestion();
gtk_widget_show(windowgestion);

treeview1=lookup_widget(windowgestion,"treeview1");
afficher_reclamation(treeview1);

}

void
on_button_ajouter_ajout_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{ 
   reclamation r;
   GtkWidget *id;
   GtkWidget *reff;
   GtkWidget *prec;
   GtkWidget *texte;
   GtkWidget *Jour;
   GtkWidget *Mois;
   GtkWidget *Annee;

  
   GtkWidget *ComboboxZoCov;
   GtkWidget *label_ajut_reussite; 
   int ajout,verif;
   char text[200];

  
  
label_ajut_reussite = lookup_widget(button,"label_ajut_reussite");
id=lookup_widget(button,"entry_id_ajout");

strcpy(r.id,gtk_entry_get_text(GTK_ENTRY(id)));

/////////////////////////////////////////////////////////
Jour=lookup_widget(button,"spinbutton1_ajout");
Mois=lookup_widget(button,"spinbutton2_ajout");
Annee=lookup_widget(button,"spinbutton3_ajout");
r.Jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Jour));
r.Mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Mois));
r.Annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Annee));
///////////////////////////////////////////////////////////
texte=lookup_widget(button,"entry_valmin_ajout");
strcpy(r.texte,gtk_entry_get_text(GTK_ENTRY(texte)));
ComboboxZoCov=lookup_widget(button,"combobox1");
strcpy(r.prec,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ComboboxZoCov)));
///////////////////////////////////////////////////////////////////////////
strcpy(r.reff,"Hebergement");
if(x==1)
{strcpy(r.reff,"Hebergement");}
if(x==2)
{strcpy(r.reff,"Restauration");}


ajout=ajouter_reclamation(r);
gtk_widget_show(label_ajut_reussite);
 }

void
on_button_retour_ajout_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* window4_ajout;
GtkWidget* windowmenu;

window4_ajout=lookup_widget(button,"window4_ajout");
gtk_widget_destroy(window4_ajout);

windowmenu=create_windowmenu();
gtk_widget_show(windowmenu);
}


void
on_button_affichier_modification_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowmodif;
GtkWidget *windowgestion;
GtkWidget *treeview1;

windowmodif=lookup_widget(button,"window5_modif");
gtk_widget_destroy(windowmodif);

windowgestion=lookup_widget(button,"window1_gestion");
windowgestion=create_window1_gestion();
gtk_widget_show(windowgestion);

treeview1=lookup_widget(windowgestion,"treeview1");
afficher_reclamation(treeview1);


}


void
on_button_modifier_modification_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{  reclamation r;
   GtkWidget *id;
   GtkWidget *reff;
   GtkWidget *prec;
   GtkWidget *texte;
   GtkWidget *Jour;
   GtkWidget *Mois;
   GtkWidget *Annee;
   GtkWidget *label44; 
   GtkWidget *ComboboxZoCov;

  
GtkWidget *window5_modif;

window5_modif=lookup_widget(button,"window5_modif");

id=lookup_widget(button,"entry_id_modif");

strcpy(r.id,gtk_entry_get_text(GTK_ENTRY(id)));

/////////////////////////////////////////////////////////
Jour=lookup_widget(button,"spinbutton4_modif");
Annee=lookup_widget(button,"spinbutton5_modif");
Mois=lookup_widget(button,"spinbutton6_modif");
r.Jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Jour));
r.Mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Mois));
r.Annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Annee));
///////////////////////////////////////////////////////////
texte=lookup_widget(button,"entry_valmin_modif");
strcpy(r.texte,gtk_entry_get_text(GTK_ENTRY(texte)));
ComboboxZoCov=lookup_widget(button,"combobox2");


strcpy(r.prec,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ComboboxZoCov)));
///////////////////////////////////////////////////////////////////////////
strcpy(r.reff,"Hebergement");
if(x==1)
{strcpy(r.reff,"Hebergement");}

if(x==2)
{strcpy(r.reff,"Restauration");}


modifier_reclamation(r);

}


void
on_button_retour_modification_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* window5_modif;
GtkWidget* windowmenu;

window5_modif=lookup_widget(button,"window5_modif");
gtk_widget_destroy(window5_modif);

windowmenu=create_windowmenu();
gtk_widget_show(windowmenu);
}


void
on_radiobutton_temp_ajout_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
x=1;
}

}

void
on_radiobutton_fumee_ajout_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
x=2;
}
}
void
on_radiobutton_temp_moodif_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
x=1;
}

}


void
on_radiobutton_fum_modif_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
x=2;
}

}

void
on_checkbutton_supp_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)){
		supp = 1;
	} else {
		supp = 0;
	}
}


void
on_Service_clicked                     (GtkButton       *objet,
                                        gpointer         user_data)
{
        reclamation r;
        int result;
	char res[120];
	strcpy(res,"Le sevice le plus reclamé est :");
	GtkWidget *dash;
	GtkWidget *Res;
	
	dash= lookup_widget(objet,"dash");
	Res= lookup_widget(dash,"Res");

	result = service_plus();
	if(result == 1)
	{
		sprintf(res,"%s Restauration",res);
	} 
	else 
	{
		sprintf(res,"%s Hebergement",res);
	}
	gtk_label_set_text(GTK_LABEL(Res),res);

}

void
on_afficher_ajout_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowajout;
GtkWidget *windowgestion;
GtkWidget *treeview1;

windowajout=lookup_widget(button,"window4_ajout");
gtk_widget_destroy(windowajout);

windowgestion=lookup_widget(button,"window1_gestion");
windowgestion=create_window1_gestion();
gtk_widget_show(windowgestion);

treeview1=lookup_widget(windowgestion,"treeview1");
afficher_reclamation(treeview1);

}


void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* input;
GtkWidget* output;
GtkWidget* windowmenu;
windowmenu=lookup_widget(button,"windowmenu");
gtk_widget_destroy(windowmenu);

GtkWidget* window4_ajout;
window4_ajout=create_window4_ajout();
gtk_widget_show(window4_ajout);

}


void
on_button2_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* input;
GtkWidget* output;
GtkWidget* window1;
window1=lookup_widget(button,"windowmenu");
gtk_widget_destroy(window1);

GtkWidget* window5_modif;

window5_modif=create_window5_modif();
gtk_widget_show(window5_modif);

}


void
on_button3_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowmenu;
GtkWidget *windowgestion;
GtkWidget *treeview1;

windowmenu=lookup_widget(button,"windowmenu");
gtk_widget_destroy(windowmenu);

windowgestion=lookup_widget(button,"window1_gestion");
windowgestion=create_window1_gestion();
gtk_widget_show(windowgestion);

treeview1=lookup_widget(windowgestion,"treeview1");
afficher_reclamation(treeview1);

}


void
on_button4_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* input;
GtkWidget* output;
GtkWidget* windowmenu;
windowmenu=lookup_widget(button,"windowmenu");
gtk_widget_destroy(windowmenu);
GtkWidget* window2_liste;
window2_liste=create_window2_liste();
gtk_widget_show(window2_liste);
}


void
on_button5_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* input;
GtkWidget* output;
GtkWidget* windowmenu;
windowmenu=lookup_widget(button,"windowmenu");
gtk_widget_destroy(windowmenu);
GtkWidget* window3_supp;
window3_supp=create_window3_supp();
gtk_widget_show(window3_supp);

}


void
on_button6_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* input;
GtkWidget* output;
GtkWidget* windowmenu;

windowmenu=lookup_widget(button,"windowmenu");
gtk_widget_destroy(windowmenu);
GtkWidget* dash;
dash=create_dash();
gtk_widget_show(dash);

}


void
on_retour_dash_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* window_dash;
GtkWidget* windowmenu;

window_dash=lookup_widget(button,"dash");
gtk_widget_destroy(window_dash);
windowmenu=create_windowmenu();
gtk_widget_show(windowmenu);

}


void
on_retour_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* window1_gestion;
GtkWidget* windowmenu;

window1_gestion=lookup_widget(button,"window1_gestion");
gtk_widget_destroy(window1_gestion);
windowmenu=create_windowmenu();
gtk_widget_show(windowmenu);

}


void
on_button_rechercher_liste_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{

}

