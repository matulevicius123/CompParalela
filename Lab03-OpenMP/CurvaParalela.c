#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>

double alturaCurva(double x) {
    return 5.0 + sin(x);
}

double calcularPorcao(double a, double b, int n) {
	double largura, resultLocal, x;
	double local_a, local_b;
	int i, local_n;
	
	int my_rank = omp_get_thread_num();
	int thread_count = omp_get_num_threads();
	
	largura = (b-a)/n;
	local_n = n/thread_count;
	local_a = a + my_rank * local_n * largura;
	local_b = local_a + local_n * largura;
	resultLocal = (alturaCurva(local_a) + alturaCurva(local_b)) / 2.0;
	for (i = 1; i <= local_n-1; i++) {
	   x = local_a + i*largura;
	   resultLocal += alturaCurva(x);
	}

	resultLocal = resultLocal * largura;
	return resultLocal;
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Utilize os seguintes argumentos de entrada: Inicio, Fim, Numero de Trapezios, e Numero de Threads.");
        return 1;
    }

    double a = atof(argv[1]);  // a = inicio da curva
    double b = atof(argv[2]);  // b = final da curva
    int n = atoi(argv[3]);     // n = numero de trapezios a serem criados
    int threads = atoi(argv[4]); //threads = numero de threads a serem utilizadas
    double resultadoGlobal = 0.0;

    #pragma omp parallel num_threads(threads) 
    {
        double resultadoThread = 0.0;
        resultadoThread = calcularPorcao(a, b, n);
        resultadoGlobal += resultadoThread;
    }

    printf("Estimativa da Integral: %lf\n", resultadoGlobal);
    return 0;
}
