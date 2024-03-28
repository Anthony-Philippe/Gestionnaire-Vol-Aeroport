#include "main.h"

int main(int argc, char **argv)
{
    srand(time(NULL));
    int prog = 1;
    piste *piste = NULL;
    parking Parking = initParking(Parking);
    avion Avion[50];
    statAvion stat;
    stat = resetStat(stat);

    affichageA();
    getchar();
    //int cpt = decollage(cpt, *piste, *Avion, Parking);

    char choix[12];
    initAvion(Avion);

    while (prog)
    {
        affichageB(stat);
        scanf("%s", choix);
        switch (*choix)
        {
        case 'a': // affichage aéroport
        case 'A':
            Clean;
            aeroport();
            break;
        case 'b': // Actualiser
        case 'B':
            stat = resetStat(stat);
            stat = countAvions(Avion, stat);
            break;
        case 'd': // ajout avion file décollage
        case 'D':
            addAvionFile(*piste, *Avion);
            break;
        case 's': // sauvegarde de la bdd
        case 'S':
            saveBDDavions(Avion);
            break;
        case 'q': // quitter le programme
        case 'Q':
            prog--;
            Clean;
            break;
        }
        usleep(cycle);
    }

    return 0;
}
