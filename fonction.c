/*!
 * \file c:\Users\ADMIN\Documents\projetAlgo\oskour\fonctions.c
 * \author PRADAL Titouan <pradaltito@cy-tech.fr>, JAULIN Gautier <jaulingaut@cy-tech.fr>
 * \version 0.1
 * \date Mon 15 November 2021 - 21:17:12
 *
 * \brief Corps des fonctions
 *
 *
 */

/*! Importation of librairies*/
#include "fonction.h"

/*!
 * \fn int estVide(arbre a)
 * \author PRADAL Titouan <pradaltito@cy-tech.fr>, JAULIN Gautier <jaulingaut@cy-tech.fr>
 * \version 0.1
 * \date Fri 19 November 2021 - 18:51:46
 * \brief vérifie si un arbre est vide
 * \param a l'arbre en entrée
 * \param a
 * \return 1 si l'arbre est vide, 0 sinon
 */
int estVide(arbre a) {
   return a == NULL;
}

/*!
 * \fn int estFeuille(arbre a)
 * \author PRADAL Titouan <pradaltito@cy-tech.fr>, JAULIN Gautier <jaulingaut@cy-tech.fr>
 * \version 0.1
 * \date Fri 19 November 2021 - 18:49:39
 * \brief vérifie si un noeud est une feuille ou non
 * \param a l'arbre en entrée
 * \param a
 * \return 1 si c'est une feuille, 0 sinon
 */
int estFeuille(arbre a) {
   return ((estVide(a->FG) && estVide(a->FD)));
}

/*!
 * \fn arbre getFG(arbre a)
 * \author PRADAL Titouan <pradaltito@cy-tech.fr>, JAULIN Gautier <jaulingaut@cy-tech.fr>
 * \version 0.1
 * \date Fri 19 November 2021 - 18:54:45
 * \brief renvoie le fils gauche d'un noeud
 * \param a l'arbre en entrée
 * \param a
 * \return le fils gauche du noeud
 */
arbre getFG(arbre a) {
   return (a->FG);
}

/*!
 * \fn arbre getFD(arbre a)
 * \author PRADAL Titouan <pradaltito@cy-tech.fr>, JAULIN Gautier <jaulingaut@cy-tech.fr>
 * \version 0.1
 * \date Fri 19 November 2021 - 18:54:45
 * \brief renvoie le fils droit d'un noeud
 * \param a l'arbre en entrée
 * \param a
 * \return le fils droit du noeud
 */
arbre getFD(arbre a) {
   return (a->FD);
}

/*!
 * \fn id getVal(arbre a)
 * \author PRADAL Titouan <pradaltito@cy-tech.fr>, JAULIN Gautier <jaulingaut@cy-tech.fr>
 * \version 0.1
 * \date Fri 19 November 2021 - 18:54:45
 * \brief renvoie la tête d'un arbre
 * \param a l'arbre en entrée
 * \param a
 * \return la tête de l'arbre
 */
id getVal(arbre a) {
   return (a->racine);
}

/*!
 * \fn Liste ajoutTete(arbre a, Liste l)
 * \author PRADAL Titouan <pradaltito@cy-tech.fr>, JAULIN Gautier <jaulingaut@cy-tech.fr>
 * \version 0.1
 * \date Sat 20 November 2021 - 16:25:34
 * \brief Ajoute un nouvel élément en tête de liste
 * \param a l'élément à rajouter
 * \param l la liste à laquelle on veut ajouter un élément
 * \param a
 * \param l
 * \return la liste avec l'élément en tête
 */
Liste ajoutTete(arbre a, Liste l) {
  Liste m = NULL;
  m = malloc(sizeof(Liste));
  m->tete = a;
  m->reste = l;
  //l->reste = l;
  //l->tete = a;
  return (m);
}

/*!
 * \fn int taille(arbre a)
 * \author PRADAL Titouan <pradaltito@cy-tech.fr>, JAULIN Gautier <jaulingaut@cy-tech.fr>
 * \version 0.1
 * \date Sun 21 November 2021 - 16:54:13
 * \brief donne la taille de l'arbre
 * \param a l'arbre dont on veut connaitre la taille
 * \param a
 * \return la taille de a
 */
int taille(arbre a) {
   if (estVide(a))
   {
     return -1;
   }
   else if (estFeuille(a))
   {
     return 1;
   }
   else
   {
     return (taille(getFG(a)) + taille(getFD(a)) + 1);
   }
}

/*!
 * \fn Liste compte(FILE* nom)
 * \author PRADAL Titouan <pradaltito@cy-tech.fr>, JAULIN Gautier <jaulingaut@cy-tech.fr>
 * \version 0.1
 * \date Fri 19 November 2021 - 14:58:16
 * \brief compte le nombre d'apparitions de chaque charactère du fichier en entrée et retourne une liste d'id triée par ordre croissant de fréquence
 * \param nom le fichier en entrée
 * \return une Liste d'arbre
 */
Liste compte(FILE* nom) {

  Liste lres = NULL;
  char  c;

  for (int i = 0; i < 128; i++)
  {
    arbre res =  malloc(sizeof(arbre));   //Allocation de la mémoire
    res->racine.lettre = (char)i; //Prend tous les char ASCII un par un
    res->racine.freq = 0;   // initialisation fréquence de chaque char a 0 au début de sa boucle
    c = fgetc(nom);

    /* On parcourt le fichier en entier et on incrémente la fréquence de la lettre en cours*/
    while (c != EOF)      
    {
      if (c == res->racine.lettre)
      {
        res->racine.freq++;
      }
      c = fgetc(nom);
    }
    /*Retour au début du fichier*/
    fseek(nom,0,SEEK_SET);    

    /*Finalisation de la construction de l'arbre*/
    res->FG = NULL;
    res->FD = NULL;

    /*Si la lettre apparait dans le fichier alors on l'ajoute ainsi que sa fréquence dans la liste*/
    if(res->racine.freq)
    {
      lres = tri(res, lres);
    } 
  }

  return (lres);
}

/*!
 * \fn arbre creerArbre(id elmt, arbre filsGauche, arbre filsDroit)
 * \author PRADAL Titouan <pradaltito@cy-tech.fr>, JAULIN Gautier <jaulingaut@cy-tech.fr>
 * \version 0.1
 * \date Fri 19 November 2021 - 15:11:53
 * \brief crée un arbre
 * \param elmt la racine
 * \param filsGauche le fils gauche
 * \param filsDroit le fils droit
 * \return un arbre
*/
arbre creerArbre(id elmt, arbre filsGauche, arbre filsDroit) {
   arbre a = malloc(sizeof(arbre));

   a->racine = elmt;
   a->FG = filsGauche;
   a->FD = filsDroit;

   return (a);
}

/*!
 * \fn Liste arbreFreq(Liste lres)
 * \author PRADAL Titouan <pradaltito@cy-tech.fr>, JAULIN Gautier <jaulingaut@cy-tech.fr>
 * \version 0.1
 * \date Fri 19 November 2021 - 15:16:48
 * \brief fusionne les 2 premiers élément de la Liste en un arbre puis le réinjecte dans la Liste, réitère jusqu'à ce qu'il n'y ai plus qu'un seul élément dans la Liste
 * \param lres une Liste
 * \return la Liste ne contenant plus qu'un seul arbre
 */
Liste arbreFreq(Liste lres) {
   id id_tmp;

   /*Si la liste est nulle ou si elle ne contient déjà plus qu'un élèment alors on la renvoie telle quelle*/
   if (lres == NULL || lres->reste == NULL)
   {
     return lres;
   }
   else
   {
     /*Définition du noeud somme de 2 fréquences*/
     id_tmp.freq = lres->tete->racine.freq + lres->reste->tete->racine.freq;
     id_tmp.lettre = -1;
     /*Retrie la liste en y ajoutant l'arbre créé et en supprimant les deux éléments utilisés*/
     lres = tri(creerArbre(id_tmp, lres->tete, lres->reste->tete), lres->reste->reste);

     return arbreFreq(lres);
   }

}

/*!
 * \fn Liste tri(noeud* res, Liste l)
 * \author PRADAL Titouan <pradaltito@cy-tech.fr>, JAULIN Gautier <jaulingaut@cy-tech.fr>
 * \version 0.1
 * \date Fri 19 November 2021 - 15:22:46
 * \brief ajoute un élément dans la Liste en le triant par ordre croissant
 * \param res l'arbre à ajouter dans la liste
 * \param l la liste à remplir
 * \return une liste triée par ordre croissant des fréquences
 */
Liste tri(noeud* res, Liste l) {
   if (l == NULL || res->racine.freq <= l->tete->racine.freq)   //La Liste est vide ou l'elmnt est déjà trié
   {
     return ajoutTete(res, l);
   }
   else
   {
     return ajoutTete(l->tete, tri(res, l->reste));
   }

}

/*!
 * \fn void codeBranche(arbre a, char* tab[], char* code)
 * \author PRADAL Titouan <pradaltito@cy-tech.fr>, JAULIN Gautier <jaulingaut@cy-tech.fr>
 * \version 0.1
 * \date Fri 19 November 2021 - 15:29:49
 * \brief donne le code associé à la branche la plus à gauche
 * \param a l'arbre étudié
 * \param tab un tableau symbolisant le code ASCII
 * \param code le code de la lettre
 */
void codeBranche(arbre a, char* tab[], char* code) {
   if(estVide(a))
   {
     return;   /*Si l'arbre est vide on arrête la procédure*/
   }
   if (estFeuille(a))
   {
     if(a->racine.lettre == -1)   //Si il n'y a pas de lettre on arrête la procédure
     {
       return;
     } 
     else   //Sinon on ajoute le code de la lettre à l'emplacement du tableau correspondant
     {
       strcpy(tab[(int) a->racine.lettre], code);
     }
   }
   else
   {
     if (a->FG != NULL)
     {
       strcat(code, "0");
       codeBranche(a->FG, tab, code);

      }
     else
     {
      strcat(code, "1");
      codeBranche(a->FD, tab, code);
     }
   }
   return;
}

/*!
 * \fn arbre suppr(arbre a)
 * \author PRADAL Titouan <pradaltito@cy-tech.fr>, JAULIN Gautier <jaulingaut@cy-tech.fr>
 * \version 0.1
 * \date Fri 19 November 2021 - 18:20:12
 * \brief supprime la feuille la plus à gauche de l'arbre
 * \param a l'arbre à modifier
 * \return l'arbre moins une feuille
 */
arbre suppr(arbre a) {
  if(estVide(a)){
    return a;
  }
   if (estFeuille(a))
   {
     free(a);
     return NULL;
   }
   else
   {
     if (a->FG != NULL)
     {
        a->FG = suppr(getFG(a));;
        return a;
     }
     else
     {
      a->FD = suppr(getFD(a));
      return a;
     }
   }
}

/*!
 * \fn void code(arbre a, char* tab[])
 * \author PRADAL Titouan <pradaltito@cy-tech.fr>, JAULIN Gautier <jaulingaut@cy-tech.fr>
 * \version 0.1
 * \date Fri 19 November 2021 - 18:23:26
 * \brief remplis le tableau associant chaque char à son code dans l'arbre
 * \param a l'arbre l'arbre des fréquences
 * \param tab un tableau symbolisant le code ASCII
 */
void code(arbre a, char* tab[]) {
  char* cod = malloc(sizeof(char*));
  int tale = taille(a);

  for (int i = 0; i < tale; i++)
   {
    cod[0] = '\0';
    codeBranche(a,tab,cod);
    a = suppr(a);
   }
}


/*!
 * \fn int tailleListe(Liste l)
 * \author PRADAL Titouan <pradaltito@cy-tech.fr>, JAULIN Gautier <jaulingaut@cy-tech.fr>
 * \version 0.1
 * \date Sun 21 November 2021 - 17:04:09
 * \brief compte le nombre de cases non NULL d'un tableau
 * \param l la liste dont on souhaite connaitre la taille
 * \return la taille de la liste
 */
int tailleListe(Liste l) {
  int nb = 0;
  if(l == NULL){
      return nb;
  }
  else{
   return 1+tailleListe(l->reste);
  }
}

/*!
 * \fn void printCode(FILE* nomFic1, FILE* nomFic2, char* tab[TAILLE_TAB_CHAR])
 * \author PRADAL Titouan <pradaltito@cy-tech.fr>, JAULIN Gautier <jaulingaut@cy-tech.fr>
 * \version 0.1
 * \date Sun 21 November 2021 - 17:23:50
 * \brief écrit le texte à compresser en version codé dans un fichier
 */
void printCode(FILE* nomFic1, FILE* nomFic2, char* tab[TAILLE_TAB_CHAR]) {
  rewind(nomFic1);
  char c = fgetc(nomFic1);

  while (c != EOF)
  {
    fprintf(nomFic2, "%s", tab[(int)c]);
    c = fgetc(nomFic1);
  }
}

/*!
 *  \fn void compresser(char* nomFichier, char* nomFicCompress)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>, JAULIN Gautier <jaulingaut@cy-tech.fr>
 *  \version 0.1
 *  \date Sat 20 November 2021 - 16:42:46
 *  \brief Crée le fichier compressé
 *  \param nomFichier le nom du fichier à compresser
 *  \param nomFicCompress le nom du fichier compressé
 */
void compresser(char* nomFichier, char* nomFicCompress) {
  char* tab[TAILLE_TAB_CHAR] = {};   /*On crée le tableau qui va contenir le code de chaque caractère*/

  for(int i = 0; i < 128; i++){     /*Allocation du tableau qui va contenir les codes*/
    tab[i] = malloc(sizeof(char*));
  } 

  FILE* nom = NULL;           /*Définit le flux du fichier à compresser*/
  FILE* nom2 = NULL;          /*Définit le flux du fichier compressé*/
  nom = fopen(nomFichier, "r+");         /*Lit le fichier à compresser*/

  if(nom == NULL){
    printf("je ne fonctionne pas - aucun fichier détecté\n");
    return;
  }
  else{
  //Codage de chaque caractère
    Liste listeArbre = compte(nom);

    if (listeArbre == NULL) {
      printf("je ne fonctionne pas - le fichier est vide\n");
    }
    else{  //créer et remplir le fichier compressé
      Liste saveList = listeArbre;

      nom2 = fopen(nomFicCompress, "w");

      fprintf(nom2, "%d\n", tailleListe(saveList));   /*On écrit le nombre de char différents de nomFichier*/
      while (saveList != NULL)    /*Puis chaque char et sa fréquence d'apparition*/
      {
        fprintf(nom2, "%c%d\n", saveList->tete->racine.lettre, saveList->tete->racine.freq);
        saveList = saveList->reste;
      }

      listeArbre = arbreFreq(listeArbre);   /*On crée l'arbre de fréquence*/

      code(listeArbre->tete, tab);    /*On associe chaque char à un code en fonction de sa position dans l'arbre*/

      printCode(nom, nom2, tab);    /*On écrit le texte avec le codage*/

      fclose(nom);
      fclose(nom2);

      printf("Compressing %s...\n", nomFichier);
      compTaille(nomFichier, nomFicCompress);   /*On compare la taille du fichier avant et après compression*/
    }
  }
}

/*!
 *  \fn void decompresser(char* nomFichier, char* nomFicDecompress)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>, JAULIN Gautier <jaulingaut@cy-tech.fr>
 *  \version 0.1
 *  \date Thu 02 December 2021 - 16:34:01
 *  \brief Crée le fichier décompressé
 *  \param nomFichier le nom du fichier à décompresser
 *  \param nomFicDecompress le nom du fichier décompressé
 */
void decompresser(char* nomFichier, char* nomFicDecompress){
  FILE* nom = NULL;           /*Définit le flux du fichier à décompresser*/
  FILE* nom2 = NULL;          /*Définit le flux du fichier décompressé*/
  nom = fopen(nomFichier, "r+");         /*Lit le fichier à compresser*/

  if(nom == NULL){
    printf("je ne fonctionne pas - aucun fichier détecté\n");
    return;
  }
  else{
    //Reconstruction de la liste
    Liste listeArbre = ficToListe(nom);

    if (listeArbre == NULL) {
      printf("je ne fonctionne pas - le fichier est vide\n");
    }
    else{
      nom2 = fopen(nomFicDecompress, "w");

      listeArbre = arbreFreq(listeArbre);
      decode(listeArbre->tete, nom, nom2);

      fclose(nom);
      fclose(nom2);

      printf("Decompressing %s...\n", nomFichier);
    }
  }
}

/*!
 *  \fn Liste ficToListe(FILE* nom)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>, JAULIN Gautier <jaulingaut@cy-tech.fr>
 *  \version 0.1
 *  \date Thu 02 December 2021 - 16:49:36
 *  \brief Lit l'en-tête et la convertit en liste d'id
 *  \param nom le nom du fichier dont on veut lire l'en-tête
 */
Liste ficToListe(FILE* nom){
  Liste lres = NULL;
  char  c;
  int nbChar = 0;

  fscanf(nom, "%d", &nbChar);
  fseek(nom, 1, SEEK_CUR);    //On saute le \n

  c = fgetc(nom);

  for(int i=0; i<nbChar; i++){
    arbre res =  malloc(sizeof(arbre));
    res->racine.lettre = c;   //On met le char dans une struct id

    fscanf(nom, "%d", &res->racine.freq);   //Lecture de la fréquence d'apparition du char et on le met dans le même id qu'au dessus
    fseek(nom, 1, SEEK_CUR);    //On saute le \n
    
    c = fgetc(nom);
    res->FG = NULL;
    res->FD = NULL;
    lres = ajoutFin(res, lres);
  }
    return (lres);
}

/*!
 *  \fn void decode(arbre a, FILE* nom1, FILE* nom2)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>, JAULIN Gautier <jaulingaut@cy-tech.fr>
 *  \version 0.1
 *  \date Thu 02 December 2021 - 17:10:27
 *  \brief Transforme un texte codé en texte normal
 *  \param a l'arbre de codage
 *  \param nom1 le fichier à décompresser
 *  \param nom2 le fichier décompresser
 */
void decode(arbre a, FILE* nom1, FILE* nom2){
  fseek(nom1, -1, SEEK_CUR);    //On replace le curseur car une autre fonction l'a amené un trop loin à la fin
  char c = fgetc(nom1);
  arbre saveArbre = a;

  while(c != EOF){
    a = saveArbre;

    while(!estFeuille(a)){    //On parcourt l'arbre pour trouver la lettre correspondant au code
      if(c == '0'){
        a = a->FG;
        c = fgetc(nom1);
      }
      else{
        a = a->FD;
        c = fgetc(nom1);
      }
    }
    fprintf(nom2, "%c", a->racine.lettre);    //On écrit la lettre décodée
  }
}

/*!
 *  \fn Liste ajoutFin(noeud* res, Liste l)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>, JAULIN Gautier <jaulingaut@cy-tech.fr>
 *  \version 0.1
 *  \date Thu 02 December 2021 - 17:19:47
 *  \brief Ajoute un élément en fin de liste
 *  \param res le noeud à ajouter
 *  \param l la liste dans laquelle on veut ajouter le noeud
 */
Liste ajoutFin(noeud* res, Liste l){
  Liste tmp = l;

  if(l == NULL){
    return ajoutTete(res, l);
  } 
  while(tmp -> reste != NULL){
    tmp = tmp->reste;
  } 
  tmp->reste = ajoutTete(res, tmp->reste);
  return l;
}

/*!
 *  \fn void testArg(int argc, char** argv)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>, JAULIN Gautier <jaulingaut@cy-tech.fr>
 *  \version 0.1
 *  \date Thu 02 December 2021 - 17:26:58
 *  \brief Lit les paramètres de l'éxécutable et compresse/décompresse
 *  \param argc le nombre de paramètres après l'éxécutable
 *  \param argv les paramètres après l'éxécutable
 */
void testArg(int argc, char** argv){
  for (int i = 0; i < argc; i++) {

    if (strcmp(argv[i], "-c") == 0) {     //Si -c alors on compresse
      if (argv[i+1] && argv[i+2]){
        compresser(argv[i+1], argv[i+2]);
        return;
      }
      else{
        printf("Bad parameters ! \n\n");
        printHelp();
        return;
      }
    }
    else if (strcmp(argv[i], "-d") == 0){   //Si -d alors on décompresse
      if (argv[i+1] && argv[i+2]){
        decompresser(argv[i+1], argv[i+2]);
        return;
      }
      else{
        printf("Bad parameters ! \n\n");
        printHelp();
        return;
      }
    }
    else if (strcmp(argv[i], "-h") == 0){   //Si -h alors on affiche l'aide
      printHelp();
      return;
    }
  }
  if(argc >= 1){
    printHelp();    /*Affiche l'aide si l'argument est incorrect*/
  }
}

/*!
 *  \fn void printHelp()
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>, JAULIN Gautier <jaulingaut@cy-tech.fr>
 *  \version 0.1
 *  \date Thu 02 December 2021 - 17:23:38
 *  \brief Affiche une aide
 */
void printHelp(){
  printf("L'option –c pour compresser, suivie du nom du fichier à compresser et du nom du fichier à créer\n"
        "Exemple : ./exe –c monfichier.txt monfichier.hfzip\n"
        "\nL'option –d pour décompresser, suivie du nom du fichier à décompresser et le nom du fichier décompressé.\n"
        "Exemple : ./exe –d monfichier.hfzip monfichier.txt\n\n");
}

/*!
 *  \fn void testArg(int argc, char** argv)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>, JAULIN Gautier <jaulingaut@cy-tech.fr>
 *  \version 0.1
 *  \date Thu 02 December 2021 - 17:19:42
 *  \brief Lit la taille d'un fichier
 *  \param nom le fichier dont on veut connaitre la taille
 */
long size(char* nom){
    FILE *fichier = NULL;
    long size;

    fichier=fopen(nom,"rb");

    if(fichier)
    {
      fseek (fichier, 0, SEEK_END);
      size=ftell (fichier);
      fclose (fichier);
    }
    return size;
}

/*!
 *  \fn void compTaille(char* nom1, char* nom2)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>, JAULIN Gautier <jaulingaut@cy-tech.fr>
 *  \version 0.1
 *  \date Thu 02 December 2021 - 17:26:58
 *  \brief Compare la taille de deux fichier et l'affiche
 *  \param nom1 le nom du premier fichier
 *  \param nom2 le nom du deuxième fichier
 */
void compTaille(char* nom1, char* nom2){
  printf("%ldkb compressed to %ldkb(%ld%%)\n", size(nom1)/1000, size(nom2)/1000, (size(nom2)/size(nom1)*100));
}
