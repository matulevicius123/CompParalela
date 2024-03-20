// Nome: Igor Benites Moura / TIA: 32275528
// Nome: Joao Pedro Maia Matulevicius / TIA: 32241429

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define linhas 10000
#define colunas 10000

//matriz, vetor e vetor de resultado globais para que possam ser acessados por todas as threads e dentro da funcao
//ja que o x de resultados esta presente aqui, nao havera necessidade de juntar 
//o y de todas as threads posteriormente.
double A[linhas][colunas];
double x[colunas];
double y[linhas]; 

int main() {
    //O seguinte itera pela A e x e incrementa cada espaço com  um valor incrementado por 1
    //a cada item.
    int i, j = 0;
    double k = 0;
    //Portanto, o problema sera calculado para vetor [1, 2, 3] e matriz [[1, 2, 3]
    //                                                                   [4, 5, 6]
    //                                                                   [7, 8, 9]]

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            k++;
            A[i][j] = k;
        }
    }
    
    k = 0;
    for (i = 0; i < colunas ; i++) {
        k++;
        x[i] = k;
    }


    for (int i = 0; i < linhas; i++) {
    	y[i] = 0;
        for (int j = 0; j < colunas; j++) {
            y[i] += A[i][j] * x[j];
	}
    }

    printf("Resultado: [ ");
    for (i = 0; i < linhas ; i++) {
            printf("%f ", y[i]);
    }
    printf("]");
    return 0;
}
