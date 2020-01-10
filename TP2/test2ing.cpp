#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<malloc.h>
//les prototypes
int * alloue_vecteur(int dimension,int val);
void libere_vecteur(int * vecteur);
int** alloue_matrice(int lignes,int colonnes,int val);
void libere_matrice(int ** matrice,int lignes);
int ** genere_matrice_identite(int dimension);
int ** alloue_matrice_zero(int lignes,int colonnes);
//les fonctions
int * alloue_vecteur(int dimension,int val)
{
	int i;
	int * vecteur=malloc(dimension*sizeof(int));
	for(i=0;i<dimension;i++)
	{
		vecteur[i]=val;
	}
	return vecteur;
}
void libere_vecteur(int * vecteur)
{
	free(vecteur);
}
int** alloue_matrice(int lignes,int colonnes,int val)
{
	int i,j;
	int** matrice = malloc(lignes*sizeof(int *));
	for(i=0;i<lignes;i++)
	{
		matrice[i]= malloc(colonnes*sizeof(int *));
	}
	for(i=0;i<lignes;i++)
	{
		for(j=0;j<colonnes;j++)
		{
			matrice[i][j]=val;
		}
	}
	return matrice;
}
void libere_matrice(int ** matrice,int lignes)
{
	int i;
	for(i=0;i<lignes;i++)
	{
		free((int *)matrice[i]);
	}
}
int ** alloue_matrice_zero(int lignes,int colonnes)
{
	int i;
	int** matrice = calloc(lignes,sizeof(int *));
	for(i=0;i<lignes;i++)
	{
		matrice[i]= calloc(colonnes,sizeof(int))//malloc un seul argument et calloc 2 arguments
	}
	return matrice;
}
int ** genere_matrice_identite(int dimension)
{
	int i;
	int ** identite = alloue_matrice_zero(dimension,dimension);
	for(i=0;i<dimension;i++)
	{
		identite[i][i]=1;
		affiche_matrice(identite,dimension,dimension);
	}
	return identite;
}
