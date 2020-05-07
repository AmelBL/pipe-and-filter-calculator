#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>


/*VARIABLES D'ENVIRONNEMENT*/

GtkWidget * p_win    = NULL;
GtkWidget * p_vbox   = NULL;
GtkWidget * p_entry [2]; //nbr1 et nbr2
GtkWidget * p_label [4]; 
GtkWidget * p_button [5]; //+ * ! et trace et quitter
GtkWidget *box1;
GtkWidget *box2;

void cb_activate (GtkEntry * p_wid, gpointer p_data){

   GtkEntry * p_entry = (GtkEntry *) p_data;
   g_return_if_fail (p_wid != NULL);
   g_return_if_fail (p_data != NULL);
   gtk_widget_grab_focus (GTK_WIDGET (p_entry));
}

void cb_clicked (GtkButton * p_wid, gpointer p_data){
   int op; //id de l'operation
   if (p_wid == p_button [0]){		op = 1 ;}
   else if (p_wid == p_button [1]){     op = 2 ;}
   else if (p_wid == p_button [2]){	op = 3 ;} 
   else if (p_wid == p_button [3]){	op = 4; }
   else if (p_wid == p_button [4]){	exit(0);}

   g_return_if_fail (p_wid != NULL);
   g_return_if_fail (p_data != NULL);
	//les 2 opérandes
   int op1 = strtol (gtk_entry_get_text (GTK_ENTRY (p_entry[0])), NULL, 10);
   int op2 = strtol (gtk_entry_get_text (GTK_ENTRY (p_entry[1])), NULL, 10);

        FILE *wfd;
	char lop[250];
	char str[50];
	sprintf(str, "        %d", op);   strcat(lop,str);
	sprintf(str, "        %d", op1);  strcat(lop,str);
	sprintf(str, "        %d", op2);  strcat(lop,str);

    	wfd = popen ("./calcul | ./trace", "w"); //creer un pipe entre gui et calcul et un autre entre calcul et trace
    	if (wfd == NULL) {
        	return -1;
    	}
		
	if (op == 4){ fprintf(wfd, "%s", "");}	
	else{
		fprintf(wfd, "%s", lop);
	}

    	pclose (wfd);
}

int main (int argc, char ** argv){

   gtk_init (& argc, & argv);

   p_win = gtk_window_new (GTK_WINDOW_TOPLEVEL);


   gtk_window_set_title (GTK_WINDOW (p_win), "CMPG");

   gtk_container_set_border_width (GTK_CONTAINER (p_win), 5);
   
   g_signal_connect (
      G_OBJECT (p_win), "destroy",
      G_CALLBACK (gtk_main_quit), NULL
   );

   p_vbox = gtk_vbox_new (TRUE, 5);

   gtk_container_add (GTK_CONTAINER (p_win), p_vbox);

   /*MISE EN PLACE DES ELEMENTS DE LA FENETRE*/
   p_entry[0] = gtk_entry_new ();
   p_entry[1] = gtk_entry_new ();

   p_label[0] = gtk_label_new("Les opérandes");
   p_label[1]  = gtk_label_new("Tapez votre 1er nombre ");
   p_label[2] = gtk_label_new("Tapez votre 2eme nombre");
   p_label[3] = gtk_label_new("Resultat:");
   p_button[0] = gtk_button_new_with_label("SOMME");
   p_button[1] = gtk_button_new_with_label("PRODUIT");
   p_button[2] = gtk_button_new_with_label("FACTORIEL");
   p_button[3] = gtk_button_new_with_label("TRACE");
   p_button[4] = gtk_button_new_with_label("QUITTER");
   
   box1 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
   gtk_box_pack_start (GTK_BOX (box1), p_button[0], TRUE, TRUE, 0);
   gtk_box_pack_start (GTK_BOX (box1), p_button[1], TRUE, TRUE, 0);
   gtk_box_pack_start (GTK_BOX (box1), p_button[2], TRUE, TRUE, 0);   


   box2 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
   gtk_box_pack_start (GTK_BOX (box2), p_button[3], TRUE, TRUE, 0);
   gtk_box_pack_start (GTK_BOX (box2), p_button[4], TRUE, TRUE, 0);  

   gtk_box_pack_start (GTK_BOX (p_vbox), p_label[0], TRUE, FALSE, 0);
   gtk_box_pack_start (GTK_BOX (p_vbox), p_label[1], TRUE, FALSE, 0);
   gtk_box_pack_start (GTK_BOX (p_vbox), p_entry[0], TRUE, TRUE, 0);
   gtk_box_pack_start (GTK_BOX (p_vbox), p_label[2], TRUE, FALSE, 0);
   gtk_box_pack_start (GTK_BOX (p_vbox), p_entry[1], TRUE, TRUE, 0);
   gtk_box_pack_start (GTK_BOX (p_vbox), p_label[3], TRUE, FALSE, 0);
   gtk_box_pack_start (GTK_BOX (p_vbox), box1, TRUE, TRUE, 0);
   gtk_box_pack_start (GTK_BOX (p_vbox), box2, TRUE, TRUE, 0);

  g_signal_connect (
      G_OBJECT (p_button[0]), "clicked",
      G_CALLBACK (cb_clicked), (void *) p_button[0]
   );

  g_signal_connect (
      G_OBJECT (p_button[1]), "clicked",
      G_CALLBACK (cb_clicked), (void *) p_button[1]
   );

  g_signal_connect (
      G_OBJECT (p_button[2]), "clicked",
      G_CALLBACK (cb_clicked), (void *) p_button[2]
   );

  g_signal_connect (
      G_OBJECT (p_button[3]), "clicked",
      G_CALLBACK (cb_clicked), (void *) p_button[3]
   );

  g_signal_connect (
      G_OBJECT (p_button[4]), "clicked",
      G_CALLBACK (cb_clicked), (void *) p_button[4]
   );
 
   g_signal_connect (
      G_OBJECT (p_entry[0]), "activate",
      G_CALLBACK (cb_activate), (GtkEntry *) p_entry[1]
   );
 
   gtk_widget_show_all (p_win);
   gtk_main ();

return 0;

}