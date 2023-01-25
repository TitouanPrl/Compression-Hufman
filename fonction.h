#ifndef __FONCTION_H
#define __FONCTION_H

/*!
 *  \file fonction.h
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>, JAULIN Gautier <jaulingaut@cy-tech.fr>
 *  \version 0.1
 *  \date Mon 15 November 2021 - 21:16:58
 *
 *  \brief Prototypes des fonctions
 *
 *
 */

// Inclusion des entetes de librairies
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
/*!
 \def EXIT_SUCCESS
  Code confirmant la bonne exécution du programme
*/
#define EXIT_SUCCESS 0
/*!
 \def ERREUR_SAISIE
  Code d'erreur attestant qu'une erreur de saisie s'est produite
*/
#define ERREUR_SAISIE -1
/*!
 \def ERREUR
  Message affiché quand il y a une erreur
*/
#define ERREUR(message) fprintf(stderr, '%s\n', message)

#define max(a,b)(a<b)?b:a

#define TAILLE_TAB_CHAR 128

/*!
 *  \struct id
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>, JAULIN Gautier <jaulingaut@cy-tech.fr>
 *  \version 0.1
 *  \date Fri 19 November 2021 - 14:39:41
 *  \brief struct qui contient une lettre et sa fréquence d'apparition dans le fichier
 *  \param lettre la lettre
 *  \param freq la fréquence d'apparition de la lettre
 */
typedef struct id {
   char lettre;
   int freq;
}id;


/*!
 *  \struct noeud
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>, JAULIN Gautier <jaulingaut@cy-tech.fr>
 *  \version 0.1
 *  \date Fri 19 November 2021 - 14:41:35
 *  \brief struct qui forme un noeud de l'arbre des fréq d'apparitions des lettres
 *  \param racine la tête de l'arbre
 *  \param FG le fils gauche
 *  \param FD le fils droit
 */

typedef struct noeud {
   id racine;
   struct noeud* FG;
   struct noeud* FD;
}noeud;

typedef noeud* arbre; /*Définit la composition d'un arbre*/


/*!
 *  \struct liste
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>, JAULIN Gautier <jaulingaut@cy-tech.fr>
 *  \version 0.1
 *  \date Fri 19 November 2021 - 14:45:06
 *  \brief liste d'arbre qui va permettre de faire l'arbre des fréquences d'apparitions
 *  \param tete la tête de la liste
 *  \remarks
 */

typedef struct liste {
   arbre tete;
   struct liste* reste;
}liste;

typedef liste* Liste;

int estVide(arbre a);

int estFeuille(arbre a);

arbre getFG(arbre a);

arbre getFD(arbre a);

id getVal(arbre a);

Liste ajoutTete(arbre a, Liste l);

Liste compte(FILE* nom);

arbre creerArbre(id elmt, arbre filsGauche, arbre filsDroit);

Liste arbreFreq(Liste lres);

Liste tri(arbre res, Liste l);

void codeBranche(arbre a, char* tab[], char* code);

arbre suppr(arbre a);

void code(arbre a, char* tab[]);

int tailleListe(Liste l);

void printCode(FILE* nomFic1, FILE* nomFic2, char* tab[TAILLE_TAB_CHAR]);

int taille(arbre a);

void compresser(char* nomFichier, char* nomFicCompress);

Liste ficToListe(FILE* nom);

void decompresser(char* nomFichier, char* nomFicDecompress);

void decode(arbre a, FILE* nom1, FILE* nom2);

Liste ajoutFin(noeud* res, Liste l);

void testArg(int argc, char** argv);

void printHelp();

long size(char* nom);

void compTaille(char* nom1, char* nom2);

#endif
