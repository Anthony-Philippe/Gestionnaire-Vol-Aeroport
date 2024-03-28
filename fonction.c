#include "main.h"

bool checkPlaceParking(parking Parking)
{
    if (Parking.placesRestantes != 0)
    {
        printf("Il reste %d places", Parking.placesRestantes);
        return true;
    }
    else
    {
        printf("Il n'y a plus de place dans le parking, veuillez atterrir autre part");
        return false;
    }

    return true;
}

bool checkTypeAvion(avion Avion, piste Piste)
{
    if (Avion.ca == ligne)
    {
        if (Piste.cp == grande)
        {
            printf("Autorisation d'atterrir");
            return true;
        }
        else
        {
            printf("Interdiction d'atterrir ici");
            return false;
        }
    }
    if (Avion.ca == leger)
    {
        if (Piste.cp != grande)
        {
            printf("Autorisation d'atterrir");
            return true;
        }
        else
        {
            printf("Interdiction d'atterrir");
            return false;
        }
    }
    return true;
}

bool checkPlaceFile(piste Piste)
{
    int cpt = 0;
    piste temp = Piste;

    while (temp.file.premier->suivant != NULL)
    {
        cpt++;
        temp.file.premier = temp.file.premier->suivant;
    }
    if (cpt >= Piste.nbMaxAttente)
    {
        printf("Vous êtes %d dans la file", cpt);
        return true;
    }
    else
    {
        printf("File complète, veuillez patienter");
        return false;
    }
    return true;
}

void resumeTrafic(avion *Avion)
{
    initAvion(Avion);
}

void addAvionFile(piste Piste, avion Avion)
{
    piste Temp = Piste;

    if (checkPlaceFile(Piste) == true)
    {
        while (Temp.file.premier->suivant != NULL)
        {
            Temp.file.premier = Temp.file.premier->suivant;
        }
        Temp.file.premier->suivant->id = Avion.id;
        Piste.file = Temp.file;
    }
}

int decollage(int cpt, piste Piste, avion avion, parking parking)
{
    cpt++;
    if (cpt == 100)
    {
        Piste.file.premier = NULL;
        Piste.file.premier = Piste.file.premier->suivant;
        avion.etat = vol;
        parking.placesRestantes++;
        cpt = 0;
    }

    return cpt;
}

void atterrissage(avion avion, piste piste, parking parking)
{
    int verifParking = 0, verifType = 0;
    verifType = checkTypeAvion(avion, piste);
    verifParking = checkPlaceParking(parking);

    if (verifType == true && verifParking == true)
    {
        avion.etat = sol;
        parking.placesRestantes--;
    }
}

parking initParking(parking parking)
{
    int i;
    for (i = 0; i < 13; i++)
    {
        parking.emplacement[i] = 0;
    }
    return parking;
}

parking remplirParking(parking parking, avion Avion)
{
    int i;
    for (i = 0; i < 13; i++)
    {
        if (parking.emplacement[i] == 0)
            parking.emplacement[i] = Avion.id;
    }
    return parking;
}

statAvion countAvions(avion *Avion, statAvion stat)
{
    avion counter[51];
    for (int i = 1; i < 51; i++)
        counter[i] = Avion[i];
    int a = 1;
    while (a < 51)
    {
        if (counter[a].ca == ligne)
            stat.ligne++;
        else if (counter[a].ca == affaire)
            stat.affaire++;
        else if (counter[a].ca == leger)
            stat.leger++;
        if (counter[a].etat == sol)
            stat.sol++;
        else if (counter[a].etat == vol)
            stat.vol++;
        if (counter[a].nbPassager > 0)
            stat.nbPassager += counter[a].nbPassager;
        a++;
    }
    return stat;
}

statAvion resetStat(statAvion stat)
{
    stat.affaire = 0;
    stat.leger = 0;
    stat.ligne = 0;
    stat.nbPassager = 0;
    stat.sol = 0;
    stat.vol = 0;
    stat.total = 0;
    return stat;
}

void initAvion(avion Avion[])
{
    int cpt = 0;
    for (int i = 1; i < 51; i++)
    {
        Avion[i].id = i;
        if (rand() % 2 == 1 && cpt < 13)
        {
            Avion[i].etat = sol;
            cpt++;
        }
        else
            Avion[i].etat = vol;
        if (rand() % 3 == 1)
        {
            Avion[i].ca = ligne;
            Avion[i].nbPassager = 500;
        }
        else if (rand() % 3 == 2)
        {
            Avion[i].ca = affaire;
            Avion[i].nbPassager = 20;
        }
        else
        {
            Avion[i].ca = leger;
            Avion[i].nbPassager = 5;
        }
    }
}

void saveBDDavions(avion *Avion)
{
    FILE *f = fopen("BDD/avions.txt", "w");
    int a = 1;
    while (a < 51)
    {
        fprintf(f, "%d %u %u %d", Avion[a].id, Avion[a].etat, Avion[a].ca, Avion[a].nbPassager);
        a++;
    }
    fclose(f);
}

/*avion loadBDDavions(avion *Avion)
{
    FILE *f = fopen("BDD/avions.txt", "r");
    int a = 1;
    while (getc(f) != EOF)
    {
        fseek(f, -1, SEEK_CUR);
        fscanf(f, "%d %u %u %d", Avion[a].id, Avion[a].etat, Avion[a].ca, Avion[a].nbPassager);
        a++;
    }
    fclose(f);
}*/