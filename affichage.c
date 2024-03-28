#include "main.h"

#define couleur(param) printf("\033[%sm",param) //couleur
#define BleuG couleur("34;1");
#define Gras couleur("1");
#define resetClr couleur("0");

#define Title0 printf("\n│                     "); BleuG; printf("Simulateur de trafics aériens"); resetClr; printf("                   │"); //optimsation affichage
#define subTitle0 printf("\n│                  Appuyez sur Entrée pour continuer...               │");
#define Title1 printf("\n┌──────────────────╢ "); BleuG; printf("Simulateur de trafics aériens"); resetClr; printf(" ╟──────────────────┐\n\n");
#define Title2 printf("\n├──────────────────────────────╢ "); BleuG; printf("Menu"); resetClr; printf(" ╟───────────────────────────────┤\n\n");
#define Top printf("\n┌─────────────────────────────────────────────────────────────────────┐");
#define Side printf("\n│                                                                     │");
#define Bottom printf("\n└─────────────────────────────────────────────────────────────────────┘\n");

void affichageA()
{
    Clean;
    Top;
    Side;
    Title0;
    Side;
    subTitle0;
    Side;
    Bottom;
    printf("\n\t\t\t\t   ");
}

void affichageB(statAvion stat)
{
    stat.total = stat.vol+stat.sol;
    Clean;
    Title1;
    Gras;
    printf("          Nombre d'Avions\n");
    resetClr;
    printf("          └→ Total ∙ %d\n", stat.total);
    printf("          └→ En vol ∙ %d", stat.vol);
    printf("      Sol ∙ %d\n", stat.sol);
    Gras;
    printf("          Nombre d'avions par Catégorie\n");
    resetClr;
    printf("          └→ Ligne ╪ ∙ %d", stat.ligne);
    printf("     Affaire ╬ ∙ %d", stat.affaire);
    printf("    Léger ┼ ∙ %d\n", stat.leger);
    Gras;
    printf("          Nombre de passager\n");
    resetClr;
    printf("          └→ Total ∙ %d\n", stat.nbPassager);
    Title2;
    printf("          Afficher l'aéroport → "); Gras; printf("A\n"); resetClr;
    printf("          Actualiser → "); Gras; printf("B\n"); resetClr;
    printf("          Sauvegarder → "); Gras; printf("S\n"); resetClr;
    printf("          Tempète de donut → "); Gras; printf("T\n"); resetClr;
    printf("\n          Quitter → "); Gras; printf("Q"); resetClr;
    Bottom;
    printf("\n     »  ");
}

void aeroport() //aeroport fichier texte
{
    FILE *f;
    char a;
    f = fopen("aeroport.txt", "r");
    while ((a = fgetc(f)) != EOF)
    {
        printf("%c", a);
    }
    fclose(f);

    char continuer[12];
    scanf("%s", continuer);
}