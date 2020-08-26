#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#ifndef MODEL_INCLUDED
#define MODEL_INCLUDED

    #define TAILLE_BLOC 1000

    /*-------Déclaration des structures-------*/
     typedef struct index
    {
        int matricule;
        int  in_reg;
        int  in_etab;
        int  in_wil;
        int  in_sp;
        int  in_anc;
    } index;
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
void rand_enreg(enreg *ch);
int max_j(int max_mois);

int main()
{

    char Tspc[20][10]= {"informatique","medcine","electronique","mecanique","biologie","geologie","letterature","architecture","math","pharmacie"};
    char Tgr[20][6]= {"Professeur(e)","Maître de conférences Rang A","Maître de conférences Rang B","Maître assistant(e) RangA","Maître assistant(e) Rang B","Assistant(e)"};
    TnOF *f;
    Tbloc *buf;int h=0;
    buf=malloc(sizeof(Tbloc));
    ouvrir(&f,"exidvd",'n');int s=1;
 h=1;
     while(h!=100)
     {
        h=h+1;
        rand_enreg(&buf->Tenreg[h]);
        printf("*******le matricule   %d \n",buf->Tenreg[h].matricule);

     }
    alloc_bloc(f);
     ecrireDir(f,1,buf);
 printf("\n       le dernier bloccccc   %d  \n",entete(f,1));
     Tbloc *buf2;
      TnOF *g;
      buf2=malloc(sizeof(Tbloc));
      ouvrir(&g,"exidvd",'A');
      printf("***************************************************************");
     lireDir(g,1,buf2);
h=1;
while(h!=100)
    {
        h=h+1;
        printf("*******le matricule   %d \n",buf2->Tenreg[h].matricule);
    }
}



ecr_enreg(enreg g)
{
    printf("*******le nom : %s      ****le prenom :  %s      *****\n la date de naissance:   %d   ****la date de recrutement: %d \n le matricule: %d ",g.nom,g.prenom,g.date_naiss,g.date_recr,g.matricule);
}
void rand_enreg(enreg *ch)
{
   /// generez un nom et un prenom aleatoirement
    int tail1,tail2,i=0;
    char f,c;
    char no[30];
    char pre[30];
    tail1=randome(1,30);
    tail2=randome(1,30);
    c=randome(65,90);
    while((i<tail1)||(i<tail2))
    {
       if(i<tail1)
        {

         no[i]=c;
         c=randome(97,122);

        }

        if(i<tail2)
        {
          f=randome(97,122);
          pre[i]=f;
        }
        i++;


     }
     strncat((*ch).nom,no,tail1);
     strncat((*ch).prenom,pre,tail2);
/// generez aleatroirememt les dates de naissnce et de l'inscription
     int j;
     int max_m=randome(1,12);
     j=max_j(max_m);
     (*ch).date_naiss=randome(1,j,j*max_m)+max_m*100+randome(1953,1992)*10000;
     max_m=randome(1,12);
     j=max_j(max_m);
     (*ch).date_recr=randome(1,j,j*max_m)+max_m*100+randome(1979,2018)*10000;
     ///generez aleatoirement la specialite
     (*ch).sp=randome(1,10);
     ///generez aleatoirement le sexe
     (*ch).sexe=randome(1,2);
     ///generez aleatoirement la wilaya
     (*ch).wilaya=randome(1,48);
     ///generez aleatoirement le groupe sanguine
    (*ch).g_sang=randome(1,8);
     ///generez aleatoirement le grade
     (*ch).grade=randome(1,6);
    ///generez aleatoirement le dernier deplome obtenue
     (*ch).der_dep=randome(1,5);
     ///generez aleatoirement un matricule
     (*ch).matricule=randome(111111,888888);

}
///une fonction qui donne le maximum de nombre de jour d'un mois donnees
int max_j(int max_m)
{
     if(max_m=2)
     {
        return 28;
     }
    else
     {
        if((max_m<8))
        {
          if(max_m%2==1)
          {
              return 31;
           }
           else
          {
              return 30;
          }
        }
        else
        {
            if(max_m%2==1)
          {
              return 30;
           }
           else
          {
              return 31;
          }
        }
      }
}
int randome(int inf,int sup)
{
    FILE *r;
    long seq;
    int res;
  r=fopen("ra.txt","rw+");
   fscanf(r,"%d",&seq);
   fseek(r,0,SEEK_SET);
   fprintf(r,"%d",(seq+1)%1000);
    fseek(r,seq,SEEK_CUR);
    fscanf(r,"%d",&res);
    fclose(r);
    res=inf+res%(sup-inf);
    if(res>0)
  {return res;}
  else
    {return -res;}
}
/*
modele.c
--------



/*--------------Fonction d'ouverture d'un fichier--------------*/
int ouvrir(TnOF **f,char *chemin,char mode)
{
    *f = malloc(sizeof(TnOF));
    char s[3];

    if((mode == 'A') || (mode == 'a')) sprintf(s,"r+b");
    else if ((mode == 'N') || (mode == 'n')) sprintf(s,"w+b");
    else return 0;
   (*f)->fichier=fopen(chemin,s);
    if((*f)->fichier==NULL)
    {
        printf("on peut pas ouvrir le fichier");
        return 0;
    }

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
    rewind(f->fichier);
    fwrite(&(f->entete), sizeof(Entete), 1, f->fichier);
    fclose(f->fichier);
    free(f);
}
    return 1;
}
/*--------------------------------------------------------------*/

/*--------------Fonction de fermeture d'un fichier--------------*/
void fermer(TnOF *f)
{
    //Sauvegarde de l'entête
/*--------------------------------------------------------------*/

/*-----------------Fonction de lecture d'un bloc----------------*/
void lireDir(TnOF *f,int N_Bloc,Tbloc *buffer)
{
    printf("liredirect");
    if(N_Bloc <= (f->entete).adrDerBloc)
    {
        fseek(f->fichier, sizeof(Entete) + (N_Bloc-1) * sizeof(Tbloc),SEEK_SET);
        fread(buffer, 1, sizeof(Tbloc), f->fichier);
        printf("bien lire ellele");
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

/*rech_decho(char *nomfich,int c,int *Trouv,int *i,int *j)
{
int bi, bs, inf, sup ,trouv, stop ;
ouvrir( F, nomfich, 'A' );
bs = entete( F,1 ); // la borne sup (le num du dernier bloc de F)
bi = 1; // la borne inf (le num du premier bloc de F)
(*Trouv) = 0; stop =0; j = 1;
while( (bi <= bs) && (*Trouv==0)&&(stop==0) )
{
     (*i) = (bi + bs)/2; // le bloc du milieu entre bi et bs
     LireDir( F, (*i), buf );
     if( (c >= buf.tab[1].mat) et (c <= buf.tab[buf.NB].mat) )
     {
         // recherche dichotomique à l'intérieur du bloc (dans la variable buf)...
            inf = 1; sup = buf.NB;
            while((inf <= sup)&&((*Trouv)==0))
            {
                   (*j) = (inf + sup)/2;
                   if(c = buf.tab[(*j)].cle) (*Trouv) =1;
                   else
                   {
                       if(c < buf.tab[(*j)].cle) sup = (*j)-1;
                       else inf=(*j)+1;
                   }
            }
         if( *Trouv==0 ) (*j)=inf;
         /// fin de la recherche interne. j indique l'endroit où devrait se trouver c
         stop = 1;
     }
    else /// non ( c >= buf.tab[1].cle et c <= buf.tab[buf.NB].cle )
    {
          if( c < buf.tab[1].cle ) bs = (*i)-1;
          else bi=(*i)+1;
     }
}
if(*Trouv==0)  (*i)=bi;
fermer( F )
}
*/



























