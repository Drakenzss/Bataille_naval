#include <stdio.h>
#include <string>
#include <string.h>

//Constante

#define TAILLE 10

//Structure

typedef struct cases
{
	int ligne = 0; // x
	int colonne = 0; // Y

}cases;

typedef struct bateau
{
	int porte_avion; // le porte avion prend 5 cases
	int croiseur; // le croiseur prend 4 cases
	int torpilleur; //le torpilleur prend 2 cases

	

}bateau;

typedef struct flotte
{
	bateau* porte_avion; // le porte avion prend 5 cases
	bateau* croiseur; // le croiseur prend 4 cases
	bateau* torpilleur; //le torpilleur prend 2 cases
}flotte;

typedef struct position
{
	int posx;
	int posy;
}position;

//déclaration de fonction
void creaCase(cases*);
int conparCase(cases*);
void creabat(bateau*,position*);
int VerifBat(cases*, bateau*);
void CreaFlotte(cases*);

int main()
{
	
	// tableau de type structuré

	cases tab_case[10] = { {0},{0},{0},{0},{0},{0},{0},{0},{0},{0} };

	//variable structure
	bateau* bateaux;
	position* pos;
	flotte* flottes;

	//initialisation pointeur
	bateaux = (bateau*)malloc(sizeof(bateau));
	pos = (position*)malloc(sizeof(position));
	flottes = (flotte*)malloc(sizeof(flotte));

	//pointeur
	bateaux = (bateau*)malloc(2 * sizeof(bateau));


	creaCase(tab_case);

	CreaFlotte(tab_case);
		
	int i;
	int j;

	do
	{
		printf("quels lignes ?\n");
		scanf_s("%d", &i);
	} while (i > 10); // tant que i n'est pas supérieur à 10 on refait la boucle do jusqu'à ce qu'il y est une valeur inférieur

		tab_case[0].ligne = i; // la valeur i prend la ligne du tableau qu'elle correspond

	do
	{
		printf("quels colonnes ?\n");
		scanf_s("%d", &j);
	} while (j > 10); // tant que j n'est pas supérieur à 10 on refait la boucle do jusqu'à ce qu'il y est une valeur inférieur

	tab_case[j].colonne = j; // la valeur j prend la colonne du tableau qu'elle correspond

	conparCase(tab_case);

	creabat(bateaux,pos);

	VerifBat(tab_case,bateaux);

	return 0;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
* *BUT: créer des cases de jeu                                                              *
*                                                                                           *
* ENTREE: /                                                                                 *
*                                                                                           *
* SORTIE: /                                                                                 *
*                                                                                           *
* DESCRIPTIF: les cases de jeu son set à 10 lignes et 10 colonnes à 0  pour pouvoir         *
* poser des objet ou non                                                                    *
*                                                                                           *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void creaCase(cases* tab_case)	
{
	int i;
	int j;

	for (i = 0; i < 10; i++)
	{
		tab_case[i].ligne = 0;
		for (j = 0; j < 10; j++)
		{
			tab_case[j].colonne = 0;
		}
	}
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* *BUT: comparaison des cases du jeu                                                        *
*                                                                                           *
* ENTREE: /                                                                                 *
*                                                                                           *
* SORTIE: /                                                                                 *
*                                                                                           *
* DESCRIPTIF: lors de l'entrée de donné de jeu les cases sont vérifié si elle sont          *
* pleine ou vide                                                                            *
*                                                                                           *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int conparCase(cases* tab_case)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < 10; i++)
	{
		if (tab_case[i].ligne == 0)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}

	for (j = 0; j < 10; j++)
	{
		if (tab_case[j].colonne == 0)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
* BUT: création du bateau                                                                   *
*                                                                                           *
* ENTREE: le nom du bateau                                                                  *
*                                                                                           *
* SORTIE: /                                                                                 *
*                                                                                           *
* DESCRIPTIF: les bateau sont initialisé                                                    *
*                                                                                           *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void creabat(bateau* bateaux, position* pos)
{
	int i;
	
	for (i = 0; i < 4; i++)
	{
		bateaux->croiseur = i;
		if (bateaux->croiseur == pos->posx)
		{
			bateaux->croiseur = pos->posx + i;
		}
		else if (bateaux->croiseur == pos->posy)
		{
			bateaux->croiseur = pos->posy + i;
		}
	}

	for (i = 0; i < 5; i++)
	{
		bateaux->porte_avion = 5;
		if (bateaux->porte_avion == pos->posx)
		{
			bateaux->porte_avion = pos->posx + i;
		}
		else if (bateaux->porte_avion == pos->posy)
		{
			bateaux->porte_avion = pos->posy + i;
		}
	}
	for (i = 0; i < 2; i++)
	{
		bateaux->torpilleur = i;
		if (bateaux->torpilleur == pos->posx)
		{
			bateaux->torpilleur = pos->posy + i;
		}
		else if (bateaux->torpilleur == pos->posy)
		{
			bateaux->torpilleur = pos->posy + i;
		}
	}
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* BUT: Vérifie si la case est prise ou non                                                  *
*                                                                                           *
* ENTREE: /                                                                                 *
*                                                                                           *
* SORTIE: /                                                                                 *
*                                                                                           *
* DESCRIPTIF: Cette fonction vérifie si une case appartient à un bateau                     *
*                                                                                           *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int VerifBat(cases* tab_case,bateau* bateaux)
{
	int i = 0;

	for (i = 0; i < 10; i++)
	{
		if (conparCase(tab_case) == bateaux->croiseur)
		{
			return 1;
			printf("toucher");

		}
		else
		{
			return 0;
			printf("pas toucher");
		}
	}

	for (i = 0; i < 10; i++)
	{
		if (conparCase(tab_case) == bateaux->porte_avion)
		{
			return 1;
			printf("toucher");

		}
		else
		{
			return 0;
			printf("pas toucher");
		}

		for (i = 0; i < 10; i++)
		{
			if (conparCase(tab_case) == bateaux->torpilleur)
			{
				return 1;
				printf("toucher");

			}
			else
			{
				return 0;
				printf("pas toucher");
			}
		}
	}
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* BUT: Vérifie si la case est prise ou non                                                  *
*                                                                                           *
* ENTREE: /                                                                                 *
*                                                                                           *
* SORTIE: /                                                                                 *
*                                                                                           *
* DESCRIPTIF: Cette fonction vérifie si une case appartient à un bateau                     *
*                                                                                           *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void CreaFlotte(cases* tab_case)
{
	int i=0;

	

	printf("Positionnez le croiseur \n");
	printf("position X: \n");
	scanf_s("%d", &tab_case[0].ligne);
	printf("Position Y: \n");
	scanf_s("%d", &tab_case[0].colonne);


	printf("Positionnez le porte avion \n");
	printf("position X: \n");
	scanf_s("%d",&tab_case[1].ligne);
	printf("Position Y: \n");
	scanf_s("%d", &tab_case[1].colonne);

	printf("Positionnez le torpilleur \n");
	printf("position X: \n");
	scanf_s("%d", &tab_case[2].ligne);
	printf("Position Y: \n");
	scanf_s("%d", &tab_case[2].colonne);
}