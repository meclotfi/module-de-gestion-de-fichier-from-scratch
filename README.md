# module-de-gestion-de-fichier-from-scratch
 un module de gestion du fichier organisé selon la méthode « TObarreF » : fichier vu comme Tableau, non Ordonnée, avec des enregistrements de taille Fixe. Un bloc peut contenir au maximum 1000 enregistrements.
 ce programme est écrit en language C et il est muni d'une interface basique dans la console 
 
La création du fichier s’appuiera sur un module de chargement initial qui consiste à remplir le fichier avec N
enregistrements (N étant un entier à lire, par exemple : 10 000, 20 000, 30 000, etc.). Pour que le chargement
initial soit rapide, il est réaliser avec des valeurs aléatoires comme suit :

- Matricule : nombre aléatoire entre 111111 et 999999

- Nom/Prénom : un nombre entre 4 et 30 (ce nombre étant le nombre
de caractères du nom/prénom). Ensuite, pour chaque caractère du nom/prénom je génère un nombre
entre 1 et 26 puis je met dans ce caractère la lettre qui correspond.

- Date_Naissance: un nombre aléatoire entre 1953 et 1992 pour l’année, un nombre aléatoire entre
1 et 12 pour le mois, et un nombre aléatoire entre 1 et le nombre de jours du mois généré (soit 28 ou 29 ou 30
ou 31) pour le jour. en tenant compte de l’ensemble des contrôles sur la date (par exemple : année
bissextile ou non, etc.).

- Wilaya_Naissance : un nombre aléatoire entre 1 et 48. Ensuite, je récupére le libellé de la
wilaya à partir de ce nombre (par exemple : 16 : Alger, 31 : Oran, ..., etc.).

- Sexe : un nombre aléatoire, soit 1 pour masculin soit 2 pour féminin.

- Groupe_Sanguin :  un nombre entre 1 et 8. Ensuite, je récupére le groupe sanguin à partir de
ce nombre (1 : O+, 2 : A+, 3 : B+, 4 : O-, 5 : A-, 6 : AB+, 7 : B-, 8 : AB-).

- Date_Recrutement : meme controle que la date de naissance

- Grade : un nombre entre 1 et 6. Ensuite, je récupérez le grade à partir d'un ensemble (1 :
Professeur(e), 2 : Maître de conférences Rang A, 3 : Maître de conférences Rang B, 4 : Maître assistant(e) Rang
A, 5 : Maître assistant(e) Rang B, 6 : Assistant(e)).

- Spécialité : un nombre aléatoire. Ensuite, je récupére la spécialité à partir de ce nombre, par
exemple (1 : Informatique, 2 : Architecture, 3 : Médecine, etc.).

- Dernier_Diplôme :  un nombre entre 1 et 5. Ensuite, je récupére le libellé du diplôme à partir
de ce nombre (1 : Doctorat d’Etat, 2 : Doctorat en sciences, 3 : PhD, 4 : HDR, 5 : Magistère).

le programme contient les modules suivants :
- Ajout d’un nouvel enseignant au fichier.
- Modification de l’établissement universitaire d’un enseignant en raison de sa mutation.
- Supprimer un enregistrement donné par le matricule.
- Supprimer tous les enregistrements relatifs à une spécialité donnée.
- Afficher tous les enseignants exerçant dans un établissement donné ayant une ancienneté entre deux
valeurs données (Requête à intervalle).
- Consulter tous les enseignants exerçant dans une région donnée (Ouest, Centre et Est).
- Afficher sur votre écran l’en-tête du fichier.
