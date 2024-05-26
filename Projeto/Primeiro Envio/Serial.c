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
        mpfr_mul_si(atual, atual, i, MPFR_RNDU); // Multiply atual by i
        mpfr_div(add, div, atual, MPFR_RNDU);
	mpfr_add(resultPonteiro, resultPonteiro, add, MPFR_RNDU); // Add atual to resultPonteiro
    }
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
    mpfr_set_d(result, 2.0, MPFR_RNDU); // Initialize result with 2.0

    fatorial(iteracoes, bits, result); // Call the fatorial function
    mpfr_out_str(stdout, 10, 0, result, MPFR_RNDU);
    // Print or use the result as needed

    mpfr_clear(result); // Clear the memory allocated for result

    return 0;
}
	

