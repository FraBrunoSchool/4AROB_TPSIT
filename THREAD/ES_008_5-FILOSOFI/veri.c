#define DIM 15

int main(int argc, char const *argv[]){
    /* code */
    int vett[DIM];
    for (int d = 0; d < DIM; d++){
        /* code */
        printf("Inserisci valore per posizione %d", d);
        scanf("%d", vett[d]);
    }
    for (int d = 0; d < DIM; d++){
        printf("posizione %d valore %d", d, vett[d]);
    }
    int sommaPari=0;
    int sommaDisp=0;
    for (int d = 0; d < DIM; d++){
        if (d%2==0){
            /* code */
            sommaPari=sommaPari+vett[d];
        }else{
            sommaDisp=sommaDisp+vett[d];
        }
    }
    printf("Somma indici pari: %d", sommaPari);
    printf("Somma indici dispari: %d", sommaDisp);
    return 0;
}

#define RIGHE 4
#define COLONNE 5

int main(){
	int argc;
	
	int r,c,matrix[RIGHE][COLONNE];
	srand(time(NULL));

    for(r=0;r<RIGHE;r++){
        for(c=0;c<COLONNE;c++){
            matrix[r][c]=rand()%100;
            printf("%d	",matrix[r][c]);
        }
	    printf("\n");
    }

    for (r = 0; r < RIGHE; r++){
      
        int sommaRiga=0;
        int n = 0;
        for (c = 0; c < COLONNE; c++){
            
            if (matrix[r][c]<=50){
              
                sommaRiga=sommaRiga+matrix[r][c];
                n++;
            }
        }
        printf("Media riga %d è %d", r, sommaRiga/n);
    }

    for (c = 0; c < COLONNE; c++){
      
        int sommaColonna=0;
        int n = 0;
        for (r = 0; r < RIGHE; r++){
           
            if (matrix[r][c]>50){
                
                sommaColonna=sommaColonna+matrix[r][c];
                n++;
            }
        }
        printf("Media Colonna %d è %d", c, sommaColonna/n);
    }
    
    return 0;
}



#define RIGHE 4
#define COLONNE 3

int main(int argc, char const *argv[])
{   
    /* code */
    int matrixUno[RIGHE][COLONNE];
    int matrixDue[RIGHE][COLONNE];
    int matrixProdotto[RIGHE][COLONNE];
    int c, r;

    for(r=0;r<RIGHE;r++){
        for(c=0;c<COLONNE;c++){
            printf("Inserisci valore matrice uno [%d][%d]", r, c);
            scanf("%d", matrixUno[r][c]);
            printf("%d	",matrixUno[r][c]);

            matrixDue[r][c]=rand()%100;
            printf("%d	",matrixDue[r][c]);
        }
	    printf("\n");
    }
    for(r=0;r<RIGHE;r++){
        int max = matrixUno[r][0];
        for(c=0;c<COLONNE;c++){
            if (matrixUno[r][c]>max){
                max=matrixUno[r][c];
            }
        }
        printf("Max riga %d è %d", r, max)
    }
    for(r=0;r<RIGHE;r++){
        for(c=0;c<COLONNE;c++){
            matrixProdotto[r][c]=matrixUno[r][c]*matrixDue[r][c];
        }
    }
    return 0;
}

