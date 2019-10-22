/*
 * Autore: Bruno Francesco;
 * Classe: 4A ROB;
 * Inizio: 16/09/2019;
 * Fine:
 * Testo esercizio: Creare un programma in linguaggio C che legga il file vgsales.csv e lo importi in un array di strutture.
   Ogni riga contiene i campi separati da virgole, per cui può essere comodo creare una funzione split
   che dalla riga letta ritorni la struttura valorizzata.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 1000
#define NUMGAME 100
#define SEPA ","

typedef struct video {
    /* data */
    int rank;
    char* name;
    char* platform;
    int year;
    char* genre;
    char* publisher;
    float na_Sales;
    float eu_Sales;
    float jp_Sales;
    float other_Sales;
    float global_Sales;
} Videogame;

void loadTableGame(Videogame games[],  int *dim, int dimMax, int lungStr, char nameFile[]);
void stampaGiochi(Videogame game[], int dim);
void stampaGioco(Videogame game);
void menu(Videogame game[], int dim);
void cercaPerRank(Videogame game[], int dim);

int main(int argc, char const *argv[]) {
    /* code */
    Videogame gameList[NUMGAME];
    int numberGame;
    char nomeFile[] = "vgsales.csv";

    loadTableGame(gameList, &numberGame, NUMGAME, DIM, nomeFile);
    stampaGiochi(gameList, numberGame);
    printf("\n\n\n");
    menu(gameList, numberGame);
    return 0;
}

void loadTableGame(Videogame games[],  int *dim, int dimMax, int lungStr, char nameFile[]) {
    /* code */
    FILE *fp;
    char appoggio[lungStr];
    char *pch;
    char primaRiga[lungStr];
    int k = 0;

    fp = fopen(nameFile, "r");
    if(fp!=NULL){
        /* code */
        fgets(primaRiga, lungStr, fp);
        printf("%s\n", primaRiga);
        while (k<dimMax && fgets(appoggio, lungStr, fp)!= NULL) {
            /* code */
            pch = strtok (appoggio, SEPA);
            games[k].rank = atoi (pch);

            pch = strtok (NULL, SEPA);
            games[k].name = malloc((strlen(pch) + 1)*sizeof(char));
            strcpy(games[k].name, pch);

            pch = strtok (NULL, SEPA);
            games[k].platform = malloc((strlen(pch) + 1)*sizeof(char));
            strcpy(games[k].platform, pch);

            pch = strtok (NULL, SEPA);
            games[k].year = atoi (pch);

            pch = strtok (NULL, SEPA);
            games[k].genre = malloc((strlen(pch) + 1)*sizeof(char));
            strcpy(games[k].genre, pch);

            pch = strtok (NULL, SEPA);
            games[k].publisher = malloc((strlen(pch) + 1)*sizeof(char));
            strcpy(games[k].publisher, pch);

            pch = strtok (NULL, SEPA);
            games[k].na_Sales = atof (pch);

            pch = strtok (NULL, SEPA);
            games[k].eu_Sales  = atof (pch);

            pch = strtok (NULL, SEPA);
            games[k].jp_Sales = atof (pch);

            pch = strtok (NULL, SEPA);
            games[k].other_Sales = atof (pch);

            pch = strtok (NULL, SEPA);
            games[k].global_Sales = atof (pch);
            k++;
        }
    }
    else{
        printf("\nfile non esiste\n");
    }
    *dim = k;
    fclose(fp);
}

void stampaGiochi(Videogame game[], int dim){
    /* code */
    for (int i = 0; i < dim; i++) {
        /* code */
        printf("%d, %s, %s, %d, %s, %s, %.2f, %.2f, %.2f, %.2f, %.2f\n", game[i].rank, game[i].name, game[i].platform, game[i].year, game[i].genre, game[i].publisher, game[i].na_Sales, game[i].eu_Sales, game[i].jp_Sales, game[i].other_Sales, game[i].global_Sales);

    }
}

void stampaGioco(Videogame game){
    /* code */
    printf("\t%d, %s, %s, %d, %s, %s, %.2f, %.2f, %.2f, %.2f, %.2f\n", game.rank, game.name, game.platform, game.year, game.genre, game.publisher, game.na_Sales, game.eu_Sales, game.jp_Sales, game.other_Sales, game.global_Sales);
}

void menu(Videogame game[], int dim){
    /* code */
    int opzione;
    do{
        printf("0 = esci;\n");
        printf("1 = Ricerca per rank;\n");
        printf("2 = Ricerca per nome;\n");
        printf("3 = Ricerca per console:\n");
        //printf("4 = Incasso per ogni reparto\n");
        //printf("5 = incasso totale per tutti i reparti nel periodo in input\n");

        printf("\nScegliere un tipo di ricerca: ");
        scanf("%d", &opzione);
        switch(opzione){
            case 1:
                cercaPerRank(game, dim);
                break;

            case 2:
                printf("\n-------------------------------------------------------\n");
                //visualizzaIncassi(incassi, REPARTI, MESI);
                printf("\n-------------------------------------------------------\n");
                break;

            case 3:
                //incassoPerMese(incassi, REPARTI, MESI);
                printf("\n-------------------------------------------------------\n");
                break;
/*
            case 4:
                incassoPerReparto(incassi, REPARTI, MESI);
                printf("\n-------------------------------------------------------\n");
                break;
            case 5:
                incassoPerRepartoPerPeriodo(incassi, REPARTI, MESI);
                printf("\n-------------------------------------------------------\n");
                break;
*/
        }
    }
    while(opzione!=0);
}

void cercaPerRank(Videogame game[], int dim){
    /* code */
    int i = 0;
    int rank = 0;
    int tro = -1;

    do{
        /* code */
        printf("\nInserire il rank da trovare:");
        scanf("%d", &rank);
    }while (rank<1 || rank>dim);

    while (i<dim && tro == -1){
        /* code */
        if(game[i].rank == rank){
            /* code */
            printf("\n--------------------------------------------------------------------------------------------------------------");
            printf("\nGioco trovato!\n");
            stampaGioco(game[i]);
            printf("--------------------------------------------------------------------------------------------------------------\n\n");
            tro = i;
        }
        i++;
    }
}
