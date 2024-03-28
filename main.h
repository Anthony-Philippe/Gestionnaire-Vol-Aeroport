#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

typedef enum CATAVION
{
	ligne,
	affaire,
	leger,
} catAvion;

typedef enum CATPISTE
{
	moyenne,
	grande,
	petite,
} catPiste;

typedef enum ETATAVION
{
	sol,
	vol,
} etatAvion;

typedef struct AVION avion;
struct AVION
{
	int id;
	etatAvion etat;
	catAvion ca;
	int nbPassager;
	avion *suivant;
};

typedef struct file file;
struct file
{
	avion *premier;
};

typedef struct PISTE
{
	int numPiste;
	int longueur;
	int nbMaxAttente;
	catPiste cp;
	file file;
} piste;

typedef struct PARKING
{
	int placesRestantes;
	int emplacement[13];
	avion avion;
	catAvion ca;
} parking;

typedef struct statAvion
{
	int ligne, affaire, leger;
	int sol, vol, total;
	int nbPassager;
} statAvion;

bool checkPlaceParking(parking Parking); //Fonction contraintes
bool checkTypeAvion(avion Avion, piste Piste);
bool checkPlaceFile(piste Piste);

void resumeTrafic(avion *Avion); //Fonction Trafic

void addAvionFile(piste Piste, avion Avion); //Fonction décollage
int decollage(int cpt, piste Piste, avion avion, parking parking);
void resumeDecollage();

void atterrissage(avion avion, piste piste, parking parking); //Fonction atterrissage
parking initParking(parking parking);
parking remplirParking(parking parking, avion Avion);

statAvion countAvions(avion *Avion, statAvion stat); //Fonction stat
statAvion resetStat(statAvion stat);
void initAvion(avion *Avion);

void saveBDDavions(avion *Avion); //BDD
avion loadBDDavions(avion *Avion);

void affichageA(); //Fonction affichage
void affichageB(statAvion stat);
#define Clean system("clear");
void aeroport();

#define cycle 100000 //0.1s