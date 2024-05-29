#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <gmp.h>
#include <mpfr.h>

void fatorial(int iteracoes, int bits, mpfr_t resultPonteiro) {
    long int posicao = omp_get_thread_num();
    long int threadnum = omp_get_num_threads();

    long int parcela = iteracoes / threadnum;
    long int inicio = parcela * posicao;
    long int fim = inicio + parcela - 1; //dividir a workload igualmente

    if (posicao == threadnum - 1) {
        fim = iteracoes;
    }

    mpfr_t atual;
    mpfr_init2(atual, bits);
    mpfr_set_d(atual, 1.0, MPFR_RNDU);

    mpfr_t div;
    mpfr_init2(div, 53);
    mpfr_set_d(div, 1.0, MPFR_RNDU);

    mpfr_t add;
    mpfr_init2(add, bits);

    for (long int i = 1; i <= inicio; ++i) {
        mpfr_mul_si(atual, atual, i, MPFR_RNDU);
    }

    mpfr_t resultParcial;
    mpfr_init2(resultParcial, bits);
    mpfr_set_d(resultParcial, 0.0, MPFR_RNDU);

    if (posicao == 0) {
        for (long int i = inicio + 2; i <= fim; ++i) {
                mpfr_mul_si(atual, atual, i, MPFR_RNDU);
                mpfr_div(add, div, atual, MPFR_RNDU); //infelizmente ha a necessidade de criar um numero mpfr para a divisao por 1,  
                mpfr_add(resultParcial, resultParcial, add, MPFR_RNDU);        //ja que ha uma funcao para dividir um mpfr por um int, mas nao um int por mpfr.
        }

     } else {
        for (long int i = inicio; i <= fim; ++i) {
                mpfr_mul_si(atual, atual, i, MPFR_RNDU);
                mpfr_div(add, div, atual, MPFR_RNDU);
                mpfr_add(resultParcial, resultParcial, add, MPFR_RNDU);
        }
    }

    mpfr_add(resultPonteiro, resultPonteiro, resultParcial, MPFR_RNDU);
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("\nErro! Execute o programa com 3 argumentos: numero de iteracoes, numero de bits, e numero de threads.");
        return 1;
    }

    int iteracoes = strtol(argv[1], NULL, 10);
    int bits = strtol(argv[2], NULL, 10);
    int threads = strtol(argv[3], NULL, 10);

    mpfr_t result;
    mpfr_init2(result, bits);
    mpfr_set_d(result, 2.0, MPFR_RNDU);

    # pragma omp parallel num_threads(threads) 
    {
    fatorial(iteracoes, bits, result); 
    }
    mpfr_out_str(stdout, 10, 0, result, MPFR_RNDU);

    return 0;
}
