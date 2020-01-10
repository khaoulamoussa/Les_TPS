#include<stdio.h>
#include<stdlib.h>
void affiche_vecteur(int * vecteur, int dimension)
{
    int i;
    printf("( ");
    for(i=0;i<dimension;i++)
    printf("%d" ,vecteur[i]);
    printf(")\n");
}
void affiche_matrice(int ** matrice, int lignes,int colonness)
{
  int i;
  for(i=0;i<lignes;i++)
  affiche_vecteur(matrice[i],colonness);
  printf("\n");
}

int * alloue_vecteur(int dimension, int val)
{
     int i;
     int * vecteur = (int*)malloc(dimension*sizeof(int));
     for(i=0;i<dimension;i++)
     vecteur[i]=val;
     return vecteur;
}
void libere_vecteur(int * vecteur)
{
    free(vecteur);
}
int ** alloue_matrice (int lignes, int colonnes,int val)
{
    int i,j;
    int** matrice = (int**)malloc(lignes*sizeof(int *));
    for (i=0;i<lignes;i++)
    matrice[i]= (int*)malloc(colonnes*sizeof(int*));
    for (i=0;i<lignes;i++)
    for(j=0;j<colonnes;j++)
    matrice[i][j]=val;
    return matrice;
}
void libere_matrice(int ** matrice,int lignes)
{
   int i;
   for (i=0;i<lignes;i++)
   free((int *)matrice[i]);
}   
int ** alloue_matrice_zero(int lignes, int colonnes)
{
    int i;
    int** matrice = (int**)calloc(lignes,sizeof(int **));
    for (i=0;i<lignes;i++)
    matrice[i]= (int*)calloc(colonnes,sizeof(int*));
    return matrice;
}
int ** genere_matrice_identite(int dimension)
{
    int i;
    int ** identite = alloue_matrice_zero(dimension,dimension);
    for (i=0;i<dimension;i++)
    identite[i][i]=1;
    affiche_matrice(identite,dimension,dimension);
    return identite;
}     
int ** alloue_matrice_pascal(int dimension)
{
int i,j;
int** matrice =(int**) malloc(dimension*sizeof(int **));
for (i=0;i<dimension;i++)
matrice[i]= (int*)malloc(i*sizeof(int*));
return matrice;
}
int ** remplit_matrice_pascal(int dimension)
{
int i,j;
int** matrice = alloue_matrice_pascal(dimension);
for (i=0;i<dimension;i++)
{
    matrice[i][0]=1;
    matrice[i][i]=1;
}
   for (i=2;i<dimension;i++)
        for(j=1;j<i;j++)
        {
          matrice[i][j]= matrice[i-1][j-1]+ matrice[i-1][j];
        }
   return matrice;
}
void affiche_matrice_pascal(int ** matrice, int dimension)
{
   int i;
   for(i=0;i<dimension;i++)
   affiche_vecteur(matrice[i],i+1);
   printf("\n");
}
char recupere_caractere()
{
char car;
scanf("%c",&car);
}
int* recupere_n_entier(int n)
{
int i;
int * tableau = alloue_vecteur(n,0);
for(i=0;i<n;i++)
scanf("%d",&tableau[i]);
return tableau;
}
int * recupere_entiers(int n,int taille_max)
{
int i;
int * tableau = alloue_vecteur(n,0);
for(i=0;i<taille_max;i++)
{
if(i == n)
{
n+=n;
tableau= (int*)realloc((void *)tableau, sizeof(int*) * n);
}
  scanf("%d",&tableau[i]);
}
return tableau;
}
int *** alloue_tableau_3D(int longueur, int largeur, int hauteur)
{
int *** tableau;
int i, j;
tableau = (int***)malloc (longueur * sizeof (int ***));
tableau[0] = (int**)malloc (longueur * largeur * sizeof (int* *));
tableau[0][0] = (int*)malloc (longueur * largeur * hauteur * sizeof (int*));
for (i = 0; i < longueur; i++)
{
tableau[i] = tableau[0] + i * largeur;
for (j = 0; j < largeur; j++)
tableau[i][j] = tableau[0][0] + i * largeur * hauteur + j * hauteur;
}
return tableau;
}
void libere_tableau_3D(int *** tableau)
{

free(tableau[0][0]);
free(tableau[0]);
free(tableau);
}
void affiche_tableau_3D(int *** tableau,int longueur, int largeur, int hauteur)
{
int i,j,k;
for(i=0;i<longueur;i++)
{
printf("( ");
for(j=0;j<largeur;j++)
{
printf("( ");
for(k=0;k<hauteur;k++)
{
printf("%d ",tableau[i][j][k]);
}
if(j==largeur-1)
printf(") ");
else
printf(")\n ");
}
printf(")\n\n ");
}
}
main()
{
int dimension=6;
int lignes =5;
int colonnes =4;
int n=5;
int taille_max=20;
int longueur=4;
int largeur=6;
int hauteur=3;
int * vecteur=alloue_vecteur(dimension, 18);
int ** matrice =alloue_matrice (lignes,colonnes,33);
int ** matrice_zero= alloue_matrice_zero(lignes,colonnes);
int ** matrice_identite= genere_matrice_identite(dimension);
int ** matrice_pascal= remplit_matrice_pascal(dimension);
int *** tableau =alloue_tableau_3D( longueur, largeur, hauteur);
int * tableau1= recupere_n_entier(n);
int * tableau2= recupere_entiers(n, taille_max);
affiche_vecteur(vecteur,dimension);
affiche_matrice(matrice,lignes, colonnes);
affiche_matrice(matrice_zero,lignes, colonnes);
affiche_matrice(matrice_identite,dimension,dimension);
affiche_matrice_pascal(matrice_pascal,dimension);
affiche_tableau_3D(tableau, longueur, largeur, hauteur);
affiche_vecteur(tableau1,n);
affiche_vecteur(tableau2,taille_max);
libere_vecteur( vecteur);
libere_matrice(matrice,lignes);
libere_matrice(matrice_zero,lignes);
libere_matrice(matrice_identite,dimension);
libere_tableau_3D(tableau);
libere_vecteur(tableau1);
libere_vecteur(tableau2);
return 1;
}


