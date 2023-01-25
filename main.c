/*!
 *  \file main.c
 *  \authors PRADAL Titouan <pradaltito@cy-tech.fr>, JAULIN Gautier <jaulingaut@cy-tech.fr>
 *  \version 0.1
 *  \date Wed 28 April 2021 - 12:00:43
 *
 *  \brief programme principal
 *
 *
 */
#include "fonction.h"
/*!
 *  \fn int main (int argc, char** argv)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>, JAULIN Gautier <jaulingaut@cy-tech.fr>
 *  \version 0.1
 *  \date Mon 15 November 2021 - 21:16:19
 *  \brief Programme principal
 *  \param argc : Nombre de paramètres à l'exécution
 *  \param argv : Valeur des paramètres
 *  \return 0 si tout s'est bien passé
 */
int main (int argc, char** argv) {

  float duree;
  clock_t debut, fin;

  debut = clock();       /*Heure de début du programme*/

  testArg(argc, argv);   /*Exécution de la compression/décompression*/

  fin = clock();  /*heure de fin du programle*/

  duree = (float)(fin - debut) / CLOCKS_PER_SEC;     /*On soustrait l'heure de fin à l'heure de début pour avoir le temps d'exécution du programme*/
  printf("Temps d'exécution du programme : %fs \n", duree);

  return (EXIT_SUCCESS);
}
