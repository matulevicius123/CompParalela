#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <mpfr.h>

void fatorial(int iteracoes, int bits, mpfr_t resultPonteiro) {
    mpfr_t atual;
    mpfr_init2(atual, bits);
    mpfr_set_d(atual, 1.0, MPFR_RNDU);

    mpfr_t div;
    mpfr_init2(div, bits);
    mpfr_set_d(div, 1.0, MPFR_RNDU);

    mpfr_t add;
    mpfr_init2(add, bits);

    for (long int i = 2; i <= iteracoes; ++i) {
        mpfr_mul_si(atual, atual, i, MPFR_RNDU); // multiplicar o atual por i
        mpfr_div(add, div, atual, MPFR_RNDU);
	mpfr_add(resultPonteiro, resultPonteiro, add, MPFR_RNDU); // adicionar atual ao ponteiro de resultado
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("\nErro! Execute o programa com 2 argumentos: numero de iteracoes e numero de bits."); 
        return 1;
    }

    int iteracoes = strtol(argv[1], NULL, 10);
    int bits = strtol(argv[2], NULL, 10);

    mpfr_t result;
    mpfr_init2(result, bits);
    mpfr_set_d(result, 2.0, MPFR_RNDU); // inicializa result com 2.0, n = 0 e n = 1 sobre 1 sao 1, e nao computariam no loop

    fatorial(iteracoes, bits, result); // chama a fatorial
    mpfr_out_str(stdout, 10, 0, result, MPFR_RNDU);

    mpfr_clear(result);
    return 0;
}
