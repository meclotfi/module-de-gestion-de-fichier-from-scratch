/*
modele.c
--------


Rôle : définir le model de manipulation des fichier (ouvrir, fermer, lireDire ...)
*/
#include <stdio.h>
#include <stdlib.h>

#include "modele.h"

/*--------------Fonction d'ouverture d'un fichier--------------*/
int ouvrir(TnOF **f,char *chemin,char mode)
{
    *f = malloc(sizeof(TnOF));
    char s[3];

    if((mode == 'A') || (mode == 'a')) sprintf(s,"rb+");
    else if ((mode == 'N') || (mode == 'n')) sprintf(s,"wb+");
    else return 0;

    (*f)->fichier = fopen(chemin, s);
    if((*f)->fichier == NULL)   return 0;

    if((mode == 'A') || (mode == 'a'))
    {
        fread(&((*f)->entete), sizeof(Entete), 1, (*f)->fichier);
    }
    else if ((mode == 'N') || (mode == 'n'))
    {
        (*f)->entete.adrDerBloc = 0;
        (*f)->entete.nbEnreg = 0;
        (*f)->entete.indice_libre = 0;
    }
    return 1;
}
/*--------------------------------------------------------------*/

/*--------------Fonction de fermeture d'un fichier--------------*/
void fermer(TnOF *f)
{
    //Sauvegarde de l'entête
    rewind(f->fichier);
    fwrite(&(f->entete), sizeof(Entete), 1, f->fichier);
    fclose(f->fichier);
    free(f);
}
/*--------------------------------------------------------------*/

/*-----------------Fonction de lecture d'un bloc----------------*/
void lireDir(TnOF *f,int N_Bloc,Tbloc *buffer)
{
    if(N_Bloc <= (f->entete).adrDerBloc)
    {
        fseek(f->fichier, sizeof(Entete) + (N_Bloc-1) * sizeof(Tbloc),SEEK_SET);
        fread(buffer, 1, sizeof(Tbloc), f->fichier);
    }
}
/*--------------------------------------------------------------*/

/*-----------------Fonction d'écriture d'un bloc----------------*/
void ecrireDir(TnOF *f,int N_Bloc,Tbloc *buffer)
{
    if(N_Bloc <= (f->entete).adrDerBloc)
    {
        fseek(f->fichier, sizeof(Entete) + (N_Bloc-1) * sizeof(Tbloc),SEEK_SET);
        fwrite(buffer, 1, sizeof(Tbloc), f->fichier);
    }
}
/*--------------------------------------------------------------*/

/*----------------Fonction de lecture de l'entête---------------*/
/* lorsque i=1 ====> lecture de l'adresse du dernier bloc
   lorsque i=2 ====> lecture du nombre d'enregistrement
   lorsque i=3 ====> lecture de la position du dernier indice
                     libre dans le dernier bloc*/
int entete(TnOF *f,int i)
{
    if(i == 1) return (f->entete).adrDerBloc;
    else if(i == 2) return (f->entete).nbEnreg;
    else if(i == 3) return (f->entete).indice_libre;
    else return -1;
}
/*--------------------------------------------------------------*/

/*-------------Fonction de modification de l'entête-------------*/
/* lorsque i=1 ====> modification de l'adresse du dernier bloc
   lorsque i=2 ====> modification du nombre d'enregistrement
   lorsque i=3 ====> modification de la position du dernier indice
                     libre dans le dernier bloc*/
void aff_entete(TnOF *f, int i, int val)
{
    if(i == 1) (f->entete).adrDerBloc = val;
    else if(i == 2) (f->entete).nbEnreg = val;
    else if(i == 3) (f->entete).indice_libre = val;
}
/*--------------------------------------------------------------*/

/*--------------------L'allocation d'un bloc--------------------*/
int alloc_bloc(TnOF *f)
{
    aff_entete(f,1,entete(f,1)+1);
    return entete(f,1);
}
