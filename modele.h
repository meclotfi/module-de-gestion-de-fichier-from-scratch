/*
modele.h
--------


Rôle : définir les prototype des fonctions pour le model de manipulation des fichier (ouvrir, fermer, lireDire ...)
*/

#ifndef MODEL_INCLUDED
#define MODEL_INCLUDED

    #define TAILLE_BLOC 1000

    /*-------Déclaration des structures-------*/
    typedef struct enreg
    {
        int matricule;
        char nom[30];
        char prenom[30];
        int date_naiss;
        int date_recr;
        int wilaya;
        int sexe;
        int g_sang;
        int grade;
        int sp;
        int der_dep;
        char etab_univ[10];
    } enreg;
    typedef struct Tbloc
    {
        enreg Tenreg[TAILLE_BLOC];

    } Tbloc;
    typedef struct Entete
    {
        int adrDerBloc;
        int nbEnreg;
        int indice_libre;
    } Entete;
    typedef struct TnOF
    {
        FILE *fichier;
        Entete entete;
    } TnOF;

    /*----------Prototypes des fonctions----------*/
    int ouvrir(TnOF **f,char *chemin,char mode);
    void fermer(TnOF *f);
    void lireDir(TnOF *f,int N_Bloc,Tbloc *buffer);
    void ecrireDir(TnOF *f,int N_Bloc,Tbloc *buffer);
    int entete(TnOF *f,int i);
    void aff_entete(TnOF *f, int i, int val);
    int alloc_bloc(TnOF *f);
    /*--------------------------------------------*/

#endif
